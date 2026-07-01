#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include <iostream>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QStringList>
#include<QWindow>
#include<QScreen>
#include<QGuiApplication>
#include<algorithm>
#include<QToolBar>
#include<QPushButton>

extern float currentCtrlLinearVelocity;
extern float currentCtrlAngularVelocity;
extern Unit_rpc currentUnitObj;
//extern Unit_rpc currentLeaderObj;
extern Ground_Unit_rpc currentGUVLeaderObj;
extern Air_Unit_rpc    currentAUVLeaderObj;
extern char* backupFileName;
extern char* backupCosNamingServerFileName;
extern char* backupTrapsFileName;
extern int currentGUVNum;
extern int currentAUVNum;
extern Console_rpc backupCosObj;


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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setleaderframe->hide();
    ui->yaokongframe->hide();
    ui->followframe->hide();
    ui->trapframe->hide();
    ui->photoframe->hide();
    path = 0;
    this->currentPointsCount = 0;
    this->pointsCount = 0;
    this->currentUnitCount = 0;
    this->currentControlledCount=0;
    timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    this->procedureStartTime=tv.tv_sec;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::hideallframe()
{
    ui->setleaderframe->hide();
    ui->yaokongframe->hide();
    ui->followframe->hide();
    ui->trapframe->hide();
    ui->photoframe->hide();
}
void MainWindow::on_pushButton_clicked()
{
    hideallframe();
    ui->setleaderframe->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    hideallframe();
    ui->yaokongframe->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    hideallframe();
    ui->followframe->show();
    ui->duixingframe->hide();
    ui->goalframe->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->goalframe->hide();
    ui->duixingframe->show();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->duixingframe->hide();
    ui->goalframe->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (backupCosObj)
    {
        Console_Message m;
        CORBA_Environment en;
        m._d = Console_OP_Closed;
        m._u.details = "shutted down by admin.";
        Console_rpc_sendMsg(backupCosObj, &m, &en);
    }
}

void MainWindow::updateBrowser(QString str)
{
    ui->textBrowser->setText(str);
    ui->textBrowser->update();
}

void MainWindow::appendInfo(QString str)
{
    ui->textBrowser_2->append(str);
}

