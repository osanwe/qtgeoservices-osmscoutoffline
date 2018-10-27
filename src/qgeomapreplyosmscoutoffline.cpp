#include "qgeomapreplyosmscoutoffline.h"

QGeoMapReplyOsmScoutOffline::QGeoMapReplyOsmScoutOffline(QNetworkReply *reply,
                                                         const QGeoTileSpec &spec, QObject *parent)
    : QGeoTiledMapReply(spec, parent)
    , m_reply(reply)
{
    connect(m_reply, SIGNAL(finished()), this, SLOT(networkReplyFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
    connect(m_reply, SIGNAL(destroyed(QObject*)), this, SLOT(replyDestroyed()));
}

QGeoMapReplyOsmScoutOffline::~QGeoMapReplyOsmScoutOffline()
{
    if (m_reply)
    {
        m_reply->deleteLater();
        m_reply = 0;
    }
}

void QGeoMapReplyOsmScoutOffline::abort()
{
    if (!m_reply) return;
    m_reply->abort();
}

QNetworkReply *QGeoMapReplyOsmScoutOffline::networkReply() const
{
    return m_reply;
}

void QGeoMapReplyOsmScoutOffline::replyDestroyed()
{
    m_reply = 0;
}

void QGeoMapReplyOsmScoutOffline::networkReplyFinished()
{
    if (!m_reply) return;
    if (m_reply->error() != QNetworkReply::NoError) return;
    QByteArray data = m_reply->readAll();
    setMapImageData(data);
    setMapImageFormat("png");
    setFinished(true);
    m_reply->deleteLater();
    m_reply = 0;
}

void QGeoMapReplyOsmScoutOffline::networkReplyError(QNetworkReply::NetworkError error)
{
    if (!m_reply) return;
    if (error != QNetworkReply::OperationCanceledError)
        setError(QGeoTiledMapReply::CommunicationError, m_reply->errorString());
    setFinished(true);
    m_reply->deleteLater();
    m_reply = 0;
}
