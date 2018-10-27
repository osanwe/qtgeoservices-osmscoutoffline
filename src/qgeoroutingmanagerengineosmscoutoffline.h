#ifndef QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
#define QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H

#include <QGeoServiceProvider>
#include <QtLocation/private/qgeoroutingmanagerengine_p.h>

class QGeoRoutingManagerEngineOsmScoutOffline : public QGeoRoutingManagerEngine
{
    Q_OBJECT

public:
    explicit QGeoRoutingManagerEngineOsmScoutOffline(const QMap<QString, QVariant> &parameters,
                                                     QGeoServiceProvider::Error *error,
                                                     QString *errorString);
};

#endif // QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
