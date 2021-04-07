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

#include "qgeomapreplyosmscoutoffline.h"

QGeoMapReplyOsmScoutOffline::QGeoMapReplyOsmScoutOffline(QNetworkReply *reply, const QGeoTileSpec &spec, QObject *parent)
    : QGeoTiledMapReply(spec, parent), m_reply(reply)
{
    connect(m_reply, &QNetworkReply::finished,
            this, &QGeoMapReplyOsmScoutOffline::networkReplyFinished);
    connect(m_reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
            this, &QGeoMapReplyOsmScoutOffline::networkReplyError);
    connect(m_reply, &QNetworkReply::destroyed,
            this, &QGeoMapReplyOsmScoutOffline::replyDestroyed);
}

QGeoMapReplyOsmScoutOffline::~QGeoMapReplyOsmScoutOffline()
{
    if (m_reply != nullptr) {
        m_reply->deleteLater();
        m_reply = nullptr;
    }
}

void QGeoMapReplyOsmScoutOffline::abort()
{
    if (m_reply == nullptr)
        return;

    m_reply->abort();
}

QNetworkReply *QGeoMapReplyOsmScoutOffline::networkReply() const
{
    return m_reply;
}

void QGeoMapReplyOsmScoutOffline::replyDestroyed()
{
    m_reply = nullptr;
}

void QGeoMapReplyOsmScoutOffline::networkReplyFinished()
{
    if (m_reply == nullptr)
        return;

    if (m_reply->error() != QNetworkReply::NoError)
        return;

    setMapImageData(m_reply->readAll());
    setMapImageFormat(QStringLiteral("png"));
    setFinished(true);
    m_reply->deleteLater();
    m_reply = nullptr;
}

void QGeoMapReplyOsmScoutOffline::networkReplyError(QNetworkReply::NetworkError error)
{
    if (m_reply == nullptr)
        return;

    if (error != QNetworkReply::OperationCanceledError)
        setError(QGeoTiledMapReply::CommunicationError, m_reply->errorString());

    setFinished(true);
    m_reply->deleteLater();
    m_reply = nullptr;
}
