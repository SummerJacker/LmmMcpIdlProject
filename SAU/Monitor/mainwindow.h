#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "monitorImpl.h"
//#include <windows.h>

#define CH(str) (QString::fromLocal8Bit(str))

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr, MonitorImpl* = nullptr, QThread* = nullptr);

    ~MainWindow();
    //set monitorPtr and connect signals and slots
    void setMonitorPtr(MonitorImpl* mptr) { monitorPtr = mptr; }

    void setServerThread(QThread* t) { serverThread = t; }

    bool init();

public slots:

    void displayMsg(std::string);

    void updateTrapsListView();

    void updateUnitsStateListView();

    void updateFireEventsListView();

    // update picLabel, firePicComboBox, fireEventLabel, firePicTimestampLabel
    void displayNewestPictureRelatives(std::string,const PicList*);

    void displayNewestPhoto(std::string);

    void openCountDownWindow(std::string, unsigned int);

private slots:

    void on_fireEventListView_clicked(const QModelIndex &index);

    void on_firePicsListComboBox_currentIndexChanged(const QString &arg1);

    void on_newWinPushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:

     void closeEvent(QCloseEvent *event);

private:

    Ui::MainWindow *ui;

    MonitorImpl* monitorPtr;
    //timer used for update the UnitsStateListView 200ms
    QTimer unitsStateUpdateTimer;
    //use signal slot for low frequent action, user timer for high frequent action?
    QThread* serverThread;

    const PicList* currPicListPtr;

    std::string currPicName;
};

extern char stateStr[10][40];
extern const char* FIRE_PIC_DIR;

#endif // MAINWINDOW_H
