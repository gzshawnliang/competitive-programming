#include <bits/stdc++.h>

using namespace std;

ifstream fin("Fire_UVA11624.in");
ofstream fout("Fire_UVA11624.out");

struct point
{
    int round;
    int y;
    int x;
};

struct grid
{
    int round;
    char ch;
};

bool g(int y, int x, int m, int n)
{
    return y >= 0 && y <= m - 1 && x >= 0 && x <= n - 1;
}

grid _grid(int round, char ch)
{
    grid temp{round, ch}; return temp;
}

point _point(int round, int y, int x)
{
    point temp{round, y, x}; return temp;
}

int main()
{
    vector<int> yP = {-1, 1, 0, 0},
                xP = {0, 0, -1, 1};

    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int m, n; fin >> m >> n;

        grid null{0, '.'};
        vector<vector<grid>> a(m, vector<grid>(n, null));

        queue<point> jPos, fPos;
        
        for (int y = 0; y <= m - 1; ++y)
        {
            for (int x = 0; x <= n - 1; ++x)
            {
                a[y][x].round = 0;
                fin >> a[y][x].ch;

                if (a[y][x].ch == 'J')
                {
                    jPos.push(_point(0, y, x));
                }
                else if (a[y][x].ch == 'F')
                {
                    fPos.push(_point(0, y, x));
                }
            }
        }

        while (fPos.empty() == false)
        {
            point now = fPos.front();
            fPos.pop();

            for (int p = 0; p <= 3; ++p)
            {
                point next;
                next.round = now.round + 1;
                next.y = now.y + yP[p];
                next.x = now.x + xP[p];

                if (g(next.y, next.x, m, n) == true)
                {
                    if (a[next.y][next.x].ch == '.' || a[next.y][next.x].ch == 'J')
                    {
                        a[next.y][next.x].round = next.round;
                        a[next.y][next.x].ch = 'F';

                        fPos.push(next);
                    }
                }
            }
        }

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        visit[jPos.front().y][jPos.front().x] = true;

        bool end = false;
        while (jPos.empty() == false && end == false)
        {
            point now = jPos.front();

            if (now.y == 0 || now.y == m - 1 || now.x == 0 || now.x == n - 1)
            {
                fout << now.round + 1 << '\n';
                end = true;
                break;
            }

            jPos.pop();

            for (int p = 0; p <= 3; ++p)
            {
                point next;
                next.round = now.round + 1;
                next.y = now.y + yP[p];
                next.x = now.x + xP[p];

                if (g(next.y, next.x, m, n) == true)
                {
                    if (visit[next.y][next.x] == false)
                    {
                        if (a[next.y][next.x].ch == '.' || (a[next.y][next.x].ch == 'F' && a[next.y][next.x].round > next.round))
                        {
                            

                            visit[next.y][next.x] = true;

                            jPos.push(next);
                        }
                    }
                }
            }
        }

        if (end == false)
        {
            fout << "IMPOSSIBLE\n";
        }
    }


    return 0;
} 
    
