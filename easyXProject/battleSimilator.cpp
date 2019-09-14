#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

const int xpn = 1500, ypn = 900, inf = INT_MAX / 3;
const double PI = 3.1415926;

int camX = 0, camY = 0, camD = 0, camS = 15;

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
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

bool updateCamPos()
{
    bool ans = false;
    if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'A'))
    {
        camD = 315;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'W') && GetAsyncKeyState((int)'D'))
    {
        camD = 45;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'A'))
    {
        camD = 225;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'S') && GetAsyncKeyState((int)'D'))
    {
        camD = 135;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'W'))
    {
        camD = 0;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'S'))
    {
        camD = 180;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'A'))
    {
        camD = 270;
        move(camX, camY, camD, camS);
        ans = true;
    }
    else if (GetAsyncKeyState((int)'D'))
    {
        camD = 90;
        move(camX, camY, camD, camS);
        ans = true;
    }

    return ans;
}

enum type {worrior = 0, archer = 1, gaint = 2};
struct troup
{
    bool isAttacked;
    int x;
    int y;
    int healthMax;
    int health;
    int attackCount;
    int attackCountMax;
    int attackDamage;
    int movementSpeed;
    int range;
    int minRange;
    type troupType;
};
troup _troup(bool isAttacked, int x, int y, int healthMax, int health, int attackCount, int attackCountMax, int attackDamage, int movementSpeed, int range, int minRange, type troupType)
{
    troup temp{isAttacked, x, y, healthMax, health, attackCount, attackCountMax, attackDamage, movementSpeed, range, minRange, troupType}; return temp;
}

void draw(vector<troup> & blue, vector<troup> & red)
{
    int sizeB = blue.size(), sizeR = red.size();
    for (int i = 0; i <= sizeB - 1; ++i)
    {
        int r = 5;
        if (blue[i].isAttacked == true) r = 7;
        
        setcolor(RGB(255,255,255));
        setfillcolor(RGB(0,0,255));
        fillrectangle(blue[i].x - r - camX, blue[i].y - r - camY, blue[i].x + r - camX, blue[i].y + r - camY);
    }
    for (int i = 0; i <= sizeR - 1; ++i)
    {
        int r = 5;
        if (red[i].isAttacked == true) r = 7;

        setcolor(RGB(255,255,255));
        setfillcolor(RGB(255,0,0));
        fillrectangle(red[i].x - r - camX, red[i].y - r - camY, red[i].x + r - camX, red[i].y + r - camY);
    }
}

