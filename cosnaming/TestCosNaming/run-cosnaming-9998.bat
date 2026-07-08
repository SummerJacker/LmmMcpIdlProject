@echo off
setlocal
cd /d "%~dp0"

set "ILUHOME=%~dp0Iluhome"
set "PATH=%ILUHOME%\bin;%PATH%"

echo Starting ILU CosNaming on 127.0.0.1:9998 ...
echo IOR will be written to: %CD%\naming-9998.ior
echo Store file: %CD%\naming-9998.store
echo.
echo Keep this window open while you use the naming service.
echo Press Ctrl+C to stop it.
echo.

"%ILUHOME%\bin\ILUCosNaming.exe" -p 9998 -h 127.0.0.1 -ior -ior_to_file "%CD%\naming-9998.ior" -f "%CD%\naming-9998.store" -verbose
