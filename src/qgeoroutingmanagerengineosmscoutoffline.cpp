#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRoutingManagerEngineOsmScoutOffline::QGeoRoutingManagerEngineOsmScoutOffline(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) : QGeoRoutingManagerEngine(parameters)
{
    mNetworkManager = new QNetworkAccessManager();

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}


QGeoRoutingManagerEngineOsmScoutOffline::~QGeoRoutingManagerEngineOsmScoutOffline()
{
    mNetworkManager->deleteLater();
    mNetworkManager = nullptr;
}


QGeoRouteReply *QGeoRoutingManagerEngineOsmScoutOffline::calculateRoute(
        const QGeoRouteRequest &request)
{
    QGeoCoordinate start = request.waypoints()[0];
    QGeoCoordinate end = request.waypoints()[1];

    QUrl requestUrl("https://sightsafari.city/pathfindingcontroller/findpath");
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("from", QString("%1,%2").arg(QString::number(start.latitude()),
                                                       QString::number(start.longitude())));
    urlQuery.addQueryItem("to", QString("%1,%2").arg(QString::number(end.latitude()),
                                                     QString::number(end.longitude())));
    urlQuery.addQueryItem("ratio", "1");
    requestUrl.setQuery(urlQuery);
    qDebug() << requestUrl;
    QNetworkRequest remoteRequest(requestUrl);
    QNetworkReply *reply = mNetworkManager->get(remoteRequest);

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    qDebug() << reply->errorString();
    QJsonDocument jDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonArray jPath = jDoc.object().value("latLonPoints").toArray();

    QList<QGeoCoordinate> coords;
    for (QJsonValue value : jPath)
    {
        QJsonArray coord = value.toArray();
        coords.append(QGeoCoordinate(coord.at(0).toDouble(), coord.at(1).toDouble()));
    }

    QGeoRoute route;
    route.setPath(coords);
    QList<QGeoRoute> routes = {route};

    return new QGeoRouteReplyOsmScoutOffline(routes, QGeoRouteReply::NoError, "");
}
