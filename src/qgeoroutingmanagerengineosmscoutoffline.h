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
#include <QtLocation/qgeoroutingmanagerengine.h>
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

private:
    QNetworkAccessManager *mNetworkManager = nullptr;
};

#endif // QGEOROUTINGMANAGERENGINEOSMSCOUTOFFLINE_H
