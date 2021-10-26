﻿; Win10传统切换中英文输入法
; CapsLock 	切换中英文输入法(caps模式)
; Control + Space 切换中英文输入法
; Control + Shift （左）循环切换输入法
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
#Persistent  ; 保持脚本运行，直达用户退出

;获取当前模式，0代表win7模式，1代表CapsLock模式
currMode := 0
RegRead, currMode, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, mode
global g_IsWin7Mode :=True

if(currMode=1)
{
	g_IsWin7Mode :=False
}
global g_IsCapsLockMode := !g_IsWin7Mode

;是否显示屏幕信息，如果显示有600ms延迟。在快速输入的时候回遗漏按下的按键
currDisplayMsgOnScreenMode := 1
RegRead, currDisplayMsgOnScreenMode, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, DisplayMsgOnScreen
global g_DisplayMsgOnScreen :=True

if(currDisplayMsgOnScreenMode=0)
{
	g_DisplayMsgOnScreen :=False
}

aboutText :="CapsLock            切换中英文输入法(caps模式)`nControl + Space 切换中英文输入法(传统模式)`nControl + Shift （左）循环切换输入法(传统模式)`nControl + 1  English (USA)`nControl + 2 中文输入法`nControl + ' 中文输入法"

Menu, Tray, Tip, Win10输入法切换`n%aboutText%

; 创建菜单
Menu, Tray, NoStandard
Menu, Tray, Add, 开机启动  ; Creates a new menu item.
Menu, Tray, Add, 取消开机启动  ; Creates a new menu item.
Menu, Tray, Add				; Creates a separator line.
Menu, Tray, Add, 传统Win7模式  ; Creates a new menu item.
Menu, Tray, Add, CapsLock模式  ; Creates a new menu item.
Menu, Tray, Add				; Creates a separator line.
Menu, Tray, Add, 显示屏幕信息  ; Creates a new menu item.
Menu, Tray, Add, 关闭屏幕信息  ; Creates a new menu item.
Menu, Tray, Add				; Creates a separator line.
Menu, Tray, Add, 关于  ; Creates a new menu item.
Menu, Tray, Add, 退出  ; Creates a new menu item.

; 设置模式
setMenuMode()

; 检测开机启动设置
checkAutoStartup()

;设置是否显示屏幕信息，如果显示有一定界面堵塞，影响键盘快速输入
setMenuDisplayMsgMode()

return

checkAutoStartup()
{
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
}

setMenuMode()
{

	if (g_IsWin7Mode = True)
	{
		Menu,Tray,Check,传统Win7模式
		DisplayTextOnScreen("输入法切换是：传统Win7模式")
	}
	else							
	{
		Menu,Tray,UnCheck,传统Win7模式
	}
	
	if (g_IsCapsLockMode  = True) 
	{
		Menu,Tray,Check,CapsLock模式
		SetCapsLockState, AlwaysOff
		DisplayTextOnScreen("输入法切换是：CapsLock模式")
	}
	else 
	{
		Menu,Tray,UnCheck,CapsLock模式
		SetCapsLockState, Off     
	}
}

setMenuDisplayMsgMode()
{
	if (g_DisplayMsgOnScreen = True)
	{
		Menu,Tray,Check,显示屏幕信息
		Menu,Tray,UnCheck,关闭屏幕信息

		Menu, Tray, Disable, 显示屏幕信息
		Menu, Tray, Enable, 关闭屏幕信息
	}
	else							
	{
		Menu,Tray,UnCheck,显示屏幕信息
		Menu,Tray,Check,关闭屏幕信息

		Menu, Tray, Enable, 显示屏幕信息
		Menu, Tray, Disable, 关闭屏幕信息	
	}
}

显示屏幕信息:
	g_DisplayMsgOnScreen:=True
	setMenuDisplayMsgMode()
	RegWrite, REG_SZ, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, DisplayMsgOnScreen, 1
	return

关闭屏幕信息:
	g_DisplayMsgOnScreen:=False
	setMenuDisplayMsgMode()
	RegWrite, REG_SZ, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, DisplayMsgOnScreen, 0
	return

传统Win7模式:
	g_IsWin7Mode :=True
	g_IsCapsLockMode := !g_IsWin7Mode
	setMenuMode()
	RegWrite, REG_SZ, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, mode, 0
	return

CapsLock模式:
	g_IsWin7Mode :=False
	g_IsCapsLockMode := !g_IsWin7Mode
	setMenuMode()
	RegWrite, REG_SZ, HKEY_CURRENT_USER\SOFTWARE\Win10ImeSwitcher, mode, 1
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
	Gui, Add, Text,cffffff,Win10输入法切换
	Gui, Font, s18,Microsoft YaHei
	Gui, Add, Text,cffffff,%aboutText%

	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	sleep, 5000
	Gui, Destroy

	return

退出:
	ExitApp
	return

;Control + 1  English (USA),添加~前缀，保留原本Control + 1键的输出
~^1::
	SetDefaultKeyboard(0x0409) ; English (USA)
	DisplayTextOnScreen("United States - English")
	return

;Control + ' 中文输入法,添加~前缀，保留原本Control + '键的输出
;Control + 2 中文输入法,添加~前缀，保留原本Control + 2键的输出
~^'::
~^2::
	SetDefaultKeyboard(0x0804) ; Chinese
	DisplayTextOnScreen("中文输入已开启")
	return

#if (g_IsWin7Mode= True)
{
	;Control + Shift (左) 循环切换输入法（支撑多钟输入法）
	LControl & LShift::
		ToggleAllInputLang()
		return	

	;Control + Space 切换中英文输入法	
	~^space::
		ToggleChsEngLang()
		return
}

; CapsLock切换中英文输入法
#if (g_IsCapsLockMode)
{

	CapsLock::
		SetCapsLockState, AlwaysOff
		ToggleChsEngLang()
		return
}

; 中英输入法切换
ToggleChsEngLang()
{
	SetFormat, Integer, H		;切换到16进制
	currLocaleID:= % DllCall("GetKeyboardLayout", Int,DllCall("GetWindowThreadProcessId", int,WinActive("A"), Int,0))
	if currLocaleID=0x4090409
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是英文输入法，马上切换中文
		SetDefaultKeyboard(0x0804) ; Chinese
		sleep,200
		DisplayTextOnScreen("中文输入已开启")
	}
	else
	{
		SetFormat, Integer, D		;切换到10进制
		;当前是中文输入法，马上切换英文
		SetDefaultKeyboard(0x0409) ; english-US
		sleep,200
		DisplayTextOnScreen("United States - English")
	}
}

; 循环切换输入法（支撑多钟输入法）
ToggleAllInputLang()
{
	SendInput #{Space}
	; todo：电池状态下MBP需要用200ms，普通电脑50ms，原因未知。可能跟cpu降速有关。
	Sleep, 200

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
}

; 循环切换输入法（支撑多钟输入法）（第二种方式）
ToggleAllInputLang2()
{
    WinExist("A")
    ControlGetFocus, CtrlInFocus
    PostMessage, 0x50,2,, %CtrlInFocus% 
}

; 根据LocaleID设置输入法（第二种方式）
SetDefaultKeyboard2(LocaleID)
{
    WinExist("A")
    ControlGetFocus, CtrlInFocus
    PostMessage, 0x50, 0, % LocaleID, %CtrlInFocus%	
}

; 根据LocaleID设置输入法
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

; 显示屏幕信息
DisplayTextOnScreen(DisText,sleepTime:=600)
{
	if(g_DisplayMsgOnScreen=False)
		return

    Gui, Color, 37474F
    Gui -Caption	

    Gui, Font, s28,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,%DisText%
	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	Sleep -1
	sleep, %sleepTime%
	Gui, Destroy
}