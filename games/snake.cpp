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

const int n = 15;

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


int main()
{
    vector<int> xp = {0, 1, 0, -1},
                yp = {1, 0, -1, 0};

    vector<vector<int>> a(n, vector<int>(n, 0));
    int headY = n / 2, headX = n / 2, delay = 20;
    bool apple = false;

    int direction = 1, score = 0, time = 500;
    while (true)
    {
        if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState((int)'W'))
        {
            if (direction != 0)
            {
                direction = 2;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState((int)'S'))
        {
            if (direction != 2)
            {
                direction = 0;
            }
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState((int)'A'))
        {
            if (direction != 1)
            {
                direction = 3;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState((int)'D'))
        {
            if (direction != 3)
            {
                direction = 1;
            }
        }

        if (headY < 0 || headY >= n || headX < 0 || headY >= n)
        {
            break;
        }

        if (apple == false)
        {
            while (true)
            {
                int ay = getRand(0, n - 1),
                    ax = getRand(0, n - 1);

                if (a[ay][ax] == 0)
                {
                    a[ay][ax] = -1;
                    break;
                }
            }

            apple = true;
        }

        headY += yp[direction]; headX += xp[direction];
        if (a[headY][headX] > 0)
        {
            break;
        }
        else if (a[headY][headX] == -1)
        {
            ++score;
            ++delay;
            apple = false;
        }
        else
        {
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= n - 1; ++x)
                {
                    if (a[y][x] > 0)
                    {
                        --a[y][x];
                    }
                }
            }
        }
        a[headY][headX] = delay;

        cls();

        cout << "Score: " << score << '\n'
             << "head: " << headY << ' ' << headX << '\n';
        for (int y = 0 - 1; y <= n - 1 + 1; ++y)
        {
            for (int x = 0 - 1; x <= n - 1 + 1; ++x)
            {
                if (y < 0 || y >= n || x < 0 || x >= n)
                {
                    cout << white << '#';
                }
                else if (a[y][x] > 0)
                {
                    cout << green;
                    if (y == headY && x == headX)
                    {
                        cout << '@';
                    }
                    else
                    {
                        cout << 'O';
                    }
                }
                else if (a[y][x] == 0)
                {
                    cout << white << ' ';
                }
                else
                {
                    cout << red << 'A';
                }
            }
            cout << '\n';
        }

        if (time - 2 >= 250)
        {
            time -= 2;
        }

        Sleep(time);
    }

    std::cout << "The Program has completed running\n";
    std::cout << "Press ENTER key to continue...\n";
    std::cin.clear();
    std::cin.get();

    return 0;
}