#ifndef GROUND_CONSOLE_H_
#define GROUND_CONSOLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "stubs\Console.h"
#include "stubs\Unit.h"
#include "stubs\Ground_Unit.h"
#include "stubs\Air_Unit.h"
#include <QApplication>
#include <QString>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#define MAX_POINT_NUM 10
#define MAX_TRAP_POINT_NUM 20
#define MAX_VEHICLE_NUM 10
#define MAX_UNIT_NUM 23
#define RECONNECT_TIME 3
#define MAX_UNITID_LENGTH 21
#define MAX_UNITSBH_LENGTH 257

extern ilu_HashTable Units_Hash_Table;

void displayBoundUnit();
ilu_boolean getUnitObject(Unit_UnitID uid);
bool setToLeader();
bool romoteControl();
bool sendCommandSeq();
bool setGroupMode(Unit_UnitMode mode);
bool setGroupMinorMode(Unit_UnitMinorMode minorMode);

bool setFormation(Unit_Formation* formation);
bool setTaskPoint(float x, float y);
bool setTrap(Console_TrapPoint trap);
bool clearTraps();
void setDefault();
void shutDownAllUnit();
void stopUnit();
void usage(char* prom);
void getLocalIP();

/** @brief 测试用：将逗号分隔的 unit_id（如 GV1,GV2）注册为 MOCK:单元，不写 BackupFile */
void registerMockRobotsForTest(const QString &commaSeparatedUnitIds);

#endif
