/****************************************************************************
**
** Copyright (c) 2018, Petr Vytovtov <osanwevpk@gmail.com>
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the <organization> nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
****************************************************************************/

#include <QUrlQuery>

#include "qgeoroutereplyosmscoutoffline.h"
#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRoutingManagerEngineOsmScoutOffline::QGeoRoutingManagerEngineOsmScoutOffline(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString)
    : QGeoRoutingManagerEngine(parameters), mNetworkManager(new QNetworkAccessManager(this))
{
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

QGeoRouteReply *QGeoRoutingManagerEngineOsmScoutOffline::calculateRoute(const QGeoRouteRequest &request)
{
    QGeoCoordinate start = request.waypoints()[0];
    QGeoCoordinate end = request.waypoints()[1];
    QString from = QStringLiteral("%1,%2").arg(QString::number(start.latitude()), QString::number(start.longitude()));
    QString to = QStringLiteral("%1,%2").arg(QString::number(end.latitude()), QString::number(end.longitude()));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("from"), from);
    query.addQueryItem(QStringLiteral("to"), to);
    query.addQueryItem(QStringLiteral("ratio"), QStringLiteral("1"));

    QUrl url(QStringLiteral("https://sightsafari.city/api/v1/routes/direct"));
    url.setQuery(query);

    QNetworkRequest remoteRequest(url);
    QNetworkReply *reply = mNetworkManager->get(remoteRequest);

    QGeoRouteReplyOsmScoutOffline *routeReply = new QGeoRouteReplyOsmScoutOffline(reply, request, this);
    connect(routeReply, &QGeoRouteReplyOsmScoutOffline::finished,
            this, &QGeoRoutingManagerEngineOsmScoutOffline::replyFinished);
    connect(routeReply, static_cast<void(QGeoRouteReplyOsmScoutOffline::*)
            (QGeoRouteReplyOsmScoutOffline::Error, const QString &)>(&QGeoRouteReplyOsmScoutOffline::error),
            this, &QGeoRoutingManagerEngineOsmScoutOffline::replyError);

    return routeReply;
}

void QGeoRoutingManagerEngineOsmScoutOffline::replyFinished()
{
    QGeoRouteReply *reply = qobject_cast<QGeoRouteReply *>(sender());
    if (reply != nullptr)
        emit finished(reply);
}

void QGeoRoutingManagerEngineOsmScoutOffline::replyError(QGeoRouteReply::Error errorCode,
                                                         const QString &errorString)
{
    QGeoRouteReply *reply = qobject_cast<QGeoRouteReply *>(sender());
    if (reply != nullptr)
        emit error(reply, errorCode, errorString);
}
