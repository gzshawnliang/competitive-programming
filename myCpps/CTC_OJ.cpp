#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool g(int y, int x)
{
    return y >= 0 && y <= 7 && x >= 0 && x <= 7;
}

void print(vector<vector<char>> out1, vector<vector<bool>> out2, vector<vector<bool>> out3)
{
    for (int y = 0; y <= 7; ++y)
    {
        for (int x = 0; x <= 7; ++x)
        {
            cout << out1[y][x];
        }
        cout << "   ";

        for (int x = 0; x <= 7; ++x)
        {
            if (out2[y][x] == 0)
            {
                cout << ".";
            }
            else
            {
                cout << "x";
            }
        }
        cout << "   ";

        for (int x = 0; x <= 7; ++x)
        {
            if (out3[y][x] == 0)
            {
                cout << ".";
            }
            else
            {
                cout << "x";
            }
        }
        cout << '\n';
    }
}

int main()
{
    int game = 1;

    while (true)
    {
        bool end = true;
        vector<vector<char>> a(8, vector<char>(8));
        vector<vector<bool>> Bhit(8, vector<bool>(8, false));
        vector<vector<bool>> Whit(8, vector<bool>(8, false));
        int bkY, bkX, wkY, wkX;
        for (int y = 0; y <= 7; ++y)
        {
            for (int x = 0; x <= 7; ++x)
            {
                cin >> a[y][x];
            }
        }

        for (int y = 0; y <= 7; ++y)
        {
            for (int x = 0; x <= 7; ++x)
            {
                if (a[y][x] != '.')
                {
                    end = false;
                }
                if (a[y][x] == 'p')
                {
                    if (g(y + 1, x - 1))
                    {
                        Bhit[y + 1][x - 1] = true;
                    }
                    if (g(y + 1, x + 1))
                    {
                        Bhit[y + 1][x + 1] = true;
                    }
                }
                else if (a[y][x] == 'P')
                {
                    if (g(y - 1, x - 1))
                    {
                        Whit[y - 1][x - 1] = true;
                    }
                    if (g(y - 1, x + 1))
                    {
                        Whit[y - 1][x + 1] = true;
                    }
                }

                else if (a[y][x] == 'r')
                {
                    int tempY = y - 1, tempX = x;
                    while (tempY >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                    }

                    tempY = y + 1, tempX = x;
                    while (tempY <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                    }

                    tempY = y, tempX = x - 1;
                    while (tempX >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempX;
                    }

                    tempY = y, tempX = x + 1;
                    while (tempX <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempX;
                    }
                }
                else if (a[y][x] == 'R')
                {
                    int tempY = y - 1, tempX = x;
                    while (tempY >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                    }

                    tempY = y + 1, tempX = x;
                    while (tempY <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                    }

                    tempY = y, tempX = x - 1;
                    while (tempX >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempX;
                    }

                    tempY = y, tempX = x + 1;
                    while (tempX <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempX;
                    }
                }

                else if (a[y][x] == 'b')
                {
                    int tempY = y - 1, tempX = x - 1;
                    while (tempY >= 0 && tempX >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        --tempX;
                    }

                    tempY = y + 1, tempX = x + 1;
                    while (tempY <= 7 && tempX <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        ++tempX;
                    }

                    tempY = y + 1, tempX = x - 1;
                    while (tempX >= 0 && tempY <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        --tempX;
                    }

                    tempY = y - 1, tempX = x + 1;
                    while (tempX <= 7 && tempY >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        ++tempX;
                    }
                }
                else if (a[y][x] == 'B')
                {
                    int tempY = y - 1, tempX = x - 1;
                    while (tempY >= 0 && tempX >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        --tempX;
                    }

                    tempY = y + 1, tempX = x + 1;
                    while (tempY <= 7 && tempX <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        ++tempX;
                    }

                    tempY = y + 1, tempX = x - 1;
                    while (tempX >= 0 && tempY <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        --tempX;
                    }

                    tempY = y - 1, tempX = x + 1;
                    while (tempX <= 7 && tempY >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        ++tempX;
                    }
                }

                else if (a[y][x] == 'q')
                {
                    int tempY = y - 1, tempX = x - 1;
                    while (tempY >= 0 && tempX >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        --tempX;
                    }

                    tempY = y + 1, tempX = x + 1;
                    while (tempY <= 7 && tempX <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        ++tempX;
                    }

                    tempY = y + 1, tempX = x - 1;
                    while (tempX >= 0 && tempY <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        --tempX;
                    }

                    tempY = y - 1, tempX = x + 1;
                    while (tempX <= 7 && tempY >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        ++tempX;
                    }

                    tempY = y - 1, tempX = x;
                    while (tempY >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                    }

                    tempY = y + 1, tempX = x;
                    while (tempY <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                    }

                    tempY = y, tempX = x - 1;
                    while (tempX >= 0)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempX;
                    }

                    tempY = y, tempX = x + 1;
                    while (tempX <= 7)
                    {
                        Bhit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempX;
                    }
                }
                else if (a[y][x] == 'Q')
                {
                    int tempY = y - 1, tempX = x - 1;
                    while (tempY >= 0 && tempX >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        --tempX;
                    }

                    tempY = y + 1, tempX = x + 1;
                    while (tempY <= 7 && tempX <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        ++tempX;
                    }

                    tempY = y + 1, tempX = x - 1;
                    while (tempX >= 0 && tempY <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                        --tempX;
                    }

                    tempY = y - 1, tempX = x + 1;
                    while (tempX <= 7 && tempY >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                        ++tempX;
                    }

                    tempY = y - 1, tempX = x;
                    while (tempY >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempY;
                    }

                    tempY = y + 1, tempX = x;
                    while (tempY <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempY;
                    }

                    tempY = y, tempX = x - 1;
                    while (tempX >= 0)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        --tempX;
                    }

                    tempY = y, tempX = x + 1;
                    while (tempX <= 7)
                    {
                        Whit[tempY][tempX] = '.';

                        if (a[tempY][tempX] != '.')
                        {
                            break;
                        }
                        ++tempX;
                    }
                }

                else if (a[y][x] == 'k')
                {
                    bkY = y;
                    bkX = x;
                    int Xp[8] = {1, 0, -1, 0, 1, -1, 1, -1};
                    int Yp[8] = {1, 1, 1, -1, -1, -1, 0, 0};

                    for (int p = 0; p <= 7; ++p)
                    {
                        if (g(y + Yp[p], x + Xp[p]) == true)
                        {
                            Bhit[y + Yp[p]][x + Xp[p]] = true;
                        }
                    }
                }
                else if (a[y][x] == 'K')
                {
                    wkY = y;
                    wkX = x;
                    int Xp[8] = {1, 0, -1, 0, 1, -1, 1, -1};
                    int Yp[8] = {1, 1, 1, -1, -1, -1, 0, 0};

                    for (int p = 0; p <= 7; ++p)
                    {
                        if (g(y + Yp[p], x + Xp[p]) == true)
                        {
                            Whit[y + Yp[p]][x + Xp[p]] = true;
                        }
                    }
                }

                else if (a[y][x] == 'n')
                {
                    int Xp[8] = {2, 1, -2, -1, -1, -2, 1, 2};
                    int Yp[8] = {1, 2, 1, 2, -2, -1, -2, -1};

                    for (int p = 0; p <= 7; ++p)
                    {
                        if (g(y + Yp[p], x + Xp[p]) == true)
                        {
                            Bhit[y + Yp[p]][x + Xp[p]] = true;
                        }
                    }
                }
                else if (a[y][x] == 'N')
                {
                    int Xp[8] = {2, 1, -2, -1, -1, -2, 1, 2};
                    int Yp[8] = {1, 2, 1, 2, -2, -1, -2, -1};

                    for (int p = 0; p <= 7; ++p)
                    {
                        if (g(y + Yp[p], x + Xp[p]) == true)
                        {
                            Whit[y + Yp[p]][x + Xp[p]] = true;
                        }
                    }
                }
            }
        }

        if (end == true)
        {
            break;
        }

        if (Bhit[wkY][wkX] == true)
        {
            cout << "Game #" << game << ": white king is in check." << '\n';
        }
        else if (Whit[bkY][bkX] == true)
        {
            cout << "Game #" << game << ": black king is in check." << '\n';
        }
        else
        {
            cout << "Game #" << game << ": no king is in check." << '\n';
        }

        ++game;
    }

    return 0;
}