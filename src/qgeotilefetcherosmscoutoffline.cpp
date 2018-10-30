#include "qgeotilefetcherosmscoutoffline.h"

QGeoTileFetcherOsmScoutOffline::QGeoTileFetcherOsmScoutOffline(
        QGeoTiledMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , m_networkManager(new QNetworkAccessManager(this))
{}

void QGeoTileFetcherOsmScoutOffline::setParams(const QVariantMap &params)
{
    m_params = params;
}

QGeoTiledMapReply *QGeoTileFetcherOsmScoutOffline::getTileImage(const QGeoTileSpec &spec)
{
    QUrlQuery query;
    for (QString &key : m_params.keys())
        query.addQueryItem(key, m_params[key].toString());
    query.addQueryItem(QStringLiteral("x"), QString::number(spec.x()));
    query.addQueryItem(QStringLiteral("y"), QString::number(spec.y()));
    query.addQueryItem(QStringLiteral("z"), QString::number(spec.zoom()));

    QUrl url(QStringLiteral("http://localhost:8553/v1/tile"));
    url.setQuery(query);

    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply *reply = m_networkManager->get(request);
    return new QGeoMapReplyOsmScoutOffline(reply, spec);
}
