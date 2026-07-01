#include "monitorImpl.h"
#include <ctime>
#include <sstream>
#include <fstream>
#include <qDebug>

extern QThread* MainThreadPtr;
extern char stateStr[10][40];

MonitorImpl::MonitorImpl(
   char *pc_instance_handle,
   iluServer& r_an_ilu_server)
    :
    //Monitor(pc_instance_handle,r_an_ilu_server),
    iluObject(Monitor::m_ILUClassRecord, pc_instance_handle, r_an_ilu_server),
    QObject(),
    fireEvents(),
    unitsState(),
    traps()
{


}

MonitorImpl::~MonitorImpl()
{
    iluDeactivate();
}

CORBA::Boolean MonitorImpl::sendUnitInfo(
   const CompleteUnitInfo&  unitInfo )
{
    std::string uid = unitInfo.cui._d() == UnitGroundType ?
         static_cast<const char*>(unitInfo.cui.groundUnitInfo().info.uid)
              : static_cast<const char*>(unitInfo.cui.airUnitInfo().info.uid);
    unitsState[uid] = unitInfo;
    //emit or use a timer to update? --use timer now
    return true;
}

CORBA::Boolean MonitorImpl::sendTrapPoint(//UnitID id*****************************
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
CORBA::Boolean MonitorImpl::sendFireLocation(
   const iluShortCharacter*  fid,
   const SRIO_Ground_Unit::Ground_Unit::Point2D&  fp,
   CORBA::Short  responseTime )
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
    iptr->state = FES_Located;
    iptr->expired = false;
//    // timer is runing
//    while(iptr->timerPtr->isActive())
//        iptr->timerPtr->stop();
    iptr->timerPtr.reset(new ExpireTimer(iptr->eventID, FES_Located, this));
    iptr->timerPtr->startTimer(responseTime * 1000);

    std::stringstream ss;
    ss << "已确认事件" << fid << "的火源位置:(" << fp.x << "," << fp.y << ")";
    emit this->updateFireEvents();
    emit this->displayMsg(ss.str());
    return true;
}

//state changed
CORBA::Boolean MonitorImpl::foundFire(
   const iluShortCharacter*  fid,
   const PictureInfo&  pi//, CORBA::Short responseTime // pi.picName->pi.format
   )
{
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
    // get timestamp
    infoptr->timestamp = std::time(nullptr);
    if(pi.cui._d() == UnitGroundType)
    {
        infoptr->reporterID = static_cast<const char*>(pi.cui.groundUnitInfo().info.uid);
        infoptr->reporterSBH = static_cast<const char*>(pi.cui.groundUnitInfo().info.sbh);
    }else
    {
        infoptr->reporterID = static_cast<const char*>(pi.cui.airUnitInfo().info.uid);
        infoptr->reporterSBH = static_cast<const char*>(pi.cui.airUnitInfo().info.sbh);
    }
    // set pic name
    std::stringstream ss;
    ss << fid << "." << pi.picturName;
    infoptr->picFileName = ss.str();
    // save the pic to local
    //qDebug()<<"get bytes size " << pi.pic->length();
    std::ofstream fout(infoptr->picFileName, std::ios_base::out|std::ios_base::binary);
    fout.write(reinterpret_cast<const char*>(pi.pic->get_buffer()), pi.pic->length());
    fout.close();
    // set state
    infoptr->state = FES_Uncomfirmed;
    infoptr->expired = false;
    infoptr->timerPtr.reset(new ExpireTimer(infoptr->eventID, FES_Uncomfirmed, this));
    infoptr->timerPtr->startTimer(pi.responseTime * 1000);
    fireEvents.insert(FireEventPair(fid, infoptr));
    // display msg
    std::string msg = "出现火情事件";
    msg += fid;
    msg += "。";
    emit this->updateFireEvents();
    emit this->updateFireEventsPic(fid,infoptr->picFileName);
    emit this->displayMsg(msg);
    return true;
}

//state changed
CORBA::Boolean MonitorImpl::confirmAction(
   const iluShortCharacter*  fid,
   CORBA::Short  responseTime )
{
    //event state change
    auto iter = this->fireEvents.find(fid);
    if(iter == fireEvents.end())
        return false;
    // change state
    auto iptr = iter->second;
    iptr->state = FES_WaitForActing;
    iptr->expired = false;
//    // timer is runing
//    while(iptr->timerPtr->isActive())
//        iptr->timerPtr->stop();
    iptr->timerPtr.reset(new ExpireTimer(iptr->eventID, FES_WaitForActing, this));
    iptr->timerPtr->startTimer(responseTime * 1000);
    std::string msg = "事件";
    msg += fid;
    msg += "正在请求确认执行灭火动作。";
    emit this->updateFireEvents();
    emit this->displayMsg(msg);
    return true;
}

//state changed
CORBA::Boolean MonitorImpl::sendMissionState(//UnitID id
   const iluShortCharacter*  fid,
   MissionSituation  ms )
{
    auto iter = fireEvents.find(fid);
    if(iter == fireEvents.end())
        return false;
    // set state
    std::string result;
    switch(ms)
    {
    case Success:
        //修改fire event状态
        iter->second->state = FES_Succeeded;
        result = "任务成功";
        break;
    case StillBurning:
        //修改fire event状态
        iter->second->state = FES_Retrying;
        result = "火情仍然存在";
        break;
    }
    iter->second->expired = false;
    emit this->updateFireEvents();
    emit this->displayMsg("收到事件" + std::string(fid) + "情况："+ result +"。");
    return true;
}

CORBA::Boolean MonitorImpl::backHome(
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

std::string MonitorImpl::getFirePicFileName(std::string eventid)
{
    auto iter = fireEvents.find(eventid);
    if(iter == fireEvents.end())
    {
        std::string msg("火情事件");
        msg += eventid;
        msg += "不存在！";
        emit this->displayMsg(msg);
    }
    return iter->second->picFileName;
}

void MonitorImpl::test()
{
    qDebug() <<"triggered";
    emit this->displayMsg("test");
}

ExpireTimer::ExpireTimer(std::string eid, FireEventState s, MonitorImpl* m)
    :state(s), eventID(eid), mptr(m)
{
    this->setSingleShot(true);
    connect(this, SIGNAL(timeout()), this, SLOT(onTimer()), Qt::DirectConnection);
    connect(this, SIGNAL(timeout(std::string,FireEventState)),
            mptr, SLOT(setExpired(std::string,FireEventState)), Qt::DirectConnection);
}

void ExpireTimer::startTimer(int msec)
{
    start(msec);
    moveToThread(MainThreadPtr);
}

void ExpireTimer::onTimer()
{
    emit this->timeout(eventID, state);
}

void MonitorImpl::setExpired(std::string eid,FireEventState state)
{
    qDebug() << "setExpired triggered";
    auto iter = this->fireEvents.find(eid);
    if(iter == fireEvents.end())
        return;

    if(iter->second->state != state || iter->second->expired)
        return;
    iter->second->expired = true;
    std::stringstream ss;
    ss << "事件" << iter->second->eventID << "当前状态\"" << stateStr[state] << "\"" << "已经失效。";
    emit updateFireEvents();
    emit displayMsg(ss.str());
}
