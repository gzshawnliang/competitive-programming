#include "pch.h"
#include <conio.h>
#include <graphics.h>

const int xpn = 1920, ypn = 1080;
const int offset = 15;
int y = 0, x = 0;
int main()
{
    // ��ʼ��ͼ�δ���
    initgraph(xpn, ypn);

    MOUSEMSG m; // ���������Ϣ
    
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

    // �ر�ͼ�δ���
    closegraph();
}