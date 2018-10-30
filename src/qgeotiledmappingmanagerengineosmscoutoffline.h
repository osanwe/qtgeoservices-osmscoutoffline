#ifndef QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H
#define QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H

#include <QGeoServiceProvider>
#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>
#include <QtLocation/private/qgeotiledmapdata_p.h>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

#include "qgeotilefetcherosmscoutoffline.h"

class QGeoTiledMappingManagerEngineOsmScoutOffline : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT

public:
    explicit QGeoTiledMappingManagerEngineOsmScoutOffline(const QVariantMap &parameters,
                                                          QGeoServiceProvider::Error *error,
                                                          QString *errorString);
    QGeoMapData *createMapData();
};

#endif // QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H
