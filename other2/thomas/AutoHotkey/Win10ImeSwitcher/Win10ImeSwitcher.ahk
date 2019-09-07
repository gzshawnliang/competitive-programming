; Win10传统切换中英文输入法
; Control + Space 切换中英文输入法
; Control + Shift （左）循环切换输入法,bug:MBP 2016 Bootcamp上失效
; Control + 1  English (USA)
; Control + 2 中文输入法
; Control + ' 中文输入法
; todo:循环切换输入法需显示名称
; 参考
; https://msdn.microsoft.com/en-us/library/dd318693%28v=vs.85%29.aspx
; "The specified language must be displayable using the current system character set." (SystemParametersInfo function)
; https://msdn.microsoft.com/en-us/library/windows/desktop/ms724947%28v=vs.85%29.aspx
; https://autohotkey.com/boards/viewtopic.php?f=6&t=18519 ---

; 仅允许唯一一个实例运行，如果第二个开启，自动刷新
; https://www.autohotkey.com/docs/commands/_SingleInstance.htm
#SingleInstance force

aboutText :="Win10输入法传统切换`nControl + Space 切换中英文输入法`nControl + Shift （左）循环切换输入法`nControl + 1  English (USA)`nControl + 2 中文输入法`nControl + ' 中文输入法"

Menu, Tray, Tip,%aboutText%

#Persistent  ; Keep the script running until the user exits it.
Menu, Tray, NoStandard
Menu, Tray, Add, 开机启动  ; Creates a new menu item.
Menu, Tray, Add				; Creates a separator line.
Menu, Tray, Add, 取消开机启动  ; Creates a new menu item.
Menu, Tray, Add				; Creates a separator line.
Menu, Tray, Add, 关于  ; Creates a new menu item.
Menu, Tray, Add, 退出  ; Creates a new menu item.

If FileExist(A_AppData . "\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk" )
{
	Menu,Tray,Check,开机启动
	Menu, Tray, Disable, 开机启动
	Menu, Tray, Enable, 取消开机启动
	Menu, Tray, Icon, DDORes.dll, 108
	Return
}
else
{
	Menu, Tray, Disable, 取消开机启动
	Menu, Tray, Icon, DDORes.dll, 110
}
return

开机启动:
	; DisplayTextOnScreen(A_ScriptDir,3000)
	; DisplayTextOnScreen(A_ScriptFullPath,3000)

	; Menu,Tray,ToggleCheck,开机启动
	If FileExist(A_AppData . "\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk")
	{
		FileDelete, % A_AppData "\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk"
	}
	FileCreateShortcut, %A_ScriptFullPath%, %A_AppData%\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk
	Menu,Tray,Check,开机启动
	Menu, Tray, Disable, 开机启动
	Menu, Tray, Enable, 取消开机启动
	Menu, Tray, Icon, DDORes.dll, 108
	return

取消开机启动:
	If FileExist(A_AppData . "\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk")
	{
		FileDelete, % A_AppData "\Microsoft\Windows\Start Menu\Programs\Startup\Win10ImeSwitcher.lnk"
	}
	Menu,Tray,Uncheck,开机启动
	Menu, Tray, Enable, 开机启动
	Menu, Tray, Disable, 取消开机启动
	Menu, Tray, Icon, DDORes.dll, 110
	return

关于:
	; DisplayTextOnScreen("Win10输入法传统切换`nControl + Space 切换中英文输入法`nControl + 1  English (USA)`nControl + 2 中文输入法`nControl + ' 中文输入法",5000)

    Gui, Color, 37474F
    Gui -Caption	

    Gui, Font, s28,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,Win10输入法传统切换
	Gui, Font, s18,Microsoft YaHei
	Gui, Add, Text,cffffff,%aboutText%

	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	sleep, 5000
	Gui, Destroy

	return

退出:
	ExitApp
	return

;Control + 1  English (USA)
^1::
	SetDefaultKeyboard(0x0409) ; English (USA)
	DisplayTextOnScreen("United States - English")
	return

