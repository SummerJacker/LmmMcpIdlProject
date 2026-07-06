#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include <iostream>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QStringList>
#include <QWindow>
#include <QScreen>
#include <QGuiApplication>
#include <algorithm>
#include <QToolBar>
#include <QPushButton>


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

// console.cpp 里维护的当前 leader uid（AVxx/GVxx）
extern Unit_UnitID currentLeaderUID;


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

    // =============================
    // 关键：显式绑定按钮槽函数
    // 当前 UI 文件中存在“按钮文字/功能”与“默认 on_xxx_clicked()”错配的情况。
    // 这里不改 UI 布局，仅在代码层面把按钮行为与界面语义对齐。
    // =============================

    auto disconnectAll = [](QObject* o){
        if (o) o->disconnect();
    };

    // (1) 队形设置窗口（duixingframe）
    // UI: pushButton_20=录入(队形), resetFormationButton_2=重置队形, sendFormationButton_2=发送队形
    // 但默认 connectSlotsByName 会把 pushButton_20 误连到 on_pushButton_20_clicked(创建路径)
    disconnectAll(ui->pushButton_20);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::on_pushButton_19_clicked);

    disconnectAll(ui->resetFormationButton_2);
    connect(ui->resetFormationButton_2, &QPushButton::clicked, this, &MainWindow::on_resetFormationButton_clicked);

    disconnectAll(ui->sendFormationButton_2);
    connect(ui->sendFormationButton_2, &QPushButton::clicked, this, &MainWindow::on_sendFormationButton_clicked);

    // (2) 任务/路径设置区域
    // UI: pushButton_22=创建路径, pushButton_23=录入(路径点), pushButton_25=发送(目标点)
    // 但默认槽函数命名与 UI 文字不一致，这里重新绑定。
    disconnectAll(ui->pushButton_22);
    connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::on_pushButton_20_clicked);

    disconnectAll(ui->pushButton_23);
    connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::on_pushButton_22_clicked);

    disconnectAll(ui->pushButton_25);
    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::on_pushButton_23_clicked);
    // --- 隐藏原顶部按钮区 ---
    ui->PBtnSetLeaderPage->hide();      // 设置领航者
    ui->PBtnRemotePage->hide();    // 遥控界面
    ui->PBtnFollowPage->hide();   // 跟随界面
    ui->PBtnSimulateModel->hide();   // 模仿模式
    ui->PBtnFollowModel->hide();   // 跟随模式
    ui->PBtnCloseAllPrograms->hide();   // 关闭所有程序
    ui->PBtnResetAllUnits->hide();   // 重置所有单元关系
    ui->PBtnClearAllCache->hide();   // 清除缓存文件
    ui->PBtnTargetTrack->hide();   // 目标跟踪
    ui->PBtnTrajectoryTrack->hide();   // 轨迹跟踪
    ui->PBtnTrapSet->hide();   // 设置陷阱

    connect(ui->actionSetToLeader, &QAction::triggered, this, &MainWindow::on_PBtnSetLeaderPage_clicked);
    connect(ui->actionRemotePage,   &QAction::triggered, this, &MainWindow::on_PBtnRemotePage_clicked);
    connect(ui->actionFollowPage,   &QAction::triggered, this, &MainWindow::on_PBtnFollowPage_clicked);
    connect(ui->actionTargetTrackPage,   &QAction::triggered, this, &MainWindow::on_PBtnTargetTrack_clicked);
    connect(ui->actionTrajectoryTrackPage,   &QAction::triggered, this, &MainWindow::on_PBtnTrajectoryTrack_clicked);
    connect(ui->actionTrapSettingPage,   &QAction::triggered, this, &MainWindow::on_PBtnTrapSet_clicked);

    connect(ui->actionSimulateModel,   &QAction::triggered, this, &MainWindow::on_PBtnSimulateModel_clicked);
    connect(ui->actionFollowModel,   &QAction::triggered, this, &MainWindow::on_PBtnFollowModel_clicked);

    connect(ui->actionCloseAllProgams, &QAction::triggered, this, &MainWindow::on_PBtnCloseAllPrograms_clicked);
    connect(ui->actionResetAllUnits, &QAction::triggered, this, &MainWindow::on_PBtnResetAllUnits_clicked);
    connect(ui->actionClearAllCache, &QAction::triggered, this, &MainWindow::on_PBtnClearAllCache_clicked);

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
void MainWindow::on_PBtnSetLeaderPage_clicked()
{
//    hideallframe();
//    ui->setleaderframe->show();
    QWidget* w = ui->setleaderframe;
        if (w->parent() == this) w->setParent(nullptr);
        w->setWindowFlag(Qt::Window, true);
        w->setAttribute(Qt::WA_DeleteOnClose, false);
        w->setWindowTitle(tr("SetLeader"));
        w->setFixedSize(QSize(900, 620));

        QScreen* target = this->windowHandle() ? this->windowHandle()->screen() : nullptr;
        if (!target) {
            const QPoint gcenter = this->mapToGlobal(this->rect().center());
            target = QGuiApplication::screenAt(gcenter);
        }
        if (!target) target = QGuiApplication::primaryScreen();

        w->show();
        if (w->windowHandle() && target) w->windowHandle()->setScreen(target);

        w->raise();
        w->activateWindow();
}

