/*
===========================================================
* @Name:           Problem 3. Moortal Cowmbat 
* @Author:         Shawn
* @create Time:    2020/1/10 22:19:27
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=971&lang=zh
* @Description:    USACO 2019 December Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowmbat.in");
ofstream fout("cowmbat.out");

const int inf = INT_MAX / 4;

int main()
{
    int n, m, k; fin >> n >> m >> k;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        char ch; fin >> ch;
        a[i] = (ch - 'a');
    }

    vector<vector<int>> convert(m, vector<int>(m, 0));
    for (int i = 0; i <= m - 1; ++i)
    {
        for (int j = 0; j <= m - 1; ++j)
        {
            fin >> convert[i][j];
        }
    }

    for (int p = 0; p <= m - 1; ++p)
    {
        for (int i = 0; i <= m - 1; ++i)
        {
            for (int j = 0; j <= m - 1; ++j)
            {
                convert[i][j] = min(convert[i][j], convert[i][p] + convert[p][j]);
            }
        }
    }

    vector<int> g(n + 1, inf);
    vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(m, vector<int>(n + 1, inf)));
    g[0] = 0;

    int ans = inf;
    for (int i = 1; i <= n; ++i)
    {
        for (int p = 0; p <= m - 1; ++p)
        {
            for (int x = 1; x <= n; ++x)
            {
                if (x == 1)
                {
                    f[i][p][x] = g[i - 1] + convert[a[i]][p];
                }
                else
                {
                    f[i][p][x] = f[i - 1][p][x - 1] + convert[a[i]][p];

                    if (x >= k) g[i] = min(g[i], f[i][p][x]);

                    if (i == n && x >= k) ans = min(ans, f[i][p][x]);
                }
            }
        }
    }

    fout << ans << '\n';

    return 0;
}
