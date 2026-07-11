#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "picturewindow.h"
#include <QStandardItem>
#include <QAbstractItemView>
#include <QThread>
#include <vector>
#include <QDebug>
#include <QFileDialog>
#include <fstream>
#include <algorithm>
#include <countdowndialog.h>




char stateStr[10][40] =
{
    "等待确认处理",
    "已忽略",
    "定位中",
    "已定位，等待确认继续",
    "正在准备灭火",
    "准备就绪，等待确认灭火",
    "正在灭火",
    "重新尝试灭火",
    "已经终止",
    "灭火成功"
};
const char* FIRE_PIC_DIR = "$$PWD/../FirePics";

// override operation funcs
static std::stringstream& operator<<(std::stringstream& ss, const SRIO_Ground_Unit::Ground_Unit::GroundUnitInfo& info)
{
    ss << "单元角色:";
    switch(info.role)
    {
    case SRIO_Unit::General_Unit::UR_None:
        ss << "无角色";
        break;
    case SRIO_Unit::General_Unit::UR_Leader:
        ss << "领航者";
        break;
    case SRIO_Unit::General_Unit::UR_Follower:
        ss << "跟随者";
        break;
    }
    ss << "\n当前速度:\n";
    ss << "--线速度:" << info.speed.leanerVel << "\n";
    ss << "--角速度:" << info.speed.angularVel << "\n";
    ss << "当前位置:";
    ss << "(" << info.pose.x;
    ss << "," << info.pose.y << ")\n";
    ss << "当前偏航角(yaw):" << info.pose.yaw << "\n";
    ss << "--------------------------------------";
    return ss;
}

static std::stringstream& operator<<(std::stringstream& ss, const SRIO_Air_Unit::Air_Unit::AirUnitInfo& info)
{
    //ss.precision(2);
    ss << "单元角色:";
    switch(info.role)
    {
    case SRIO_Unit::General_Unit::UR_None:
        ss << "无角色";
        break;
    case SRIO_Unit::General_Unit::UR_Leader:
        ss << "领航者";
        break;
    case SRIO_Unit::General_Unit::UR_Follower:
        ss << "跟随者";
        break;
    }
    ss << "\n当前线速度:";
    ss << "(" << info.speed.x;
    ss << "," << info.speed.y;
    ss << "," << info.speed.z << ")\n";
    ss << "当前角速度:";
    ss << "(" << info.angularVelocity.x;
    ss << "," << info.angularVelocity.y;
    ss << "," << info.angularVelocity.z << ")\n";
    ss << "当前GPS位置:\n";
    ss << "--时间戳:" << std::fixed << info.gps.time << "\n";
    ss << "--经度:" << info.gps.longitude << "\n";
    ss << "--纬度:" << info.gps.latitude << "\n";
    ss << "--海拔:" << info.gps.altitude << "\n";
    ss << "--高度:" << info.gps.height << "\n";//???
    ss << "--GPS状况:" << info.gps.health << "%\n";
    ss << "当前位姿:\n";
    ss << "--俯仰角(pitch):" << info.gs.pitch << "\n";
    ss << "--偏航角(yaw):" << info.gs.yaw << "\n";
    ss << "--翻滚角(roll):" << info.gs.roll << "\n";
    ss << "--------------------------------------";
    return ss;
}

static std::stringstream& operator<<(std::stringstream& ss, const FireEventInfo& info)
{
    ss << "火情事件ID:\n" << info.eventID << "\n";
    ss << "事件创建时间:\n" << timestampToDate(info.timestamp) << "\n";
    ss << "汇报单元:\n" << info.reporterID << "\n";
    ss << "火情事件状态:\n" << stateStr[info.state] << "\n";
    ss << "状态是否有效:\n" << (info.expired?"已失效":"有效") << "\n";
    if(info.location.x >= 0)
        ss << "起火位置:" << "(" << info.location.x
            << "," << info.location.y << ")\n";
    else
        ss << "起火位置:" << "未知\n";
    ss << "---------------------------------";
    return ss;
}

MainWindow::MainWindow(QWidget *parent, MonitorImpl* m, QThread* t) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    monitorPtr(m),
    unitsStateUpdateTimer(this),
    serverThread(t),
    currPicListPtr(nullptr),
    currPicName("None")
{
    ui->setupUi(this);
//    ui->pushButton_2->hide();    //setAttribute(Qt::WA_DeleteOnClose);// delete this object when window is closed
    //this->setFixedSize(1824, 900);
    this->setWindowTitle(CH("监控器"));
    qRegisterMetaType<std::string>("string");
    connect(&unitsStateUpdateTimer, SIGNAL(timeout()), this, SLOT(updateUnitsStateListView()));
    unitsStateUpdateTimer.start(200);//200ms
}

