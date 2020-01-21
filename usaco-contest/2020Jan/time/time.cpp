#include <bits/stdc++.h>

using namespace std;

ifstream fin("time.in");
ofstream fout("time.out");

const int maxT = 500, inf = INT_MAX / 2, rot = 1;

int main()
{
    int n, m, c; fin >> n >> m >> c;
    vector<int> val(n + 1, 0);
    for (int u = 1; u <= n; ++u) fin >> val[u];

    vector<vector<int>> f(n + 1);

    for (int cfm = 1; cfm <= m; ++cfm)
    {
        int u, v; fin >> u >> v;
        f[v].push_back(u);
    }

    int ans = 0;
    vector<int> dp_last(n + 1, -1 * inf), dp(n + 1, -1 * inf);
        dp_last[rot] = 0;

    for (int t = 1; t <= maxT; ++t)
    {
        for (int v = 1; v <= n; ++v)
        {
            int siz = f[v].size();
            for (int i = 0; i <= siz - 1; ++i)
            {
                int u = f[v][i];
                dp[v] = max(dp[v], dp_last[u] + val[v] - c * (2 * t - 1));
            }
        }

        // for (int u = 1; u <= n; ++u)
        // {
        //     fout << max(dp[u], -100) << ' ';
        // }
        // fout << '\n';

        ans = max(ans, dp[rot]);

        dp_last = dp;
        for (int u = 1; u <= n; ++u) dp[u] = -1 * inf;
    }

    fout << ans << '\n';

    return 0;
}
