@if not defined _echo echo off
rem set language to english

set VSLANG=1033
rem Start Developer Command Prompt
for /f "usebackq delims=" %%i in (`%~dp0%.vscode\vswhere.exe -prerelease -latest -property installationPath`) do (
  if exist "%%i\Common7\Tools\vsdevcmd.bat" (
    call "%%i\Common7\Tools\vsdevcmd.bat" %* && cd /d %~dp0% 	
  )
)

rem Instance or command prompt not found