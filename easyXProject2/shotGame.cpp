#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

const int xpn = 1920, ypn = 1080;
const int ps = 5;

const double PI = 3.1415926;

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

struct bullet
{
    int x;
    int y;
    int d;
    int s;
    int t;
};
bullet _bullet(int x, int y, int d, int s, int t) 
{
    bullet temp{x, y, d, s, t};
    return temp;
}

//int direction(int x1, int y1, int x2, int y2)
//{
//    int ans = round(atan((y1 - y2) / (x1 - x2)) / PI * 180.0);
//
//	if (x1 > x2)
//        ans += 180;
//
//    return ans;
//}

int distance2(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void move(int & x, int & y, int d, int speed) 
{
    double _d = d;
    _d = _d / 180.0 * PI;

    x += speed * sin(_d);
    if (d != 90) y -= speed * cos(_d);
}

int main()
{
    srand(time(0));
		
    initgraph(xpn, ypn);
    //setwritemode(R2_XORPEN);
    MOUSEMSG m; // 定义鼠标消息

	vector<bullet> bullets;
    
	int p1x = xpn / 3,
        p1y = ypn / 2,
        p1d = 0,
        p1s = 10,
        p1bs = 15,
        p1cdm = 1,
        p1cd = p1cdm,
        p2x = xpn / 3 * 2,
        p2y = ypn / 2,
        p2d = 0,
        p2s = 10,
        p2bs = 15,
        p2cdm = 2,
        p2cd = p2cdm,
		camX = 0,
		camY = 0;
    while (true)
    {
        if (p1cd > 0)
        {
            --p1cd;
        }
        if (p2cd > 0)
        {
            --p2cd;
        }

        if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'A'))
        {
            p1d = 315;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'D'))
        {
            p1d = 45;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'A'))
        {
            p1d = 225;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'D'))
        {
            p1d = 135;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'W'))
        {
            p1d = 0;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'S'))
        {
            p1d = 180;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'A'))
        {
            p1d = 270;
            move(p1x, p1y, p1d, p1s);
        }
        else if (GetAsyncKeyState((int)'D'))
        {
            p1d = 90;
            move(p1x, p1y, p1d, p1s);
        }

		if (GetAsyncKeyState(VK_SPACE))
        {
            if (p1cd == 0)
            {
                for (int c = 1; c <= 10; ++c)
                {
                    int tempX = p1x,
                        tempY = p1y,
                        tempD = p1d + getRand(-360 + 360, 360 + 360) - 360;

                    move(tempX, tempY, tempD, p1bs);

                    bullets.push_back(_bullet(tempX, tempY, tempD, p1bs, 75));
                }

				p1cd = p1cdm;
            }
        }

		if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_LEFT))
        {
            p2d = 315;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_RIGHT))
        {
            p2d = 45;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_LEFT))
        {
            p2d = 225;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_RIGHT))
        {
            p2d = 135;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            p2d = 0;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            p2d = 180;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            p2d = 270;
            move(p2x, p2y, p2d, p2s);
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            p2d = 90;
            move(p2x, p2y, p2d, p2s);
        }

		if (GetAsyncKeyState(VK_RETURN))
        {
            if (p2cd == 0)
            {
                for (int c = 1; c <= 1; ++c)
                {
                    int tempX = p2x,
                        tempY = p2y,
                        tempD = p2d + getRand(-10 + 10, 10 + 10) - 10;
                    move(tempX, tempY, tempD, p2bs);

                    bullets.push_back(_bullet(tempX, tempY, tempD, p2bs, 75));
                }

				p2cd = p2cdm;
			}
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            closegraph();
        }

		cleardevice();
        fillrectangle(p1x - 10 - camX, p1y - 10 - camY, p1x + 10 - camX, p1y + 10 - camY);
        rectangle(p2x - 10 - camX, p2y - 10 - camY, p2x + 10 - camX, p2y + 10 - camY);

		int sizeB = bullets.size();
        for (int i = 0; i <= sizeB - 1; ++i)
        {
            move(bullets[i].x, bullets[i].y, bullets[i].d, bullets[i].s);
            --bullets[i].t;

			if (bullets[i].t == 0)
            {
                bullets.erase(bullets.begin() + i);
                --i;
                --sizeB;
            }
        }
        for (int i = 0; i <= sizeB - 1; ++i)
        {
            //fillcircle(bullets[i].x - camX, bullets[i].y - camY, 5);
            fillrectangle(bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
        }

		for (int i = 0; i <= sizeB - 1; ++i)
        {
            if (distance2(bullets[i].x, bullets[i].y, p1x, p1y) < 17 * 17)
            {
                Sleep(1000);
                closegraph();
            }
            if (distance2(bullets[i].x, bullets[i].y, p2x, p2y) < 17 * 17)
            {
                Sleep(1000);
                closegraph();
            }
        }

        Sleep(50);
    }

    // 关闭图形窗口
    closegraph();
}