# $Id: WinMakefile.mak,v 1.4 2025/07/05 01:44:55 cvswxc Exp $
# 这是SRIOPProject的全局Window下的编译程序,需要递归到每个上层的各个目录递规执行. 
# 包括Build目录, DEBUG RELEASE STUBBER目录等 

!IFDEF NODEBUG
CFG="Win32 Release"
!ELSE
CFG="Win32 Debug"
!ENDIF


STUBSUBS=  	Ground_Vehicle.stubs Air_Vehicle.stubs Console.stubs
LIBSUBS=   	Ground_Vehicle.libs Air_Vehicle.libs Console.libs
EXESUBS=   	Ground_Vehicle.exes Air_Vehicle.exes Console.exes
CLEANSUBS= 	Ground_Vehicle.cleans Air_Vehicle.clean Console.clean
CLEANRESSUBS= 	Ground_Vehicle.cleanres Air_Vehicle.cleanres Console.sleanres
INSTALLSUBS= 	Ground_Vehicle.installs Air_Vehicle.install Console.install
UNINSTALLSUBS=	Ground_Vehicle.uninstalls Air_Vehicle.uninstall Console.uninstall

ALL : STUB #LIBRARY EXE 

STUB:		$(STUBSUBS)
LIBRARY:	$(LIBSUBS)
EXE:		$(EXESUBS)
CLEAN:	$(CLEANSUBS)

$(STUBSUBS):
	cd ..\$*\build
	nmake /nologo -f WinMakefile.mak $(FLAGS) STUB
      cd ..\..\build

$(LIBSUBS):
	cd ..\$*\build
	nmake /nologo -f WinMakefile.mak $(FLAGS) LIBRARY
      cd ..\..\build

$(EXESUBS): 
	cd ..\$*\build
	nmake /nologo  -f WinMakefile.mak $(FLAGS) EXE
      cd ..\..\build

CLEANMIDS:
        @cd ..\
        @del /S /F /Q .#*.*
        @del /S /F /Q *.*.bak
        @del /S /F /Q *.obj
        @del /S /F /Q *.pch
        @del /S /F /Q *.pdb
        @del /S /F /Q *.idb
        @del /S /F /Q *.sbr
        @del /S /F /Q *.ncb
        @del /S /F /Q *.opt
        @cd ..\..\build

$(CLEANSUBS):
	cd ..\$*\build
	nmake /nologo  -f WinMakefile.mak $(FLAGS) CLEAN
      cd ..\..\build

$(CLEANRESSUBS):
	cd ..\$*\..\build
	nmake /nologo -f WinMakefile.mak  $(FLAGS) CLEANRES
      cd ..\..\build


install: $(INSTALLSUBS)

$(INSTALLSUBS):
	cd ..\$*\build 
	nmake  -f WinMakefile.mak  $(CFG)-install
	cd ..\..\ Build

uninstall:$(UNINSTALLSUBS)

$(UNINSTALLSUBS):
	cd ..\$*\build 
	nmake  -f WinMakefile.mak  $(CFG)-uninstall
	cd ..\..\Build
