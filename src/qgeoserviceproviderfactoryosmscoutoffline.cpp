#include "qgeoserviceproviderfactoryosmscoutoffline.h"


QGeoMappingManagerEngine *QGeoServiceProviderFactoryOsmScoutOffline::createMappingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineOsmScoutOffline(parameters, error, errorString);
}


//QGeoRoutingManagerEngine *QGeoServiceProviderFactoryOsmScoutOffline::createRoutingManagerEngine(
//        const QMap<QString, QVariant> &parameters, QGeoServiceProvider::Error *error,
//        QString *errorString) const
//{
//    return new QGeoRoutingManagerEngineOsmScoutOffline(parameters, error, errorString);
//}
