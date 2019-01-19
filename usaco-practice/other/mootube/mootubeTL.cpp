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

void solve(int ult, int u, vector<bool> & dp, vector<vector<int>> & a, vector<vector<int>> & s, vector<vector<int>> & d)
{
    dp[u] = true;

    int size = s[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = s[u][i];

        if (dp[v] == true)
        {
            continue;
        }

        d[ult][v] = min(d[ult][u], d[u][v]);

        solve(ult, v, dp, a, s, d);
    }
}

int main()
{
    int n, q; fin >> n >> q;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, -1)),
                        s(n + 1), 
                        d(n + 1, vector<int>(n + 1, inf));

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v, r; fin >> u >> v >> r;

        a[u][v] = r; a[v][u] = r;
        s[u].push_back(v); s[v].push_back(u);
        d[u][v] = r; d[v][u] = r;
    }

    for (int u = 1; u <= n; ++u)
    {
        vector<bool> dp(n + 1, false);

        solve(u, u, dp, a, s, d);
    }

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
