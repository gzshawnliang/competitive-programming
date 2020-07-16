rem Clean java the workspace directory
for /f "tokens=*" %%G in ('dir /b /s /a:d "%APPDATA%\Code\User\workspaceStorage\*redhat.java"') do rmdir /Q /S %%G

@if not defined _echo echo off
rem set language to english set VSLANG=1033

set VSLANG=1033
rem Start Developer Command Prompt
for /f "usebackq delims=" %%i in (`%~dp0%.vscode\vswhere.exe -prerelease -latest -property installationPath`) do (
  if exist "%%i\Common7\Tools\vsdevcmd.bat" (
    call "%%i\Common7\Tools\vsdevcmd.bat" %* && cd /d %~dp0% && code .	
    exit /b 0
  )
)

rem Instance or command prompt not found
exit /b 2