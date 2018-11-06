#ifndef QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H
#define QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H

#include <QGeoServiceProviderFactory>
#include <QObject>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

#include "qgeoroutingmanagerengineosmscoutoffline.h"
#include "qgeotiledmappingmanagerengineosmscoutoffline.h"

class QGeoServiceProviderFactoryOsmScoutOffline : public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0"
                      FILE "../osmscoutoffline_plugin.json")

public:
    QGeoRoutingManagerEngine *createRoutingManagerEngine(const QVariantMap &parameters,
                                                         QGeoServiceProvider::Error *error,
                                                         QString *errorString) const;
    QGeoMappingManagerEngine *createMappingManagerEngine(const QVariantMap &parameters,
                                                         QGeoServiceProvider::Error *error,
                                                         QString *errorString) const;
};

#endif // QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H
