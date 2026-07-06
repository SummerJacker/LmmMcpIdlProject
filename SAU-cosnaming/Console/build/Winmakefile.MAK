#$Id: Winmakefile.MAK,v 1.3 2025/07/08 03:44:33 cvswxc Exp $
#这是SRIOPProjet下Console 目录下Window下的编译程序
#手工编译命令是  nmake -f Winmakefile.mak ALL 
#自动编译过程中, 会产生 DEBUG RELEASE STUBS等目录 

!IFDEF NODEBUG
CFG=Relase 
!ELSE
CFG=Debug
!ENDIF

BUILD=$(SAU_CONSOLE)


C_STUBBER=$(BUILD)\ilu\bin\c-stubber
STUB_INCLUDE=-I $(BUILD)\Interfaces -I $(BUILD)\ilu\interfaces 

ALL : STUB #LIBRARY EXE 

STUB:
	@cd ..
	@echo making Console STUBS in  $(BUILD)
	@if not exist stubs\nul mkdir stubs
	@nmake /nologo /f  build\Winmakefile.mak GENERATE_STUBS
	@cd build

LIBRARY:
	@echo nothing to do for target LIBRARY in package Ground_Vehicle 

EXE:
	@echo building ground_veihcle server 
	
CLEAN: 
	@echo making CLEAN in package Interfaces using configuration "$(CFG)"
	@cd ..
	@if exist stubs\nul @del /q stubs\*.*
      @if exist Debug\nul @del /q Debug\*.*
	@if exist Debug\nul @rmdir /Q Debug
      @if exist Release\nul @del /q Release\*.*
	@if exist Release\nul @rmdir /Q Release
	@if exist *.opt @del /q *.opt
	@if exist *.ncb @del /q *.ncb
	@if exist *.plg @del /q *.plg	
     	@cd build

CLEANRES: #清除更多的执行文件
        @cd ..
        @if exist  $(BUILD)\bin\XXX.exe @del /q  $(BUILD)\bin\XXX.exe
        @cd build 

STUBS = general_unit ground_unit air_unit console monitor 

GENERATE_STUBS: $(STUBS)

general_unit: $(BUILD)\Interfaces\general_unit.idl
	@cd ..
	$(C_STUBBER) -nodefaulttrueclass $(STUB_INCLUDE) \
		-dir $(BUILD)\Console\stubs  general_unit.idl
	@cd build

ground_unit: $(BUILD)\Interfaces\Ground_Unit.idl
	$(C_STUBBER) -nodefaulttrueclass $(STUB_INCLUDE) \
	-dir $(BUILD)\Console\stubs Ground_Unit.idl

air_unit: $(BUILD)\Interfaces\air_unit.idl
	$(C_STUBBER) -nodefaulttrueclass $(STUB_INCLUDE) \
		-dir $(BUILD)\Console\stubs  air_unit.idl

console: $(BUILD)\Interfaces\console.idl
	$(C_STUBBER) -nodefaulttrueclass $(STUB_INCLUDE) \
		-dir $(BUILD)\Console\stubs  console.idl
	
monitor: $(BUILD)\Interfaces\monitor.idl
	$(C_STUBBER) -nodefaulttrueclass $(STUB_INCLUDE) \
		-dir $(BUILD)\Console\stubs monitor.idl
