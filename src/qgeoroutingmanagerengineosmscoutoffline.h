#ifndef QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
#define QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

#include <QGeoCoordinate>
#include <QGeoRoute>

#include <QGeoServiceProvider>
#include <QtLocation/QGeoRoutingManagerEngine>
//#include <QtLocation/qgeoroutingmanagerengine.h>
#include <QtLocation/private/qgeoroutingmanagerengine_p.h>

#include <QDebug>

#include "qgeoroutereplyosmscoutoffline.h"

class QGeoRoutingManagerEngineOsmScoutOffline : public QGeoRoutingManagerEngine
{
    Q_OBJECT

public:
    explicit QGeoRoutingManagerEngineOsmScoutOffline(const QVariantMap &parameters,
                                                     QGeoServiceProvider::Error *error,
                                                     QString *errorString);
    ~QGeoRoutingManagerEngineOsmScoutOffline();

    QGeoRouteReply *calculateRoute(const QGeoRouteRequest &request);
//    const QGeoRouteParser *routeParser() const;

private Q_SLOTS:
    void replyFinished();
    void replyError(QGeoRouteReply::Error errorCode, const QString &errorString);

private:
    QNetworkAccessManager *mNetworkManager = nullptr;
//    QGeoRouteParser *mRouteParser;
    QByteArray mUserAgent;
    QString mUrlPrefix;
};

#endif // QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
