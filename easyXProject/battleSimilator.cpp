#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int xpn = 1200, ypn = 700;
const int inf = INT_MAX / 3, doubleKSpr = 250, doubleKSpc = 100;
const double PI = 3.1415926, collideBackPers = 0.5, collidePushPers = 0.7;

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

void drawHealthBar(int x, int y, int r, int h, int health, int healthMax)
{
    health = max(health, 0);

    setcolor(RGB(255,255,255));
    setfillcolor(RGB(0,255,0));
    rectangle(x - r, y - h, x + r, y + h);
    fillrectangle(x - r, y - h, x - r + (int)((double)(2 * r) * (double)(health) / (double)(healthMax)), y + h);
}

void draw(vector<troup> & blue, vector<troup> & red)
{
    int sizeB = blue.size(), sizeR = red.size();
    for (int i = 0; i <= sizeB - 1; ++i)
    {
        int r = 5;
        if (blue[i].isAttacked == true) r = 7;
        
        if (blue[i].troupType == type::worrior)
        {
            setcolor(RGB(255,255,255));
            setfillcolor(RGB(0,0,255));
            fillrectangle(blue[i].x - r - camX, blue[i].y - r - camY, blue[i].x + r - camX, blue[i].y + r - camY);

            if (blue[i].health < blue[i].healthMax) drawHealthBar(blue[i].x - camX, blue[i].y - camY - 8, 4, 1, blue[i].health, blue[i].healthMax);
        }
        else if (blue[i].troupType == type::gaint)
        {
            r = (double)r * 1.5;

            setcolor(RGB(255,255,255));
            setfillcolor(RGB(0,0,255));
            fillrectangle(blue[i].x - r - camX, blue[i].y - r - camY, blue[i].x + r - camX, blue[i].y + r - camY);

            if (blue[i].health < blue[i].healthMax) drawHealthBar(blue[i].x - camX, blue[i].y - camY - 15, 4, 1, blue[i].health, blue[i].healthMax);
        }
        else if (blue[i].troupType == type::archer)
        {
            setcolor(RGB(255,255,255));
            setfillcolor(RGB(0,0,255));
            fillcircle(blue[i].x - camX, blue[i].y- camY, r);

            if (blue[i].health < blue[i].healthMax) drawHealthBar(blue[i].x - camX, blue[i].y - camY - 8, 4, 1, blue[i].health, blue[i].healthMax);
        }
    }
    for (int i = 0; i <= sizeR - 1; ++i)
    {
        int r = 5;
        if (red[i].isAttacked == true) r = 7;
        
        if (red[i].troupType == type::worrior)
        {
            setcolor(RGB(255,255,255));
            setfillcolor(RGB(255,0,0));
            fillrectangle(red[i].x - r - camX, red[i].y - r - camY, red[i].x + r - camX, red[i].y + r - camY);

            if (red[i].health < red[i].healthMax) drawHealthBar(red[i].x - camX, red[i].y - camY - 8, 4, 1, red[i].health, red[i].healthMax);
        }
        else if (red[i].troupType == type::gaint)
        {
            r = (double)r * 1.5;

            setcolor(RGB(255,255,255));
            setfillcolor(RGB(255,0,0));
            fillrectangle(red[i].x - r - camX, red[i].y - r - camY, red[i].x + r - camX, red[i].y + r - camY);

            if (red[i].health < red[i].healthMax) drawHealthBar(red[i].x - camX, red[i].y - camY - 15, 4, 1, red[i].health, red[i].healthMax);
        }
        else if (red[i].troupType == type::archer)
        {
            setcolor(RGB(255,255,255));
            setfillcolor(RGB(255,0,0));
            fillcircle(red[i].x - camX, red[i].y- camY, r);

            if (red[i].health < red[i].healthMax) drawHealthBar(red[i].x - camX, red[i].y - camY - 8, 4, 1, red[i].health, red[i].healthMax);
        }
    }

    string text = to_string(sizeB) + " B----R " + to_string(sizeR);
	
    int sizeT = text.size(), x = 10, y = 10;
    for (int i = 0; i <= sizeT - 1; ++i)
    {
        moveto(x, y);
        outtext(text[i]);
        x += 9;
    }
}

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

    troup temp;
    temp.isAttacked = false;
    temp.healthMax = 100;
    temp.health = temp.healthMax;
    temp.attackCount = 0;
    temp.attackCountMax = 10;
    temp.attackDamage = 20;
    temp.movementSpeed = 3;
    temp.range = 15;
    temp.minRange = 0;
    temp.troupType = type::worrior;

    int pDelay = 0;
    vector<string> lastOpe;
    MOUSEMSG m;
    while (true)
    {
        if (MouseHit()) m = GetMouseMsg();
        if (pDelay > 0) --pDelay;

        if (updateCamPos() == true)
        {
            cleardevice();
            draw(blue, red);
        }
        if (GetAsyncKeyState((int)'F'))
        {
            if (pDelay == 0)
            {
                if (lastOpe.size() == 0)
                {

                }
                else if (lastOpe.back() == "blue")
                {
                    blue.erase(blue.begin() + blue.size() - 1);
                }
                else if (lastOpe.back() == "red")
                {
                    red.erase(red.begin() + red.size() - 1);
                }
                else if (lastOpe.back() == "blueM")
                {
                    for (int c = 1; c <= doubleKSpc - 1; ++c)
                    {
                        blue.erase(blue.begin() + blue.size() - 1);
                    }
                }
                else if (lastOpe.back() == "redM")
                {
                    for (int c = 1; c <= doubleKSpc - 1; ++c)
                    {
                        red.erase(red.begin() + red.size() - 1);
                    }
                }

                if (lastOpe.size() > 0) lastOpe.erase(lastOpe.begin() + lastOpe.size() - 1);

                cleardevice();
                draw(blue, red);

                pDelay = 20;
            }
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

        if (m.uMsg == WM_LBUTTONDBLCLK)
        {
            if (pDelay == 0)
            {
                for (int c = 1; c <= doubleKSpc - 1; ++c)
                {
                    temp.x = m.x + camX + getRand(0, doubleKSpr * 2) - doubleKSpr;
                    temp.y = m.y + camY + getRand(0, doubleKSpr * 2) - doubleKSpr;
                    blue.push_back(temp);
                }

                cleardevice();
                draw(blue, red);

                lastOpe.push_back("blueM");
                pDelay = 20;
            }
        }
        else if (m.uMsg == WM_RBUTTONDBLCLK)
        {
            if (pDelay == 0)
            {
                for (int c = 1; c <= doubleKSpc - 1; ++c)
                {
                    temp.x = m.x + camX + getRand(0, doubleKSpr * 2) - doubleKSpr;
                    temp.y = m.y + camY + getRand(0, doubleKSpr * 2) - doubleKSpr;
                    red.push_back(temp);
                }

                cleardevice();
                draw(blue, red);

                lastOpe.push_back("redM");
                pDelay = 20;
            }
        }
        else if (m.uMsg == WM_LBUTTONDOWN)
        {
            if (pDelay == 0)
            {
                temp.x = m.x + camX;
                temp.y = m.y + camY;
                blue.push_back(temp);

                cleardevice();
                draw(blue, red);

                lastOpe.push_back("blue");
                pDelay = 20;
            }
        }
        else if (m.uMsg == WM_RBUTTONDOWN)
        {
            if (pDelay == 0)
            {
                temp.x = m.x + camX;
                temp.y = m.y + camY;
                red.push_back(temp);

                cleardevice();
                draw(blue, red);

                lastOpe.push_back("red");
                pDelay = 20;
            }
        }

        if (GetAsyncKeyState((int)'Z'))
        {
            temp.isAttacked = false;
            temp.healthMax = 400;
            temp.health = temp.healthMax;
            temp.attackCount = 0;
            temp.attackCountMax = 10;
            temp.attackDamage = 50;
            temp.movementSpeed = 3;
            temp.range = 15;
            temp.minRange = 0;
            temp.troupType = type::worrior;
        }
        else if (GetAsyncKeyState((int)'X'))
        {
            temp.isAttacked = false;
            temp.healthMax = 1000;
            temp.health = temp.healthMax;
            temp.attackCount = 0;
            temp.attackCountMax = 20;
            temp.attackDamage = 60;
            temp.movementSpeed = 2;
            temp.range = 20;
            temp.minRange = 0;
            temp.troupType = type::gaint;
        }
        else if (GetAsyncKeyState((int)'C'))
        {
            temp.isAttacked = false;
            temp.healthMax = 70;
            temp.health = temp.healthMax;
            temp.attackCount = 0;
            temp.attackCountMax = 30;
            temp.attackDamage = 15;
            temp.movementSpeed = 2;
            temp.range = 200;
            temp.minRange = 50;
            temp.troupType = type::archer;
        }

        FlushBatchDraw();
        Sleep(5);
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
                }
            }

            for (int k = 0; k <= sizeB - 1; ++k)
            {
                if (i == k) continue;

                int nowD = distance2(blue[i].x, blue[i].y, blue[k].x, blue[k].y);

                if (nowD < troupHitboxSize * troupHitboxSize)
                {
                    move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, blue[k].x, blue[k].y), (int)((double)blue[i].movementSpeed * -1 * collideBackPers));
                    move(blue[k].x, blue[k].y, direction(blue[i].x, blue[i].y, blue[k].x, blue[k].y), (int)((double)blue[i].movementSpeed * collidePushPers));
                }
            }

            for (int k = 0; k <= sizeR - 1; ++k)
            {
                int nowD = distance2(blue[i].x, blue[i].y, red[k].x, red[k].y);

                if (nowD < troupHitboxSize * troupHitboxSize)
                {
                    move(blue[i].x, blue[i].y, direction(blue[i].x, blue[i].y, red[k].x, red[k].y), (int)((double)blue[i].movementSpeed * -1 * collideBackPers));
                    move(red[k].x, red[k].y, direction(blue[i].x, blue[i].y, red[k].x, red[k].y), (int)((double)blue[i].movementSpeed * collidePushPers));
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
                }
            }

            for (int k = 0; k <= sizeR - 1; ++k)
            {
                if (i == k) continue;

                int nowD = distance2(red[i].x, red[i].y, red[k].x, red[k].y);

                if (nowD < troupHitboxSize * troupHitboxSize)
                {
                    move(red[i].x, red[i].y, direction(red[i].x, red[i].y, red[k].x, red[k].y), (int)((double)red[i].movementSpeed * -1 * collideBackPers));
                    move(red[k].x, red[k].y, direction(red[i].x, red[i].y, red[k].x, red[k].y), (int)((double)red[i].movementSpeed * collidePushPers));
                }
            }

            for (int k = 0; k <= sizeB - 1; ++k)
            {
                int nowD = distance2(red[i].x, red[i].y, blue[k].x, blue[k].y);

                if (nowD < troupHitboxSize * troupHitboxSize)
                {
                    move(red[i].x, red[i].y, direction(red[i].x, red[i].y, blue[k].x, blue[k].y), (int)((double)red[i].movementSpeed * -1 * collideBackPers));
                    move(blue[k].x, blue[k].y, direction(red[i].x, red[i].y, blue[k].x, blue[k].y), (int)((double)red[i].movementSpeed * collidePushPers));
                }
            }
        }

        updateCamPos();
        // if (sizeB > 0)
        // {
        //     camX = blue[0].x - xpn / 2; camY = blue[0].y - ypn / 2;
        // }

        FlushBatchDraw();
        cleardevice();
        draw(blue, red);
        
        Sleep(30);
    }
    
    EndBatchDraw();
    closegraph();
    return 0;
}