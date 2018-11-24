#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRoutingManagerEngineOsmScoutOffline::QGeoRoutingManagerEngineOsmScoutOffline(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString)
    : QGeoRoutingManagerEngine(parameters), mNetworkManager(new QNetworkAccessManager(this))
{
    mUrlPrefix = QStringLiteral("https://sightsafari.city/pathfindingcontroller/findpath");

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}


QGeoRoutingManagerEngineOsmScoutOffline::~QGeoRoutingManagerEngineOsmScoutOffline()
{}


QGeoRouteReply *QGeoRoutingManagerEngineOsmScoutOffline::calculateRoute(
        const QGeoRouteRequest &request)
{
    QGeoCoordinate start = request.waypoints()[0];
    QGeoCoordinate end = request.waypoints()[1];

    QUrl requestUrl(mUrlPrefix);
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

    QGeoRouteReplyOsmScoutOffline *routeReply = new QGeoRouteReplyOsmScoutOffline(reply, request, this);
    connect(routeReply, SIGNAL(finished()), this, SLOT(replyFinished()));
    connect(routeReply, SIGNAL(error(QGeoRouteReply::Error,QString)),
            this, SLOT(replyError(QGeoRouteReply::Error,QString)));

    return routeReply;
}


void QGeoRoutingManagerEngineOsmScoutOffline::replyFinished()
{
    qDebug() << "Finished";
    QGeoRouteReply *reply = qobject_cast<QGeoRouteReply *>(sender());
    if (reply)
        emit finished(reply);
}


void QGeoRoutingManagerEngineOsmScoutOffline::replyError(QGeoRouteReply::Error errorCode,
                                                         const QString &errorString)
{
    qDebug() << "Error " << errorString;
    QGeoRouteReply *reply = qobject_cast<QGeoRouteReply *>(sender());
    if (reply)
        emit error(reply, errorCode, errorString);
}
