#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    //vector<vector<int>> field(50, vector<int>(50));
    int x = 25, y = 25, wide = 20;

    while (true)
    {
        if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState((int)'W'))
        {
            --x;
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState((int)'S'))
        {
            ++x;
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState((int)'D'))
        {
            ++y;
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState((int)'A'))
        {
            --y;
        }
        if (GetAsyncKeyState((int)'Q'))
        {
            break;
        }

        system("cls");

        if (x < 0)
        {
            x = wide - 1;
        }
        if (x > wide - 1)
        {
            x = 0;
        }

        if (y < 0)
        {
            y = wide - 1;
        }
        else if (y > wide - 1)
        {
            y = 0;
        }

        cout << "x = " << x << "\ny = " << y << '\n';
        for (int i = 0; i <= wide - 1; ++i)
        {
            cout << "-";
        }
        cout << "\n";
        for (int i = 0; i <= wide - 1; ++i)
        {
            for (int j = -1; j <= wide; ++j)
            {
                if (j == -1 || j == wide)
                {
                    //cout << "£ü";
                    cout << "|";
                }
                else if (i == x && j == y)
                {
                    cout << 'O';
                }
                else
                {
                    cout << " ";
                }
            }
            cout << '\n';
        }
        for (int i = 0; i <= wide - 1; ++i)
        {
            cout << "-";
        }
        cout << "\n";

        Sleep(100);
    }

    cout << "The Program has completed running\n";
    cout << "Press ENTER key to continue...";
    cin.clear();
    cin.get();
    return 0;
}