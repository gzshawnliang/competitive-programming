/*
===========================================================
 * @名称:     GoldenDict & 欧路取词脚本（AutoHotkey）
 * @作者:	  Thomas 
 * @创建时间: 2018-04-28 20:12:16 
 * @修改人:   Thomas 
 * @修改时间: 2020-06-23 11:27:08 
 * @备注:	    增加开关(F12)取词的指示器，和部分浏览器和pdf阅读器取词
                增加浏览器 Microsoft Edge（Chrome）取词
                增加屏蔽VSCode取词
 * @来源：    https://www.pdawiki.com/forum/forum.php?mod=viewthread&tid=23696&extra=page%3D1
===========================================================
*/
F12::
Suspend, permit
if (State = 0) {

    Gui, Color, 37474F
    Gui -Caption

    Gui, Font, s32,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,字典已开启
	Gui, Show, xCenter yCenter, 状态, NoActivate,
	sleep, 1200
	Gui, Destroy
	State++
}
else {
	State := 0

    Gui, Color, 37474F
    Gui -Caption

    Gui, Font, s32,Microsoft YaHei
	Gui, +AlwaysOnTop +Disabled -SysMenu +Owner 
	Gui, Add, Text,cffffff,字典已关闭
	Gui, Show, xCenter yCenter, 状态, NoActivate, 
	sleep, 1200
	Gui, Destroy
}
Suspend, toggle
return


~LButton::

MouseGetPos, ,,win
SetTitleMatchMode, 2

if( WinActive("ahk_exe Code.exe")==win )	   ;vscode不取词
{
    return
}

if( WinActive("Chrome") != win                                                      ;浏览器 Chrome
    and WinActive("Firefox") != win                                                 ;浏览器 Firefox
    and WinActive("ahk_exe vivaldi.exe") != win                                     ;浏览器 vivaldi
    and WinActive("ahk_class ApplicationFrameWindow") != win                        ;浏览器 Microsoft Edge
    and WinActive("ahk_class Chrome_WidgetWin_1") != win                            ;浏览器 Microsoft Edge (Chromium)
    and WinActive("ahk_class SUMATRA_PDF_FRAME") != win                             ;pdf阅读器 SumatraPDF
    and WinActive("ahk_class AcrobatSDIWindow") != win                              ;pdf阅读器 Adobe Acrobat
    and WinActive("ahk_exe UVA Arena.exe") != win                                   ;UVA Arena
    and WinActive("ahk_class PXE:{C5309AD3-73E4-4707-B1E1-2940D8AF3B9D}") != win    ;pdf阅读器 PDF-XChange Editor
    and WinActive("ahk_class Qt5QWindowIcon")   != win                              ;calibre 电子书查看器
    and WinActive("添加") != win)
    {    
        ;判断当前所处的软件窗口
        return
    }
SetKeyDelay -1, 10
CoordMode, Mouse, Screen
MouseGetPos, x1, y1
KeyWait, LButton
MouseGetPos, x2, y2
if (x1-x2>30 or x2-x1>30) {   ;判断鼠标点住左键后移动范围,防误触
oldClipboard := Clipboard    ;赋值鼠标原始剪贴板内容
	gosub, Copy     ;执行第19行的Copy标签
}
else if (A_priorHotKey = "~LButton" and A_TimeSincePriorHotkey < 450){    ;双击鼠标左键
oldClipboard := Clipboard    
	gosub, Copy 
}
return

Copy:
Send ^c   ;发送ctrl+c 复制所选内容到剪贴板
Sleep 200
 len := strlen(clipboard)    ;剪贴板字符数
    index := 1               
    loop    ;循环剪贴板里的每个字符
    { 
        code := asc( substr(clipboard, index, 1) ) ;获得ascii码
        if(code > 122 or code < 20 or code >= 33 and code <= 38 or code >= 40 and code <= 44 or code >=46 and code<=64 or code >=91 and code<=96 or code >=123 and code <= 126)   ;判断剪贴板里是否包含中文/数字/特殊字符
    {
		Clipboard := oldClipboard    ;恢复原始剪贴板内容
		return             ;终止执行
        }
        ++index
		 if(index > len)
            break
    }
if(len <3){    ;判断句子或三字母以下的单词
		  Clipboard := oldClipboard      
		 return
		}
Send ^{c 2}  ;发送全局的 ctrl+ctrlt+c  ,请在goldendict中设置翻译剪切板的热键为 Ctrl+ctrl+C
Sleep 200
 Clipboard := oldClipboard   ;恢复原始剪贴板内容,如果希望默认复制所翻译的内容,可删除此行
return