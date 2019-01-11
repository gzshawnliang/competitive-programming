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

int mouseY = 2, mouseX = 2;

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

bool g(int y, int x)
{
    return y >= 0 && y <= 4 && x >= 0 && x <= 4;
}

void out(vector<vector<int>> & a, vector<vector<int>> & team, bool turn)
{
    cls();

    cout << white << "TURN: ";
    if (turn == true)
    {
        cout << blue << "BLUE\n";
    }
    else
    {
        cout << red << "RED\n";
    }

    for (int y = 0; y <= 4; ++y)
    {
        for (int x = 0; x <= 4; ++x)
        {
            if (mouseY == y && mouseX == x)
            {
                cout << yellow << '[';
            }
            else
            {
                 cout << ' ';
            }

            if (team[y][x] == -1)
            {
                cout << white;
            }
            else if (team[y][x] == 1)
            {
                cout << blue;
            }
            else 
            {
                cout << red;
            }

            cout << a[y][x];

            if (mouseY == y && mouseX == x)
            {
                cout << yellow << ']';
            }
            else
            {
                 cout << ' ';
            }
        }
        cout << '\n';
    }
}

void reflesh(vector<vector<int>> & a, vector<vector<int>> & team, int pointY, int pointX, bool turn)
{
    if (g(pointY, pointX) == false)
    {
        return;
    }

    ++a[pointY][pointX];
    team[pointY][pointX] = turn;

    out(a, team, turn);
    Sleep(75);
    if (a[pointY][pointX] == 4)
    {
        a[pointY][pointX] = 0;
        team[pointY][pointX] = -1;

        reflesh(a, team, pointY + 1, pointX, turn);
        reflesh(a, team, pointY - 1, pointX, turn);
        reflesh(a, team, pointY, pointX + 1, turn);
        reflesh(a, team, pointY, pointX - 1, turn);
    }
}
int main()
{
    mouseY = 2; mouseX = 2;
    bool turn = true;
    vector<vector<int>> a(5, vector<int>(5, 0));
    vector<vector<int>> team(5, vector<int>(5, -1));
    team[0][0] = 1; team[4][4] = 0;
    a[0][0] = 1; a[4][4] = 1;
    out(a, team, turn);

    while (true)
    {
        bool press = false;
        while (press == false)
        {   
            if (turn == true)
            {
                if (GetAsyncKeyState(VK_UP))
                {
                    --mouseY;
                    press = true;
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    ++mouseY;
                    press = true;
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    --mouseX;
                    press = true;
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    ++mouseX;
                    press = true;
                }
                if (GetAsyncKeyState((int)'M'))
                {
                    if (team[mouseY][mouseX] == 1 || team[mouseY][mouseX] == -1)
                    {
                        reflesh(a, team, mouseY, mouseX, turn);
                        mouseY = 2; mouseX = 2;
                        turn = false;

                        press = true;
                    }
                } 
            }
            else
            {
                if (GetAsyncKeyState((int)'W'))
                {
                    --mouseY;
                    press = true;
                }
                if (GetAsyncKeyState((int)'S'))
                {
                    ++mouseY;
                    press = true;
                }
                if (GetAsyncKeyState((int)'A'))
                {
                    --mouseX;
                    press = true;
                }
                if (GetAsyncKeyState((int)'D'))
                {
                    ++mouseX;
                    press = true;
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    if (team[mouseY][mouseX] == 0 || team[mouseY][mouseX] == -1)
                    {
                        reflesh(a, team, mouseY, mouseX, turn);
                        mouseY = 2; mouseX = 2;
                        turn = true;

                        press = true;
                    }
                }
            }

            if (mouseY < 0) mouseY = 4;
            else if (mouseY >= 5) mouseY = 0;
            if (mouseX < 0) mouseX = 4;
            else if (mouseX >= 5) mouseX = 0;
        }

        bool allBlue = true;
        bool allRed = true;
        for (int y = 0; y <= 4; ++y)
        {
            for (int x = 0; x <= 4; ++x)
            {
                if (team[y][x] == 1)
                {
                    allRed = false;
                }
                else if (team[y][x] == 0)
                {
                    allBlue = false;
                }
            }
        }

        if (allBlue == true)
        {
            cout << blue << "BLUE" << yellow << " WINS!!\n";
            cout << white;
            break;
        }
        else if (allRed == true)
        {
            cout << red << "RED" << yellow << " WINS!!\n";
            cout << white;
            break;
        }

        out(a, team, turn);
        Sleep(150);
    }

    system("Pause");
    return 0;
}