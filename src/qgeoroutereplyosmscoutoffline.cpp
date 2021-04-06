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

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "qgeoroutereplyosmscoutoffline.h"
#include "qgeoroutingmanagerengineosmscoutoffline.h"

QGeoRouteReplyOsmScoutOffline::QGeoRouteReplyOsmScoutOffline(QNetworkReply *reply,
                                                             const QGeoRouteRequest &request,
                                                             QObject *parent)
    : QGeoRouteReply(request, parent)
{
    if (reply == nullptr) {
        setError(UnknownError, QStringLiteral("Null reply"));
        return;
    }

    connect(reply, &QNetworkReply::finished,
            this, &QGeoRouteReplyOsmScoutOffline::networkReplyFinished);
    connect(reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
            this, &QGeoRouteReplyOsmScoutOffline::networkReplyError);
    connect(this, &QGeoRouteReplyOsmScoutOffline::destroyed,
            reply, &QNetworkReply::deleteLater);
}

void QGeoRouteReplyOsmScoutOffline::networkReplyFinished()
{
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError)
        return;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonBody = jsonDoc.object().value(QStringLiteral("body")).toObject();
    QJsonArray jsonPath = jsonBody.value(QStringLiteral("latLonPoints")).toArray();
    QList<QGeoCoordinate> coords;
    for (QJsonValue value : jsonPath) {
        QJsonArray coord = value.toArray();
        coords.append(QGeoCoordinate(coord.at(0).toDouble(), coord.at(1).toDouble()));
    }

    QGeoRoute route;
    route.setPath(coords);
    route.setRequest(request());

    setRoutes({ route });
    setFinished(true);
}

void QGeoRouteReplyOsmScoutOffline::networkReplyError(QNetworkReply::NetworkError error)
{
    Q_UNUSED(error)
    QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    setError(QGeoRouteReply::CommunicationError, reply->errorString());
}
