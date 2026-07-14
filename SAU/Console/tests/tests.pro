#-------------------------------------------------
# Qt Test Project for Formation System
#-------------------------------------------------
TEMPLATE = app
TARGET = test_formation
CONFIG += testcase
QT += testlib core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS -= -Zc:strictStrings

# MSVC：源码为无 BOM 的 UTF-8，中文 locale 下按 GBK 解析会导致乱码假错，用 /utf-8 修复
win32:!win32-g++ {
    QMAKE_CFLAGS   += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += __STDC_LIMIT_MACROS
DEFINES += UNIT_TEST

#-------------------------------------------------
# Source files
#-------------------------------------------------
SOURCES += \
    test_formation.cpp \
    ../console.cpp \
    ../TaskManager.cpp \
    ../TaskOrchestrator.cpp \
    ../SafetyValidator.cpp \
    ../LegacyIdlAdapter.cpp \
    ../stubs/Air_Unit-common.c \
    ../stubs/Air_Unit-surrogate.c \
    ../stubs/Console-common.c \
    ../stubs/Console-surrogate.c \
    ../stubs/Console-true.c \
    ../stubs/CosNaming-common.c \
    ../stubs/CosNaming-surrogate.c \
    ../stubs/Ground_Unit-common.c \
    ../stubs/Ground_Unit-surrogate.c \
    ../stubs/Monitor-common.c \
    ../stubs/Monitor-surrogate.c \
    ../stubs/Unit-common.c \
    ../stubs/Unit-surrogate.c \
    ../mainwindow.cpp \
    ../MockRobotSimulator.cpp \
    ../agents/contracts/AgentContractsUtil.cpp \
    ../agents/identity/AgentNameNormalizer.cpp \
    ../agents/identity/AliasStore.cpp \
    ../agents/identity/AgentDirectory.cpp

HEADERS += \
    ../console.h \
    ../TaskManager.h \
    ../TaskOrchestrator.h \
    ../SafetyValidator.h \
    ../LegacyIdlAdapter.h \
    ../mainwindow.h \
    ../serverthread.h \
    ../stubs/Monitor.h \
    ../stubs/Console.h \
    ../stubs/CosNaming.h \
    ../stubs/Unit.h \
    ../stubs/Ground_Unit.h \
    ../stubs/Air_Unit.h \
    ../MockRobotSimulator.h \
    ../agents/contracts/AgentContracts.h \
    ../agents/identity/AgentNameNormalizer.h \
    ../agents/identity/AliasStore.h \
    ../agents/identity/AgentDirectory.h

FORMS += ../mainwindow.ui

#-------------------------------------------------
# ILU Library Configuration
#-------------------------------------------------
ILU_INCLUDE = $$PWD/../../Ilu/include
ILU_LIB = $$PWD/../../Ilu/lib

INCLUDEPATH += $$PWD/..
INCLUDEPATH += $$ILU_INCLUDE
DEPENDPATH += $$ILU_INCLUDE

win32 {
    LIBS += -L$$ILU_LIB -lilu32 -liluc32 -lilucpp32 -lparser32
}
