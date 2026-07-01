#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <serverthread.h>

char host[20] = "172.26.203.228";


int main(int argc, char *argv[])
{
    // 初始化 Qt 应用，argc/argv 用于支持命令行参数
    QApplication a(argc, argv);

    // 初始化 ILU（Inter-Language Unification）中间件运行时，禁用调试模式（ILUCPP_FALSE）
    iluCppRuntime::iluInitialize(ILUCPP_FALSE);

    // 注册 std::string 类型，以便 Qt 的信号槽机制能传递该类型
    qRegisterMetaType<std::string>("std::string");

    // ------------------ 创建 iluServer 服务器 ------------------

    // 构建服务器地址字符串，例如：tcp_localhost_9999
    std::stringstream ss;
    ss << "tcp_" << host << "_" << "9999";  // 变量 host 应为全局或定义于其他模块
    std::string infostr = ss.str();

    // 构造 iluServer 的参数：地址信息 info
    char* info[3] = { const_cast<char*>(infostr.c_str()), nullptr, nullptr };

    // 设置服务器ID（Server ID）与协议（iiop = Internet Inter-ORB Protocol）
    char sid[]{"MonitorServer"};
    char proto[]{"iiop"};

    // 创建真正的 CORBA 分布式服务端对象（iluServer），绑定到给定协议地址
    iluServer* server = new iluServer(sid, nullptr, proto, info, nullptr, ILUCPP_TRUE);

    // ------------------ 创建监控对象 MonitorImpl ------------------

    // 设置 Monitor 的实例句柄 ID
    char ih[]{"Monitor"};

    // 创建监控对象（实现远程接口），并注册到 server 中
    MonitorImpl monitor(ih, *server);

    // ------------------ 启动服务线程 ------------------

    // 创建服务线程对象（封装了 server 的异步处理）
    ServerThread thread(server);

    // 启动后台 server 线程，用于监听远程调用等
    thread.start();

    // 输出 monitor 的对象引用字符串（通常是 IOR 或 URL），用于调试或注册到目录服务
    qDebug() << QString::fromStdString(monitor.iluObjectToString());

    // ------------------ 创建主窗口并初始化 ------------------

    // 创建 Qt 主窗口，并传入监控对象和服务线程引用
    MainWindow w(nullptr, &monitor, &thread);

    // 初始化窗口逻辑（包括信号槽绑定等），若失败则仍进入主事件循环
    if (!w.init())
        return a.exec();

    // 显示主窗口
    w.show();

    // 将窗口移动到屏幕中央位置（略微向上偏移 20 像素）
    w.move(
        (QApplication::desktop()->width() - w.width()) / 2,
        (QApplication::desktop()->height() - w.height()) / 2 - 20
    );

    // 启动 Qt 事件循环（阻塞直到关闭）
    return a.exec();
}
