#include "qgeoroutereplyosmscoutoffline.h"
#include "qgeoroutingmanagerengineosmscoutoffline.h"


QGeoRouteReplyOsmScoutOffline::QGeoRouteReplyOsmScoutOffline(QNetworkReply *reply,
                                                             const QGeoRouteRequest &request,
                                                             QObject *parent)
    : QGeoRouteReply(request, parent)
{
    if (!reply)
    {
        qDebug() << "Null reply";
        setError(UnknownError, QStringLiteral("Null reply"));
        return;
    }
    connect(reply, SIGNAL(finished()), this, SLOT(networkReplyFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
//    connect(this, &QGeoRouteReply::aborted, reply, &QNetworkReply::abort);
    connect(this, &QObject::destroyed, reply, &QObject::deleteLater);
}


QGeoRouteReplyOsmScoutOffline::~QGeoRouteReplyOsmScoutOffline()
{}


void QGeoRouteReplyOsmScoutOffline::networkReplyFinished()
{
    qDebug() << "network finished";
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError)
        return;

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

    for (QGeoRoute &route : routes)
    {
        route.setRequest(request());
    }

    setRoutes(routes);
    setFinished(true);
}


void QGeoRouteReplyOsmScoutOffline::networkReplyError(QNetworkReply::NetworkError error)
{
    qDebug() << "network error";
    Q_UNUSED(error)
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    setError(QGeoRouteReply::CommunicationError, reply->errorString());
}
