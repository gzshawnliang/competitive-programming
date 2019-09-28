SET current_path=%~dp0
tasklist|%SystemRoot%\system32\find.exe /i "Win10ImeSwitcher.exe" && taskkill /im Win10ImeSwitcher.exe /f
"%PROGRAMFILES%\AutoHotkey\Compiler\Ahk2Exe.exe" /in "%current_path%Win10ImeSwitcher.ahk" /icon "%current_path%Win10ImeSwitcher2.ico"
start /D "%current_path%" Win10ImeSwitcher.exe
