#include "pch.h"
#include <conio.h>
#include <graphics.h>

const int xpn = 1920, ypn = 1080;
const int offset = 15;

int y = 100, x = 100;

int main()
{
    // ��ʼ��ͼ�δ���
    initgraph(xpn, ypn);
    //setwritemode(R2_XORPEN);

    MOUSEMSG m; // ���������Ϣ
    
    while (true)
    {
        //rectangle(x - 10, y - 10, x + 10, y + 10);
        if (GetAsyncKeyState(VK_UP) )
        {
            y -= offset;
        }
        if (GetAsyncKeyState(VK_DOWN) )
        {
            y += offset;
        }
        if (GetAsyncKeyState(VK_LEFT) )
        {
            x -= offset;
        }
        if (GetAsyncKeyState(VK_RIGHT) )
        {
            x += offset;
        }

        if (GetAsyncKeyState(VK_ESCAPE) )
        {
            closegraph();
        }

		cleardevice();
        rectangle(x - 10, y - 10, x + 10, y + 10);
        Sleep(50);
    }

    // �ر�ͼ�δ���
    closegraph();
}