#include <bits/stdc++.h>

using namespace std;

ifstream fin("findingNemo_UVA1202.in");
ofstream fout("findingNemo_UVA1202.out");

struct wall
{
    int x;
    int y;
    int d;
    int t;
};

struct door
{
    int x;
    int y;
    int d;
};

int main()
{
    while (true)
    {
        int m = -1, n = -1; fin >> m >> n;
        if (m == -1 && n == -1) break;

        int maxX = 0, maxY = 0;
        vector<wall> w(m);
        vector<door> d(n);

        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> w[i].x >> w[i].y >> w[i].d >> w[i].t;

            if (w[i].d == 0)
            {
                maxX = max(maxX, w[i].x + w[i].t);
                maxY = max(maxY, w[i].y);
            }
            else
            {
                maxX = max(maxX, w[i].x);
                maxY = max(maxY, w[i].y + w[i].t);
            }
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> d[i].x >> d[i].y >> d[i].d;

            if (w[i].d == 0)
            {
                maxX = max(maxX, w[i].x + 1);
                maxY = max(maxY, w[i].y);
            }
            else
            {
                maxX = max(maxX, w[i].x);
                maxY = max(maxY, w[i].y + 1);
            }
        }

        char f[200 + 2][200 + 2][2];
        memset(f, '.', sizeof(f));

        //vector<vector<vector<char>>> f(maxX + 2, vector<vector<char>>(maxY + 2, vector<char>(2, '.')));

        for (int i = 0; i <= m - 1; ++i)
        {
            if (w[i].d == 0)
            {
                for (int c = 0; c <= w[i].t - 1; ++c)
                {
                    f[w[i].x + c][w[i].y][0] = 'w';
                }
            }
            else
            {
                for (int c = 0; c <= w[i].t - 1; ++c)
                {
                    f[w[i].x][w[i].y + c][1] = 'w';
                }
            }
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            f[d[i].x][d[i].y][d[i].d] = 'd';
        }

        int vt = maxX * maxY;
        vector<int> xp = {-1, 0, 1, 0}, yp = {0, -1, 0, 1};
        vector<vector<int>> g(vt), a(vt, vector<int>(vt, INT_MAX));

        for (int y = 0; y <= maxY - 1; ++y)
        {
            for (int x = 0; x <= maxX - 1; ++x)
            {
                int NO = x + y * maxX;
                fout << NO << '\n';

                a[NO][NO] = 0;

                for (int p = 0; p <= 3; ++p)
                {
                    int nowX = x + xp[p], nowY = y + yp[p], nowNO = nowX + nowY * maxX;

                    if (nowNO < 0 || nowNO > vt - 1)
                    {
                        continue;
                    }
                }
            }
        }

        double tempEx, tempEy; fin >> tempEx >> tempEy;
    }

    return 0;
}
