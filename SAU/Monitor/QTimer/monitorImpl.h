#ifndef MONITORIMPL_H
#define MONITORIMPL_H
#include <SRIO-Monitor-cpp.hpp>
#include <QObject>
#include <QTimer>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>

// monitor 不会主动发送确认，只会被动接收，火情事件状态的转换都依赖接收到的新消息
enum FireEventState
{
    FES_Uncomfirmed,    //事件等待确认
    FES_Ignored,        //事件已忽略
    FES_Locating,       //火情定位中
    FES_Located,        //火情已定位
    FES_PrepareForActing,//正在准备灭火
    FES_WaitForActing,  //等待确认灭火
    FES_Acting,         //正在执行灭火
    FES_Retrying,       //火情仍然存在，重新尝试灭火
    FES_Aborted,        //任务已终止
    FES_Succeeded       //任务执行成功
};

struct Point2D
{
    float x;
    float y;
    Point2D(float ax, float ay):x(ax), y(ay) {}
};

class ExpireTimer;
class MonitorImpl;

struct FireEventInfo
{
    std::string     eventID;
    time_t          timestamp;
    std::string     reporterID;
    std::string     reporterSBH;
    std::string     picFileName;//此变量为图像文件全名
    FireEventState  state;
    Point2D         location;//GPS langitude latitude or x y
    bool            expired;//当前状态是否有效
    std::shared_ptr<ExpireTimer>    timerPtr;

    FireEventInfo()
        :timestamp(0),
          reporterID(),
          reporterSBH(),
          picFileName(),
          state(FES_Uncomfirmed),
          location(-1,-1),
          expired(false),
          timerPtr(nullptr)
    {}
};

typedef std::unordered_map<std::string, std::shared_ptr<FireEventInfo>> FireEventMap;

typedef std::pair<std::string,std::shared_ptr<FireEventInfo>> FireEventPair;

typedef std::unordered_map<std::string, SRIO_Monitor::Monitor::CompleteUnitInfo> UnitsStateMap;

typedef std::vector<SRIO_Console::Console::TrapPoint> TrapPointList;

class ExpireTimer : public QTimer
{
    Q_OBJECT

public:

    ExpireTimer(std::string eid, FireEventState s, MonitorImpl* m);

    ExpireTimer(const ExpireTimer&) = delete;

    virtual ~ExpireTimer() { mptr = nullptr; }

    inline void startTimer(int msec);

    inline void setState(FireEventState newState) { state = newState; }

private slots:

    void onTimer();

signals:

    void timeout(std::string, FireEventState);

private:

    FireEventState state;

    std::string eventID;

    MonitorImpl* mptr;
};

class MonitorImpl : public QObject, public SRIO_Monitor::Monitor
{
    Q_OBJECT

public:

    MonitorImpl(
       char *pc_instance_handle,
       iluServer& r_an_ilu_server
    );

    ~MonitorImpl();

    //virtual funcs from SRIO_Monitor::Monitor
    CORBA::Boolean sendUnitInfo(
       const CompleteUnitInfo&  unitInfo
    );

    CORBA::Boolean sendTrapPoint(
       const SRIO_Console::Console::TrapPoint&  tp
    );

    CORBA::Boolean sendFireLocation(
       const iluShortCharacter*  fid,
       const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
       CORBA::Short  responseTime
    );

    CORBA::Boolean foundFire(
       const iluShortCharacter*  fid,
       const PictureInfo&  pi
    );

    CORBA::Boolean confirmAction(
       const iluShortCharacter*  fid,
       CORBA::Short  responseTime
    );

    CORBA::Boolean backHome(
       const iluShortCharacter*  uid,
       BackHomeReason  bhr
    );

    CORBA::Boolean sendMissionState(
       const iluShortCharacter*  fid,
       MissionSituation  ms
    );
    // add some interfaces to expose the data in unordermaps and vectors
    // or just set mainwindows to a friend class
    std::string getFirePicFileName(std::string);

    const FireEventMap& getFireEvents() const { return fireEvents; }

    const UnitsStateMap& getUnitsState() const { return unitsState; }

    const TrapPointList& getTrapPointList() const { return traps; }

private slots:

    void test();

    void setExpired(std::string eid,FireEventState state);

signals:

    void displayMsg(std::string);

    void updateTraps();//deliver the whole list here or do it in the respective slot

    void updateFireEvents();

    void updateFireEventsPic(std::string, std::string);

private:
    //a list to hold all the fire event
    FireEventMap fireEvents;
    //a unordermap holds the units states
    UnitsStateMap unitsState;
    //a arraylist holds all the traps
    TrapPointList traps;
};

#endif // MONITOR_H
