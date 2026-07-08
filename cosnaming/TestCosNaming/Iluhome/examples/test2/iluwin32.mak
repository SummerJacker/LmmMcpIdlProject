# $Id: iluwin32.mak,v 1.5 2025/08/01 09:21:55 cvswxc Exp $
# Top level makefile to build the TEST2 example programs (bclient, bserver, fibber)
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
ISLIDL= -I $(ILUHOME)\Interfaces;$(ILUHOME)\examples\test2

ALL : TEST2MAKE

TEST2MAKE :
	if not  exist ilu.isl copy $(ILUHOME)\interfaces\ilu.isl ilu.isl 
	c-stubber -I .  Fibber.isl
	nmake -f fibber.mak CFG="$(CFG)"
	c-stubber -I .  Batcher.isl
	nmake -f bclient.mak CFG="$(CFG)"
	nmake -f bserver.mak CFG="$(CFG)"
	nmake -f bclientp.mak CFG="$(CFG)"

clean :
    if exist WinDebug\nul del /q WinDebug\*
    if exist WinDebug\nul rmdir WinDebug
    if exist WinRel\nul del /q Winrel\*
    if exist WinRel\nul rmdir Winrel
    if exist  Batcher.h del /q Batcher.h 
    if exist  Batcher-common.c del /q Batcher-common.c 
    if exist  Batcher-surrogate.c del /q Batcher-surrogate.c 
    if exist  Batcher-true.c del /q Batcher-true.c 
    if exist  Fibber.h del /q Fibber.h 
    if exist  Fibber-common.c del /q Fibber-common.c 
    if exist  Fibber-surrogate.c del /q Fibber-surrogate.c 
    if exist  Fibber-true.c del /q Fibber-true.c 

# End 
################################################################################
