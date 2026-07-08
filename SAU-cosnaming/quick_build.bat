@echo off
call "D:\Application\Visual Studio\other_data\VC\Auxiliary\Build\vcvarsall.bat" x86 >nul 2>&1
cd /d "D:\projects\project\SAU\build-console-Desktop_Qt_5_12_4_MSVC2017_32bit-Profile"
"D:\Application\Qt\Qt\Tools\QtCreator\bin\jom.exe" -j4
exit %ERRORLEVEL%
