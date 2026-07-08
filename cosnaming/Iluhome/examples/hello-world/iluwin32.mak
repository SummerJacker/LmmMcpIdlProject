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

ALL: HELLO-WORLDMAKE ALLC


HELLO-WORLDMAKE:
	c-stubber -I "$(ILUHOME)\interfaces" hello-world.isl
     	python-stubber.exe -I "$(ILUHOME)\interfaces" -quiet  hello-world.isl
	java-stubber -I "$(ILUHOME)\interfaces"  hello-world.isl

clean:CLEANC
    if exist WinDebug\nul del /q WinDebug
    if exist WinDebug\nul rmdir WinDebug
    if exist WinRel\nul del /q Winrel
    if exist WinRel\nul rmdir Winrel


# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103


!IF "$(CFG)" != "Win32 Release" && "$(CFG)" !="Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "client.mak" CFG="Win32 Debug"
!MESSAGE NMAKE /f "server.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "WinRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "WinRel"
# PROP Target_Dir ""
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALLC: "$(OUTDIR)\client.exe" "$(OUTDIR)\server.exe"

CLEANC: 
	-@erase "$(INTDIR)\client.obj"
	-@erase "$(INTDIR)\server.obj"
	-@erase "$(INTDIR)\hello_world-common.obj"
	-@erase "$(INTDIR)\hello_world-surrogate.obj"
	-@erase "$(INTDIR)\hello_world-true.obj"
	-@erase "$(OUTDIR)\client.exe"
	-@erase "$(OUTDIR)\server.exe"
	if exist hello_world.h del /q hello_world.h 
	if exist hello_world.py del /q hello_world.py	
	if exist hello_world__skel.py del /q hello_world__skel.py
	if exist hello_world-common.c del /q hello_world-common.c
	if exist hello_world-surrogate.c del /q hello_world-surrogate.c
	if exist hello_world-true.c del /q hello_world-true.c 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "$(ILUHOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "$(ILUHOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE"\
 /Fp"$(INTDIR)/client.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/client.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\client.sbr" \
	"$(INTDIR)\hello_world-common.sbr" \
	"$(INTDIR)\hello_world-surrogate.sbr"

"$(OUTDIR)\client.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
LINK32_FLAGS=$(ILUHOME)\lib\ilu32.lib $(ILUHOME)\lib\iluc32.lib\
 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/client.pdb" /machine:I386 /out:"$(OUTDIR)/client.exe" 
LINK32_OBJS= \
	"$(INTDIR)\client.obj" \
	"$(INTDIR)\hello_world-common.obj" \
	"$(INTDIR)\hello_world-surrogate.obj" 

"$(OUTDIR)\client.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/server.bsc" 
BSC32_SBRS= \

LINK32_FLAGS= \
	"$(INTDIR)\server.sbr" \
	"$(INTDIR)\hello_world-common.sbr" \
	"$(INTDIR)\hello_world-true.sbr"

"$(OUTDIR)\server.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32_FLAGS=$(ILUHOME)\lib\iluc32.lib $(ILUHOME)\lib\ilu32.lib\
 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/server.pdb" /machine:I386 /out:"$(OUTDIR)/server.exe" 
LINK32_OBJS= \
	"$(INTDIR)\server.obj" \
	"$(INTDIR)\hello_world-common.obj" \
	"$(INTDIR)\hello_world-true.obj"

"$(OUTDIR)\server.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "WinDebug"
# PROP Target_Dir ""
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALLC: "$(OUTDIR)\client.exe"  "$(OUTDIR)\server.exe"


CLEANC: 
	-@erase "$(INTDIR)\client.obj"
	-@erase "$(INTDIR)\client.sbr"
	-@erase "$(INTDIR)\hello_world-common.obj"
	-@erase "$(INTDIR)\hello_world-common.sbr"
	-@erase "$(INTDIR)\hello_world-surrogate.obj"
	-@erase "$(INTDIR)\hello_world-surrogate.sbr"
	-@erase "$(INTDIR)\hello_world-true.obj"
	-@erase "$(INTDIR)\hello_world-true.sbr"
	-@erase "$(INTDIR)\server.obj
	-@erase "$(INTDIR)\server.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\client.bsc"
	-@erase "$(OUTDIR)\client.exe"
	-@erase "$(OUTDIR)\client.ilk"
	-@erase "$(OUTDIR)\client.pdb"
	-@erase "$(OUTDIR)\server.bsc"
	-@erase "$(OUTDIR)\server.exe"
	-@erase "$(OUTDIR)\server.ilk"
	-@erase "$(OUTDIR)\server.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MD /W3 /Gm /GX /Zi /Od /I "$(ILUHOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /MD /W3 /Gm /GX /Zi /Od \
 /I "$(ILUHOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" \
 /Fp"$(INTDIR)/client.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/

# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/client.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\client.sbr" \
	"$(INTDIR)\hello_world-common.sbr" \
	"$(INTDIR)\hello_world-surrogate.sbr"

"$(OUTDIR)\client.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 $(ILUHOME)\lib\ilucpp2.lib $(ILUHOME)\lib\ilu32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=$(ILUHOME)\lib\ilu32.lib $(ILUHOME)\lib\iluc32.lib\
 msvcirt.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/client.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/client.exe" 
LINK32_OBJS= \
	"$(INTDIR)\client.obj" \
	"$(INTDIR)\hello_world-common.obj" \
	"$(INTDIR)\hello_world-surrogate.obj"

"$(OUTDIR)\client.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/server.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\server.sbr" \
	"$(INTDIR)\hello_world-common.sbr" \
	"$(INTDIR)\hello_world-true.sbr"

"$(OUTDIR)\server.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 $(ILUHOME)\lib\iluc32.lib $(ILUHOME)\lib\ilu32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=$(ILUHOME)\lib\iluc32.lib $(ILUHOME)\lib\ilu32.lib\
 msvcirt.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/server.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/server.exe" 
LINK32_OBJS= \
	"$(INTDIR)\server.obj" \
	"$(INTDIR)\hello_world-common.obj" \
	"$(INTDIR)\hello_world-true.obj"

"$(OUTDIR)\server.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Win32 Release"
# Name "Win32 Debug"

################################################################################
# Begin Source File

SOURCE=.\client.c

!IF  "$(CFG)" == "Win32 Release"

DEP_CPP_client=\
	"$(ILUHOME)\include\iluhash.h"\
	"$(ILUHOME)\include\ilubasic.h"\
	"$(ILUHOME)\include\iludebug.h"\
	"$(ILUHOME)\include\iluerror.h"\
	"$(ILUHOME)\include\iluerrs.h"\
	"$(ILUHOME)\include\iluntrnl.h"\
	"$(ILUHOME)\include\iluwin.h"\
	"$(ILUHOME)\include\iluxport.h"\
	"$(ILUHOME)\include\corba-templates.hpp"\
	"$(ILUHOME)\include\corba.hpp"\
	"$(ILUHOME)\include\cppportability.hpp"\
	"$(ILUHOME)\include\ilu.hpp"\
	".\hello_world.h"\
	
NODEP_CPP_client=\
	"$(ILUHOME)\include\ilutypes.h"\
	

"$(INTDIR)\client.obj" : $(SOURCE) $(DEP_CPP_client) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Win32 Debug"

DEP_CPP_client=\
	"$(ILUHOME)\include\corba.hpp"\
	".\hello_world.h"	

BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\client.obj" : $(SOURCE) $(DEP_CPP_client) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\client.sbr" : $(SOURCE) $(DEP_CPP_client) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 


SOURCE=".\server.c"

!IF  "$(CFG)" == "Win32 Release"

DEP_CPP_server_=\
	"$(ILUHOME)\include\iluhash.h"\
	"$(ILUHOME)\include\ilubasic.h"\
	"$(ILUHOME)\include\iludebug.h"\
	"$(ILUHOME)\include\iluerror.h"\
	"$(ILUHOME)\include\iluerrs.h"\
	"$(ILUHOME)\include\iluntrnl.h"\
	"$(ILUHOME)\include\iluwin.h"\
	"$(ILUHOME)\include\iluxport.h"\
	"$(ILUHOME)\include\corba-templates.hpp"\
	"$(ILUHOME)\include\corba.hpp"\
	"$(ILUHOME)\include\cppportability.hpp"\
	"$(ILUHOME)\include\ilu.hpp"\
	".\hello_world.h"\


NODEP_CPP_server_=\
	"$(ILUHOME)\include\ilutypes.h"\
	

"$(INTDIR)\server.obj" : $(SOURCE) $(DEP_CPP_server_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Win32 Debug"

DEP_CPP_server_=\
	"$(ILUHOME)\include\corba.hpp"\
	".\hello_world.h"\
	

BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\server.obj" : $(SOURCE) $(DEP_CPP_server_) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\server.sbr" : $(SOURCE) $(DEP_CPP_server_) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
