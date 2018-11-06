#include "qgeoserviceproviderfactoryosmscoutoffline.h"


QGeoRoutingManagerEngine *QGeoServiceProviderFactoryOsmScoutOffline::createRoutingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) const
{
    return new QGeoRoutingManagerEngineOsmScoutOffline(parameters, error, errorString);
}


QGeoMappingManagerEngine *QGeoServiceProviderFactoryOsmScoutOffline::createMappingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineOsmScoutOffline(parameters, error, errorString);
}
