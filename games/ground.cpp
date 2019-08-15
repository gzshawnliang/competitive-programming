#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <windows.h>
#include <bits/stdc++.h>
#include "ConsoleColor.h"

using namespace std;

const int ym = 100, xm = 100;
vector<int> yp = {-1, 0, 1, 0}, xp = {0, 1, 0, -1};

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

//#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

struct point
{
    int y;
    int x;
};
point _point(int y, int x)
{
    point temp{y, x}; return temp;
}

struct bullet
{
    int y;
    int x;
    int direction;
    int speed;
};
bullet _bullet(int y, int x, int direction, int speed)
{
    bullet temp{y, x, direction, speed}; return temp;
}

bool g(int y, int x)
{
    return y >= 0 && y <= ym - 1 && x >= 0 && x <= xm - 1;
}

void randSpread(int y, int x, int count, char ch, vector<vector<char>> & a)
{
    queue<point> q; q.push(_point(y, x));
    while (q.empty() == false && count > 0)
    {
        point now = q.front(); q.pop();
        if (g(now.y, now.x) == false) continue;
        if (a[now.y][now.x] != '.') continue;

        a[now.y][now.x] = ch;
        --count;

        int randP = getRand(0, 3);
        for (int p = 0; p <= 3; ++p)
        {
            if (randP != p)
            {
                q.push(_point(now.y + yp[p], now.x + xp[p]));
            }
        }
    }
}

void _loop(int & i, int n)
{
    if (i >= n)
    {
        i = 0;
    }
    else if (i < 0)
    {
        i = n - 1;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);

    srand(time(0));

    vector<vector<char>> a(ym, vector<char>(xm, '.'));
    for (int c = 1; c <= 10; ++c)
    {
        randSpread(getRand(0, ym - 1), getRand(0, xm - 1), getRand(100, 500), '#', a);
    }
    for (int y = 0; y <= ym - 1; ++y)
    {
        for (int x = 0; x <= xm - 1; ++x)
        {
            if (a[y][x] == '.' && getRand(0, 5) == 0)
            {
                a[y][x] = 'g';
            }
        }
    }

    int playerY = ym / 2, playerX = xm / 2, direction = 0;
    int r = 10;
    vector<bullet> bullets;
    bullets.push_back(_bullet(playerY, playerX, direction, 3));

    while (true)
    {
        system("cls");

        cout << white << playerY << ' ' << playerX << '\n';
        for (int y = playerY - r + 1; y <= playerY + r - 1; ++y)
        {
            for (int x = playerX - r + 1; x <= playerX + r - 1; ++x)
            {
                if (g(y, x) == false)
                {
                    cout << ' ';
                }
                else if (y == playerY && x == playerX)
                {
                    cout << yellow << 'x';
                }
                else if (a[y][x] == '.')
                {
                    cout << ' ';
                }
                else if (a[y][x] == 'g')
                {
                    cout << green << '.';
                }
                else if (a[y][x] == '#')
                {
                    cout << white << '#';
                }
                else if (a[y][x] == 'b')
                {
                    cout << red << 'O';
                }

                //cout << ' ';
            }
            cout << '\n';
        }

        bool move = false;
        if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState((int)'W'))
        {
            direction = 0;
            move = true;
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState((int)'S'))
        {
            direction = 2;
            move = true;
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState((int)'D'))
        {
            direction = 1;
            move = true;
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState((int)'A'))
        {
            direction = 3;
            move = true;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            bullets.push_back(_bullet(playerY, playerX, direction, 1));
        }
        
        if (move == true)
        {
            playerY += yp[direction]; playerX += xp[direction];
            if (a[playerY][playerX] == '#')
            {
                playerY -= yp[direction]; playerX -= xp[direction];
            }

            move = false;
        }
        
        _loop(playerY, ym); _loop(playerX, xm);

        int size = bullets.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            bool ok = true;
            int lastY = bullets[i].y, lastX = bullets[i].x;
            for (int c = 1; c <= bullets[i].speed; ++c)
            {
                bullets[i].y += yp[bullets[i].direction];
                bullets[i].x += xp[bullets[i].direction];
                a[lastY - yp[bullets[i].direction] * c][lastX - xp[bullets[i].direction] * c] = '.';

                if (g(bullets[i].y, bullets[i].x) == false)
                {
                    ok = false;
                    break;
                }
                else
                {
                    if (a[bullets[i].y][bullets[i].x] == '#')
                    {
                        a[bullets[i].y][bullets[i].x] = '.';
                        ok = false;
                        break;
                    }
                    else
                    {
                        a[bullets[i].y][bullets[i].x] = 'b';
                    }
                }
            }
            
            if (ok == false)
            {
                bullets.erase(bullets.begin() + i);
                --size;
                --i;
            }
        }

        Sleep(5);
    }

    cout.flush();
    return 0;
}