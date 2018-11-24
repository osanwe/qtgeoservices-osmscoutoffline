#ifndef QGEOROUTEREPLYOSMSCOUTOFFLINE_H
#define QGEOROUTEREPLYOSMSCOUTOFFLINE_H


#include <QtNetwork/QNetworkReply>
//#include <QtLocation/QGeoRouteReply>
#include <QtLocation/private/qgeoroutereply_p.h>

#include <QDebug>


class QGeoRouteReplyOsmScoutOffline : public QGeoRouteReply
{
    Q_OBJECT

public:
    explicit QGeoRouteReplyOsmScoutOffline(QObject *parent = 0);
    QGeoRouteReplyOsmScoutOffline(QNetworkReply *reply, const QGeoRouteRequest &request,
                                  QObject *parent = 0);
    ~QGeoRouteReplyOsmScoutOffline();

private Q_SLOTS:
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);
};

#endif // QGEOROUTEREPLYOSMSCOUTOFFLINE_H