void MainWindow::on_pushButton_5_clicked()
{
    extern Unit_UnitMode currentMode;
    extern Unit_UnitID currentLeaderUID;
    
    Unit_MoveAction action;
    CORBA_Environment ev;
    action._d = Unit_MA_GoAhead;
    action._u.goAheadData.duration.keep = ilu_TRUE;
    action._u.goAheadData.speed = (float)(ui->doubleSpinBox_2->value());
    
    // 如果是模仿模式，自动控制Leader
    if (currentMode == Unit_UM_Imitate && currentLeaderUID != NULL) {
        if (currentGUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentGUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)){
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            } else {
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送前进指令，线速度为%2！").arg(currentLeaderUID).arg(action._u.goAheadData.speed));
            }
        } else if (currentAUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentAUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)){
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            } else {
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送前进指令，线速度为%2！").arg(currentLeaderUID).arg(action._u.goAheadData.speed));
            }
        } else {
            ui->textBrowser_2->append(QStringLiteral("错误：模仿模式下未找到Leader对象！"));
        }
    }
    // 非模仿模式，按原来的逻辑控制指定车辆
    else {
        string str = "GV";
        int index = ui->spinBox_2->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev)){
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            }
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送前进指令，线速度为%2！").arg(str.c_str()).arg(action._u.goAheadData.speed));
        }
        else{
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    extern Unit_UnitMode currentMode;
    extern Unit_UnitID currentLeaderUID;
    
    Unit_MoveAction action;
    CORBA_Environment ev;
    action._d = Unit_MA_GoBackward;
    action._u.goBackwardData.duration.keep = ilu_TRUE;
    action._u.goBackwardData.speed = (float)(ui->doubleSpinBox_2->value());
    
    // 如果是模仿模式，自动控制Leader
    if (currentMode == Unit_UM_Imitate && currentLeaderUID != NULL) {
        if (currentGUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentGUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送后退指令，线速度为%2！").arg(currentLeaderUID).arg(action._u.goBackwardData.speed));
        } else if (currentAUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentAUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送后退指令，线速度为%2！").arg(currentLeaderUID).arg(action._u.goBackwardData.speed));
        } else {
            ui->textBrowser_2->append(QStringLiteral("错误：模仿模式下未找到Leader对象！"));
        }
    }
    // 非模仿模式，按原来的逻辑控制指定车辆
    else {
        string str = "GV";
        int index = ui->spinBox_2->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送后退指令，线速度为%2！").arg(str.c_str()).arg(action._u.goBackwardData.speed));
        }
        else
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    extern Unit_UnitMode currentMode;
    extern Unit_UnitID currentLeaderUID;
    
    Unit_MoveAction action;
    CORBA_Environment ev;
    action._d = Unit_MA_TurnLeft;
    action._u.turnLeftData.duration.keep = ilu_TRUE;
    action._u.turnLeftData.speed = (float)(ui->doubleSpinBox_3->value());
    
    // 如果是模仿模式，自动控制Leader
    if (currentMode == Unit_UM_Imitate && currentLeaderUID != NULL) {
        if (currentGUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentGUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送左转指令，角速度为%2！").arg(currentLeaderUID).arg(action._u.turnLeftData.speed));
        } else if (currentAUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentAUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送左转指令，角速度为%2！").arg(currentLeaderUID).arg(action._u.turnLeftData.speed));
        } else {
            ui->textBrowser_2->append(QStringLiteral("错误：模仿模式下未找到Leader对象！"));
        }
    }
    // 非模仿模式，按原来的逻辑控制指定车辆
    else {
        string str = "GV";
        int index = ui->spinBox_2->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送左转指令，角速度为%2！").arg(str.c_str()).arg(action._u.turnLeftData.speed));
        }
        else
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    extern Unit_UnitMode currentMode;
    extern Unit_UnitID currentLeaderUID;
    
    Unit_MoveAction action;
    CORBA_Environment ev;
    action._d = Unit_MA_TurnRight;
    action._u.turnRightData.duration.keep = ilu_TRUE;
    action._u.turnRightData.speed = (float)(ui->doubleSpinBox_3->value());
    
    // 如果是模仿模式，自动控制Leader
    if (currentMode == Unit_UM_Imitate && currentLeaderUID != NULL) {
        if (currentGUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentGUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送右转指令，角速度为%2！").arg(currentLeaderUID).arg(action._u.turnRightData.speed));
        } else if (currentAUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentAUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送右转指令，角速度为%2！").arg(currentLeaderUID).arg(action._u.turnRightData.speed));
        } else {
            ui->textBrowser_2->append(QStringLiteral("错误：模仿模式下未找到Leader对象！"));
        }
    }
    // 非模仿模式，按原来的逻辑控制指定车辆
    else {
        string str = "GV";
        int index = ui->spinBox_2->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送右转指令，角速度为%2！").arg(str.c_str()).arg(action._u.turnRightData.speed));
        }
        else
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }
}
// 停止命令
void MainWindow::on_pushButton_9_clicked()
{
    extern Unit_UnitMode currentMode;
    extern Unit_UnitID currentLeaderUID;
    
    Unit_MoveAction action;
    CORBA_Environment ev;
    action._d = Unit_MA_Stop;
    action._u.stopData.keep = ilu_TRUE;
    
    // 如果是模仿模式，自动控制Leader
    if (currentMode == Unit_UM_Imitate && currentLeaderUID != NULL) {
        if (currentGUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentGUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送停止指令！").arg(currentLeaderUID));
        } else if (currentAUVLeaderObj != NULL) {
            Unit_rpc_sendMoveAction(currentAUVLeaderObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("成功向Leader %1发送停止指令！").arg(currentLeaderUID));
        } else {
            ui->textBrowser_2->append(QStringLiteral("错误：模仿模式下未找到Leader对象！"));
        }
    }
    // 非模仿模式，按原来的逻辑控制指定车辆
    else {
        string str = "GV";
        int index = ui->spinBox_2->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
            if (!ILU_C_SUCCESSFUL(&ev))
                ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送停止指令！").arg(str.c_str()));
        }
        else
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }
}
//发送指令序列
void MainWindow::on_pushButton_10_clicked()
{
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        if(sendCommandSeq())
        {
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送指令序列！").arg(str.c_str()));
        }
        else
        {
            ui->textBrowser_2->append(QStringLiteral("向单元%1发送指令序列失败！").arg(str.c_str()));
        }
    }
    else{
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }
}
//删除备份文件
void MainWindow::on_pushButton_17_clicked()
{
    if(!remove(backupFileName))
        ui->textBrowser_2->append(QStringLiteral("文件%1已经成功删除！").arg(backupFileName));
    else
        ui->textBrowser_2->append(QStringLiteral("文件%1不存在！").arg(backupFileName));

    if (!remove(backupCosNamingServerFileName))
        ui->textBrowser_2->append(QStringLiteral("文件%1已经成功删除！").arg(backupCosNamingServerFileName));
    else
        ui->textBrowser_2->append(QStringLiteral("文件%1不存在！").arg(backupCosNamingServerFileName));
    if (!remove(backupTrapsFileName))
        ui->textBrowser_2->append(QStringLiteral("文件%1已经成功删除！").arg(backupTrapsFileName));
    else
        ui->textBrowser_2->append(QStringLiteral("文件%1不存在！").arg(backupTrapsFileName));
}

