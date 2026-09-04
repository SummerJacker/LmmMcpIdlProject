/**
 * @file HttpPlugin.cpp
 * @brief HttpPlugin / HttpServerWorker：最小 HTTP/1.1 JSON API。
 */

#include "HttpPlugin.h"

#include "HttpApiExecutor.h"

#include <QAbstractSocket>
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMetaObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>
#include <QVector>

namespace {

/**
 * @brief 构造与 HttpApiExecutor 一致的错误 JSON体（success/message/data）。
 */
QJsonObject makeJsonErrorBody(const QString &message) {
    QJsonObject o;
    o.insert(QStringLiteral("success"), false);
    o.insert(QStringLiteral("message"), QJsonValue(message));
    o.insert(QStringLiteral("data"), QJsonValue::Null);
    return o;
}

QByteArray buildHttpResponse(int statusCode, const QByteArray &jsonBody, const char *contentType) {
    QString reason;
    switch (statusCode) {
    case 200: reason = QStringLiteral("OK"); break;
    case 400: reason = QStringLiteral("Bad Request"); break;
    case 404: reason = QStringLiteral("Not Found"); break;
    case 405: reason = QStringLiteral("Method Not Allowed"); break;
    case 409: reason = QStringLiteral("Conflict"); break;
    case 422: reason = QStringLiteral("Unprocessable Entity"); break;
    case 429: reason = QStringLiteral("Too Many Requests"); break;
    case 503: reason = QStringLiteral("Service Unavailable"); break;
    default:
        statusCode = 500;
        reason = QStringLiteral("Internal Server Error");
        break;
    }
    const QString statusLine = QStringLiteral("%1 %2").arg(statusCode).arg(reason);
    QByteArray hdr;
    hdr += "HTTP/1.1 " + statusLine.toUtf8() + "\r\n";
    hdr += "Content-Type: ";
    hdr += contentType;
    hdr += "\r\n";
    hdr += "Connection: close\r\n";
    hdr += "Content-Length: " + QByteArray::number(jsonBody.size()) + "\r\n\r\n";
    return hdr + jsonBody;
}

bool readHttpRequest(QTcpSocket *socket, QByteArray *outHeaders, QByteArray *outBody) {
    *outHeaders = QByteArray();
    *outBody = QByteArray();
    while (socket->waitForReadyRead(30000)) {
        *outHeaders += socket->readAll();
        int idx = outHeaders->indexOf("\r\n\r\n");
        if (idx >= 0) {
            QByteArray rest = outHeaders->mid(idx + 4);
            *outHeaders = outHeaders->left(idx);
            int cl = -1;
            const QList<QByteArray> lines = outHeaders->split('\n');
            for (const QByteArray &line : lines) {
                const QByteArray l = line.trimmed();
                const QByteArray low = l.toLower();
                static const QByteArray kCl = QByteArrayLiteral("content-length:");
                if (low.startsWith(kCl)) {
                    cl = low.mid(kCl.size()).trimmed().toInt();
                }
            }
            *outBody = rest;
            if (cl < 0) {
                if (rest.isEmpty())
                    return true;
                return false;
            }
            while (outBody->size() < cl && socket->waitForReadyRead(30000))
                *outBody += socket->readAll();
            return outBody->size() >= cl;
        }
    }
    return false;
}

void parseRequestLine(const QByteArray &headers, QString *method, QString *path, QString *query) {
    *method = QString();
    *path = QString();
    *query = QString();
    const QList<QByteArray> lines = headers.split('\n');
    if (lines.isEmpty())
        return;
    const QList<QByteArray> parts = lines[0].trimmed().split(' ');
    if (parts.size() < 2)
        return;
    *method = QString::fromLatin1(parts[0].toUpper());
    QByteArray pathQuery = parts[1];
    int q = pathQuery.indexOf('?');
    if (q >= 0) {
        *path = QString::fromUtf8(pathQuery.left(q));
        *query = QString::fromUtf8(pathQuery.mid(q + 1));
    } else {
        *path = QString::fromUtf8(pathQuery);
    }
}

} // namespace

HttpServerWorker::HttpServerWorker(HttpApiExecutor *executor, QObject *parent)
    : QObject(parent), executor_(executor) {
    /**
     * @description
     * 让 QTcpServer 成为 worker 的子对象，确保在 worker moveToThread 后与其保持同线程亲和性。
     * 否则 server_ 停留在创建线程，nextPendingConnection() 创建 QTcpSocket 时会触发跨线程 parent 错误。
     */
    server_.setParent(this);
    sseTimer_.setParent(this);
    sseTimer_.setInterval(1000);
    QObject::connect(&sseTimer_, &QTimer::timeout, this, &HttpServerWorker::broadcastXy2dSse);
}

void HttpServerWorker::listenOnPort(quint16 port, const QHostAddress &bindAddress) {
    connect(&server_, &QTcpServer::newConnection, this, &HttpServerWorker::onNewConnection);
    if (!server_.listen(bindAddress, port)) {
        qWarning() << QStringLiteral("[HttpPlugin] listen failed:") << server_.errorString();
        return;
    }
    sseTimer_.start();
    qInfo() << QStringLiteral("[HttpPlugin] listening on") << bindAddress.toString()
            << QStringLiteral("port") << port << QStringLiteral("XY2D monitor: GET /debug/xy2d  SSE /debug/xy2d/stream");
}

void HttpServerWorker::onNewConnection() {
    while (QTcpSocket *sock = server_.nextPendingConnection()) {
        QObject::connect(sock, &QTcpSocket::disconnected, sock, &QTcpSocket::deleteLater);
        handleClient(sock);
    }
}

