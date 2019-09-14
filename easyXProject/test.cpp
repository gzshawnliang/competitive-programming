#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

const double PI = 3.1415926;

void move(int & x, int & y, int d, int speed) 
{
    double _d = d;
    _d = _d / 180.0 * PI;

    x += speed * sin(_d);
    if (d != 90) y -= speed * cos(_d);
}

int direction(int x1, int y1, int x2, int y2)
{
	if (y1 == y2)
	{
		if (x1 < x2)
		{
			return 90;
		}
		else
		{
			return 270;
		}
	}

	int ans = round(atan(((double)x1 - (double)x2) / ((double)y2 - (double)y1)) / PI * 180.0);
	if (y1 < y2) ans += 180;

	return ans;
}

int main()
{
	initgraph(640, 480);

	int x = 100, y = 100, d = 0, s = 5;
	while(true)
	{
		if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'A'))
        {
            d = 315;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'D'))
        {
            d = 45;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'A'))
        {
            d = 225;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'D'))
        {
            d = 135;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'W'))
        {
            d = 0;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'S'))
        {
            d = 180;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'A'))
        {
            d = 270;
            move(x, y, d, s);
        }
        else if (GetAsyncKeyState((int)'D'))
        {
            d = 90;
            move(x, y, d, s);
        }

		cleardevice();
		rectangle(x - 10, y - 10, x + 10, y + 10);

		int tempX = 100, tempY = 100;
		rectangle(tempX - 10, tempY - 10, tempX + 10, tempY + 10);
		move(tempX, tempY, direction(tempX, tempY, x, y), 40);
		rectangle(tempX - 10, tempY - 10, tempX + 10, tempY + 10);

		Sleep(50);
	}

	// 关闭图形窗口
	closegraph();
}