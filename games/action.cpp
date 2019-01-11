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

struct line
{
    int x;
    int y;
};

void cls()
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };
    std::cout.flush();
    if (!GetConsoleScreenBufferInfo(hOut, &csbi))
    {
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
    SetConsoleCursorPosition(hOut, topLeft);
}

int getRand()
{
    return (rand() % (3 - 0 + 1)) + 0;
}

int main()
{
    srand(time(NULL));

    int count = 0;
    long long point = 15, plus = 3, maxPoint = 0;
    vector<line> a;

    while (true)
    {
        maxPoint = max(maxPoint, point);

        ++count;
        cls();

        vector<string> out(10, "    ");
        out[9] = "====";

        line temp;

        if (count == 5)
        {
            temp.x = getRand();
            temp.y = 0;
            a.push_back(temp);

            count = 0;
        }

        int size = a.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            ++a[i].y;

            if (a[i].y == 9 || a[i].y == 8)
            {
                if (a[i].x == 0)
                {
                    if (GetAsyncKeyState((int)'S'))
                    {
                        point += plus;
                        ++plus;
                    }
                    else if (a[i].y == 9)
                    {
                        plus = 3;
                        --point;
                        out[9][a[i].x] = '_';
                    }
                }
                else if (a[i].x == 1)
                {
                    if (GetAsyncKeyState((int)'F'))
                    {
                        point += plus;
                        ++plus;
                    }
                    else if (a[i].y == 9)
                    {
                        plus = 3;
                        --point;
                        out[9][a[i].x] = '_';
                    }
                }
                else if (a[i].x == 2)
                {
                    if (GetAsyncKeyState((int)'H'))
                    {
                        point += plus;
                        ++plus;
                    }
                    else if (a[i].y == 9)
                    {
                        plus = 3;
                        --point;
                        out[9][a[i].x] = '_';
                    }
                }
                else if (a[i].x == 3)
                {
                    if (GetAsyncKeyState((int)'K'))
                    {
                        point += plus;
                        ++plus;
                    }
                    else if (a[i].y == 9)
                    {
                        plus = 3;
                        --point;
                        out[9][a[i].x] = '_';
                    }
                }

                if (a[i].y == 9)
                {
                    a.erase(a.begin() + i);
                    --i;
                    --size;
                }
                else
                {
                    out[a[i].y][a[i].x] = 'v';
                }
            }
            else
            {
                out[a[i].y][a[i].x] = 'v';
            }
        }

        if (point < 0)
        {
            break;
        }

        for (int y = 0; y <= 9; ++y)
        {
            for (int x = 0; x <= 3; ++x)
            {
                if (x > 0)
                {
                    cout << ' ';
                }

                if (out[y][x] == '_')
                {
                    cout << red << '=';
                }
                else if (out[y][x] == '=')
                {
                    cout << yellow;

                    if (x == 0 && GetAsyncKeyState((int)'S'))
                    {
                        --point;
                        cout << green;
                    }
                    else if (x == 1 && GetAsyncKeyState((int)'F'))
                    {
                        --point;
                        cout << green;
                    }
                    else if (x == 2 && GetAsyncKeyState((int)'H'))
                    {
                        --point;
                        cout << green;
                    }
                    else if (x == 3 && GetAsyncKeyState((int)'K'))
                    {
                        --point;
                        cout << green;
                    }

                    cout << '=';
                }
                else if (out[y][x] == '|')
                {
                    cout << blue << '|';
                }
                else
                {
                    cout << out[y][x];
                }
            }
            cout << '\n';
        }
        cout << white << point << '\n';

        Sleep(100);
    }

    cout << red << "GAME OVER, YOUR SCORE:" << maxPoint << '\n';
    int temp;
    cin >> temp;

    return 0;
}