void HttpServerWorker::handleClient(QTcpSocket *socket) {
    QByteArray headers;
    QByteArray body;
    if (!readHttpRequest(socket, &headers, &body)) {
        const QByteArray resp =
            buildHttpResponse(400,
                              QJsonDocument(makeJsonErrorBody(QStringLiteral("Bad HTTP request")))
                                  .toJson(QJsonDocument::Compact),
                              "application/json; charset=utf-8");
        socket->write(resp);
        socket->flush();
        socket->disconnectFromHost();
        return;
    }

    QString method;
    QString path;
    QString query;
    parseRequestLine(headers, &method, &path, &query);

    if (method == QStringLiteral("GET") && path == QStringLiteral("/debug/xy2d")) {
        QFile f(QStringLiteral(":/web/xy2d_monitor.html"));
        if (!f.open(QIODevice::ReadOnly)) {
            const QByteArray resp =
                buildHttpResponse(500,
                                  QJsonDocument(makeJsonErrorBody(QStringLiteral("xy2d_monitor.html missing")))
                                      .toJson(QJsonDocument::Compact),
                                  "application/json; charset=utf-8");
            socket->write(resp);
            socket->flush();
            socket->disconnectFromHost();
            return;
        }
        const QByteArray html = f.readAll();
        QByteArray hdr;
        hdr += "HTTP/1.1 200 OK\r\n";
        hdr += "Content-Type: text/html; charset=utf-8\r\n";
        hdr += "Connection: close\r\n";
        hdr += "Content-Length: " + QByteArray::number(html.size()) + "\r\n\r\n";
        socket->write(hdr + html);
        socket->flush();
        socket->disconnectFromHost();
        return;
    }

    if (method == QStringLiteral("GET") && path == QStringLiteral("/debug/xy2d/stream")) {
        QByteArray hdr;
        hdr += "HTTP/1.1 200 OK\r\n";
        hdr += "Content-Type: text/event-stream; charset=utf-8\r\n";
        hdr += "Cache-Control: no-cache\r\n";
        hdr += "Connection: keep-alive\r\n";
        hdr += "\r\n";
        socket->write(hdr);
        socket->flush();
        xy2dSseSockets_.append(socket);
        QObject::connect(socket, &QTcpSocket::disconnected, this, [this, socket]() {
            xy2dSseSockets_.removeAll(socket);
        });
        QTimer::singleShot(0, this, &HttpServerWorker::broadcastXy2dSse);
        return;
    }

    QByteArray jsonBody;
    int httpStatus = 200;
    if (!executor_) {
        httpStatus = 500;
        jsonBody = QJsonDocument(makeJsonErrorBody(QStringLiteral("executor null")))
                       .toJson(QJsonDocument::Compact);
    } else {
        jsonBody = QByteArray();
        const bool invoked = QMetaObject::invokeMethod(
            executor_, "processRequestSlot", Qt::BlockingQueuedConnection,
            Q_RETURN_ARG(QByteArray, jsonBody), Q_ARG(QString, method), Q_ARG(QString, path),
            Q_ARG(QString, query), Q_ARG(QByteArray, body));
        if (!invoked) {
            httpStatus = 500;
            jsonBody = QJsonDocument(makeJsonErrorBody(QStringLiteral("invoke failed")))
                           .toJson(QJsonDocument::Compact);
        } else {
            httpStatus = executor_->lastHttpStatus();
        }
    }

    const QByteArray resp = buildHttpResponse(httpStatus, jsonBody, "application/json; charset=utf-8");
    socket->write(resp);
    socket->flush();
    socket->disconnectFromHost();
}

void HttpServerWorker::broadcastXy2dSse() {
    if (xy2dSseSockets_.isEmpty() || !executor_)
        return;
    QByteArray payload;
    const bool invoked = QMetaObject::invokeMethod(executor_, "buildXy2dMonitorEventPayload",
                                                   Qt::BlockingQueuedConnection,
                                                   Q_RETURN_ARG(QByteArray, payload));
    if (!invoked || payload.isEmpty())
        return;
    QByteArray chunk = QByteArrayLiteral("data: ");
    chunk += payload;
    chunk += "\n\n";
    const QVector<QTcpSocket *> snapshot = xy2dSseSockets_;
    for (QTcpSocket *sock : snapshot) {
        if (!sock || sock->state() != QAbstractSocket::ConnectedState)
            continue;
        if (sock->write(chunk) < 0)
            sock->disconnectFromHost();
        else
            sock->flush();
    }
}

HttpPlugin::HttpPlugin(HttpApiExecutor *executor, QObject *parent)
    : QObject(parent), executor_(executor) {}

HttpPlugin::~HttpPlugin() { stop(); }

bool HttpPlugin::start(quint16 port, const QHostAddress &bindAddress) {
    if (!executor_) {
        qWarning() << QStringLiteral("[HttpPlugin] executor is null");
        return false;
    }
    stop();
    thread_ = new QThread(this);
    worker_ = new HttpServerWorker(executor_);
    worker_->moveToThread(thread_);
    QObject::connect(thread_, &QThread::started, worker_, [this, port, bindAddress]() {
        worker_->listenOnPort(port, bindAddress);
    });
    QObject::connect(thread_, &QThread::finished, worker_, &QObject::deleteLater);
    thread_->start();
    return true;
}

void HttpPlugin::stop() {
    if (thread_) {
        thread_->quit();
        thread_->wait(5000);
        thread_ = nullptr;
    }
    worker_ = nullptr;
}
