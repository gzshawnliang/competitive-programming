#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("rooked.in");
ofstream fout("rooked.out");

int solve(vector<vector<char>> &a, int lvl)
{
    int size = a[0].size(), maxCount = 0;
    for (int y = 0; y <= size - 1; ++y)
    {
        for (int x = 0; x <= size - 1; ++x)
        {
            if (a[y][x] != 'X' && a[y][x] != 'a')
            {
                vector<vector<char>> temp = a;
                temp[y][x] = 'X';
                for (int p = y - 1; p >= 0; --p)
                {
                    if (temp[p][x] == 'X')
                    {
                        break;
                    }
                    temp[p][x] = 'a';
                }
                for (int p = y + 1; p <= size - 1; ++p)
                {
                    if (temp[p][x] == 'X')
                    {
                        break;
                    }
                    temp[p][x] = 'a';
                }
                for (int p = x - 1; p >= 0; --p)
                {
                    if (temp[y][p] == 'X')
                    {
                        break;
                    }
                    temp[y][p] = 'a';
                }
                for (int p = x + 1; p <= size - 1; ++p)
                {
                    if (temp[y][p] == 'X')
                    {
                        break;
                    }
                    temp[y][p] = 'a';
                }

                // if (lvl == 0)
                // {
                //     for (int y = 0; y <= size - 1; ++y)
                //     {
                //         for (int x = 0; x <= size - 1; ++x)
                //         {
                //             fout << temp[y][x] << ' ';
                //         }
                //         fout << '\n';
                //     }
                //     fout << '\n';
                // }

                maxCount = max(maxCount, solve(temp, lvl + 1) + 1);
            }
        }
    }

    return maxCount;
}

int main()
{
    while (true)
    {
        int size = 0;
        fin >> size;
        if (size == 0)
        {
            break;
        }
        vector<vector<char>> a(size, vector<char>(size));

        for (int y = 0; y <= size - 1; ++y)
        {
            for (int x = 0; x <= size - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        fout << solve(a, 0) << '\n';
    }

    return 0;
}