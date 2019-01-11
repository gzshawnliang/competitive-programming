#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    int p1Y = 2, p1X = 0, p1H = 3, p1S = 0;
    int p2Y = 2, p2X = 29, p2H = 3, p2S = 0;
    int sizeY = 8, sizeX = 30;

    while (true)
    {
        Sleep(70);
        system("cls");
        
        vector<string> board;
        board.push_back("..............................");
        board.push_back("..............................");
        board.push_back("..............GGGGGGG.........");
        board.push_back(".................N............");
        board.push_back(".......GGGGG.....N............");
        board.push_back(".........G.......NGGGGG.......");
        board.push_back(".........G.......N..G.........");
        board.push_back("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");

        if (p1S > 0)
        {
            --p1Y;
            --p1S;
            if (p1Y < 0)
            {
                p1Y = 0;
            }
            else if (board[p1Y][p1X] == 'G')
            {
                ++p1Y;
            }
        }

        if (p1X < 0)
        {
            p1X = 0;
        }
        else if (p1X > sizeX - 1)
        {
            p1X = sizeX - 1;
        }

        else if (board[p1Y + 1][p1X] != 'G' && p1S == 0)
        {
            ++p1Y;
        }

        if (GetAsyncKeyState((int)'W') && board[p1Y + 1][p1X] == 'G' && p1S == 0)
        {
            p1S = 4;
        }
        if (GetAsyncKeyState((int)'D'))
        {
            ++p1X;
            if (board[p1Y][p1X] == 'G')
            {
                --p1X;
            }
        }
        if (GetAsyncKeyState((int)'A'))
        {
            --p1X;
            if (board[p1Y][p1X] == 'G')
            {
                ++p1X;
            }
        }


        if (p2S > 0)
        {
            --p2Y;
            --p2S;
            if (p2Y < 0)
            {
                p2Y = 0;
            }
            else if (board[p2Y][p2X] == 'G')
            {
                ++p2Y;
            }
        }

        if (p2X < 0)
        {
            p2X = 0;
        }
        else if (p2X > sizeX - 1)
        {
            p2X = sizeX - 1;
        }

        else if (board[p2Y + 1][p2X] != 'G' && p2S == 0)
        {
            ++p2Y;
        }

        if (GetAsyncKeyState(VK_UP) && board[p2Y + 1][p2X] == 'G' && p2S == 0)
        {
            p2S = 4;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            ++p2X;
            if (board[p2Y][p2X] == 'G')
            {
                --p2X;
            }
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            --p2X;
            if (board[p2Y][p2X] == 'G')
            {
                ++p2X;
            }
        }



        for (int y = 0; y <= sizeY - 1; ++y)
        {
            for (int x = 0; x <= sizeX - 1; ++x)
            {
                if (y == p1Y && x == p1X)
                {
                    cout << "¡ö";
                }
                else if (y == p2Y && x == p2X)
                {
                    cout << "¡ø";
                }
                else if (board[y][x] == 'G')
                {
                    cout << "¡õ";
                }
                else if (board[y][x] == 'N')
                {
                    cout << "||";
                }
                else if (board[y][x] == '.')
                {
                    cout << "  ";
                }
                else if (board[y][x] == 'B')
                {
                    cout << "¡ò";
                }
            }
            cout << '\n';
        }
    }

    cout << "The game has completed running\n";
    cout << "Press ENTER key to continue...";
    cin.clear();
    cin.get();
    return 0;
}