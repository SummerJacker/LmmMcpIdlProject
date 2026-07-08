# Microsoft Developer Studio Generated NMAKE File, Based on ILUCosNaming.dsp
!IF "$(CFG)" == ""
CFG=ILUCosNaming - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ILUCosNaming - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ILUCosNaming - Win32 Release" && "$(CFG)" != "ILUCosNaming - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ILUCosNaming.mak" CFG="ILUCosNaming - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ILUCosNaming - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ILUCosNaming - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ILUCosNaming - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ILUCosNaming.exe"


CLEAN :
	-@erase "$(INTDIR)\CosNaming-common.obj"
	-@erase "$(INTDIR)\CosNaming-surrogate.obj"
	-@erase "$(INTDIR)\CosNaming-true.obj"
	-@erase "$(INTDIR)\NamingImpl.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ILUCosNaming.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /GX /O2 /I "..\..\runtime\kernel" /I "..\..\runtime\c" /I "..\..\GSS\kernel" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\ILUCosNaming.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ILUCosNaming.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=iluc32.lib ilu32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\ILUCosNaming.pdb" /machine:I386 /out:"$(OUTDIR)\ILUCosNaming.exe" /libpath:"..\..\..\..\build\ilu\lib" 
LINK32_OBJS= \
	"$(INTDIR)\NamingImpl.obj" \
	"$(INTDIR)\CosNaming-common.obj" \
	"$(INTDIR)\CosNaming-surrogate.obj" \
	"$(INTDIR)\CosNaming-true.obj"

"$(OUTDIR)\ILUCosNaming.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\ILUCosNaming.exe"
   cp -f Release\ILUCosNaming.exe "$(ILUHOME)\bin\ILUCosNaming.exe"
   echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)")

!ELSEIF  "$(CFG)" == "ILUCosNaming - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ILUCosNaming.exe"


CLEAN :
	-@erase "$(INTDIR)\CosNaming-common.obj"
	-@erase "$(INTDIR)\CosNaming-surrogate.obj"
	-@erase "$(INTDIR)\CosNaming-true.obj"
	-@erase "$(INTDIR)\NamingImpl.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ILUCosNaming.exe"
	-@erase "$(OUTDIR)\ILUCosNaming.ilk"
	-@erase "$(OUTDIR)\ILUCosNaming.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /Gm /GX /ZI /Od /I "..\..\runtime\kernel" /I "..\..\runtime\c" /I "..\..\GSS\kernel" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\ILUCosNaming.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ILUCosNaming.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=iluc32.lib ilu32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\ILUCosNaming.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ILUCosNaming.exe" /pdbtype:sept /libpath:"..\..\..\..\build\ilu\lib" 
LINK32_OBJS= \
	"$(INTDIR)\NamingImpl.obj" \
	"$(INTDIR)\CosNaming-common.obj" \
	"$(INTDIR)\CosNaming-surrogate.obj" \
	"$(INTDIR)\CosNaming-true.obj"

"$(OUTDIR)\ILUCosNaming.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\ILUCosNaming.exe"
   cp -f  Debug\ILUCosNaming.exe "$(ILUHOME)\bin\ILUCosNaming.exe"
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ILUCosNaming.dep")
!INCLUDE "ILUCosNaming.dep"
!ELSE 
!MESSAGE Warning: cannot find "ILUCosNaming.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ILUCosNaming - Win32 Release" || "$(CFG)" == "ILUCosNaming - Win32 Debug"
SOURCE=.\NamingImpl.c

"$(INTDIR)\NamingImpl.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=".\CosNaming-common.c"

"$(INTDIR)\CosNaming-common.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=".\CosNaming-surrogate.c"

"$(INTDIR)\CosNaming-surrogate.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=".\CosNaming-true.c"

"$(INTDIR)\CosNaming-true.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