int main()
{
    srand(time(0));
		
    initgraph(xpn, ypn);
    //setwritemode(R2_XORPEN);

    // bool isAttacked;
    // int x;
    // int y;
    // int health;
    // int attackCount;
    // int attackCountMax;
    // int attackDamage;
    // int movementSpeed;
    // int range;
    // type troupType;

    vector<troup> blue, red;

    MOUSEMSG m;
    while (true)
    {
        if (updateCamPos() == true)
        {
            cleardevice();
            draw(blue, red);
        }

        if (m.uMsg == WM_LBUTTONDOWN)
        {
            troup temp;
            temp.isAttacked = false;
            temp.x = m.x + camX;
            temp.y = m.y + camY;
            temp.healthMax = 100;
            temp.health = temp.healthMax;
            temp.attackCount = 0;
            temp.attackCountMax = 10;
            temp.attackDamage = 20;
            temp.movementSpeed = 5;
            temp.range = 5;
            temp.minRange = 0;
            temp.troupType = type::worrior;

            blue.push_back(temp);
            cleardevice();
            draw(blue, red);
        }
        else if (m.uMsg == WM_RBUTTONDOWN)
        {
            troup temp;
            temp.isAttacked = false;
            temp.x = m.x + camX;
            temp.y = m.y + camY;
            temp.healthMax = 100;
            temp.health = temp.healthMax;
            temp.attackCount = 0;
            temp.attackCountMax = 10;
            temp.attackDamage = 20;
            temp.movementSpeed = 5;
            temp.range = 5;
            temp.minRange = 0;
            temp.troupType = type::worrior;

            red.push_back(temp);
            cleardevice();
            draw(blue, red);
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

        Sleep(5);

        m = GetMouseMsg();
    }

    //blue.push_back(_troup(false, 100, 100, 100, 0, 10, 10, 5, 15, type::worrior));
    //red.push_back(_troup(false, 500, 100, 100, 0, 10, 10, 5, 15, type::worrior));
	
    int troupHitboxSize = 10;
    while (true)
    {
        int sizeB = blue.size(), sizeR = red.size();
        for (int i = 0; i <= sizeB - 1; ++i)
        {
            if (blue[i].health <= 0)
            {
                blue.erase(blue.begin() + i);
                --i;
                --sizeB;
            }

            if (blue[i].attackCount > 0)
            {
                --blue[i].attackCount;
            }

            blue[i].isAttacked = false;
        }

        for (int i = 0; i <= sizeR - 1; ++i)
        {
            if (red[i].health <= 0)
            {
                red.erase(red.begin() + i);
                --i;
                --sizeR;
            }

            if (red[i].attackCount > 0)
            {
                --red[i].attackCount;
            }

            red[i].isAttacked = false;
        }

        for (int i = 0; i <= sizeB - 1; ++i)
        {
            int minD = inf, minDIndex = inf;
            for (int j = 0; j <= sizeR - 1; ++j)
            {
                int nowD = distance2(blue[i].x, blue[i].y, red[j].x, red[j].y);
                if (nowD < minD)
                {
                    minD = nowD;
                    minDIndex = j;
                }
            }

            if (minDIndex != inf)
            {
                if (blue[i].range * blue[i].range >= minD)
                {
                    if (blue[i].minRange * blue[i].minRange >= minD)
                    {
                        move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, red[minDIndex].x, red[minDIndex].y), blue[i].movementSpeed * -1);

                        int minDS = inf;
                        for (int k = 0; k <= sizeB - 1; ++k)
                        {
                            if (i == k) continue;
                            minDS = min(minDS, distance2(blue[i].x, blue[i].y, blue[k].x, blue[k].y));
                        }

                        if (minDS < troupHitboxSize * troupHitboxSize)
                        {
                            move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, red[minDIndex].x, red[minDIndex].y), blue[i].movementSpeed * 1 + 2);
                        }
                    }

                    if (blue[i].attackCount == 0)
                    {
                        red[minDIndex].health -= blue[i].attackDamage;
                        red[minDIndex].isAttacked = true;
                        blue[i].attackCount = blue[i].attackCountMax;
                    }
                }
                else
                {
                    move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, red[minDIndex].x, red[minDIndex].y), blue[i].movementSpeed);

                    int minDS = inf;
                    for (int k = 0; k <= sizeB - 1; ++k)
                    {
                        if (i == k) continue;
                        minDS = min(minDS, distance2(blue[i].x, blue[i].y, blue[k].x, blue[k].y));
                    }

                    if (minDS < troupHitboxSize * troupHitboxSize)
                    {
                        move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, red[minDIndex].x, red[minDIndex].y), blue[i].movementSpeed * -1 - 2);
                    }
                }
            }
        }

        for (int i = 0; i <= sizeR - 1; ++i)
        {
            int minD = inf, minDIndex = inf;
            for (int j = 0; j <= sizeB - 1; ++j)
            {
                int nowD = distance2(red[i].x, red[i].y, blue[j].x, blue[j].y);
                if (nowD < minD)
                {
                    minD = nowD;
                    minDIndex = j;
                }
            }

            if (minDIndex != inf)
            {
                if (red[i].range * red[i].range >= minD)
                {
                    if (red[i].minRange * red[i].minRange >= minD)
                    {
                        move(red[i].x, red[i].y, direction(red[i].x, red[i].y, blue[minDIndex].x, blue[minDIndex].y), red[i].movementSpeed * -1);

                        int minDS = inf;
                        for (int k = 0; k <= sizeR - 1; ++k)
                        {
                            if (i == k) continue;
                            minDS = min(minDS, distance2(red[i].x, red[i].y, red[k].x, red[k].y));
                        }

                        if (minDS < troupHitboxSize * troupHitboxSize)
                        {
                            move(red[i].x, red[i].y, direction(red[i].x, red[i].y, blue[minDIndex].x, blue[minDIndex].y), red[i].movementSpeed * 1 + 2);
                        }
                    }
                    
                    if (red[i].attackCount == 0)
                    {
                        blue[minDIndex].health -= red[i].attackDamage;
                        blue[minDIndex].isAttacked = true;
                        red[i].attackCount = red[i].attackCountMax;
                    }
                }
                else
                {
                    move(red[i].x, red[i].y, direction(red[i].x, red[i].y, blue[minDIndex].x, blue[minDIndex].y), red[i].movementSpeed);

                    int minDS = inf;
                    for (int k = 0; k <= sizeR - 1; ++k)
                    {
                        if (i == k) continue;
                        minDS = min(minDS, distance2(red[i].x, red[i].y, red[k].x, red[k].y));
                    }

                    if (minDS < troupHitboxSize * troupHitboxSize)
                    {
                        move(red[i].x, red[i].y, direction(red[i].x, red[i].y, blue[minDIndex].x, blue[minDIndex].y), red[i].movementSpeed * -1 - 2);
                    }
                }
            }
        }

        updateCamPos();

        cleardevice();
        draw(blue, red);

        Sleep(50);
    }
    
    closegraph();
    return 0;
}