MainWindow::~MainWindow()
{
    unitsStateUpdateTimer.stop();
    if(serverThread != nullptr)
    {
        serverThread->terminate();
        serverThread->wait();
    }
    delete ui;
}

// MainWindow 类的初始化函数，建立 UI 与监控模块之间的信号槽连接
bool MainWindow::init()
{
    // 如果监控模块指针尚未初始化，直接返回 false 表示初始化失败
    if(monitorPtr == nullptr)
        return false;
    qDebug() << monitorPtr;
    // 将 monitorPtr 发出的 displayMsg(std::string) 信号连接到 MainWindow 的 displayMsg(std::string) 槽函数
    // 用于在界面上显示日志、提示等文本信息
    connect(monitorPtr, SIGNAL(displayMsg(std::string)), this, SLOT(displayMsg(std::string)));

    // 将 monitorPtr 发出的 updateTraps() 信号连接到 MainWindow 的 updateTrapsListView() 槽函数
    // 用于更新陷阱（如传感器、侦测装置）列表视图，表示系统检测器状态可能发生了变化
    connect(monitorPtr, SIGNAL(updateTraps()), this, SLOT(updateTrapsListView()));

    // 将 monitorPtr 发出的 updateFireEvents() 信号连接到 MainWindow 的 updateFireEventsListView() 槽函数
    // 用于刷新火情事件的列表，表示火情数据（如新增、状态变化）发生了更新
    connect(monitorPtr, SIGNAL(updateFireEvents()), this, SLOT(updateFireEventsListView()));

    // 将 monitorPtr 发出的 updateFireEventsPicRelatives(std::string, const PicList*) 信号
    // 连接到 MainWindow 的 displayNewestPictureRelatives(std::string, const PicList*) 槽函数
    // 用于显示指定火情事件相关的图片（如无人机拍摄的现场照片）
    connect(monitorPtr, SIGNAL(updateFireEventsPicRelatives(std::string,const PicList*)),
            this, SLOT(displayNewestPictureRelatives(std::string,const PicList*)));

    // 将 monitorPtr 发出的 updateNewestPhoto(std::string) 信号连接到 MainWindow 的 displayNewestPhoto(std::string) 槽函数
    // 用于界面上更新最新拍摄的火情照片
    connect(monitorPtr, SIGNAL(updateNewestPhoto(std::string)),
            this, SLOT(displayNewestPhoto(std::string)));

    // 将 monitorPtr 发出的 openCountDownWindow(std::string, unsigned int) 信号
    // 连接到 MainWindow 的 openCountDownWindow(std::string, unsigned int) 槽函数
    // 当触发倒计时操作时（如拍照前的延时），在主界面弹出倒计时窗口
    connect(monitorPtr, SIGNAL(openCountDownWindow(std::string, unsigned int)),
            this, SLOT(openCountDownWindow(std::string, unsigned int)));

    // 所有信号槽连接成功后返回 true，表示初始化完成
    return true;
}


// public slots
void MainWindow::displayMsg(std::string str)
{
    std::string msg = timestampToDate(getCurrentMilliTimestamp()) + ":\n";
    msg += str;
    this->ui->msgOutput->append(CH(msg.c_str()));
    this->ui->msgOutput->update();
}

void MainWindow::updateTrapsListView()
{
    // go fetch the data and update list view
    QAbstractItemModel* oldModel = ui->trapListView->model();
    if(oldModel != nullptr)
        delete oldModel;
    QStandardItemModel* newModel = new QStandardItemModel(this);
    // get traps info and build qstringlist
    const TrapPointList trapList = monitorPtr->getTrapPointList();
    auto iter = trapList.begin();
    for(; iter != trapList.end(); iter++)
    {
        std::stringstream ss;
        ss << "陷阱位置:\n";
        switch(iter->_d())
        {
        case SRIO_Console::Console::TrapGroundType:
            ss << "(" << iter->trapPoint2D().point.x << ","
               << iter->trapPoint2D().point.y << ")\n";
            ss << "陷阱半径:\n" << iter->trapPoint2D().radius;
            break;
        case SRIO_Console::Console::TrapAirType:
            ss << "(" << iter->trapPoint3D().point.x << ","
               << iter->trapPoint3D().point.y << ","
               << iter->trapPoint3D().point.z << ")\n";
            ss << "陷阱半径:\n" << iter->trapPoint3D().radius;
            break;
        }
        ss << "\n----------------------------------";
        QStandardItem *item = new QStandardItem(CH(ss.str().c_str()));
        newModel->appendRow(item);
    }
    ui->trapListView->setModel(newModel);
    ui->trapListView->update();
}

