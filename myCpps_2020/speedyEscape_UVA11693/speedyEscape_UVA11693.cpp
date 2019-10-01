#include <bits/stdc++.h>

using namespace std;

ifstream fin("speedyEscape_UVA11693.in");
ofstream fout("speedyEscape_UVA11693.out");

const int inf = INT_MAX / 2;
const double ps = 160.0;

int main()
{
    fout << fixed << setprecision(10);

    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m, e; fin >> n >> m >> e;
        
        vector<int> exits(e);
        vector<vector<int>> d(n + 1, vector<int>(n + 1, inf)),
                            a(n + 1, vector<int>(n + 1, inf)),
                            g(n + 1);

        for (int c = 1; c <= m; ++c)
        {
            int u, v, l; fin >> u >> v >> l;
            d[u][v] = l; d[v][u] = l; a[u][v] = l; a[v][u] = l;
            g[u].push_back(v); g[v].push_back(u);
        }

        for (int i = 0; i <= e - 1; ++i)
        {
            fin >> exits[i];
        }

        int b, p; fin >> b >> p;

        for (int u = 1; u <= n; ++u)
        {
            d[u][u] = 0;
        }
        for (int k = 1; k <= n; ++k)
        {
            for (int u = 1; u <= n; ++u)
            {
                for (int v = 1; v <= n; ++v)
                {
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                }
            }
        }

        
    }

    return 0;
}
