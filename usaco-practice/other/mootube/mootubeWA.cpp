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

ifstream fin("mootube.in");
ofstream fout("mootube.out");

const int inf = 2147483647;

void solve(int u, vector<bool> & visit, vector<vector<int>> & s, vector<vector<int>> & d)
{
    visit[u] = true;

    int size = s[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = s[u][i];

        if (visit[v] == true)
        {
            continue;
        }

        solve(v, visit, s, d);

        int n = s.size() - 1;

        for (int w = 1; w <= n; ++w)
        {
            if (w == u || d[v][w] == inf)
            {
                continue;
            }

            d[u][w] = min(d[u][v], d[w][v]);
            d[w][u] = d[u][w];
        }

        for (int w = 1; w <= n; ++w)
        {
            if (w == v || d[u][w] == inf)
            {
                continue;
            }

            d[v][w] = min(d[v][u], d[u][w]);
            d[w][v] = d[v][w];
        }
    }
}

int main()
{
    int n, q; fin >> n >> q;

    vector<bool>        visit(n + 1, false);
    vector<vector<int>> s(n + 1), 
                        d(n + 1, vector<int>(n + 1, inf));

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v, r; fin >> u >> v >> r;

        s[u].push_back(v); s[v].push_back(u);
        d[u][v] = r; d[v][u] = r;
    }
    
    solve(1, visit, s, d);

    for (int c = 1; c <= q; ++c)
    {
        int k, u, ans = 0; fin >> k >> u;

        for (int v = 1; v <= n; ++v)
        {
            if (u == v)
            {
                continue;
            }
            else if (d[u][v] >= k && d[u][v] != inf)
            {
                ++ans;
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