void MainWindow::updateUnitsStateListView()
{
    qDebug() << "updateUnitsStateListView";
    //go fetch the data and update list view
    QAbstractItemModel* oldModel = ui->unitsStateListView->model();
    if(oldModel != nullptr)
        delete oldModel;
    QStandardItemModel* newModel = new QStandardItemModel(this);
    // get traps info and build qstringlist
    const UnitsStateMap map = monitorPtr->getUnitsState();
    auto iter = map.begin();
    for(; iter != map.end(); iter++)
    {
        std::stringstream ss;
        ss << "单元ID:" << iter->first << "\n";
        ss << "整体状况:" << iter->second.us.health << "\n";
        ss << "电池电量:" << iter->second.us.battery << "%\n";
        switch(iter->second.cui._d())
        {
        case SRIO_Monitor::Monitor::UnitGroundType:
            ss << iter->second.cui.groundUnitInfo();
            break;
        case SRIO_Monitor::Monitor::UnitAirType:
            ss << iter->second.cui.airUnitInfo();
            break;
        }
        QStandardItem *item = new QStandardItem(CH(ss.str().c_str()));
        newModel->appendRow(item);
        qDebug() << ss.str().c_str();
    }
    ui->unitsStateListView->setModel(newModel);
    ui->unitsStateListView->update();
}

void MainWindow::updateFireEventsListView()
{
    //go fetch the data and update list view
    QAbstractItemModel* oldModel = ui->fireEventListView->model();
    if(oldModel != nullptr)
        delete oldModel;
    QStandardItemModel* newModel = new QStandardItemModel(this);
    // get traps info and build qstringlist
    const FireEventMap map = monitorPtr->getFireEvents();
    std::vector<FireEventPair> sortedInfos(map.begin(),map.end());
    // sort
    sort(sortedInfos.begin(),sortedInfos.end(), compareByTimestamp);
    for(auto iter = sortedInfos.begin(); iter != sortedInfos.end(); iter++)
    {
        std::stringstream ss;
        ss << *(iter->second);
        QStandardItem *item = new QStandardItem(CH(ss.str().c_str()));
        newModel->appendRow(item);
    }
    ui->fireEventListView->setModel(newModel);
    ui->fireEventListView->update();
}

// update firePictureLabel, firePicComboBox, fireEventLabel, firePicTimestampLabel
void MainWindow::displayNewestPictureRelatives(std::string eid,const PicList* list)
{
    // set fireEventLabel

    qDebug() << "displayNewestPictureRelatives";
    ui->fireEventIDLabel->setText(CH("火情事件")+CH(eid.c_str()));
    ui->fireEventIDLabel->adjustSize();
    // set firePicComboBox
    currPicListPtr = list;
    ui->firePicsListComboBox->clear();
    for(auto iter = currPicListPtr->begin(); iter != currPicListPtr->end(); iter++)
        ui->firePicsListComboBox->addItem(CH(iter->discription.c_str()));
    ui->firePicsListComboBox->adjustSize();
    // current combo box item should be the last node in the list
    ui->firePicsListComboBox->setCurrentIndex(static_cast<int>(list->size()) - 1);
    // set firePictureLabel
    currPicName = currPicListPtr->back().picFileName;
    ui->firePictureLabel->setPixmap(QPixmap(QString(FIRE_PIC_DIR) + currPicName.c_str()));
    // set firePicTimestamp
    ui->firePicTimestampLabel->setText(
               CH(timestampToDate(currPicListPtr->back().timestamp).c_str()));
    ui->firePicTimestampLabel->adjustSize();
    // update items
    ui->fireEventIDLabel->update();
    ui->firePicsListComboBox->update();
    ui->firePictureLabel->update();
    ui->firePicTimestampLabel->update();
}

