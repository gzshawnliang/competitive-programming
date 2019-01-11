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

using namespace std;

ifstream fin("mooyomooyo.in");
ofstream fout("mooyomooyo.out");

bool g(int y, int x, int n)
{
    return y >= 0 && y <= n - 1 && x >= 0 && x <= 9;
}

void del(int n, int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX, n) == false)
    {
        return;
    }
    else if (a[nowY][nowX] == '0' || a[nowY][nowX] != color)
    {
        return;
    }
    else
    {
        a[nowY][nowX] = '0';
        del(n, nowY + 1, nowX, a, color);
        del(n, nowY - 1, nowX, a, color);
        del(n, nowY, nowX + 1, a, color);
        del(n, nowY, nowX - 1, a, color);
    }
}

int _count(int n, int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX, n) == false)
    {
        return 0;
    }
    else if (a[nowY][nowX] == '0' || a[nowY][nowX] != color)
    {
        return 0;
    }
    else
    {   
        a[nowY][nowX] = '0';

        int ans = 1;
        ans += _count(n, nowY + 1, nowX, a, color);
        ans += _count(n, nowY - 1, nowX, a, color);
        ans += _count(n, nowY, nowX + 1, a, color);
        ans += _count(n, nowY, nowX - 1, a, color);

        return ans;
    }
}

void fall(int n, vector<vector<char>> & a)
{
    for (int x = 0; x <= 9; ++x)
    {
        int y = n - 1;
        while (y >= 0)
        {
            if (a[y][x] == '0')
            {
                int up = 0;
                while (true)
                {
                    if (y < 0)
                    {
                        break;
                    }
                    else if (a[y][x] != '0')
                    {
                        break;
                    }

                    --y;
                    ++up;
                }

                while (true)
                {
                    if (y < 0)
                    {
                        break;
                    }
                    else if (a[y][x] == '0')
                    {
                        y = y + up + 1;
                        break;
                    }

                    a[y + up][x] = a[y][x];
                    a[y][x] = '0';
                    --y;
                }
                up = 0;
            }
            else
            {
                --y;
            }
        }
    }
}

void connect(int n, vector<vector<char>> & a)
{
    for (int x = 9; x >= 0; --x)
    {
        bool ok = true;
        for (int y = 0; y <= n - 1; ++y)
        {
            if (a[y][x] != '0')
            {
                ok = false;
                break;
            }
        }

        if (ok == true)
        {
            for (int x0 = x; x0 <= 9; ++x0)
            {
                for (int y = 0; y <= n - 1; ++y)
                {
                    a[y][x0] = a[y][x0 + 1];
                    a[y][x0 + 1] = '0';
                }
            }
        }
    }
}

int main()
{
    //fall(n, a);
    //connect(n, a);

    int n, k; fin >> n >> k;

    vector<vector<char>> a(n, vector<char>(10));
    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= 9; ++x)
        {
            fin >> a[y][x];
        }
    }

    while (true)
    {
        bool ok = false;
        vector<vector<char>> temp = a;

        for (int x = 0; x <= 9; ++x)
        {
            for (int y = n - 1; y >= 0; --y)
            {
                if (temp[y][x] != '0')
                {
                    int res = _count(n, y, x, temp, temp[y][x]);
                    if (res >= k)
                    {
                        del(n, y, x, a, a[y][x]);
                        ok = true;
                    }
                }
            }
        }

        if (ok == false)
        {
            break;
        }

        fall(n, a);
    }

    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= 9; ++x)
        {
            fout << a[y][x];
        }
        fout << '\n';
    }

    return 0;
}