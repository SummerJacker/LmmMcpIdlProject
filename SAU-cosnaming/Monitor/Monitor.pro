#-------------------------------------------------
#
# Project created by QtCreator 2021-07-05T09:21:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Monitor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += _CRT_SECURE_NO_WARNINGS

DEFINES += __STDC_LIMIT_MACROS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
QMAKE_CXXFLAGS -= -Zc:strictStrings

# MSVC：源码为无 BOM 的 UTF-8，中文 locale 下按 GBK 解析会导致乱码假错，用 /utf-8 修复
win32:!win32-g++ {
    QMAKE_CFLAGS   += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    SRIO-Monitor-cpp.cpp \
    SRIO-Monitor-cpptrue.cpp \
    SRIO-Air-Unit-cpp.cpp \
    SRIO-Console-cpp.cpp \
    SRIO-Ground-Unit-cpp.cpp \
    SRIO-Unit-cpp.cpp \
    monitorImpl.cpp \
    picturewindow.cpp \
    countdowndialog.cpp

HEADERS += \
        mainwindow.h \
    SRIO-Monitor-cpp.hpp \
    SRIO-Monitor-cpptrue.hpp \
    SRIO-Ground-Unit-cpp.hpp \
    SRIO-Air-Unit-cpp.hpp \
    SRIO-Console-cpp.hpp \
    SRIO-Unit-cpp.hpp \
    monitorImpl.h \
    serverthread.h \
    picturewindow.h \
    countdowndialog.h

FORMS += \
        mainwindow.ui \
    picturewindow.ui \
    countdowndialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../ilu/lib/ilu32.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/../ilu/lib/ilu32.a

#win32: LIBS += -L$$PWD/../ilu/lib/ -liluc32

#INCLUDEPATH += $$PWD/../ilu/include
#DEPENDPATH += $$PWD/../ilu/include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../ilu/lib/iluc32.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/../ilu/lib/libiluc32.a

win32: LIBS += -L$$PWD/../lib/ -lilu32

INCLUDEPATH += $$PWD/../ilu/include
DEPENDPATH += $$PWD/../ilu/include

win32: LIBS += -L$$PWD/../ilu/lib/ -lilucpp2

INCLUDEPATH += $$PWD/../ilu/include
DEPENDPATH += $$PWD/../ilu/include
