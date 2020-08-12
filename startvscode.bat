@if not defined _echo echo off

rem %APPDATA%\Code\User
rem %USERPROFILE%\.vscode\extensions

rem vc++ directory
rem C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC

rem Clean java the workspace directory
echo checking java workspace Storage
for /f "tokens=*" %%G in ('dir /b /s /a:d "%APPDATA%\Code\User\workspaceStorage\*redhat.java"') do rmdir /Q /S %%G && echo %%G deleted!
rem for /f "tokens=*" %%G in ('dir /b /s /a:d "../usersetting/User/workspaceStorage/*redhat.java"') do rmdir /Q /S %%G && echo %%G deleted!

rem set language to english set VSLANG=1033
set VSLANG=1033
rem Start Developer Command Prompt
for /f "usebackq delims=" %%i in (`%~dp0%.vscode\vswhere.exe -prerelease -latest -property installationPath`) do (
  if exist "%%i\Common7\Tools\vsdevcmd.bat" (
    call "%%i\Common7\Tools\vsdevcmd.bat" %* && cd /d %~dp0% 
    rem call code --user-data-dir ../usersetting --extensions-dir ../extensions .
    call code .
    exit /b 0
  )
)

rem Instance or command prompt not found
exit /b 2