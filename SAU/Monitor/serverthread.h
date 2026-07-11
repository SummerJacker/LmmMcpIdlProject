#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QThread>
#include <ilu.hpp>
#include <QDebug>

class ServerThread : public QThread
{
public:
    ServerThread(iluServer* s):sptr(s){}
protected:
    void run() { sptr->iluRun(); qDebug()<< "return"; }
private:
    iluServer* sptr;
};

#endif // SERVERTHREAD_H
