@echo off
REM 为 link.exe 注入含 rc.exe 的 PATH 与 RC（修复 LNK1158；与已装 Windows 10 SDK 版本一致时可改下方路径）
set "PATH=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x86;%PATH%"
set "RC=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x86\rc.exe"
link %*
