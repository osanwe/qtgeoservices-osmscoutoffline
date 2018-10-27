#ifndef QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H
#define QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H

#include <QGeoServiceProvider>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

#include "qgeotilefetcherosmscoutoffline.h"

class QGeoTiledMappingManagerEngineOsmScoutOffline : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT

public:
    explicit QGeoTiledMappingManagerEngineOsmScoutOffline(const QMap<QString, QVariant> &parameters,
                                                          QGeoServiceProvider::Error *error,
                                                          QString *errorString);
    QGeoMapData *createMapData();
};

#endif // QGEOTILEDMAPPINGMANAGERENGINEOSMSCOUTOFFLINE_H
