#ifndef MONITORIMPL_H
#define MONITORIMPL_H

#include <SRIO-Monitor-cpp.hpp>
#include <QObject>
#include <QTimer>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <windows.h>
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

struct AlarmArg
{
    MonitorImpl* mptr;
    std::string eid;
    FireEventState state;

    AlarmArg(MonitorImpl* m, std::string id, FireEventState s)
        :mptr(m), eid(id), state(s)
    {}
};

struct PicListNode
{
    std::string picFileName; // pic total file name
    std::string discription; // pic discription
    time_t      timestamp; // for now, it's the timestamp this pic arrives at the monitor side
};

typedef std::vector<PicListNode> PicList;

struct FireEventInfo
{
    std::string     eventID;
    time_t          timestamp;
    std::string     reporterID;
    std::string     reporterSBH;
    FireEventState  state;
    Point2D         location;// GPS langitude latitude or x y?
    bool            expired;// whether current state is valid
    iluAlarm        alarm;
    AlarmArg        args;
    PicList         pics;// fire-relative pictures

    FireEventInfo()
        :timestamp(0),
          reporterID(),
          reporterSBH(),
          state(FES_Uncomfirmed),
          location(-1,-1),
          expired(false),
          alarm(nullptr),
          args(nullptr, "", FES_Uncomfirmed),
          pics()
    {}
};

typedef std::map<std::string, std::shared_ptr<FireEventInfo>> FireEventMap;

typedef std::pair<std::string,std::shared_ptr<FireEventInfo>> FireEventPair;

bool compareByTimestamp(const FireEventPair& a, const FireEventPair& b);

typedef std::unordered_map<std::string, SRIO_Monitor::Monitor::CompleteUnitInfo> UnitsStateMap;

typedef std::vector<SRIO_Console::Console::TrapPoint> TrapPointList;

void setExpired(void*);

time_t getCurrentMilliTimestamp();

std::string timestampToDate(time_t stamp);

class MonitorImpl : public QObject, public SRIO_Monitor::Monitor
{
    Q_OBJECT

public:

    friend void setExpired(void*);

    MonitorImpl(
       char *pc_instance_handle,
       iluServer& r_an_ilu_server
    );

    ~MonitorImpl();

    //virtual funcs from SRIO_Monitor::Monitor
    CORBA_(Boolean) sendUnitInfo(
       const CompleteUnitInfo&  unitInfo
    );

    CORBA_(Boolean) sendTrapPoint(
       const SRIO_Console::Console::TrapPoint&  tp
    );

    CORBA_(Boolean) sendFireLocation(
       const iluShortCharacter*  fid,
       const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
       CORBA_(Short)  responseTime
    );

    CORBA_(Boolean) foundFire(
       const iluShortCharacter*  fid,
       const PictureInfo&  pi
    );

    CORBA_(Boolean) confirmAction(
       const iluShortCharacter*  fid,
       CORBA_(Short)  responseTime
    );

    CORBA_(Boolean) backHome(
       const iluShortCharacter*  uid,
       BackHomeReason  bhr
    );

    CORBA_(Boolean) sendMissionState(
       const iluShortCharacter*  fid,
       MissionSituation  ms
    );
    CORBA_(Boolean) MonitorImpl::sendPicture(
            const iluShortCharacter*  pictureName,
            const PictureFlow&  pic,
            CORBA_(Long)  time,
            CORBA_(Long)  procedureStartTime
         );
    // add some interfaces to expose the data in unordermaps and vectors
    // or just set mainwindows to a friend class
    const PicList& getFirePicList(const std::string&);

    const FireEventMap& getFireEvents() const { return fireEvents; }

    const UnitsStateMap& getUnitsState() const { return unitsState; }

    const TrapPointList& getTrapPointList() const { return traps; }

signals:

    void displayMsg(std::string);

    void updateTraps();

    void updateFireEvents();

    void updateNewestPhoto(std::string);

    void updateFireEventsPicRelatives(std::string, const PicList*);

    void openCountDownWindow(std::string, unsigned int);

private:

    inline void setState(std::shared_ptr<FireEventInfo>&, FireEventState);

    void setState(std::shared_ptr<FireEventInfo>&, FireEventState, short);

private:
    //a list to hold all the fire event
    FireEventMap fireEvents;
    //a unordermap holds the units states
    UnitsStateMap unitsState;
    //a arraylist holds all the traps
    TrapPointList traps;
};

#endif // MONITOR_H
