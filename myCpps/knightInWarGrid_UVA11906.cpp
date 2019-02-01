#include <bits/stdc++.h>

using namespace std;

ifstream fin("knightInWarGrid_UVA11906.in");
ofstream fout("knightInWarGrid_UVA11906.out");

struct point
{
    int y;
    int x;
};

bool g(int y, int x, int c, int r)
{
    return y >= 0 && y <= c - 1 && x >= 0 && x <= r - 1;
}

void mark(int y, int x, int n, int m, vector<vector<char>> & a)
{
    int c = a.size(), r = a[0].size();
    
    vector<int> pY = {n, n, m, m, -1 * n, -1 * n, -1 * m, -1 * m},
                pX = {m, -1 * m, n, -1 * n, m, -1 * m, n, -1 * n};

    int _count = 0;
    for (int p = 0; p <= 7; ++p)
    {
        int nowY = y + pY[p], nowX = x + pX[p];

        if (g(nowY, nowX, c, r) == true)
        {
            if (a[nowY][nowX] != 'w')
            {
                ++_count;
            }
        }
    }

    if (m == n || n == 0 || m == 0)
    {
        _count /= 2;
    }

    if(_count % 2 == 0)
    {
        a[y][x] = 'e';
    }
    else
    {
        a[y][x] = 'o';
    }
}

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int c, r, n, m; fin >> r >> c >> m >> n;

        vector<vector<char>> a(c, vector<char>(r, '.'));

        int w; fin >> w;
        for (int c = 1; c <= w; ++c)
        {
            int y, x; fin >> x >> y;

            a[y][x] = 'w';
        }

        vector<int> pY = {n, n, m, m, -1 * n, -1 * n, -1 * m, -1 * m},
                    pX = {m, -1 * m, n, -1 * n, m, -1 * m, n, -1 * n};

        queue<point> q;
        point _temp{0, 0};
        q.push(_temp);
        while (!q.empty())
        {
            point now = q.front();
            q.pop();

            int y = now.y, x = now.x;

            if (a[y][x] != '.')
            {
                continue;
            }

            mark(y, x, n, m, a);

            for (int p = 0; p <= 7; ++p)
            {
                int nowY = y + pY[p], nowX = x + pX[p];

                if (g(nowY, nowX, c, r) == true)
                {
                    point temp{nowY, nowX};

                    q.push(temp);
                }
            }
        }

        int ansE = 0, ansO = 0;
        for (int y = 0; y <= c - 1; ++y)
        {
            for (int x = 0; x <= r - 1; ++x)
            {
                if (a[y][x] == 'e')
                {
                    ++ansE;
                }
                else if (a[y][x] == 'o')
                {
                    ++ansO;
                }
            }
        }

        fout << "Case " << t << ": " << ansE << ' ' << ansO << '\n';
    }

    return 0;
}
