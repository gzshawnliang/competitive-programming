#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
};

struct chess
{
    char type;
    point Npos;
};

int main()
{
    int Xp[4] = {0, 1, 0, -1};
    int Yp[4] = {1, 0, -1, 0};

    while (true)
    {
        int number;
        vector<chess> chesses;
        vector<vector<char>> a(10, vector<char>(9, '.'));
        point general;
        cin >> number >> general.x >> general.y;

        if (number == 0)
        {
            break;
        }

        for (int i = 1; i <= number; ++i)
        {
            chess temp;
            cin >> temp.type >> temp.Npos.x >> temp.Npos.y;
            a[temp.Npos.x - 1][temp.Npos.y - 1] = temp.type;
            chesses.push_back(temp);
        }

        int size = chesses.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (chesses[i].type == 'G')
            {
                for (int j = chesses[i].Npos.x - 1; j >= 1; --j)
                {
                    if (a[j - 1][chesses[i].Npos.y - 1] == '.' || a[j - 1][chesses[i].Npos.y - 1] == 'x')
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'x';
                    }
                    else
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'P';
                        break;
                    }
                }
            }
            else if (chesses[i].type == 'R')
            {
                for (int j = chesses[i].Npos.x - 1; j >= 1; --j)
                {
                    if (a[j - 1][chesses[i].Npos.y - 1] == '.' || a[j - 1][chesses[i].Npos.y - 1] == 'x')
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'x';
                    }
                    else
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'P';
                        break;
                    }
                }
                for (int j = chesses[i].Npos.x + 1; j <= 10; ++j)
                {
                    if (a[j - 1][chesses[i].Npos.y - 1] == '.' || a[j - 1][chesses[i].Npos.y - 1] == 'x')
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'x';
                    }
                    else
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'P';
                        break;
                    }
                }
                for (int j = chesses[i].Npos.y + 1; j <= 9; ++j)
                {
                    if (a[chesses[i].Npos.x - 1][j - 1] == '.' || a[chesses[i].Npos.x - 1][j - 1] == 'x')
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'x';
                    }
                    else
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'P';
                        break;
                    }
                }
                for (int j = chesses[i].Npos.y - 1; j >= 1; --j)
                {
                    if (a[chesses[i].Npos.x - 1][j - 1] == '.' || a[chesses[i].Npos.x - 1][j - 1] == 'x')
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'x';
                    }
                    else
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'P';
                        break;
                    }
                }
            }
            else if (chesses[i].type == 'H')
            {
                if (chesses[i].Npos.x >= 0 && chesses[i].Npos.x <= 9 && chesses[i].Npos.y - 1 >= 0 && chesses[i].Npos.y - 1 <= 8)
                {
                    if (a[chesses[i].Npos.x][chesses[i].Npos.y - 1] == '.' || a[chesses[i].Npos.x][chesses[i].Npos.y - 1] == 'x')
                    {
                        if (chesses[i].Npos.x + 1 >= 0 && chesses[i].Npos.x + 1 <= 9 && chesses[i].Npos.y - 2 >= 0 && chesses[i].Npos.y - 2 <= 8)
                            a[chesses[i].Npos.x + 1][chesses[i].Npos.y - 2] = 'x';
                        if (chesses[i].Npos.x + 1 >= 0 && chesses[i].Npos.x + 1 <= 9 && chesses[i].Npos.y >= 0 && chesses[i].Npos.y <= 8)
                            a[chesses[i].Npos.x + 1][chesses[i].Npos.y] = 'x';
                    }
                }
                if (chesses[i].Npos.x - 2 >= 0 && chesses[i].Npos.x - 2 <= 9 && chesses[i].Npos.y - 1 >= 0 && chesses[i].Npos.y - 1 <= 8)
                {
                    if (a[chesses[i].Npos.x - 2][chesses[i].Npos.y - 1] == '.' || a[chesses[i].Npos.x - 2][chesses[i].Npos.y - 1] == 'x')
                    {
                        if (chesses[i].Npos.x - 3 >= 0 && chesses[i].Npos.x - 3 <= 9 && chesses[i].Npos.y - 2 >= 0 && chesses[i].Npos.y - 2 <= 8)
                            a[chesses[i].Npos.x - 3][chesses[i].Npos.y - 2] = 'x';
                        if (chesses[i].Npos.x - 3 >= 0 && chesses[i].Npos.x - 3 <= 9 && chesses[i].Npos.y >= 0 && chesses[i].Npos.y <= 8)
                            a[chesses[i].Npos.x - 3][chesses[i].Npos.y] = 'x';
                    }
                }
                if (chesses[i].Npos.x - 1 >= 0 && chesses[i].Npos.x - 1 <= 9 && chesses[i].Npos.y >= 0 && chesses[i].Npos.y <= 8)
                {
                    if (a[chesses[i].Npos.x - 1][chesses[i].Npos.y] == '.' || a[chesses[i].Npos.x - 1][chesses[i].Npos.y] == 'x')
                    {
                        if (chesses[i].Npos.x >= 0 && chesses[i].Npos.x <= 9 && chesses[i].Npos.y + 1 >= 0 && chesses[i].Npos.y + 1 <= 8)
                            a[chesses[i].Npos.x][chesses[i].Npos.y + 1] = 'x';
                        if (chesses[i].Npos.x - 2 >= 0 && chesses[i].Npos.x - 2 <= 9 && chesses[i].Npos.y + 1 >= 0 && chesses[i].Npos.y + 1 <= 8)
                            a[chesses[i].Npos.x - 2][chesses[i].Npos.y + 1] = 'x';
                    }
                }
                if (chesses[i].Npos.x - 1 >= 0 && chesses[i].Npos.x - 1 <= 9 && chesses[i].Npos.y - 2 >= 0 && chesses[i].Npos.y - 2 <= 8)
                {
                    if (a[chesses[i].Npos.x - 1][chesses[i].Npos.y - 2] == '.' || a[chesses[i].Npos.x - 1][chesses[i].Npos.y - 2] == 'x')
                    {
                        if (chesses[i].Npos.x >= 0 && chesses[i].Npos.x <= 9 && chesses[i].Npos.y - 3 >= 0 && chesses[i].Npos.y - 3 <= 8)
                            a[chesses[i].Npos.x][chesses[i].Npos.y - 3] = 'x';
                        if (chesses[i].Npos.x - 2 >= 0 && chesses[i].Npos.x - 2 <= 9 && chesses[i].Npos.y - 3 >= 0 && chesses[i].Npos.y - 3 <= 8)
                            a[chesses[i].Npos.x - 2][chesses[i].Npos.y - 3] = 'x';
                    }
                }
            }
            else
            {
                bool ready = false;
                for (int j = chesses[i].Npos.x - 1; j >= 1; --j)
                {
                    if (a[j - 1][chesses[i].Npos.y - 1] != '.' && a[j - 1][chesses[i].Npos.y - 1] != 'x' && ready == false)
                    {
                        ready = true;
                    }
                    else if ((a[j - 1][chesses[i].Npos.y - 1] == '.' || a[j - 1][chesses[i].Npos.y - 1] == 'x') && ready == true)
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'x';
                    }
                    else if (ready == true)
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'P';
                        break;
                    }
                }
                ready = false;
                for (int j = chesses[i].Npos.x + 1; j <= 10; ++j)
                {
                    if (a[j - 1][chesses[i].Npos.y - 1] != '.' && a[j - 1][chesses[i].Npos.y - 1] != 'x' && ready == false)
                    {
                        ready = true;
                    }
                    else if ((a[j - 1][chesses[i].Npos.y - 1] == '.' || a[j - 1][chesses[i].Npos.y - 1] == 'x') && ready == true)
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'x';
                    }
                    else if (ready == true)
                    {
                        a[j - 1][chesses[i].Npos.y - 1] = 'P';
                        break;
                    }
                }
                ready = false;
                for (int j = chesses[i].Npos.y - 1; j >= 1; --j)
                {
                    if (a[chesses[i].Npos.x - 1][j - 1] != '.' && a[chesses[i].Npos.x - 1][j - 1] != 'x' && ready == false)
                    {
                        ready = true;
                    }
                    else if ((a[chesses[i].Npos.x - 1][j - 1] == '.' || a[chesses[i].Npos.x - 1][j - 1] == 'x') && ready == true)
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'x';
                    }
                    else if (ready == true)
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'P';
                        break;
                    }
                }
                ready = false;
                for (int j = chesses[i].Npos.y + 1; j <= 9; ++j)
                {
                    if (a[chesses[i].Npos.x - 1][j - 1] != '.' && a[chesses[i].Npos.x - 1][j - 1] != 'x' && ready == false)
                    {
                        ready = true;
                    }
                    else if ((a[chesses[i].Npos.x - 1][j - 1] == '.' || a[chesses[i].Npos.x - 1][j - 1] == 'x') && ready == true)
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'x';
                    }
                    else if (ready == true)
                    {
                        a[chesses[i].Npos.x - 1][j - 1] = 'P';
                        break;
                    }
                }
            }
        }

        // for (int i = 0; i <= 9; ++i)
        // {
        //     for (int j = 0; j <= 8; ++j)
        //     {
        //         cout << a[i][j];
        //     }
        //     cout << '\n';
        // }

        bool ok = true;
        for (int i = general.x; i <= 10; ++i)
        {
            if (i == 10 && a[i - 1][general.y - 1] == 'G')
            {
                break;
            }
            else if (a[i - 1][general.y - 1] != '.' && a[i - 1][general.y - 1] != 'x')
            {
                ok = true;
                break;
            }
        }

        if (ok == false)
        {
            cout << "NO" << '\n';
            continue;
        }

        bool done = false;
        for (int i = 0; i <= 3; ++i)
        {
            if (general.x + Xp[i] >= 1 && general.x + Xp[i] <= 3 && general.y + Yp[i] >= 4 && general.y + Yp[i] <= 6)
            {
                if (a[general.x + Xp[i] - 1][general.y + Yp[i] - 1] != 'x' && a[general.x + Xp[i] - 1][general.y + Yp[i] - 1] != 'P')
                {
                    cout << "NO" << '\n';
                    done = true;
                    break;
                }
            }
        }

        if (done == false)
        {
            cout << "YES" << '\n';
        }
    }

    return 0;
}