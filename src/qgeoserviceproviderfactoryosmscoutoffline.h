#ifndef QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H
#define QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H

#include <QGeoServiceProviderFactory>
#include <QObject>

class QGeoServiceProviderFactoryOsmScoutOffline : public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0"
                      FILE "osmscoutoffline_plugin.json")

public:
    QGeoMappingManagerEngine *createMappingManagerEngine(const QMap<QString, QVariant> &parameters,
                                                         QGeoServiceProvider::Error *error,
                                                         QString *errorString) const;
    QGeoRoutingManagerEngine *createRoutingManagerEngine(const QMap<QString, QVariant> &parameters,
                                                         QGeoServiceProvider::Error *error,
                                                         QString *errorString) const;
};

#endif // QGEOSERVICEPROVIDERFACTORYOSMSCOUTOFFLINE_H
