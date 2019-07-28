#include <bits/stdc++.h>

using namespace std;

ifstream fin("routeChange_UVA11833.in");
ofstream fout("routeChange_UVA11833.out");

const int inf = INT_MAX / 3;

struct segment
{
    int u;
    int t;

    bool operator < (const segment & temp) const
    {
        return t > temp.t;
    }
};
segment _segment(int u, int t)
{
    segment temp{u, t}; return temp;
}

int main()
{
    while (true)
    {
        int n = 0, m = 0, cc = 0, kk = 0; fin >> n >> m >> cc >> kk;
        if (n + m + cc + kk == 0) break;

        vector<vector<int>> a(n, vector<int>(n, inf)),
                            g(n);
        for (int c = 1; c <= m; ++c)
        {
            int u, v, t; fin >> u >> v >> t;
            a[u][v] = t; a[v][u] = a[u][v];
            g[u].push_back(v); g[v].push_back(u);
        }

        int temp = 0;
        vector<int> d(cc, 0);
        for (int u = cc - 2; u >= 0; --u)
        {
            temp += a[u][u + 1];
            d[u] = temp;
        }

        vector<int> dp(n, inf);
        priority_queue<segment> pq; pq.push(_segment(kk, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.t >= dp[now.u]) continue;

            dp[now.u] = now.t;

            if (now.u <= cc - 1)
            {
                dp[cc - 1] = min(dp[cc - 1], now.t + d[now.u]);
                continue;
            }

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                pq.push(_segment(v, now.t + a[now.u][v]));
            }
        }

        fout << dp[cc - 1] << '\n';
    }

    return 0;
}