void MainWindow::on_PBtnRemotePage_clicked()
{
//    hideallframe();
//    ui->yaokongframe->show();
    QWidget* w = ui -> yaokongframe;
    if(w->parent() == this) w -> setParent(nullptr);
    w -> setWindowFlag(Qt::Window, true);
    w -> setAttribute(Qt::WA_DeleteOnClose, false);
    w -> setWindowTitle(tr("Remote"));
    w -> setFixedSize(QSize(1000, 700));
    QScreen* target = nullptr;
        if (this->windowHandle()) {
            target = this->windowHandle()->screen();           // 首选：主窗的屏
        }
    w->show();
           if (w->windowHandle() && target) {
               w->windowHandle()->setScreen(target);
           }
    w->raise();
    w->activateWindow();
}

void MainWindow::on_PBtnFollowPage_clicked()
{
//    hideallframe();
//    ui->followframe->show();
//    ui->duixingframe->hide();
//    ui->goalframe->hide();
//    QWidget* w = ui->followframe;
//        if (w->parent() == this) w->setParent(nullptr);
//        w->setWindowFlag(Qt::Window, true);
//        w->setAttribute(Qt::WA_DeleteOnClose, false);
//        w->setWindowTitle(tr("Follow"));
//        w->setFixedSize(QSize(980, 680));

//        QScreen* target = this->windowHandle() ? this->windowHandle()->screen() : nullptr;
//        if (!target) {
//            const QPoint gcenter = this->mapToGlobal(this->rect().center());
//            target = QGuiApplication::screenAt(gcenter);
//        }
//        if (!target) target = QGuiApplication::primaryScreen();

//        w->show();
//        if (w->windowHandle() && target)
//        {
//            w->windowHandle()->setScreen(target);
//            qDebug()<<"1";
//        }
//        w->raise();
//        w->activateWindow();
    QWidget* w = ui->followframe;
    QWidget* x = ui->duixingframe;
    QWidget* y = ui->goalframe;
        if (w->parent() != nullptr) w->setParent(nullptr);  // 脱离原布局，成为顶层
        w->setFixedSize(QSize(980, 680));
        w->show();
        x->hide();
        y->hide();
        w->raise(); w->activateWindow();
}

void MainWindow::on_PBtnSetFormation_clicked()
{
//    ui->goalframe->hide();
//    ui->duixingframe->show();
    QWidget* w = ui->duixingframe;
        if (w->parent() != nullptr) w->setParent(nullptr);  // 脱离原布局，成为顶层
        w->setFixedSize(QSize(980, 680));

        // 修改：允许用户输入任意编号（1~99），在录入时检查是否存在
        // 因为实际单元 ID 可能不是从 1 开始连续编号的（比如 GV2, GV3）
        ui->spinBox_bianhao->setMinimum(1);
        ui->spinBox_bianhao->setMaximum(99);

        w->show(); w->raise(); w->activateWindow();
}