;Control + ' 中文输入法
;Control + 2 中文输入法
^'::
^2::
	SetDefaultKeyboard(0x0804) ; Chinese
	DisplayTextOnScreen("中文输入已开启")
	return
;
;Control + Shift (左) 循环切换输入法（支撑多钟输入法）
LControl & LShift::
	SendInput #{Space}
	Sleep, 50

	SetFormat, Integer, H		;切换到16进制
	currLocaleID:= % DllCall("GetKeyboardLayout", Int,DllCall("GetWindowThreadProcessId", int,WinActive("A"), Int,0))
	if currLocaleID=0x4090409
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是英文输入法
		DisplayTextOnScreen("United States - English")
	}
	else
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是中文输入法
		DisplayTextOnScreen("中文输入已开启")
	}	
	return

;Control + Space 切换中英文输入法	
^space::
	SetFormat, Integer, H		;切换到16进制
	currLocaleID:= % DllCall("GetKeyboardLayout", Int,DllCall("GetWindowThreadProcessId", int,WinActive("A"), Int,0))
	if currLocaleID=0x4090409
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是英文输入法，马上切换中文
		SetDefaultKeyboard(0x0804) ; Chinese
		DisplayTextOnScreen("中文输入已开启")
	}
	else
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是中文输入法，马上切换英文
		SetDefaultKeyboard(0x0409) ; english-US
		DisplayTextOnScreen("United States - English")
	}
	return

; 大写打开/关闭指示器，有延迟，指示器消失之前不能输入
; g_LastCtrlKeyDownTime := 0
; g_AbortSendEsc := false
; g_ControlRepeatDetected := false

; *CapsLock::
;     if (g_ControlRepeatDetected)
;     {
;         return
;     }

; 	DisplayTextOnScreen("大写打开",500)

;     send,{CapsLock}
;     g_LastCtrlKeyDownTime := A_TickCount
;     g_AbortSendEsc := false
;     g_ControlRepeatDetected := true

;     return

; *CapsLock Up::
;     SetCapsLockState Off
; 	DisplayTextOnScreen("大写关闭",500)
;     g_ControlRepeatDetected := false
;     if (g_AbortSendEsc)
;     {
;         return
;     }
	
;     current_time := A_TickCount
;     time_elapsed := current_time - g_LastCtrlKeyDownTime
;     if (time_elapsed <= 250)
;     {
;         SetCapsLockState Off
;     }
;     return

ToggleInputLang()
{
    WinExist("A")
    ControlGetFocus, CtrlInFocus
    PostMessage, 0x50,2,, %CtrlInFocus% 
}

SetDefaultKeyboard2(LocaleID)
{
    WinExist("A")
    ControlGetFocus, CtrlInFocus
    PostMessage, 0x50, 0, % LocaleID, %CtrlInFocus%	
}

SetDefaultKeyboard(LocaleID)
{
	Global
	SPI_SETDEFAULTINPUTLANG := 0x005A
	SPIF_SENDWININICHANGE := 2

	Lan := DllCall("LoadKeyboardLayout", "Str", Format("{:08x}", LocaleID), "Int", 0)
	VarSetCapacity(Lan%LocaleID%, 4, 0)
	NumPut(LocaleID, Lan%LocaleID%)
	DllCall("SystemParametersInfo", "UInt", SPI_SETDEFAULTINPUTLANG, "UInt", 0, "UPtr", &Lan%LocaleID%, "UInt", SPIF_SENDWININICHANGE)

	WinGet, windows, List
	Loop %windows% 
	{
		PostMessage 0x50, 0, %Lan%, , % "ahk_id" windows%A_Index%
	}
}

DisplayTextOnScreen(DisText,sleepTime:=600)
{
    Gui, Color, 37474F
    Gui -Caption	

    Gui, Font, s28,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,%DisText%
	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	sleep, %sleepTime%
	Gui, Destroy
}