void MainWindow::on_pushButton_2_clicked()
{
//    string str = "GV";
    string str = ui->comboBox->currentText().toStdString();
    int index = ui->spinBox_5->value();
    str += to_string(index);
//    ui->textBrowser_2->append(QString::fromStdString(str));
    if(getUnitObject((char*)(str.c_str())))
    {
        if(setToLeader())
        {
            ui->textBrowser_4->setText(QString::fromStdString(str));
            ui->textBrowser_2->append(QStringLiteral("成功设置领航者！"));
        }
        else
            ui->textBrowser_2->append(QStringLiteral("设置领航者失败！"));

    }else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
//设置模仿模式
void MainWindow::on_pushButton_11_clicked()
{
    if(setGroupMode(Unit_UM_Imitate))
        ui->textBrowser_2->append(QStringLiteral("成功设置模拟模式！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置模拟模式失败！"));
}
//设置跟随模式
void MainWindow::on_pushButton_12_clicked()
{
    if(setGroupMode(Unit_UM_Follow))
        ui->textBrowser_2->append(QStringLiteral("成功设置跟随模式！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置跟随模式失败！"));
}

void MainWindow::on_pushButton_23_clicked()
{
    string str = "GV";
    int index = ui->spinBox_4->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        float x,y;
        x = (float)ui->doubleSpinBox->value();
        y =(float) ui->doubleSpinBox_4->value();
        if(setTaskPoint(x, y))
            ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送目标点(%2,%3)！").arg(str.c_str()).arg(x).arg(y));
        else
            ui->textBrowser_2->append(QStringLiteral("向单元%1发送目标点(%2,%3)失败！").arg(str.c_str()).arg(x).arg(y));

    }else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
// 清除陷阱
void MainWindow::on_pushButton_21_clicked()
{
    if(clearTraps())
        ui->textBrowser_2->append(QStringLiteral("成功清除所有陷阱！"));
    else
        ui->textBrowser_2->append(QStringLiteral("清除陷阱失败！"));

}

void MainWindow::on_pushButton_20_clicked()
{
    pointsCount = ui->spinBox->value();
    if(pointsCount != 0)
    {
        currentPointsCount = 0;
        if(path)
        {
            Console_PointSeq__Free(path);
            path = NULL;
        }
        path = Console_PointSeq_Create(pointsCount, NULL);
        ui->textBrowser_2->append(QStringLiteral("创建空路径，长度为%1！").arg(pointsCount));
    }else
        ui->textBrowser_2->append(QStringLiteral("创建失败，路径长度不能为0！"));
}

void MainWindow::on_pushButton_22_clicked()
{
	if(currentPointsCount < pointsCount)
	{
        Console_Point point;
        Console_Point* pointTmp;
		ilu_Error e;
        point._d=Console_PointGroundType;
        point._u.p2D.x = (float)ui->doubleSpinBox_6->value();
        point._u.p2D.y = (float)ui->doubleSpinBox_7->value();
        Console_PointSeq_Append(path, &point, &e);
        pointTmp = Console_PointSeq_Nth(path,currentPointsCount);
        currentPointsCount ++;
        ui->textBrowser_2->append(QStringLiteral("成功添加目标点（%1，%2）！").arg(pointTmp->_u.p2D.x).arg(pointTmp->_u.p2D.y));
	}else
		ui->textBrowser_2->append(QStringLiteral("添加失败，路径已达到最大长度%1！").arg(pointsCount));
}
// 录入队形 按钮
void MainWindow::on_pushButton_19_clicked()
{
    ilu_Error err;
    if(!currentGUVNum)
    {
        ui->textBrowser_2->append(QStringLiteral("操作失败，当前绑定单元数为0！"));
        return;
    }
    if(!currentUnitCount)
    {
        formation = (Unit_Formation*)malloc(sizeof(Unit_Formation));
        formation->robot_ids = *Unit_UnitIDSeq_Create(currentGUVNum, NULL);
        formation->leader_ids = *Unit_ShortSeq_Create(currentGUVNum, NULL);
        formation->distances = *Unit_FloatSeq_Create(currentGUVNum, NULL);
        formation->angles = *Unit_FloatSeq_Create(currentGUVNum, NULL);
        
        for(int i=0; i<currentGUVNum; i++)
        {
            Unit_FloatSeq_Append(&formation->angles, 0, &err);
            if(i!=0)
                Unit_ShortSeq_Append(&formation->leader_ids, i-1, &err);
            else
                Unit_ShortSeq_Append(&formation->leader_ids, 0, &err);
        }
    }
    if(currentUnitCount < currentGUVNum)
	{
		currentUnitCount ++;
		char* robot_id = (char*)ilu_malloc(strlen(to_string(ui->spinBox_3->value()).c_str())+3);
        
		strcpy(robot_id, (char*)string("GV"+to_string(ui->spinBox_3->value())).c_str());
        Unit_UnitIDSeq_Append(&formation->robot_ids, robot_id, &err);
        Unit_FloatSeq_Append(&formation->distances, (float)ui->doubleSpinBox_5->value(),&err);
		ui->textBrowser_2->append(QStringLiteral("队形信息%1添加成功！").arg(robot_id));
	}else
		ui->textBrowser_2->append(QStringLiteral("队形已满！"));
}

void MainWindow::on_pushButton_27_clicked()
{
    hideallframe();
    ui->trapframe->show();
}
//添加陷阱
void MainWindow::on_pushButton_24_clicked()
{
    Console_TrapPoint trap;
    trap._d=Console_TrapGroundType;
    trap._u.trapPoint2D.radius = ui->doubleSpinBox_10->value();
    trap._u.trapPoint2D.point.x = ui->doubleSpinBox_8->value();
    trap._u.trapPoint2D.point.y = ui->doubleSpinBox_9->value();
    if(setTrap(trap))
        ui->textBrowser_2->append(QStringLiteral("成功设置陷阱点(%1,%2)陷阱半径为%3！").arg(trap._u.trapPoint2D.point.x).arg(trap._u.trapPoint2D.point.y).arg(trap._u.trapPoint2D.radius));
    else
        ui->textBrowser_2->append(QStringLiteral("设置陷阱点(%1,%2)陷阱半径为%3失败！").arg(trap._u.trapPoint2D.point.x).arg(trap._u.trapPoint2D.point.y).arg(trap._u.trapPoint2D.radius));
}

void MainWindow::on_pushButton_25_clicked()
{
    if(setGroupMinorMode(Unit_UMM_FW_Object))
        ui->textBrowser_2->append(QStringLiteral("设置目标跟踪模式成功！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置目标跟踪模式失败！"));
}

void MainWindow::on_pushButton_26_clicked()
{
    if(setGroupMinorMode(Unit_UMM_FW_Track))
        ui->textBrowser_2->append(QStringLiteral("设置轨迹跟踪模式成功！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置轨迹跟踪失败！"));
}

void MainWindow::on_pushButton_15_clicked()
{
    shutDownAllUnit();
    ui->textBrowser_2->append(QStringLiteral("成功关闭所有单元程序！"));
}

void MainWindow::on_pushButton_16_clicked()
{
    setDefault();
    ui->textBrowser_2->append(QStringLiteral("成功重置单元间关系！"));
}
//重置队形 按钮
void MainWindow::on_resetFormationButton_clicked()
{
    if(currentUnitCount)
    {
        currentUnitCount = 0;
        Unit_UnitIDSeq__Free(&formation->robot_ids);
        Unit_ShortSeq__Free(&formation->leader_ids);
        Unit_FloatSeq__Free(&formation->distances);
        Unit_FloatSeq__Free(&formation->angles);
        free(formation);
        ui->textBrowser_2->append(QStringLiteral("已重置队形信息！"));
    }else
        ui->textBrowser_2->append(QStringLiteral("当前未录入队形信息！"));
}
// 发送队形按钮
void MainWindow::on_sendFormationButton_clicked()
{
    if(currentUnitCount == currentGUVNum && currentGUVNum != 0)// 允许录入数量不足时发送
    {
        if(setFormation(formation))
        {
            currentUnitCount = 0;
            Unit_UnitIDSeq__Free(&formation->robot_ids);
            Unit_ShortSeq__Free(&formation->leader_ids);
            Unit_FloatSeq__Free(&formation->distances);
            Unit_FloatSeq__Free(&formation->angles);
            free(formation);
            ui->textBrowser_2->append(QStringLiteral("成功将队形信息发送给所有单元！"));
        }else
            ui->textBrowser_2->append(QStringLiteral("向所有单元发送队形信息失败!"));
    }else if(currentUnitCount == currentGUVNum && currentGUVNum == 0)
        ui->textBrowser_2->append(QStringLiteral("无单元绑定！"));
}
//发送路径按钮
void MainWindow::on_taskPathSendButton_clicked()
{
    if(currentPointsCount == pointsCount)
    {
        CORBA_Environment en;
        string str = "GV";
        ilu_Error err;
        int index = ui->spinBox_4->value();
        str += to_string(index);
        if(getUnitObject((char*)(str.c_str())))
        {
            Ground_Unit_TaskPath * path2D = CORBA_sequence_Ground_Unit_TaskPath_allocbuf (path->_length /* count */);
            for(int i=0;i<path->_length;i++){
                Ground_Unit_TaskPath_Append (path2D, &path->_buffer[i]._u.p2D, &err);
            }
            if(Ground_Unit_rpc_setTaskPath(currentUnitObj, path2D, &en)&&ILU_C_SUCCESSFUL(&en))
            {
                pointsCount = 0;
                currentPointsCount = 0;
                Ground_Unit_TaskPath__Free(path2D);
                path2D = NULL;
                Console_PointSeq__Free(path);
                path = NULL;
                ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送路径！").arg(str.c_str()));
            }
            else if(!ILU_C_SUCCESSFUL(&en))
                ui->textBrowser_2->append(QStringLiteral("向单元%1发送路径失败，出现异常%2！").arg(str.c_str()).arg(en.returnCode));
            else
                ui->textBrowser_2->append(QStringLiteral("向单元%1发送路径失败！").arg(str.c_str()));
        }else
            ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    }else
        ui->textBrowser_2->append(QStringLiteral("路径尚未录入完毕，还需录入%1个点！").arg(pointsCount-currentPointsCount));
}

void MainWindow::on_pushButton_18_clicked()
{
    hideallframe();
    ui->photoframe->show();
}

void MainWindow::on_pushButton_28_clicked()
{
    string str = "GV";
    int index = ui->spinBox_6->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        float frequency=(float)ui->doubleSpinBox_11->value();
        Unit_rpc_startPhotoStream(currentUnitObj, frequency, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送拍照指令，频率为%2！").arg(str.c_str()).arg(frequency));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_29_clicked()
{
    string str = "GV";
    int index = ui->spinBox_6->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        float frequency=ui->doubleSpinBox_11->value();
        Unit_rpc_stopPhotoStream(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送停止拍照指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
// 解锁按钮
void MainWindow::on_pushButton_43_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_Unlock;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送解锁指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_31_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_TakeOff;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送起飞指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_39_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoDown;
        action._u.goDownData.duration.keep = ilu_TRUE;
        action._u.goDownData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送下降指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goDownData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_30_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_Land;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送降落指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_32_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_LandConfirm;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送确认降落指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_44_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_Lock;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送上锁指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_33_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoUp;
        action._u.goUpData.duration.keep = ilu_TRUE;
        action._u.goUpData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送上升指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goUpData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_34_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_TurnLeft;
        action._u.turnLeftData.duration.keep = ilu_TRUE;
        action._u.turnLeftData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送左旋指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.turnLeftData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_41_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_TurnRight;
        action._u.turnRightData.duration.keep = ilu_TRUE;
        action._u.turnRightData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送右旋指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.turnRightData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_35_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoAhead;
        action._u.goAheadData.duration.keep = ilu_TRUE;
        action._u.goAheadData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送前进指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goAheadData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_40_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoBackward;
        action._u.goBackwardData.duration.keep = ilu_TRUE;
        action._u.goBackwardData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送后退指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goBackwardData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_37_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoLeft;
        action._u.goLeftData.duration.keep = ilu_TRUE;
        action._u.goLeftData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送左飞指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goLeftData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_38_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_GoRight;
        action._u.goRightData.duration.keep = ilu_TRUE;
        action._u.goRightData.speed = (float)(ui->doubleSpinBox_12->value());
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送右飞指令！,速度为%2 m/s").arg(str.c_str()).arg(action._u.goRightData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_45_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        extern ilu_HashTable Units_Hash_Table;
        string strG = "GV";
        int indexG = ui->spinBox_8->value();
        strG += to_string(indexG);
        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strG.c_str()));
        if (sbh != ILU_NIL) {
        CORBA_Environment ev;
        Unit_UnitInfo gui;
        gui.uid=(char*)(strG.c_str());
        gui.sbh=sbh;
        Unit_rpc_setFollower (currentUnitObj,&gui,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送控制%2指令！").arg(str.c_str()).arg(strG.c_str()));
        }
        else
                ui->textBrowser_2->append(QStringLiteral("操作失败，地面单元%1不存在！").arg(strG.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_46_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        extern ilu_HashTable Units_Hash_Table;
        string strG = "GV";
        int indexG = ui->spinBox_8->value();
        strG += to_string(indexG);
        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strG.c_str()));
        if (sbh != ILU_NIL) {
        CORBA_Environment ev;
        Unit_rpc_unsetFollower (currentUnitObj,(char*)(strG.c_str()),&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送控制%2指令！").arg(str.c_str()).arg(strG.c_str()));
        }
        else
                ui->textBrowser_2->append(QStringLiteral("操作失败，地面单元%1不存在！").arg(strG.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
// 获得权限 按钮
void MainWindow::on_pushButton_47_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_obtainCtrlAuthority(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送获得权限指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_48_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_releaseCtrlAuthority(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送释放权限指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_49_clicked()
{
    string str = "AV";
    CORBA_boolean flag = 1;
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_Point3D point;
        point.x = (float)ui->doubleSpinBox_13->value();
        point.y = (float)ui->doubleSpinBox_14->value();
        point.z = (float)ui->doubleSpinBox_15->value();
        flag = Air_Unit_rpc_setTaskPoint(currentUnitObj, &point, &ev);
        if (!flag) {
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));}
        else
               ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送控制指令！").arg(str.c_str()));

    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_50_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_ForceLanding;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送强制降落指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
//
void MainWindow::on_pushButton_51_clicked()
{


        extern ilu_HashTable Units_Hash_Table;
        string strA = "AV";
        int indexA = ui->spinBox_9->value();
        strA += to_string(indexA);
        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strA.c_str()));
        
        if (sbh != ILU_NIL) {
        CORBA_Environment ev;
        Unit_UnitInfo gui;
        gui.uid=(char*)(strA.c_str());
        gui.sbh=sbh;
        //Unit_rpc_setFollower (currentLeaderObj,&gui,&ev);
        // 选择正确的 leader 对象
              Unit_rpc leader = nullptr;
              if (currentGUVLeaderObj != nullptr)
                 leader = (Unit_rpc)currentGUVLeaderObj;
            else if (currentAUVLeaderObj != nullptr)
                  leader = (Unit_rpc)currentAUVLeaderObj;
              Unit_rpc_setFollower(leader, &gui, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向leader发送控制%1指令！").arg(strA.c_str()));
        }
        else
                ui->textBrowser_2->append(QStringLiteral("操作失败，空中单元%1不存在！").arg(strA.c_str()));

}

void MainWindow::on_pushButton_52_clicked()
{

        extern ilu_HashTable Units_Hash_Table;
        string strA = "AV";
        int indexA = ui->spinBox_9->value();
        strA += to_string(indexA);
        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strA.c_str()));
        if (sbh != ILU_NIL) {
        CORBA_Environment ev;
        //Unit_rpc_unsetFollower (currentLeaderObj,(char*)(strA.c_str()),&ev);
        // 选择正确的 leader 对象
              Unit_rpc leader = nullptr;
              if (currentGUVLeaderObj != nullptr)
                  leader = (Unit_rpc)currentGUVLeaderObj;
              else if (currentAUVLeaderObj != nullptr)
                  leader = (Unit_rpc)currentAUVLeaderObj;
              Unit_rpc_unsetFollower (leader,(char*)(strA.c_str()),&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向leader发送控制%1指令！").arg(strA.c_str()));
        }
        else
                ui->textBrowser_2->append(QStringLiteral("操作失败，地面单元%1不存在！").arg(strA.c_str()));

}

void MainWindow::on_pushButton_36_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_MoveAction action;
        action._d = Unit_MA_Stop;
        Unit_rpc_sendMoveAction (currentUnitObj,&action,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送停止指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_53_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_ActionRole actionRole;
        actionRole = Air_Unit_Facilitators;
        Air_Unit_rpc_setActionRole (currentUnitObj,actionRole,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令设置角色发送失败，出现异常：%1").arg(ev.returnCode));
            return;}
        Air_Unit_ActionMode actionMode;
        actionMode = Air_Unit_Cruise;
        Air_Unit_rpc_setActionMode (currentUnitObj,actionMode,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令设置模式发送失败，出现异常：%1").arg(ev.returnCode));
            return;}
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送设置模式为巡航模式指令！").arg(str.c_str()));
        Air_Unit_Point3D po;
        po.x=ui->doubleSpinBox_16->value();
        po.y=ui->doubleSpinBox_17->value();
        po.z=0;
        Air_Unit_SiteType siteType=Air_Unit_Rectangle;
        Air_Unit_Site site;
        site._d=siteType;
        site._u.rd.po=po;
        
        site._u.rd.x=ui->spinBox_10->value();
        site._u.rd.y=ui->spinBox_14->value();
        Air_Unit_rpc_setCruiseScope(currentUnitObj,&site,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令设置巡航范围发送失败，出现异常：%1").arg(ev.returnCode));
            return;}
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_79_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_confirmThrow(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令设置模式发送失败，出现异常：%1").arg(ev.returnCode));
            return;}
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送确认抛投指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_77_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_confirmFire(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送确认火情指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_83_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_cancelFire(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送取消火情指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_78_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_confirmFireLocation(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送确认位置指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_85_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_cancelFireLocation(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送重新计算位置指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_84_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_cancelThrow(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送取消抛投指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_76_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_ActionMode actionMode;
        actionMode = Air_Unit_Nothing;
        Air_Unit_rpc_setActionMode (currentUnitObj,actionMode,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令设置模式发送失败，出现异常：%1").arg(ev.returnCode));
            return;}
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送设置模式为空模式指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
//无人机添加 按钮
void MainWindow::on_pushButton_80_clicked()
{
    ilu_Error err;
    if(!currentAUVNum)
    {
        ui->textBrowser_2->append(QStringLiteral("操作失败，当前绑定单元数为0！"));
        return;
    }
    //当前控制单元数为空，新建队列
    if(!currentControlledCount)
    {
        extern ilu_HashTable Units_Hash_Table;
        string strA = "AV";
        int indexA = ui->spinBox_15->value();
        strA += to_string(indexA);

        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strA.c_str()));
        unitSBHSeq=Unit_UnitSBHSeq_Create(currentAUVNum,NULL);
    }
    //控制单元数不为空
    if(currentControlledCount<currentAUVNum)
    {
        currentControlledCount++;
        extern ilu_HashTable Units_Hash_Table;
        string strA = "AV";
        int indexA = ui->spinBox_15->value();
        strA += to_string(indexA);
        char *sbh;
        sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (char*)(strA.c_str()));
        char* sbhtmp = (char*)ilu_malloc(strlen(sbh)+1);
        strcpy(sbhtmp, sbh);
        Unit_UnitSBHSeq_Append(unitSBHSeq,sbhtmp,&err);
        ui->textBrowser_2->append(QStringLiteral("可控无人机%1添加成功！").arg(strA.c_str()));
    }else
        ui->textBrowser_2->append(QStringLiteral("数量已满！"));
}
//无人机发送 按钮
void MainWindow::on_pushButton_81_clicked()
{
    if (unitSBHSeq==NULL){
        ui->textBrowser_2->append(QStringLiteral("操作失败，请先添加可控制单元！"));
        return;
    }
    string str = "AV";
    
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Air_Unit_rpc_sendControlledVehicle (currentUnitObj,unitSBHSeq,&ev);

        if (!ILU_C_SUCCESSFUL(&ev))
        {ui->textBrowser_2->append(QStringLiteral("指令发送可控无人机发送失败，出现异常：%1").arg(ev.returnCode));
            return;
        }
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送发送可控无人机指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
    currentControlledCount=0;
    Unit_UnitSBHSeq__Free(unitSBHSeq);
}
//清空 按钮
void MainWindow::on_pushButton_82_clicked()
{
    if (currentControlledCount!=0){
        currentControlledCount=0;
        Unit_UnitSBHSeq__Free(unitSBHSeq);
        ui->textBrowser_2->append(QStringLiteral("已重置添加无人机！"));
    }
    else {
        ui->textBrowser_2->append(QStringLiteral("未录入无人机！"));
    }
}


//巡航速度设置
void MainWindow::on_pushButton_54_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        float cs=ui->doubleSpinBox_18->value();
        CORBA_Environment ev;
        Air_Unit_rpc_setCruiseSpeed(currentUnitObj,cs,&ev);
        if (!ILU_C_SUCCESSFUL(&ev)){
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        }
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送设置巡航速度指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_57_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        float frequency=(float)ui->doubleSpinBox_19->value();
        Unit_rpc_startPhotoStream(currentUnitObj, frequency, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送打开视频流指令，频率为%2！").arg(str.c_str()).arg(frequency));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_55_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        Unit_rpc_stopPhotoStream(currentUnitObj,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送关闭视频流指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_56_clicked()
{
    string str = "AV";
    int index = ui->spinBox_7->value();
    str += to_string(index);
    /*timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    long long startTime= tv.tv_sec ;
    qDebug()<<"get bytes size " <<startTime;*/
    if(getUnitObject((char*)(str.c_str())))
    {
        CORBA_Environment ev;
        timeval tv;
        gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
        CORBA_long startTime=(tv.tv_sec-this->procedureStartTime) * 1000 + tv.tv_usec / 1000;
        Unit_rpc_takePicture(currentUnitObj,startTime,this->procedureStartTime,&ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送拍照指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

