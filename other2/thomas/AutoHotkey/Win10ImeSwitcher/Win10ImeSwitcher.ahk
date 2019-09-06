; https://msdn.microsoft.com/en-us/library/dd318693%28v=vs.85%29.aspx
; "The specified language must be displayable using the current system character set." (SystemParametersInfo function)
; https://msdn.microsoft.com/en-us/library/windows/desktop/ms724947%28v=vs.85%29.aspx
;-------- https://autohotkey.com/boards/viewtopic.php?f=6&t=18519 ---

Menu, Tray, Tip,Win10输入法传统切换`nControl + Space 切换中英文输入法`nControl + 1  English (USA)`nControl + 2 中文输入法`nControl + ' 中文输入法

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

;Control + Shift (左) 切换中英文输入法
;Control + Space 切换中英文输入法
LControl & LShift::
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
	Loop %windows% {
		PostMessage 0x50, 0, %Lan%, , % "ahk_id " windows%A_Index%
	}
}

DisplayTextOnScreen(DisText)
{
    Gui, Color, 37474F
    Gui -Caption	

    Gui, Font, s28,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,%DisText%
	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	sleep, 600
	Gui, Destroy
}
;=====================================================