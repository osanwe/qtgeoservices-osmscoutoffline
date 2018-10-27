#ifndef QGEOTILEFETCHEROSMSCOUTOFFLINE_H
#define QGEOTILEFETCHEROSMSCOUTOFFLINE_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QtLocation/private/qgeotilespec_p.h>

#include "qgeomapreplyosmscoutoffline.h"

class QGeoTileFetcherOsmScoutOffline : public QGeoTileFetcher
{
    Q_OBJECT

public:
    explicit QGeoTileFetcherOsmScoutOffline(QGeoTiledMappingManagerEngine *parent = 0);
    void setParams(const QMap<QString, QVariant> &params);

private:
    QGeoTiledMapReply *getTileImage(const QGeoTileSpec &spec);

    QMap<QString, QVariant> m_params;
    QNetworkAccessManager *m_networkManager;
};

#endif // QGEOTILEFETCHEROSMSCOUTOFFLINE_H
