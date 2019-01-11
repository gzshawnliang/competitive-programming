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
#include "ConsoleColor.h"

using namespace std;

ifstream fin("theSameGame.in");

int total = 0;

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


bool g(int y, int x)
{
    return y >= 0 && y <= 9 && x >= 0 && x <= 14;
}

void del(int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX) == false)
    {
        return;
    }
    else if (a[nowY][nowX] == '.' || a[nowY][nowX] != color)
    {
        return;
    }
    else
    {
        a[nowY][nowX] = '.';
        del(nowY + 1, nowX, a, color);
        del(nowY - 1, nowX, a, color);
        del(nowY, nowX + 1, a, color);
        del(nowY, nowX - 1, a, color);
    }
}

void fall(vector<vector<char>> & a)
{
    for (int x = 0; x <= 14; ++x)
    {
        int y = 9;
        while (y >= 0)
        {
            if (a[y][x] == '.')
            {
                int up = 0;
                while (true)
                {
                    if (y < 0)
                    {
                        break;
                    }
                    else if (a[y][x] != '.')
                    {
                        break;
                    }

                    --y;
                    ++up;
                }

                while (true)
                {
                    if (y < 0)
                    {
                        break;
                    }
                    else if (a[y][x] == '.')
                    {
                        y = y + up + 1;
                        break;
                    }

                    a[y + up][x] = a[y][x];
                    a[y][x] = '.';
                    --y;
                }
                up = 0;
            }
            else
            {
                --y;
            }
        }
    }
}

void connect(vector<vector<char>> & a)
{
    for (int x = 13; x >= 0; --x)
    {
        bool ok = true;
        for (int y = 0; y <= 9; ++y)
        {
            if (a[y][x] != '.')
            {
                ok = false;
                break;
            }
        }

        if (ok == true)
        {
            for (int x0 = x; x0 <= 13; ++x0)
            {
                for (int y = 0; y <= 9; ++y)
                {
                    a[y][x0] = a[y][x0 + 1];
                    a[y][x0 + 1] = '.';
                }
            }
        }
    }
}

void out(vector<vector<char>> & a, int mouseY, int mouseX)
{
    for (int y = 0; y <= 9; ++y)
    {
        for (int x = 0; x <= 14; ++x)
        {
            if (y == mouseY && x == mouseX)
            {
                std::cout << white << '[';
            }
            else
            {
                std::cout << white << ' ';
            }

            if (a[y][x] == 'R')
            {
                std::cout << red;
            }
            else if (a[y][x] == 'G')
            {
                std::cout << green;
            }
            else if (a[y][x] == 'B')
            {
                std::cout << blue;
            }
            else if (a[y][x] == 'Y')
            {
                std::cout << yellow;
            }

            if (a[y][x] == '.')
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << a[y][x];
            }
            

            if (y == mouseY && x == mouseX)
            {
                std::cout << white << ']';
            }
            else
            {
                std::cout << white << ' ';
            }
        }
        std::cout << '\n';
    }
}

int _count(int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX) == false)
    {
        return 0;
    }
    else if (a[nowY][nowX] == '.' || a[nowY][nowX] != color)
    {
        return 0;
    }
    else
    {   
        a[nowY][nowX] = '.';

        int ans = 1;
        ans += _count(nowY + 1, nowX, a, color);
        ans += _count(nowY - 1, nowX, a, color);
        ans += _count(nowY, nowX + 1, a, color);
        ans += _count(nowY, nowX - 1, a, color);

        return ans;
    }
}

void reflesh(int nowY, int nowX, vector<vector<char>> & a)
{
    vector<vector<char>> temp = a;
    int res = _count(nowY, nowX, temp, temp[nowY][nowX]);
    if (res >= 2)
    {
        total += (res - 2) * (res - 2);

        del(nowY, nowX, a, a[nowY][nowX]);

        if (res < 10)
        {
            cout << '\a';
        }
        else
        {
            cout << "\a\a";
        }

        //system("cls");
        cls();
        std::cout << white << "mouseY: " << nowY << " mouseX: " << nowX << " total score: " << total << '\n';
        out(a, nowY, nowX);
        Sleep(250);


        fall(a);

        //system("cls");
        cls();
        std::cout << white << "mouseY: " << nowY << " mouseX: " << nowX << " total score: " << total << '\n';
        out(a, nowY, nowX);
        Sleep(250);


        connect(a);
    }   
}

int main()
{
    //vector<vector<int>> field(50, vector<int>(50));
    int mouseY = 0, mouseX = 0;

    vector<vector<char>> a(10, vector<char>(15));
    for (int y = 0; y <= 9; ++y)
    {
        for (int x = 0; x <= 14; ++x)
        {
            fin >> a[y][x];
        }
    }

    std::cout << white << "mouseY: " << mouseY << " mouseX: " << mouseX << " total score: " << total << '\n';
    out(a, mouseY, mouseX);

    while (true)
    {
        bool press = false;
        while (press == false)
        {
            if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState((int)'W'))
            {
                press = true;
                --mouseY;
            }
            if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState((int)'S'))
            {
                press = true;
                ++mouseY;
            }
            if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState((int)'D'))
            {
                press = true;
                ++mouseX;
            }
            if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState((int)'A'))
            {
                press = true;
                --mouseX;
            }
            if (GetAsyncKeyState((int)'Q'))
            {
                break;
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                press = true;
                reflesh(mouseY, mouseX, a);
            }

            if (mouseY < 0)
            {
                mouseY = 9;
            }
            else if (mouseY >= 10)
            {
                mouseY = 0;
            }
            if (mouseX < 0)
            {
                mouseX = 14;
            }
            else if (mouseX >= 15)
            {
                mouseX = 0;
            }
        }
        

        //system("cls");
        cls();
        std::cout << white << "mouseY: " << mouseY << " mouseX: " << mouseX << " total score: " << total << '\n';
        out(a, mouseY, mouseX);

        vector<vector<char>> temp = a; 
        int maxRemaining = 0;
        for (int y = 0; y <= 9; ++y)
        {
            for (int x = 0; x <= 14; ++x)
            {
                if (temp[y][x] != '.')
                {
                    maxRemaining = max(maxRemaining, _count(y, x, temp, temp[y][x]));
                }
            }
        }

        if (maxRemaining <= 1)
        {
            if (maxRemaining == 0) total += 1000;
            std::cout << white << "\nfinal score: " << total << "\n\n";
            break;
        }

        Sleep(150);
    }

    std::cout << "The Program has completed running\n";
    std::cout << "Press ENTER key to continue...\n";
    std::cin.clear();
    std::cin.get();

    return 0;
}