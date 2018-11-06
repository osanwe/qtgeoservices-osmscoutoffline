#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRoutingManagerEngineOsmScoutOffline::QGeoRoutingManagerEngineOsmScoutOffline(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) : QGeoRoutingManagerEngine(parameters)
{
    // TODO: Maybe add Fetcher

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

QGeoRouteReply *QGeoRoutingManagerEngineOsmScoutOffline::calculateRoute(
        const QGeoRouteRequest &request)
{
//    QGeoRouteReply *reply = new QGeoRouteReply(QGeoRouteReply::NoError, "", 0);

    QGeoCoordinate start(55.7708, 37.5944);
    QGeoCoordinate finish(55.7513, 37.6286);
    QList<QGeoCoordinate> coords = {start, finish};

    QGeoRoute route;
    route.setPath(coords);
    QList<QGeoRoute> routes = {route};

    return new QGeoRouteReplyOsmScoutOffline(routes, QGeoRouteReply::NoError, "");

//    reply->addRoutes(routes);

//    return reply;
}
