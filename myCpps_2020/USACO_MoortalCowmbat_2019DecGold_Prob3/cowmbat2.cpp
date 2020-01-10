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

    vector<vector<int>> convertAll(n + 1, vector<int>(m, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int p = 0; p <= m - 1; ++p)
        {
            convertAll[i][p] = convertAll[i - 1][p] + convert[a[i]][p];
        }
    }

    vector<int> g(n + 1, inf);
    vector<int> f(m + 1, inf);
    g[0] = 0;

    for (int i = k; i <= n; ++i)
    {
        for (int p = 0; p <= m - 1; ++p)
        {
            f[p] = min(f[p] + convert[a[i]][p], g[i - k] + convertAll[i][p] - convertAll[i - k][p]);
            g[i] = min(g[i], f[p]);
        }
    }

    fout << g[n] << '\n';

    return 0;
}
