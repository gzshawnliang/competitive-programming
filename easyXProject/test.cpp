#include <bits/stdc++.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

int xpn = 1200, ypn = 700;

int main()
{
	int scrWidth = GetSystemMetrics(SM_CXSCREEN);
    int scrHeight = GetSystemMetrics(SM_CYSCREEN);

    xpn = scrWidth - 0;
    ypn = scrHeight - 150;

    srand(time(0));
    HWND hWnd = initgraph(xpn, ypn, SHOWCONSOLE);

    SetWindowText(hWnd, "Battle Similator");
    SetWindowPos(hWnd, HWND_TOP, (scrWidth - xpn) / 2, (scrHeight - ypn) / 2 - 50, xpn, ypn, SWP_SHOWWINDOW);

    BeginBatchDraw();

	int space = 15;
	int r = space / 5;
    for (int y = space; y <= 500; y += 1)
    {
        for (int x = space; x <= 600; x += 1)
        {
			FlushBatchDraw();
        	cleardevice();
			
            fillcircle(x, y, r);

			Sleep(10);
        }
    }

    while (true)
        ;

    // 关闭图形窗口
    closegraph();
}