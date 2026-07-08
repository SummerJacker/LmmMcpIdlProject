# $Id: iluwin32.mak,v 1.7 2025/08/07 13:51:06 cvswxc Exp $
# Top level makefile to build Win32 version of ILU examples using
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

OUTDIR=WinDebug
!IF "$(CFG)" == "Win32 Release" 
OUTDIR=WinRel
!ENDIF


################################################################################

IDLPATH= -I $(ILUHOME)\interfaces;$(ILUHOME)\examples\httest

ALL : HTTESTMAKE


HTTESTMAKE :
	c-stubber $(IDLPATH) iluhttp.isl
	c-stubber $(IDLPATH) httest.isl
	nmake -f htclient.mak CFG="$(CFG)"  
	nmake -f htserver.mak CFG="$(CFG)"  
	nmake -f webserver.mak CFG="$(CFG)" 
	nmake -f ilugetbot.mak CFG="$(CFG)" 


clean :
    if exist  $(OUTDIR)\nul del /q $(OUTDIR)\*
    if exist  $(OUTDIR)\nul rmdir /Q  $(OUTDIR)
    if exist httest.h 		del /q httest.h 
    if exist httest-common.c 	del /q httest-common.c 
    if exist httest-surrogate.c 	del /q httest-surrogate.c 
    if exist httest-true.c 	del /q httest-true.c 
    if exist iluhttp.h 		del /q iluhttp.h 
    if exist iluhttp-common.c 	del /q iluhttp-common.c 
    if exist iluhttp-surrogate.c 	del /q iluhttp-surrogate.c 
    if exist iluhttp-true.c 	del /q iluhttp-true.c 

# End 
################################################################################
