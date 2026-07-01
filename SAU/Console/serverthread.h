#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include "stubs\console.h"

class ServerThread : public QThread
{
    Q_OBJECT
    friend void displayBoundUnit();
public:
    explicit ServerThread(QObject *parent = 0){}
    ~ServerThread(){};

protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run(){
        printf("ServerThread: start.\n");
        ILU_C_Run();
    }

signals:
       void bindInfoChanged(QString bindInfo);
       void infoAppended(QString info);

public slots:
};

#endif // SERVERTHREAD_H
