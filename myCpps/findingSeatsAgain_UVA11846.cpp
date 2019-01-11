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

using namespace std;

ifstream fin("findingSeatsAgain_UVA11846.in");
ofstream fout("findingSeatsAgain_UVA11846.out");

bool g(int nowY, int nowX, int n)
{
    return nowY >= 0 && nowY <= n - 1 && nowX >= 0 && nowX <= n - 1;
}

void solve(int n, int nowY, int nowX, vector<vector<char>> & a, vector<vector<char>> seat, char nowChar)
{
    if (nowX == n)
    {
        nowX = 0;
        ++nowY;
    }

    if (nowY == n)
    {
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                fout << seat[y][x];
            }

            fout << '\n';
        }
    }
    else if (a[nowY][nowX] == '.')
    {
        solve(n, nowY, nowX + 1, a, seat, nowChar);
    }
    else
    {
        for (int y1 = 0; y1 <= nowY; ++y1)
        {
            for (int x1 = 0; x1 <= nowX; ++x1)
            {
                for (int y2 = nowY; y2 <= n - 1; ++y2)
                {
                    for (int x2 = nowX; x2 <= n - 1; ++x2)
                    {
                        if ((y2 - y1 + 1) * (x2 - x1 + 1) < a[nowY][nowX] - '0')
                        {
                            continue;
                        }
                        else if ((y2 - y1 + 1) * (x2 - x1 + 1) > a[nowY][nowX] - '0')
                        {
                            break;
                        }

                        bool ok = true;
                        for (int i = y1; i <= y2 && ok == true; ++i)
                        {
                            for (int j = x1; j <= x2 && ok == true; ++j)
                            {
                                if (seat[i][j] != '-')
                                {
                                    ok = false;
                                }
                            }
                        }

                        if (ok == true)
                        {
                            vector<vector<char>> temp = seat;
                            for (int i = y1; i <= y2 && ok == true; ++i)
                            {
                                for (int j = x1; j <= x2 && ok == true; ++j)
                                {
                                    temp[i][j] = nowChar;
                                }
                            }

                            solve(n, nowY, nowX + 1, a, temp, nowChar + 1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while (true)
    {
        int n = 0, k = 0;
        fin >> n >> k;

        if (n == 0)
        {
            break;
        }

        vector<vector<char>> a(n, vector<char>(n));
        vector<vector<char>> seat(n, vector<char>(n, '-'));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        solve(n, 0, 0, a, seat, 'A');
    }

    return 0;
}