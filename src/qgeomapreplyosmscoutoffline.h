#ifndef QGEOMAPREPLYOSMSCOUTOFFLINE_H
#define QGEOMAPREPLYOSMSCOUTOFFLINE_H

#include <QNetworkReply>
#include <QtLocation/private/qgeotiledmapreply_p.h>

class QGeoMapReplyOsmScoutOffline : public QGeoTiledMapReply
{
    Q_OBJECT

public:
    explicit QGeoMapReplyOsmScoutOffline(QNetworkReply *reply, const QGeoTileSpec &spec,
                                         QObject *parent = 0);
    virtual ~QGeoMapReplyOsmScoutOffline();
    void abort();
    QNetworkReply *networkReply() const;

private Q_SLOTS:
    void replyDestroyed();
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);

private:
    QNetworkReply *m_reply;
};

#endif // QGEOMAPREPLYOSMSCOUTOFFLINE_H
