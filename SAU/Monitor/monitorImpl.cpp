#include "monitorImpl.h"
#include "countdowndialog.h"
#include <ctime>
#include <sstream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <QDebug>
#include <QThread>

extern char stateStr[10][40];
extern const char* FIRE_PIC_DIR;

int gettimeofday(struct timeval *tp, void *tzp)
{
  time_t clock;
  struct tm tm;
  SYSTEMTIME wtm;
  GetLocalTime(&wtm);
  tm.tm_year   = wtm.wYear - 1900;
  tm.tm_mon   = wtm.wMonth - 1;
  tm.tm_mday   = wtm.wDay;
  tm.tm_hour   = wtm.wHour;
  tm.tm_min   = wtm.wMinute;
  tm.tm_sec   = wtm.wSecond;
  tm. tm_isdst  = -1;
  clock = mktime(&tm);
  tp->tv_sec = clock;
  tp->tv_usec = wtm.wMilliseconds * 1000;
  return (0);
}

MonitorImpl::MonitorImpl(
   char *pc_instance_handle,
   iluServer& r_an_ilu_server)
    :iluObject(Monitor::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server),
    QObject(),
    fireEvents(),
    unitsState(),
    traps()
{}

MonitorImpl::~MonitorImpl()
{
    iluDeactivate();
}

CORBA_(Boolean) MonitorImpl::sendUnitInfo(
   const CompleteUnitInfo&  unitInfo )
{
    std::string uid = unitInfo.cui._d() == UnitGroundType ?
         static_cast<const char*>(unitInfo.cui.groundUnitInfo().info.uid)
              : static_cast<const char*>(unitInfo.cui.airUnitInfo().info.uid);
    unitsState[uid] = unitInfo;
    //emit or use a timer to update? --use timer now
    return true;
}

CORBA_(Boolean) MonitorImpl::sendTrapPoint(//UnitID id*****************************
   const SRIO_Console::Console::TrapPoint&  tp )
{
    traps.push_back(tp);
    std::stringstream ss;
    ss << "单元%id%汇报陷阱位置：(";
    switch(tp._d())
    {
    case SRIO_Console::Console::TrapGroundType:
        ss << tp.trapPoint2D().point.x << tp.trapPoint2D().point.y << ")\n";
        ss << "陷阱半径为: " << tp.trapPoint2D().radius;
        break;
    case SRIO_Console::Console::TrapAirType:
        ss << tp.trapPoint3D().point.x << tp.trapPoint3D().point.y << tp.trapPoint3D().point.z << ")\n";
        ss << "陷阱半径为: " << tp.trapPoint3D().radius;
        break;
    }
    this->updateTraps();
    this->displayMsg(ss.str());
    return true;
}

//state changed
CORBA_(Boolean) MonitorImpl::sendFireLocation(
   const iluShortCharacter*  fid,
   const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
   CORBA_(Short)  responseTime )
{
    //find the event and set its location field
    auto iter = fireEvents.find(fid);
    if(iter == fireEvents.end())
    {
        std::string msg = "无效的火情位置信息:";
        msg += fid;
        msg += "。";
        emit this->displayMsg(msg);
        return false;
    }
    auto iptr = iter->second;
    iptr->location.x = fp.x;
    iptr->location.y = fp.y;
    //set state
    setState(iptr, FES_Located, responseTime);
    //build msg
    std::stringstream ss;
    ss << "已确认事件" << fid << "的火源位置:(" << fp.x << "," << fp.y << ")";
    emit this->updateFireEvents();
    emit this->displayMsg(ss.str());
    return true;
}

// for test
void addNodes(std::shared_ptr<FireEventInfo>& infoptr);

