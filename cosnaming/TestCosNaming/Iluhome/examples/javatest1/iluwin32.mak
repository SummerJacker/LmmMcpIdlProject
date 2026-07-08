# $Id: iluwin32.mak,v 1.4 2025/08/02 11:45:15 cvswxc Exp $
# Top level makefile to build Win32 version of ILU javatest1 example

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

!MESSAGE NOTE: that only the Java version of the javatest1 example 
!MESSAGE is set up to be built with this makefile

!IF "$(JAVA_HOME)" == ""
!MESSAGE JAVA_HOME environment variable not set, not building Java example
ALL : 
!ELSE
ALL : JAVAMAKE
!ENDIF



JAVAMAKE:
	if not exist ilu.isl copy $(ILUHOME)\interfaces\ilu.isl ilu.isl 
	nmake -f javawin32.mak CFG="$(CFG)"


clean :
    if exist classes\nul rmdir /Q classes /s
    if exist javastubs\nul rmdir /Q javastubs /s
    if exist ilu.isl del /q ilu.isl 



# End 
################################################################################
