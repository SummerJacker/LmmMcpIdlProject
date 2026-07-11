#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Include windows.h first to ensure SIZE_T is defined before ILU headers
#include <windows.h>

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
#include <QTextCodec>
#include "ui_mainwindow.h"
#include "stubs\Unit.h"
#include "stubs\Ground_Unit.h"
#include "stubs\Air_Unit.h"
#include "stubs\Console.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void hideallframe();
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private slots:

    void updateBrowser(QString str);

    void appendInfo(QString str);

    void on_PBtnSetLeaderPage_clicked();

    void on_PBtnRemotePage_clicked();

    void on_PBtnFollowPage_clicked();

    void on_PBtnSetFormation_clicked();

    void on_PBtnSetDestination_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_PBtnClearAllCache_clicked();

    void on_pushButton_2_clicked();

    void on_PBtnSimulateModel_clicked();

    void on_PBtnFollowModel_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void addFormationUnit();

    void on_pushButton_21_clicked();

    void on_PBtnTrapSet_clicked();

    void on_pushButton_24_clicked();

    void on_PBtnTargetTrack_clicked();

    void on_PBtnTrajectoryTrack_clicked();

    void on_PBtnCloseAllPrograms_clicked();

    void on_PBtnResetAllUnits_clicked();

    void resetFormation();

    void sendFormation();

    void on_taskPathSendButton_clicked();

    void showPhotoWindow();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_50_clicked();

    void addAirFollower();

    void removeAirFollower();

    void on_pushButton_36_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_82_clicked();

    void on_pushButton_81_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();


public:

    Console_PointSeq* path;

    // Unit_Formation* formation;  // 已改为使用全局变量，不再使用类成员变量

    Unit_UnitSBHSeq* unitSBHSeq;

    //SRIO_Air_Unit_Air_Unit_Formation* airFormation;

    int pointsCount;

    int currentPointsCount;

    int currentUnitCount;

    int currentControlledCount;

    Ui::MainWindow *ui;

    CORBA_long procedureStartTime;
};

#endif // MAINWINDOW_H
