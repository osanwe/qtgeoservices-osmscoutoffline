#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRoutingManagerEngineOsmScoutOffline::QGeoRoutingManagerEngineOsmScoutOffline(
        const QMap<QString, QVariant> &parameters, QGeoServiceProvider::Error *error,
        QString *errorString)
{
    // TODO: Maybe add Fetcher

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}
