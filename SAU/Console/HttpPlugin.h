#ifndef HTTP_PLUGIN_H
#define HTTP_PLUGIN_H

#include <QHostAddress>
#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include <QVector>

class HttpApiExecutor;
class QTcpSocket;

/**
 * @file HttpPlugin.h
 * @brief 轻量 HTTP 服务：在独立线程中接受连接，将请求投递到主线程 HttpApiExecutor。
 *
 * 避免在监听线程中直接调用 ILU；与 Qt 事件循环协作，请求排队由 Qt 连接语义保证。
 */

class HttpServerWorker : public QObject {
    Q_OBJECT

public:
    explicit HttpServerWorker(HttpApiExecutor *executor, QObject *parent = nullptr);

public slots:
    /**
     * @brief 在工作线程中监听指定端口（须在本对象已 moveToThread 之后调用）。
     * @param port TCP 端口
     * @param bindAddress 绑定地址，默认仅本机
     */
    void listenOnPort(quint16 port, const QHostAddress &bindAddress);

private slots:
    void onNewConnection();
    /** @brief 每秒向所有 XY2D SSE 连接广播一帧 JSON（在工作线程 + 定时器上下文）。 */
    void broadcastXy2dSse();

private:
    void handleClient(QTcpSocket *socket);

    QTcpServer server_;
    HttpApiExecutor *executor_;
    QTimer sseTimer_;
    QVector<QTcpSocket *> xy2dSseSockets_;
};

/**
 * @brief 管理 HTTP 工作线程生命周期的薄封装。
 */
class HttpPlugin : public QObject {
    Q_OBJECT

public:
    explicit HttpPlugin(HttpApiExecutor *executor, QObject *parent = nullptr);
    ~HttpPlugin() override;

    /**
     * @brief 启动后台监听线程。
     * @param port 端口
     * @param bindAddress 默认 QHostAddress::LocalHost
     * @returns 是否成功进入监听（异步；失败时工作线程会 qWarning）
     */
    bool start(quint16 port, const QHostAddress &bindAddress = QHostAddress::LocalHost);

    void stop();

private:
    HttpApiExecutor *executor_ = nullptr;
    QThread *thread_ = nullptr;
    HttpServerWorker *worker_ = nullptr;
};

#endif