//state changed
CORBA_(Boolean) MonitorImpl::foundFire(
   const iluShortCharacter*  fid,
   const PictureInfo&  pi
   )
{
    qDebug() << "foundFire";
    // existing fire event
    if(auto iter = fireEvents.find(fid) != fireEvents.end())
    {
        std::string msg = "重复的火情报告：事件";
        msg += fid;
        msg += "已经存在。";
        emit this->displayMsg(msg);
        return false;
    }
    std::shared_ptr<FireEventInfo> infoptr(new FireEventInfo());
    infoptr->eventID = fid;
    infoptr->location.x = -1;
    infoptr->location.y = -1;
    // millisec timestamp
    infoptr->timestamp = getCurrentMilliTimestamp();//信息中没有时间戳，先获取本地时间戳
    if(pi.cui._d() == UnitGroundType)
    {
        infoptr->reporterID = static_cast<const char*>(pi.cui.groundUnitInfo().info.uid);
        infoptr->reporterSBH = static_cast<const char*>(pi.cui.groundUnitInfo().info.sbh);
    }else
    {
        infoptr->reporterID = static_cast<const char*>(pi.cui.airUnitInfo().info.uid);
        infoptr->reporterSBH = static_cast<const char*>(pi.cui.airUnitInfo().info.sbh);
    }
    // set pic list node
    PicListNode node;
    node.timestamp = infoptr->timestamp;
    node.discription = "发现火情";
    // set pic name
    std::stringstream ss;
    ss << fid << "." << pi.picturName;
    node.picFileName = ss.str();
    // set pic list
    infoptr->pics.push_back(node);
    // for test
    //addNodes(infoptr);
    // save the pic to local
    qDebug()<<"get bytes size " << pi.pic->length();
    std::ofstream fout(std::string(FIRE_PIC_DIR) + node.picFileName, std::ios_base::out|std::ios_base::binary);
    fout.write(reinterpret_cast<const char*>(pi.pic->get_buffer()), pi.pic->length());
    fout.close();
    // display msg
    std::string msg = "出现火情事件";
    msg += fid;
    msg += "。";
    // set alarm relatives
    infoptr->alarm = iluMainLoop::iluDefaultLoopCreateAlarm();
    infoptr->args.eid = infoptr->eventID;
    infoptr->args.mptr = this;
    // insert into
    fireEvents.insert(FireEventPair(fid, infoptr));
    // start timers
    setState(infoptr, FES_Uncomfirmed, pi.responseTime);
    emit this->updateFireEvents();
    emit this->updateFireEventsPicRelatives(fid,&infoptr->pics);
    emit this->displayMsg(msg);
    return true;
}

//state changed
CORBA_(Boolean) MonitorImpl::confirmAction(
   const iluShortCharacter*  fid,
   CORBA_(Short)  responseTime )
{
    //event state change
    auto iter = this->fireEvents.find(fid);
    if(iter == fireEvents.end())
        return false;
    //change state
    setState(iter->second, FES_WaitForActing, responseTime);
    //build msg
    std::string msg = "事件";
    msg += fid;
    msg += "正在请求确认执行灭火动作。";
    emit this->updateFireEvents();
    emit this->displayMsg(msg);
    return true;
}

//state changed
CORBA_(Boolean) MonitorImpl::sendMissionState(//UnitID id
   const iluShortCharacter*  fid,
   MissionSituation  ms )
{
    auto iter = fireEvents.find(fid);
    if(iter == fireEvents.end())
        return false;
    // set state
    std::string result;
    FireEventState newState;
    switch(ms)
    {
    case Success:
        newState = FES_Succeeded;
        result = "任务成功";
        break;
    case StillBurning:
        newState = FES_Retrying;
        result = "火情仍然存在";
        break;
    default:
        break;
    }
    setState(iter->second, newState);
    emit this->updateFireEvents();
    emit this->displayMsg("收到事件" + std::string(fid) + "情况："+ result +"。");
    return true;
}

CORBA_(Boolean) MonitorImpl::backHome(
   const iluShortCharacter*  uid,
   BackHomeReason  bhr )
{
    std::string reason;
    switch(bhr)
    {
    case LowBattery:
        reason = "电量低";
        break;
    case EmptyLoad:
        reason = "负载已空";
        break;
    }
    emit this->displayMsg("单元" + std::string(uid) + "正在返回,原因：" + reason);
    return true;
}

const PicList& MonitorImpl::getFirePicList(const std::string& eventid)
{
    auto iter = fireEvents.find(eventid);
    if(iter == fireEvents.end())
    {
        std::string msg("火情事件");
        msg += eventid;
        msg += "不存在！";
        emit this->displayMsg(msg);
    }
    return iter->second->pics;
}

void MonitorImpl::setState(std::shared_ptr<FireEventInfo>& iptr, FireEventState s)
{
    iptr->state = s;
    iptr->expired = false;
}

