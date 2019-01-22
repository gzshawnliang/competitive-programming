#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
}

void solve(int y, int x, int & s, int & c, vector<vector<char>> & a)
{
    int n = a.size();

    if (g(y, x, n) == false)
    {
        return;
    }
    else if (a[y][x] == '.' || a[y][x] == 'x')
    {
        return;
    }
    else
    {
        a[y][x] = 'x';

        ++s;

        vector<int> yP = {0,1,0,-1};
        vector<int> xP = {1,0,-1,0};

        for (int p = 0; p <= 3; ++p)
        {
            int nowY = y + yP[p], nowX = x + xP[p];

            if (g(nowY, nowX, n) == false)
            {
                ++c;
            }
            else if (a[nowY][nowX] == '.')
            {
                ++c;
            }
        }

        for (int p = 0; p <= 3; ++p)
        {
            int nowY = y + yP[p], nowX = x + xP[p];

            solve(nowY, nowX, s, c, a);
        }
    }
}

int main()
{
    int n; fin >> n;

    vector<vector<char>> a(n, vector<char>(n, 0));

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            fin >> a[y][x];
        }
    }

    int ansS = 0, ansC = 0;
    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= n - 1; ++x)
        {
            if (a[y][x] == '#')
            {
                int s = 0, c = 0;
                solve(y, x, s, c, a);

                if (s >= ansS)
                {
                    if (s > ansS || c < ansC)
                    {
                        ansS = s;
                        ansC = c;
                    }
                }
            }
        }
    }

    fout << ansS << ' ' << ansC << '\n';

    return 0;
}
