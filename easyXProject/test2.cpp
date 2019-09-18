#include <graphics.h>
#include <windows.h>
#include <bits/stdc++.h>

using namespace  std;

void setMaxCenter(int scrWidth,int scrHeight,const HWND & hWnd)
{
	//HWND hWnd = GetHWnd();
	//使用 Windows API 修改窗口名称
	SetWindowText(hWnd, "Hello!");	

	//居中窗口

	RECT rect;
    GetWindowRect(hWnd, &rect);
	cout << abs(scrWidth - rect.right) / 2 << '\n';
	cout << abs(scrHeight - rect.bottom) / 2 << '\n';

	cout << rect.right - rect.left << '\n';
	cout << rect.bottom - rect.top << '\n';
    SetWindowPos(hWnd, HWND_TOP, abs(scrWidth - rect.right) / 2, abs(scrHeight - rect.bottom) / 2, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
	
}

int main()
{
    int scrWidth = GetSystemMetrics(SM_CXSCREEN);
    int scrHeight = GetSystemMetrics(SM_CYSCREEN);

	int winWidth = scrWidth-0;
	int winHeight = scrHeight-80;

	HWND hWnd = initgraph(winWidth,winHeight,NOMINIMIZE | SHOWCONSOLE);

	SetWindowText(hWnd, "Game!");	
	SetWindowPos(hWnd, HWND_TOP, (scrWidth-winWidth) / 2, (scrHeight-winHeight) / 2, winWidth, winHeight, SWP_SHOWWINDOW);

	setlinecolor(WHITE);
	setfillcolor(RED);

	BeginBatchDraw();
	while (true)
	{
		for(int i=50; i<winWidth; i++)
		{
			circle(i, 100, 40);
			floodfill(i, 100, WHITE);
			FlushBatchDraw();
			Sleep(1);
			cleardevice();
		}

	}
	EndBatchDraw();
	closegraph();
}