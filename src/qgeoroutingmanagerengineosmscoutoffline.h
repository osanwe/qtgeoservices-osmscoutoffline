#ifndef QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
#define QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H

#include <QGeoCoordinate>
#include <QGeoRoute>

#include <QGeoServiceProvider>
#include <QtLocation/qgeoroutingmanagerengine.h>
#include <QtLocation/private/qgeoroutingmanagerengine_p.h>

#include "qgeoroutereplyosmscoutoffline.h"

class QGeoRoutingManagerEngineOsmScoutOffline : public QGeoRoutingManagerEngine
{
    Q_OBJECT

public:
    explicit QGeoRoutingManagerEngineOsmScoutOffline(const QVariantMap &parameters,
                                                     QGeoServiceProvider::Error *error,
                                                     QString *errorString);
    QGeoRouteReply *calculateRoute(const QGeoRouteRequest &request);
};

#endif // QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
