/**
 * @file main.cpp
 * @brief 轻量 HTTP 服务：接收 POST /api/robot/sendmove，解析 JSON，打印线速度/角速度并返回统一 JSON。
 *
 * 用途：课设演示用，可整体拷贝进你的 Qt 工程；依赖 Qt Core + Network。
 *
 * 构建（任选其一）：
 * - qmake: 在 qt_http_server 目录执行 qmake && nmake 或 mingw32-make
 * - CMake: mkdir build && cd build && cmake .. && cmake --build .
 */

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QElapsedTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMutex>
#include <QMutexLocker>
#include <QTcpServer>
#include <QTcpSocket>
#include <memory>
#include <unordered_map>

namespace {
struct QStringHash {
    size_t operator()(const QString &s) const noexcept { return qHash(s); }
};
} // namespace

static QMutex s_robotMapMutex;
/** 每 robot 一把互斥锁；必须用 std::unordered_map，勿用 QMap（Qt 隐式共享会尝试拷贝含 unique_ptr 的节点，编译失败）。 */
static std::unordered_map<QString, std::unique_ptr<QMutex>, QStringHash> s_robotMutexes;

static const int kPort = 9000;
static const char *kPath = "/api/robot/sendmove";

static QByteArray httpJsonResponse(int statusCode, const QJsonObject &jsonBody) {
    const QByteArray body = QJsonDocument(jsonBody).toJson(QJsonDocument::Compact);
    QString statusLine = (statusCode == 200) ? "200 OK"
                         : (statusCode == 503) ? "503 Service Unavailable"
                         : (statusCode == 429) ? "429 Too Many Requests"
                         : "400 Bad Request";
    QByteArray hdr;
    hdr += "HTTP/1.1 " + statusLine.toUtf8() + "\r\n";
    hdr += "Content-Type: application/json\r\n";
    hdr += "Connection: close\r\n";
    hdr += "Content-Length: " + QByteArray::number(body.size()) + "\r\n\r\n";
    return hdr + body;
}

static bool readHttpRequest(QTcpSocket *socket, QByteArray *outHeaders, QByteArray *outBody) {
    *outHeaders = QByteArray();
    *outBody = QByteArray();
    while (socket->waitForReadyRead(5000)) {
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
                // Qt 6：QByteArray::startsWith 无 CaseSensitivity 重载，先 toLower 再比前缀。
                static const QByteArray kCl = QByteArrayLiteral("content-length:");
                if (low.startsWith(kCl)) {
                    cl = low.mid(kCl.size()).trimmed().toInt();
                }
            }
            *outBody = rest;
            if (cl < 0)
                return false;
            while (outBody->size() < cl && socket->waitForReadyRead(5000))
                *outBody += socket->readAll();
            return outBody->size() >= cl;
        }
    }
    return false;
}

static void handleClient(QTcpSocket *socket) {
    QElapsedTimer timer;
    timer.start();

    QByteArray headers, body;
    if (!readHttpRequest(socket, &headers, &body)) {
        socket->write(httpJsonResponse(400, QJsonObject{{"success", false}, {"message", "Bad HTTP request"}, {"data", QJsonValue::Null}}));
        socket->flush();
        socket->waitForBytesWritten(2000);
        socket->disconnectFromHost();
        return;
    }

    const QList<QByteArray> firstLineParts = headers.split('\n').value(0).trimmed().split(' ');
    if (firstLineParts.size() < 2) {
        socket->write(httpJsonResponse(400, QJsonObject{{"success", false}, {"message", "Bad request line"}, {"data", QJsonValue::Null}}));
        socket->flush();
        socket->waitForBytesWritten(2000);
        socket->disconnectFromHost();
        return;
    }
    const QByteArray method = firstLineParts[0];
    const QByteArray path = firstLineParts[1];

    if (method != "POST" || path != kPath) {
        socket->write(httpJsonResponse(400, QJsonObject{{"success", false}, {"message", "Only POST " + QString::fromUtf8(kPath)}, {"data", QJsonValue::Null}}));
        socket->flush();
        socket->waitForBytesWritten(2000);
        socket->disconnectFromHost();
        return;
    }

    QJsonParseError perr{};
    QJsonDocument doc = QJsonDocument::fromJson(body, &perr);
    if (!doc.isObject()) {
        socket->write(httpJsonResponse(400, QJsonObject{{"success", false}, {"message", "Invalid JSON"}, {"data", QJsonValue::Null}}));
        socket->flush();
        socket->waitForBytesWritten(2000);
        socket->disconnectFromHost();
        return;
    }
    QJsonObject o = doc.object();
    if (!o.contains("linear_velocity") || !o.contains("angular_velocity")) {
        socket->write(httpJsonResponse(400, QJsonObject{{"success", false}, {"message", "Missing linear_velocity or angular_velocity"}, {"data", QJsonValue::Null}}));
        socket->flush();
        socket->waitForBytesWritten(2000);
        socket->disconnectFromHost();
        return;
    }

    const QString robotId = o.value("robot_id").toString("unknown");
    const double lv = o.value("linear_velocity").toDouble();
    const double av = o.value("angular_velocity").toDouble();
    const qint64 durationMs = o.value("duration_ms").toVariant().toLongLong();

    QMutex *mtx = nullptr;
    {
        QMutexLocker mapLocker(&s_robotMapMutex);
        std::unique_ptr<QMutex> &slot = s_robotMutexes[robotId];
        if (!slot)
            slot = std::make_unique<QMutex>();
        mtx = slot.get();
    }
    QMutexLocker rlock(mtx);

    const qint64 ms = timer.elapsed();
    qDebug().noquote() << QDateTime::currentDateTime().toString(Qt::ISODateWithMs)
                       << "robot_id=" << robotId
                       << "linear_velocity(m/s)=" << lv
                       << "angular_velocity(rad/s)=" << av
                       << "duration_ms=" << durationMs
                       << "handle_ms=" << ms;

    QJsonObject data;
    data["robot_id"] = robotId;
    data["linear_velocity"] = lv;
    data["angular_velocity"] = av;
    data["duration_ms"] = durationMs;

    QJsonObject resp{{"success", true}, {"message", "accepted"}, {"data", data}};
    socket->write(httpJsonResponse(200, resp));
    socket->flush();
    socket->waitForBytesWritten(2000);
    socket->disconnectFromHost();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QTcpServer server;
    if (!server.listen(QHostAddress::LocalHost, kPort)) {
        qCritical() << "Listen failed on port" << kPort << server.errorString();
        return 1;
    }
    qInfo() << "QT HTTP server listening on http://127.0.0.1:" << kPort << kPath;

    QObject::connect(&server, &QTcpServer::newConnection, [&server]() {
        QTcpSocket *sock = server.nextPendingConnection();
        if (!sock)
            return;
        QObject::connect(sock, &QTcpSocket::disconnected, sock, &QTcpSocket::deleteLater);
        handleClient(sock);
    });

    return app.exec();
}
