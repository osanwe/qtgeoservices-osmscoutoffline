#ifndef QGEOROUTEREPLYOSMSCOUTOFFLINE_H
#define QGEOROUTEREPLYOSMSCOUTOFFLINE_H


#include <QtLocation/private/qgeoroutereply_p.h>


class QGeoRouteReplyOsmScoutOffline : public QGeoRouteReply
{
public:
    explicit QGeoRouteReplyOsmScoutOffline(const QList<QGeoRoute> &routes, Error error,
                                           const QString &errorString);
};

#endif // QGEOROUTEREPLYOSMSCOUTOFFLINE_H
