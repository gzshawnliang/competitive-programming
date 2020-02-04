@echo off
REM 启动gdb之前删除进程，防止错误
cmd /c chcp 65001
rem (tasklist|find /i "gdb.exe" && taskkill /im gdb.exe /f) & g++.exe %*
tasklist|%SystemRoot%\system32\find.exe /i "gdb.exe" && taskkill /im gdb.exe /f
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
gdb --version
echo. 
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
g++ --version
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo g++.exe %*
g++.exe %*
if %ERRORLEVEl% == 0 
(
    echo g++ compile successfully and launching debuger...
)
else 
(
    echo build fail %ERRORLEVEl%
)
echo.
EXIT %ERRORLEVEl%
