SET current_path=%~dp0
TASKKILL /F /IM Win10ImeSwitcher.exe
"%PROGRAMFILES%\AutoHotkey\Compiler\Ahk2Exe.exe" /in "%current_path%Win10ImeSwitcher.ahk" /icon "%current_path%Win10ImeSwitcher2.ico"
start /D "%current_path%" Win10ImeSwitcher.exe
