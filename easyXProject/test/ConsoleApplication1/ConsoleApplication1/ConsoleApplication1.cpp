#include "pch.h"
#include <conio.h>
#include <graphics.h>

const int xpn = 1920, ypn = 1080;
const int offset = 15;
int y = 0, x = 0;
int main()
{
    // 初始化图形窗口
    initgraph(xpn, ypn);

    MOUSEMSG m; // 定义鼠标消息
    
    while (true)
    {
        //rectangle(x - 10, y - 10, x + 10, y + 10);
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y -= offset;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y += offset;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            x -= offset;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            x += offset;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            closegraph();
        }

		//cleardevice();
        rectangle(x - 10, y - 10, x + 10, y + 10);
        Sleep(60);
    }

    // 关闭图形窗口
    closegraph();
}