void MainWindow::displayNewestPhoto(std::string picName){
    currPicName = picName;
    ui->firePictureLabel->setPixmap(QPixmap(QString(FIRE_PIC_DIR) + currPicName.c_str()));
}

void MainWindow::openCountDownWindow(std::string tips, unsigned int number)
{
    CountDownDialog* window = new CountDownDialog(tips, number, this);
    window->show();
}

// event funcs
void MainWindow::closeEvent(QCloseEvent *event)
{
    serverThread->terminate();
    serverThread->wait();
    serverThread = nullptr;
}

// private slots
void MainWindow::on_fireEventListView_clicked(const QModelIndex &index)
{
    QAbstractItemModel* model = ui->fireEventListView->model();
    QVariant v = model->data(index);
    //qDebug() << v.toString();
    const QString& qstr = v.toString();
    QStringList list = qstr.split("\n");
    currPicListPtr = &monitorPtr->getFirePicList(list[1].toStdString());
    currPicName = currPicListPtr->at(0).picFileName;
    ui->firePictureLabel->setPixmap(QPixmap
        (QString(FIRE_PIC_DIR) + currPicName.c_str()));
    // combo box
    ui->firePicsListComboBox->clear();
    for(auto iter = currPicListPtr->begin(); iter != currPicListPtr->end(); iter++)
        ui->firePicsListComboBox->addItem(CH(iter->discription.c_str()));
    ui->firePicsListComboBox->adjustSize();
    // pic label
    ui->fireEventIDLabel->setText(CH("火情事件")+list[1]);
    ui->fireEventIDLabel->adjustSize();
    // pic timestamp
    ui->firePicTimestampLabel->setText(
               CH(timestampToDate(currPicListPtr->at(0).timestamp).c_str()));
    ui->firePicTimestampLabel->adjustSize();
    // update
    ui->firePicsListComboBox->update();
    ui->firePictureLabel->update();
    ui->fireEventIDLabel->update();
}

bool isSameDiscription(const PicListNode& n, const QString& d)
{
    return !d.compare(CH(n.discription.c_str()));
}

void MainWindow::on_firePicsListComboBox_currentIndexChanged(const QString &discription)
{
    auto iter = find_if(currPicListPtr->begin(), currPicListPtr->end(),
            std::bind(isSameDiscription, std::placeholders::_1, discription));
    if(iter != currPicListPtr->end())
    {
        // pic label
        currPicName = iter->picFileName;
        ui->firePictureLabel->setPixmap(QPixmap
            (QString(FIRE_PIC_DIR) + currPicName.c_str()));
        // pic timestamp
        ui->firePicTimestampLabel->setText(
                    CH(timestampToDate(iter->timestamp).c_str()));
        ui->firePicTimestampLabel->adjustSize();
        // update
        ui->firePictureLabel->update();
        ui->fireEventIDLabel->update();
    }
}

void MainWindow::on_newWinPushButton_clicked()
{

//    if(currPicName.compare("None"))
    if(1)
    {
        PictureWindow *picWin = new PictureWindow(currPicName, this);
        picWin->show();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(currPicName.compare("None"))//not equal
    {
        //获取当前文件后缀名
        unsigned int index = currPicName.find_last_of(".");
        std::string extension = currPicName.substr(index + 1);
        std::string filter = extension;
        std::transform(extension.begin(), extension.end(), filter.begin(), ::toupper);
        filter += " Files(.";
        filter = filter + extension + ")";
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("图片另存为"), "", tr(filter.c_str()));
        if (!fileName.isNull())
        {
            std::ifstream fin(std::string(FIRE_PIC_DIR) + currPicName, std::ios_base::in | std::ios_base::binary);
            std::ofstream fout(fileName.toStdString(), std::ios_base::out | std::ios_base::binary);
            fin.seekg(0, std::ios_base::end);
            long long fileSize = fin.tellg();
            fin.seekg(0, std::ios_base::beg);
            char buf[128];
            long long count = 0;
            while(count < fileSize)
            {
                long long size;
                if (fileSize - count>static_cast<long long>(sizeof(buf)))   size =static_cast<long long>(sizeof(buf));
                else size =fileSize - count;
                //long long size = std::min(fileSize - count, static_cast<long long>(sizeof(buf)));
                fin.read(buf, size);
                fout.write(buf, size);
                count += size;
            }
            fin.close();
            fout.close();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    CountDownDialog* test = new CountDownDialog("测试",10,this);
    test->show();
}
