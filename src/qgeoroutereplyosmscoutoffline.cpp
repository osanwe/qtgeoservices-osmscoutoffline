#include "qgeoroutereplyosmscoutoffline.h"

QGeoRouteReplyOsmScoutOffline::QGeoRouteReplyOsmScoutOffline(const QList<QGeoRoute> &routes,
                                                             Error error,
                                                             const QString &errorString)
    : QGeoRouteReply(error, errorString)
{
    setRoutes(routes);
}
