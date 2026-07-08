@echo off
REM ==========================================
REM  Console 一键重编译 & 重启
REM  (HttpApiExecutor mock bugfix)
REM ==========================================

echo [1/4] Stopping running Console...
taskkill /F /IM main_console.exe >nul 2>&1
if %ERRORLEVEL% equ 0 (
    echo   Console stopped.
) else (
    echo   No running Console found.
)

echo [2/4] Setting up MSVC 2017 x86 environment...
call "D:\Application\Visual Studio\other_data\VC\Auxiliary\Build\vcvarsall.bat" x86 >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo   ERROR: vcvarsall.bat failed
    pause
    exit /b 1
)
echo   MSVC environment ready.

echo [3/4] Building...
cd /d "D:\projects\project\SAU\build-console-Desktop_Qt_5_12_4_MSVC2017_32bit-Profile"
"D:\Application\Qt\Qt\Tools\QtCreator\bin\jom.exe" -j4
if %ERRORLEVEL% neq 0 (
    echo   BUILD FAILED! See errors above.
    pause
    exit /b 1
)
echo   Build succeeded.

echo [4/4] Binary info:
dir release\main_console.exe 2>nul | find "main_console"
echo.
echo ==========================================
echo   Build complete!
echo   Binary: release\main_console.exe
echo   Launch: start release\main_console.exe
echo ==========================================
pause
