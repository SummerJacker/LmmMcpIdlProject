# $Id: iluwin32.mak,v 1.5 2025/08/02 10:00:49 cvswxc Exp $
# Top level makefile to build Win32 version of ILU using
# Microsoft Visual C++
#
# Assumes your PATH has the appropriate bin directory in it (e.g. msvc\bin)
# Assumes your INCLUDE environment variable includes the appropriate directories (e.g. msvc\include) 
# Assumes your LIB environment variable includes the appropriate directories (e.g. msvc\lib) 

!IF "$(CFG)" == ""
CFG=Win32 Release
!MESSAGE No configuration specified.  Defaulting to Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "iluwin32.mak" CFG="Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release"
!MESSAGE "Win32 Debug"
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 



################################################################################

!IF "$(JAVA_HOME)" == ""
!MESSAGE JAVA_HOME environment variable not set, not building Java example
ALL : TEST1MAKE
!ELSE
ALL : TEST1MAKE JAVAMAKE
!ENDIF 


TEST1MAKE :
	c-stubber -I $(ILUHOME)\interfaces Test1.isl
	c-stubber -I $(ILUHOME)\interfaces Test2.isl
	c-stubber -I $(ILUHOME)\interfaces Test3.isl
	nmake -f clnt.mak CFG="$(CFG)"
	nmake -f clntw.mak CFG="$(CFG)"
	nmake -f srvr.mak CFG="$(CFG)"
	nmake -f srvrw.mak CFG="$(CFG)"
	c++-stubber   Test1.isl
	c++-stubber   Test2.isl
	c++-stubber   Test3.isl
	nmake -f cppclnt.mak CFG="$(CFG)"
	nmake -f cppclntw.mak CFG="$(CFG)"
	nmake -f cppsrvr.mak CFG="$(CFG)"
	nmake -f cppsrvrw.mak CFG="$(CFG)"
	python-stubber  Test1.isl
	python-stubber  Test2.isl
	python-stubber  Test3.isl
	cpp2-stubber   Test1.isl
	cpp2-stubber   Test2.isl
	cpp2-stubber   Test3.isl
	nmake -f cpp2clnt.mak CFG="$(CFG)"
	nmake -f cpp2srvr.mak CFG="$(CFG)"


JAVAMAKE:
	nmake -f javawin32.mak CFG="$(CFG)"


clean :
    if exist WinDebug\nul del /q WinDebug\*
    if exist WinDebug\nul rmdir WinDebug
    if exist WinRel\nul del /q Winrel\*
    if exist WinRel\nul rmdir /Q Winrel
    if exist WinDebugW\nul del /q WinDebugW\*
    if exist WinDebugW\nul rmdir /Q WinDebugW
    if exist WinRelW\nul del /q WinrelW\*
    if exist WinRelW\nul rmdir WinrelW
    if exist classes\nul rmdir /Q classes /s
    if exist javastubs\nul rmdir /Q javastubs /s
    if exist Test1.h del /q Test1.h 
    if exist Test1.cpp del /q Test1.cpp
    if exist Test1.hh del /q Test1.hh 
    if exist Test1.py del /q Test1.py 
    if exist Test1__skel.py del /q Test1__skel.py 
    if exist Test1-common.c del /q Test1-common.c
    if exist Test1-cpp.hpp del /q Test1-cpp.hpp
    if exist Test1-cpp.cpp del /q Test1-cpp.cpp 
    if exist Test1-cppsurrogate.hpp del /q Test1-cppsurrogate.hpp
    if exist Test1-cppsurrogate.cpp del /q Test1-cppsurrogate.cpp 
    if exist Test1-cpptrue.hpp del /q Test1-cpptrue.hpp
    if exist Test1-cpptrue.cpp del /q Test1-cpptrue.cpp 
    if exist Test1-server-stubs.cpp del /q Test1-server-stubs.cpp
    if exist Test1-surrogate.c del /q Test1-surrogate.c
    if exist Test1-true.c del /q Test1-true.c 
    if exist Test2.h del /q Test2.h 
    if exist Test2.cpp del /q Test2.cpp
    if exist Test2.hh del /q Test2.hh 
    if exist Test2.py del /q Test2.py 
    if exist Test2__skel.py del /q Test2__skel.py 
    if exist Test2-common.c del /q Test2-common.c
    if exist Test2-cpp.hpp del /q Test2-cpp.hpp
    if exist Test2-cpp.cpp del /q Test2-cpp.cpp 
    if exist Test2-cppsurrogate.hpp del /q Test2-cppsurrogate.hpp
    if exist Test2-cppsurrogate.cpp del /q Test2-cppsurrogate.cpp 
    if exist Test2-cpptrue.hpp del /q Test2-cpptrue.hpp
    if exist Test2-cpptrue.cpp del /q Test2-cpptrue.cpp 
    if exist Test2-server-stubs.cpp del /q Test2-server-stubs.cpp
    if exist Test2-surrogate.c del /q Test2-surrogate.c
    if exist Test2-true.c del /q Test2-true.c
    if exist Test3.h del /q Test3.h 
    if exist Test3.cpp del /q Test3.cpp
    if exist Test3.hh del /q Test3.hh 
    if exist Test3.py del /q Test3.py 
    if exist Test3__skel.py del /q Test3__skel.py 
    if exist Test3-common.c del /q Test3-common.c
    if exist Test3-cpp.hpp del /q Test3-cpp.hpp
    if exist Test3-cpp.cpp del /q Test3-cpp.cpp 
    if exist Test3-cppsurrogate.hpp del /q Test3-cppsurrogate.hpp
    if exist Test3-cppsurrogate.cpp del /q Test3-cppsurrogate.cpp 
    if exist Test3-cpptrue.hpp del /q Test3-cpptrue.hpp
    if exist Test3-cpptrue.cpp del /q Test3-cpptrue.cpp 
    if exist Test3-server-stubs.cpp del /q Test3-server-stubs.cpp
    if exist Test3-surrogate.c del /q Test3-surrogate.c
    if exist Test3-true.c del /q Test3-true.c

# End 
################################################################################
