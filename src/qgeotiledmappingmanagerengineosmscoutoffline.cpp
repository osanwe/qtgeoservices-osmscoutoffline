#include "qgeotiledmappingmanagerengineosmscoutoffline.h"

QGeoTiledMappingManagerEngineOsmScoutOffline::QGeoTiledMappingManagerEngineOsmScoutOffline(
        const QMap<QString, QVariant> &parameters, QGeoServiceProvider::Error *error,
        QString *errorString)
{
    QGeoCameraCapabilities cameraCaps;
    cameraCaps.setMinimumZoomLevel(0.0);
    cameraCaps.setMaximumZoomLevel(19.0);
    setCameraCapabilities(cameraCaps);
    setTileSize(QSize(256, 256));

    QList<QGeoMapType> mapTypes;
    mapTypes << QGeoMapType(QGeoMapType::StreetMap, tr("Street Map"), tr("OSM Street Map"),
                            false, false, 1);
    setSupportedMapTypes(mapTypes);

    // TODO: Add Fetcher

    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

QGeoMapData *QGeoTiledMappingManagerEngineOsmScoutOffline::createMapData()
{
    return new QGeoTiledMapData(this, 0);
}