void MonitorImpl::setState(std::shared_ptr<FireEventInfo>& iptr, FireEventState s, short responseTime)
{
    //set state
    iptr->state = s;
    iptr->expired = false;
    //set alarm
    std::string tips = "火情事件";
    tips = tips + iptr->eventID + ":\n" + stateStr[s];
    iptr->args.state = s;
    iluFineTime intvl = {responseTime, 0};
    iluMainLoop::iluDefaultLoopSetAlarm(
                iptr->alarm, ilu_FineTime_Add(ilu_FineTime_Now(),intvl),
                setExpired, reinterpret_cast<void*>(&iptr->args));
    emit this->openCountDownWindow(tips, static_cast<unsigned int>(responseTime));
}

CORBA_(Boolean) MonitorImpl::sendPicture(
        const iluShortCharacter*  pictureName,
        const PictureFlow&  pic,
        CORBA_(Long)  time,
        CORBA_(Long)  procedureStartTime
     )
{
    std::stringstream ss;
    ss <<"Photo." << pictureName;
    // save the pic to local
    qDebug()<<"get bytes size " << pic.length();
    std::ofstream fout(std::string(FIRE_PIC_DIR) + ss.str(), std::ios_base::out|std::ios_base::binary);
    fout.write(reinterpret_cast<const char*>(pic.get_buffer()), pic.length());
    fout.close();
    // display msg
    std::string msg = "获得现场图片";
    msg += "。\n 响应时间为";
    emit this->updateNewestPhoto(ss.str());
    timeval tv;
    gettimeofday(&tv, NULL);    // /time.h头文件中
    CORBA_(Long) finishTime=(tv.tv_sec-procedureStartTime) * 1000 + tv.tv_usec / 1000;
    CORBA_(Long) duration;
    duration=finishTime-time;
    msg +=std::to_string(duration);
    msg += "毫秒。\n";
    qDebug()<<"get bytes size " << finishTime<<"******"<<time<<"********"<<tv.tv_sec<<"********"<<tv.tv_usec<<endl;

    emit this->displayMsg(msg);
    return true;
}

void setExpired(void* param)
{
    //qDebug() << "setExpired triggered";
    AlarmArg* argptr = reinterpret_cast<AlarmArg*>(param);
    auto iter = argptr->mptr->fireEvents.find(argptr->eid);
    if(iter == argptr->mptr->fireEvents.end())
        return;
    if(iter->second->state != argptr->state || iter->second->expired)
        return;
    iter->second->expired = true;
    std::stringstream ss;
    ss << "事件" << iter->second->eventID << "当前状态\"" << stateStr[argptr->state] << "\"" << "已经失效。";
    emit argptr->mptr->updateFireEvents();
    emit argptr->mptr->displayMsg(ss.str());
}

bool compareByTimestamp(const FireEventPair& a, const FireEventPair& b)
{
    return a.second->timestamp >= b.second->timestamp;
}

time_t getCurrentMilliTimestamp()
{
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>
                (std::chrono::system_clock::now().time_since_epoch());
    return ms.count();
}

std::string timestampToDate(time_t stamp)
{
    auto local = stamp + 8 *60 * 60 * 1000ll;
    auto mTime = std::chrono::milliseconds(local);
    auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
    auto tt = std::chrono::system_clock::to_time_t(tp);
    std::tm *now = std::gmtime(&tt);
    char buf[64];
    sprintf(buf, "%4d年%02d月%02d日 %02d:%02d:%02d",
            now->tm_year+1900,now->tm_mon+1,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
    return std::string(buf);
}

// for test
void addNodes(std::shared_ptr<FireEventInfo>& infoptr)
{
    PicListNode node2;
    node2.picFileName="located.jpeg";
    node2.timestamp=getCurrentMilliTimestamp()+2000;
    node2.discription="已定位";
    PicListNode node3;
    node3.picFileName="result.jpeg";
    node3.timestamp=node2.timestamp+2000;
    node3.discription="灭火结果";
    PicListNode node4;
    node4.picFileName="result2.jpeg";
    node4.timestamp=node3.timestamp+2000;
    node4.discription="灭火结果2";
    infoptr->pics.push_back(node2);
    infoptr->pics.push_back(node3);
    infoptr->pics.push_back(node4);
}
