haiyou#-------------------------------------------------
# 项目名称与模板类型
#-------------------------------------------------
TEMPLATE = app                 # 应用程序模板
TARGET = main_console        # 生成的可执行文件名

#-------------------------------------------------
# Qt 模块配置
#-------------------------------------------------
QT += core gui network         # 启用

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  # 启用 QtWidgets（Qt5 及以上）

#-------------------------------------------------
# 编译配置
#-------------------------------------------------
CONFIG += c++11                        # 启用 C++11 标准
QMAKE_CXXFLAGS -= -Zc:strictStrings    # 关闭严格字符串检查（MSVC 特有）

# MSVC：源码为「无 BOM 的 UTF-8」，中文 locale 下 MSVC 默认按 GBK 代码页解析，
# 会把 UTF-8 中文注释的多字节误判，导致后续正常代码报出乱码标识符、C3927/C2447 等假错。
# /utf-8 同时设置 source-charset 与 execution-charset 为 UTF-8，从根本上修复。
win32:!win32-g++ {
    QMAKE_CFLAGS   += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

# MSVC：用 cmd 包装 link，注入 SDK 下 rc.exe 所在 PATH（修复 LNK1158；不依赖 console.pro.user 里 RC/PATH 是否被 Qt Creator 覆盖）
win32:!win32-g++ {
    QMAKE_LINK = cmd.exe /C $$shell_path($$PWD/msvc-link-rc.cmd)
}

#-------------------------------------------------
# 宏定义：控制编译警告、安全函数等
#-------------------------------------------------
DEFINES += QT_DEPRECATED_WARNINGS      # 使用 Qt 标记为 deprecated 的 API 时输出警告
DEFINES += __STDC_LIMIT_MACROS         # 启用 stdint.h 的某些宏定义（如 UINT64_MAX）
#DEFINES += _CRT_SECURE_NO_WARNINGS     # 关闭 MSVC 对不安全函数（如 strcpy/fopen）的警告


#-------------------------------------------------
# 项目源文件
#-------------------------------------------------
SOURCES += \
    stubs\Air_Unit-common.c \
    stubs\Air_Unit-surrogate.c \
    #stubs\Air_Unit-true.c \
    stubs\Console-common.c \
    stubs\Console-surrogate.c \
    stubs\Console-true.c \
    stubs\CosNaming-common.c \
    stubs\CosNaming-surrogate.c \
    stubs\Ground_Unit-common.c \
    stubs\Ground_Unit-surrogate.c \
    #stubs\Ground_Unit-true.c \
    stubs\Monitor-common.c \
    stubs\Monitor-surrogate.c \
    #stubs\Monitor-true.c \
    stubs\Unit-common.c \
    stubs\Unit-surrogate.c \
    #stubs\Unit-true.c \
    console.cpp \
    serverthread.cpp \
    HttpApiExecutor.cpp \
    HttpPlugin.cpp \
    MockRobotSimulator.cpp \
    LegacyIdlAdapter.cpp \
    TaskOrchestrator.cpp \
    TaskManager.cpp \
    SafetyValidator.cpp \
    mainwindow.cpp \
    FormationTopologyView.cpp \
    agents/identity/AgentNameNormalizer.cpp \
    agents/identity/AliasStore.cpp \
    agents/identity/AgentDirectory.cpp \
    agents/status/MockStatusProbe.cpp \
    agents/status/GroundStatusProbe.cpp \
    agents/status/AirStatusProbe.cpp \
    agents/status/AgentStatusService.cpp \
    agents/http/AgentHttpController.cpp \
    agents/contracts/AgentContractsUtil.cpp

#-------------------------------------------------
# 项目头文件
#-------------------------------------------------
HEADERS += \
    stubs\Monitor.h \
    stubs\Console.h \
    stubs\CosNaming.h \
    stubs\Unit.h \
    stubs\Ground_Unit.h \
    stubs\Air_Unit.h \
    console.h \
    HttpApiExecutor.h \
    HttpPlugin.h \
    MockRobotSimulator.h \
    LegacyIdlAdapter.h \
    TaskOrchestrator.h \
    TaskManager.h \
    SafetyValidator.h \
    mainwindow.h \
    FormationTopologyView.h \
    serverthread.h \
    agents/contracts/AgentContracts.h \
    agents/identity/AgentNameNormalizer.h \
    agents/identity/AliasStore.h \
    agents/identity/AgentDirectory.h \
    agents/status/MockStatusProbe.h \
    agents/status/GroundStatusProbe.h \
    agents/status/AirStatusProbe.h \
    agents/status/AgentStatusService.h \
    agents/http/AgentHttpController.h

#-------------------------------------------------
# UI 表单文件（供 Qt Designer 使用）
#-------------------------------------------------
FORMS += mainwindow.ui

RESOURCES += xy2d_monitor.qrc


#-------------------------------------------------
# ILU 库配置（用于链接 ilu 和 iluc）
#-------------------------------------------------

# 统一路径变量设置
ILU_INCLUDE = $$PWD/../ilu/include
ILU_LIB     = $$PWD/../ilu/lib

# MinGW：勿把 ILU 放在普通 -I 最前，否则 <pthread.h> 会吃到 Ilu/include 里 pthreads-win32 的头，
# 与 GCC/libstdc++ 期望的 winpthreads 不一致，导致 std_thread.h 中 native_handle 无法 ==。
win32-g++ {
    ILU_INC_AFTER = $$shell_path($$ILU_INCLUDE)
    QMAKE_CFLAGS   += -idirafter $$ILU_INC_AFTER
    QMAKE_CXXFLAGS += -idirafter $$ILU_INC_AFTER
    DEPENDPATH += $$ILU_INCLUDE
} else {
    INCLUDEPATH += $$ILU_INCLUDE
    DEPENDPATH  += $$ILU_INCLUDE
}

win32 {
    # MinGW：仅识别 -lxxx（对应 libxxx.a）；-ilucpp32、xxx.lib 会被当成非法编译选项传给 gcc
    win32-g++ {
        message("SAU Console: 若链接报 skipping incompatible ilu32*.lib：库为 32 位而当前为 64 位 MinGW。请改用 Qt 的 MSVC 32-bit 套件，或自备与 MinGW 同架构的 ILU（lib*.a）。")
        LIBS += -L$$ILU_LIB -lilu32 -liluc32 -lilucpp32 -lparser32 -lilupr -lws2_32
    } else {
        # 方案A：Qt **MSVC 32-bit** 套件 + 本仓库 ilu32*.lib（与 iluwin.h 中 SIZEOF_VOID_P 等 32 位配置一致）
        message("SAU Console: MSVC link branch. Use Qt MSVC 32-bit kit (e.g. Qt 5.15.2 MSVC2019 32bit). Do not use MinGW or MSVC 64-bit.")
        LIBS += $$ILU_LIB/ilu32.lib \
            $$ILU_LIB/iluc32.lib \
            $$ILU_LIB/ilucpp32.lib \
            $$ILU_LIB/parser32.lib \
            $$ILU_LIB/ilupr.lib \
            ws2_32.lib
        PRE_TARGETDEPS += $$ILU_LIB/ilu32.lib \
            $$ILU_LIB/iluc32.lib \
            $$ILU_LIB/ilucpp32.lib \
            $$ILU_LIB/parser32.lib
    }
}

#-------------------------------------------------
# ILU 运行时 DLL（与 ilu32.lib 等配套的 ilu32.dll、iluc32.dll…）
# 说明：仅 .lib 可成功链接；若运行目录与 PATH 中无对应 DLL，进程常在进入 main 之前即失败，
#       Qt Creator 表现为「程序异常结束 / crashed」。
# 请将官方/本机构建的 32 位 ILU DLL 放到 ../ilu/bin/，重新 qmake 后构建会自动复制到 debug/release。
#-------------------------------------------------
ILU_DLL_DIR = $$PWD/../ilu/bin
win32:!win32-g++ {
    !exists($$ILU_DLL_DIR/ilu32.dll) {
        warning("未在 $$ILU_DLL_DIR 发现 ilu32.dll：运行时极易立即崩溃。请将 ILU 的 32 位 DLL（ilu32、iluc32、ilucpp32、parser32 等）放入该目录后重新构建，或将其目录加入系统 PATH 并在 Qt Creator「运行」环境变量中同步配置。")
    } else {
        CONFIG(debug, debug|release) {
            ILU_DLL_DEST = $$OUT_PWD/debug
        } else {
            ILU_DLL_DEST = $$OUT_PWD/release
        }
        QMAKE_POST_LINK += $$escape_expand(\\n\\t)cmd /c if exist \"$$shell_path($$ILU_DLL_DIR)\\ilu32.dll\" copy /Y \"$$shell_path($$ILU_DLL_DIR)\\*.dll\" \"$$shell_path($$ILU_DLL_DEST)\\\"
    }
}

#-------------------------------------------------
# 安装路径（用于部署阶段）
#-------------------------------------------------
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
