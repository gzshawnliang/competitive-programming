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


bool g(int y, int x)
{
    return y >= 0 && y <= 9 && x >= 0 && x <= 14;
}

void del(int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX) == false)
    {
        return;
    }
    else if (a[nowY][nowX] == '.' || a[nowY][nowX] != color)
    {
        return;
    }
    else
    {
        a[nowY][nowX] = '.';
        del(nowY + 1, nowX, a, color);
        del(nowY - 1, nowX, a, color);
        del(nowY, nowX + 1, a, color);
        del(nowY, nowX - 1, a, color);
    }
}

int _count(int nowY, int nowX, vector<vector<char>> & a, char color)
{
    if (g(nowY, nowX) == false)
    {
       	return 0;
    }
    else if (a[nowY][nowX] == '.' || a[nowY][nowX] != color)
    {
       	return 0;
    }
    else
    {   
        a[nowY][nowX] = '.';

        int ans = 1;
        ans += _count(nowY + 1, nowX, a, color);
        ans += _count(nowY - 1, nowX, a, color);
        ans += _count(nowY, nowX + 1, a, color);
        ans += _count(nowY, nowX - 1, a, color);

        return ans;
    }
}

void fall(vector<vector<char>> & a)
{
    for (int x = 0; x <= 14; ++x)
    {
        int y = 9;
        while (y >= 0)
        {
            if (a[y][x] == '.')
            {
                int up = 0;
                while (true)
                {
                    if (y < 0)
                    {
                        break;
                    }
                    else if (a[y][x] != '.')
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
                    else if (a[y][x] == '.')
                    {
                        y = y + up + 1;
                        break;
                    }

                    a[y + up][x] = a[y][x];
                    a[y][x] = '.';
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

void connect(vector<vector<char>> & a)
{
    for (int x = 13; x >= 0; --x)
    {
        bool ok = true;
        for (int y = 0; y <= 9; ++y)
        {
            if (a[y][x] != '.')
            {
                ok = false;
                break;
            }
        }

        if (ok == true)
        {
            for (int x0 = x; x0 <= 13; ++x0)
            {
                for (int y = 0; y <= 9; ++y)
                {
                    a[y][x0] = a[y][x0 + 1];
                    a[y][x0 + 1] = '.';
                }
            }
        }
    }
}

void reflesh(int nowY, int nowX, vector<vector<char>> & a)
{
    del(nowY, nowX, a, a[nowY][nowX]);
    fall(a);
    connect(a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        if (c > 1)
        {
            cout << '\n';
        }
        cout << "Game " << c << ":\n\n";

        vector<vector<char>> a(10, vector<char>(15));
        for (int y = 0; y <= 9; ++y)
        {
            for (int x = 0; x <= 14; ++x)
            {
                cin >> a[y][x];
            }
        }

        int move = 0, finalScore = 0;
        while (true)
        {
            ++move;

            vector<vector<char>> temp = a;
            int maxCount = 0, posY, posX;
            char color;
            for (int x = 0; x <= 14; ++x)
            {
                for (int y = 9; y >= 0; --y)
                {
                    if (temp[y][x] != '.')
                    {
                        int res = _count(y, x, temp, temp[y][x]);
                        if (maxCount < res)
                        {
                            maxCount = res;
                            posY = y; posX = x; color = a[y][x];
                        }
                    }
                }
            }

            if (maxCount < 2)
            {
                break;
            }

            reflesh(posY, posX, a);

            cout << "Move " << move << " at (" << 10 - posY << ',' << posX + 1 << "): removed " << maxCount << " balls of color " << color << ", got " << (maxCount - 2) * (maxCount - 2) << " points.\n";
            finalScore += (maxCount - 2) * (maxCount - 2);

        }

        int remaining = 0;
        for (int y = 0; y <= 9; ++y)
        {
            for (int x = 0; x <= 14; ++x)
            {
                if (a[y][x] != '.')
                {
                    ++remaining;
                }
            }
        }

        if (remaining == 0)
        {
            finalScore += 1000;
        }

        cout << "Final score: " << finalScore << ", with " << remaining << " balls remaining.\n";
    }

   	cout.flush();
   	return 0;
}
