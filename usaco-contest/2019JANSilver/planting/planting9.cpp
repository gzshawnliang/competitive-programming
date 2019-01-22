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

ifstream fin("planting.in");
ofstream fout("planting.out");

void solve(int u, int & ans, vector<int> & color, vector<vector<int>> & g)
{
    if (color[u] > 0)
    {
        return;
    }

    vector<bool> s(ans + 1, false);

    int sizeU = g[u].size();
    for (int i = 0; i <= sizeU - 1; ++i)
    {
        int v = g[u][i];

        s[color[v]] = true;

        int sizeV = g[v].size();
        for (int j = 0; j <= sizeV - 1; ++j)
        {
            s[color[g[v][j]]] = true;
        }
    }

    bool _find = false;
    for (int co = 1; co <= ans; ++co)
    {
        if (s[co] == false)
        {
            color[u] = co;
            _find = true;

            break;
        }
    }

    if (_find == false)
    {
        ++ans;
        color[u] = ans;
    }

    for (int i = 0; i <= sizeU - 1; ++i)
    {
        int v = g[u][i];

        solve(v, ans, color, g);
    }
}

int main()
{
    int n; fin >> n;

    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 1;

    solve(1, ans, color, g);

    fout << ans << '\n';

    return 0;
}