void MainWindow::on_PBtnSetDestination_clicked()
{
//    ui->duixingframe->hide();
//    ui->goalframe->show();
    QWidget* w = ui->goalframe;
        if (w->parent() != nullptr) w->setParent(nullptr);
        w->show(); w->raise(); w->activateWindow();
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
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        Unit_MoveAction action;
        CORBA_Environment ev;
        action._d = Unit_MA_GoAhead;
        action._u.goAheadData.duration.keep = ilu_TRUE;
        action._u.goAheadData.speed = (float)(ui->doubleSpinBox_2->value());
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

void MainWindow::on_pushButton_8_clicked()
{
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        Unit_MoveAction action;
        CORBA_Environment ev;
        action._d = Unit_MA_GoBackward;
        action._u.goBackwardData.duration.keep = ilu_TRUE;
        action._u.goBackwardData.speed = (float)(ui->doubleSpinBox_2->value());
        Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送后退指令，线速度为%2！").arg(str.c_str()).arg(action._u.goBackwardData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_6_clicked()
{
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        Unit_MoveAction action;
        CORBA_Environment ev;
        action._d = Unit_MA_TurnLeft;
        action._u.turnLeftData.duration.keep = ilu_TRUE;
        action._u.turnLeftData.speed = (float)(ui->doubleSpinBox_3->value());
        Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送左转指令，角速度为%3！").arg(str.c_str()).arg(action._u.turnLeftData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}

void MainWindow::on_pushButton_7_clicked()
{
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        Unit_MoveAction action;
        CORBA_Environment ev;
        action._d = Unit_MA_TurnRight;
        action._u.turnRightData.duration.keep = ilu_TRUE;
        action._u.turnRightData.speed = (float)(ui->doubleSpinBox_3->value());
        Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送右转指令，角速度为%3！").arg(str.c_str()).arg(action._u.turnRightData.speed));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
}
// 停止命令
void MainWindow::on_pushButton_9_clicked()
{
    string str = "GV";
    int index = ui->spinBox_2->value();
    str += to_string(index);
    if(getUnitObject((char*)(str.c_str())))
    {
        Unit_MoveAction action;
        CORBA_Environment ev;
        action._d = Unit_MA_Stop;
        action._u.stopData.keep = ilu_TRUE;
        Unit_rpc_sendMoveAction(currentUnitObj, &action, &ev);
        if (!ILU_C_SUCCESSFUL(&ev))
            ui->textBrowser_2->append(QStringLiteral("指令发送失败，出现异常：%1").arg(ev.returnCode));
        ui->textBrowser_2->append(QStringLiteral("成功向单元%1发送停止指令！").arg(str.c_str()));
    }
    else
        ui->textBrowser_2->append(QStringLiteral("操作失败，单元%1不存在！").arg(str.c_str()));
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
void MainWindow::on_PBtnClearAllCache_clicked()
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
void MainWindow::on_PBtnSimulateModel_clicked()
{
    if(setGroupMode(Unit_UM_Imitate))
        ui->textBrowser_2->append(QStringLiteral("成功设置模拟模式！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置模拟模式失败！"));
}
//设置跟随模式
void MainWindow::on_PBtnFollowModel_clicked()
{
    if(setGroupMode(Unit_UM_Follow))
        ui->textBrowser_2->append(QStringLiteral("成功设置跟随模式！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置跟随模式失败！"));
}

void MainWindow::on_pushButton_23_clicked()
{
    string str = "GV";
    int index = ui->spinBox_currentUGV->value();
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
        point._u.p2D.x = (float)ui->doubleSpinBox_lujingx->value();
        point._u.p2D.y = (float)ui->doubleSpinBox_lujingy->value();
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

    // ========= 选择“本次录入的队形属于 UAV 还是 UGV” =========
    // 不改 UI：根据当前 Leader 类型决定。
    // - Leader=AVxx -> 录入/发送 AV 编队
    // - Leader=GVxx -> 录入/发送 GV 编队
    // 如果当前未设置 Leader：
    // - 仅存在一种类型时自动选择
    // - 同时存在 UAV + UGV 时拒绝录入，避免歧义
    const bool leaderIsAir   = (currentLeaderUID != NULL && currentLeaderUID[0] == 'A');
    const bool leaderIsGround= (currentLeaderUID != NULL && currentLeaderUID[0] == 'G');

    bool isAirFormation = false;
    if (leaderIsAir) isAirFormation = true;
    else if (leaderIsGround) isAirFormation = false;
    else {
        if (currentAUVNum > 0 && currentGUVNum == 0) isAirFormation = true;
        else if (currentGUVNum > 0 && currentAUVNum == 0) isAirFormation = false;
        else {
            ui->textBrowser_2->append(QStringLiteral("请先在【设置领航者】中选择 Leader（AVxx 或 GVxx），再录入队形。"));
            return;
        }
    }

    const int groupNum = isAirFormation ? currentAUVNum : currentGUVNum;
    const std::string prefix = isAirFormation ? "AV" : "GV";
    if (groupNum <= 0) {
        ui->textBrowser_2->append(QStringLiteral("操作失败：当前该类型单元数为0。"));
        return;
    }

    // 首次录入：创建 formation（序列长度从 0 开始，逐条 Append，避免长度不一致）
    if (!currentUnitCount) {
        formation = (Unit_Formation*)malloc(sizeof(Unit_Formation));
        formation->robot_ids  = *Unit_UnitIDSeq_Create(groupNum, NULL);
        formation->leader_ids = *Unit_ShortSeq_Create(groupNum, NULL);
        formation->distances  = *Unit_FloatSeq_Create(groupNum, NULL);
        formation->angles     = *Unit_FloatSeq_Create(groupNum, NULL);

        // 若已设置 Leader，则自动把 Leader 作为第一个录入项（避免“Leader 不在第一个”导致发送错误）
        if (currentLeaderUID != NULL && ((isAirFormation && currentLeaderUID[0] == 'A') || (!isAirFormation && currentLeaderUID[0] == 'G'))) {
            char* leader_copy = (char*)ilu_malloc(strlen(currentLeaderUID) + 1);
            strcpy(leader_copy, currentLeaderUID);
            Unit_UnitIDSeq_Append(&formation->robot_ids, leader_copy, &err);
            Unit_ShortSeq_Append(&formation->leader_ids, 0, &err);
            Unit_FloatSeq_Append(&formation->distances, 0.0f, &err);
            Unit_FloatSeq_Append(&formation->angles, 0.0f, &err);
            currentUnitCount = 1;
            ui->textBrowser_2->append(QStringLiteral("已自动录入 Leader：%1").arg(currentLeaderUID));
        }
    }

    // 如果当前只有 Leader（或没有 Leader），继续录入一个 follower
    if (currentUnitCount >= groupNum) {
        ui->textBrowser_2->append(QStringLiteral("队形已满（已录入%1/%2）。").arg(currentUnitCount).arg(groupNum));
        return;
    }

    std::string uid = prefix + std::to_string(ui->spinBox_bianhao->value());
    // 不允许重复录入 Leader
    if (currentLeaderUID != NULL && uid == std::string(currentLeaderUID)) {
        ui->textBrowser_2->append(QStringLiteral("%1 已是 Leader，无需重复录入。" ).arg(QString::fromStdString(uid)));
        return;
    }

    // 检查是否已绑定（Units_Hash_Table 中找不到则通常意味着没连接成功）
    char* sbh = (char*)ilu_hash_FindInTable(Units_Hash_Table, (ilu_refany)uid.c_str());
    if (sbh == NULL) {
        ui->textBrowser_2->append(QStringLiteral("录入失败：%1 未绑定/未连接（找不到 SBH）。").arg(QString::fromStdString(uid)));
        return;
    }

    char* robot_id = (char*)ilu_malloc(uid.size() + 1);
    strcpy(robot_id, uid.c_str());
    Unit_UnitIDSeq_Append(&formation->robot_ids, robot_id, &err);
    
    // 链式拓扑：新 Follower 的 leader_ids 设为上一个被录入单元的索引（而非固定为0）
    // 这样形成链式结构：Leader(0) <- F1(1) <- F2(2) <- F3(3)...
    // Requirements 1.1: 将新Follower的leader_ids设置为上一个被录入单元的索引
    short leaderIdx = (currentUnitCount > 0) ? (short)(currentUnitCount - 1) : 0;
    Unit_ShortSeq_Append(&formation->leader_ids, leaderIdx, &err);
    
    Unit_FloatSeq_Append(&formation->distances, (float)ui->doubleSpinBox_jianju->value(), &err);
    Unit_FloatSeq_Append(&formation->angles, 0.0f, &err);
    currentUnitCount++;

    ui->textBrowser_2->append(QStringLiteral("队形信息 %1 添加成功！（跟随索引=%4）（%2/%3）")
                             .arg(robot_id)
                             .arg(currentUnitCount)
                             .arg(groupNum)
                             .arg(leaderIdx));
}

void MainWindow::on_PBtnTrapSet_clicked()
{
//    hideallframe();
//    ui->trapframe->show();
    auto w = ui->trapframe;
        if (w->parent() == this) w->setParent(nullptr);
        w->show(); w->raise(); w->activateWindow();
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

void MainWindow::on_PBtnTargetTrack_clicked()
{
    if(setGroupMinorMode(Unit_UMM_FW_Object))
        ui->textBrowser_2->append(QStringLiteral("设置目标跟踪模式成功！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置目标跟踪模式失败！"));
}

void MainWindow::on_PBtnTrajectoryTrack_clicked()
{
    if(setGroupMinorMode(Unit_UMM_FW_Track))
        ui->textBrowser_2->append(QStringLiteral("设置轨迹跟踪模式成功！"));
    else
        ui->textBrowser_2->append(QStringLiteral("设置轨迹跟踪失败！"));
}

void MainWindow::on_PBtnCloseAllPrograms_clicked()
{
    shutDownAllUnit();
    ui->textBrowser_2->append(QStringLiteral("成功关闭所有单元程序！"));
}

void MainWindow::on_PBtnResetAllUnits_clicked()
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
    if (formation == NULL || currentUnitCount == 0) {
        ui->textBrowser_2->append(QStringLiteral("当前未录入队形信息！"));
        return;
    }

    if (currentUnitCount < 2) {
        ui->textBrowser_2->append(QStringLiteral("至少需要 1 个 Leader + 1 个 Follower 才能发送队形。"));
        return;
    }

    // 如果已设置 Leader，则要求 formation 的第 0 个必须是 Leader（必要时自动调整）
    if (currentLeaderUID != NULL) {
        const int n = (int)formation->robot_ids._length;
        int leaderIdx = -1;
        for (int i = 0; i < n; ++i) {
            const char* uid = *(Unit_UnitIDSeq_Nth(&formation->robot_ids, i));
            if (uid != NULL && strcmp(uid, currentLeaderUID) == 0) { leaderIdx = i; break; }
        }
        if (leaderIdx == -1) {
            ui->textBrowser_2->append(QStringLiteral("发送失败：当前 Leader(%1) 不在已录入队形中。请重置队形后重新录入。")
                                     .arg(currentLeaderUID));
            return;
        }
        if (leaderIdx != 0) {
            // 交换到第 0 位
            std::swap(formation->robot_ids._buffer[0], formation->robot_ids._buffer[leaderIdx]);
            std::swap(formation->leader_ids._buffer[0], formation->leader_ids._buffer[leaderIdx]);
            std::swap(formation->distances._buffer[0], formation->distances._buffer[leaderIdx]);
            std::swap(formation->angles._buffer[0], formation->angles._buffer[leaderIdx]);
            formation->distances._buffer[0] = 0.0f;
            formation->angles._buffer[0] = 0.0f;
            ui->textBrowser_2->append(QStringLiteral("已将 Leader(%1) 自动调整为队形第一个。")
                                     .arg(currentLeaderUID));
        }
    }

    // 防止“Leader 类型”和“队形类型”不一致
    const char* uid0 = *(Unit_UnitIDSeq_Nth(&formation->robot_ids, 0));
    if (uid0 != NULL && uid0[0] == 'A' && currentAUVLeaderObj == NULL) {
        ui->textBrowser_2->append(QStringLiteral("当前 Leader 不是无人机（AV），无法发送无人机队形。请先设置 AV Leader。"));
        return;
    }
    if (uid0 != NULL && uid0[0] == 'G' && currentGUVLeaderObj == NULL) {
        ui->textBrowser_2->append(QStringLiteral("当前 Leader 不是无人车（GV），无法发送无人车队形。请先设置 GV Leader。"));
        return;
    }

    // 使用 setFormationWithResult 获取详细结果 (Requirements 10.2, 10.4)
    FormationResult result = setFormationWithResult(formation);
    
    // 显示跨类型边警告 (Requirements 6.1)
    if (!result.crossTypeWarnings.empty()) {
        ui->textBrowser_2->append(QStringLiteral("⚠ 检测到跨类型边（空地混合），已自动忽略："));
        for (const auto& edge : result.crossTypeWarnings) {
            ui->textBrowser_2->append(QStringLiteral("  - [%1 → %2] 已忽略")
                                     .arg(edge.fromUid).arg(edge.toUid));
        }
    }
    
    if (result.isSuccess()) {
        // 完全成功
        currentUnitCount = 0;
        Unit_UnitIDSeq__Free(&formation->robot_ids);
        Unit_ShortSeq__Free(&formation->leader_ids);
        Unit_FloatSeq__Free(&formation->distances);
        Unit_FloatSeq__Free(&formation->angles);
        free(formation);
        formation = NULL;
        
        int totalSuccess = result.airResult.successCount + result.groundResult.successCount;
        ui->textBrowser_2->append(QStringLiteral("✓ 队形下发成功！（%1个单元，耗时%2ms）")
                                 .arg(totalSuccess).arg(result.elapsedMs));
    } else if (result.isPartialSuccess()) {
        // 部分成功 (Requirements 10.4)
        int totalSuccess = result.airResult.successCount + result.groundResult.successCount;
        int totalFail = result.airResult.failCount + result.groundResult.failCount;
        
        ui->textBrowser_2->append(QStringLiteral("⚠ 队形部分成功：成功%1个，失败%2个（耗时%3ms）")
                                 .arg(totalSuccess).arg(totalFail).arg(result.elapsedMs));
        
        // 显示失败单元详情
        std::vector<UnitResult> failedUnits = result.getAllFailedUnits();
        for (const auto& ur : failedUnits) {
            QString orphanTag = ur.isOrphan ? QStringLiteral("（独立节点）") : QStringLiteral("");
            ui->textBrowser_2->append(QStringLiteral("  - %1 失败%2: %3")
                                     .arg(ur.uid).arg(orphanTag).arg(ur.errorMsg));
        }
        
        // 部分成功时也清理 formation
        currentUnitCount = 0;
        Unit_UnitIDSeq__Free(&formation->robot_ids);
        Unit_ShortSeq__Free(&formation->leader_ids);
        Unit_FloatSeq__Free(&formation->distances);
        Unit_FloatSeq__Free(&formation->angles);
        free(formation);
        formation = NULL;
    } else {
        // 全部失败
        int totalFail = result.airResult.failCount + result.groundResult.failCount;
        ui->textBrowser_2->append(QStringLiteral("✗ 队形下发失败！（%1个单元失败，耗时%2ms）")
                                 .arg(totalFail).arg(result.elapsedMs));
        
        // 显示失败单元详情
        std::vector<UnitResult> failedUnits = result.getAllFailedUnits();
        for (const auto& ur : failedUnits) {
            ui->textBrowser_2->append(QStringLiteral("  - %1: %2")
                                     .arg(ur.uid).arg(ur.errorMsg));
        }
        
        ui->textBrowser_2->append(QStringLiteral("请查看控制台日志/单元状态，可重试发送。"));
    }
}
//发送路径按钮
void MainWindow::on_taskPathSendButton_clicked()
{
    if(currentPointsCount == pointsCount)
    {
        CORBA_Environment en;
        string str = "GV";
        ilu_Error err;
        int index = ui->spinBox_currentUGV->value();
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
//    hideallframe();
//    ui->photoframe->show();
    auto w = ui->photoframe;
        if (w->parent() == this) w->setParent(nullptr);
        w->show(); w->raise(); w->activateWindow();
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
        int indexA = ui->spinBox_UAVbianhao->value();
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
        int indexA = ui->spinBox_UAVbianhao->value();
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

