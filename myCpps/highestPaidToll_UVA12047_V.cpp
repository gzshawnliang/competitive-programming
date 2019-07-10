#include <bits/stdc++.h>

using namespace std;

ifstream fin("highestPaidToll_UVA12047.in");
ofstream fout("highestPaidToll_UVA12047.out");

const int inf = INT_MAX / 2;

struct segment
{
    int u;
    int curPMax;
    int curPTotal;

    bool operator < (const segment & temp) const
    {
        if (curPMax != temp.curPMax) return curPMax < temp.curPMax;
        else return curPTotal > temp.curPTotal;
    }
};
segment _segment(int u, int curPMax, int curPTotal)
{
    segment temp{u, curPMax, curPTotal}; return temp;
}

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m, s, e, pMax; fin >> n >> m >> s >> e >> pMax;

        vector<vector<int>> a(n + 1, vector<int>(n + 1, -1)),
                            g(n + 1);
        for (int c = 1; c <= m; ++c)
        {
            int u, v, p; fin >> u >> v >> p;
            a[u][v] = p;
            g[u].push_back(v);
        }

        if (t == 9)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        bool isFirst = true;
        int ans = -1;
        vector<vector<int>> dp(n + 1, vector<int>(pMax + 1, -1)); dp[s][0] = 0;
        priority_queue<segment> pq; pq.push(_segment(s, 0, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.curPMax <= dp[now.u][now.curPTotal] && isFirst == false) continue;
            isFirst = false;
            dp[now.u][now.curPTotal] = now.curPMax;

            if (now.u == e) ans = max(ans, now.curPMax);

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                if (now.curPTotal + a[now.u][v] <= pMax)
                {
                    pq.push(_segment(v, max(now.curPMax, a[now.u][v]), now.curPTotal + a[now.u][v]));
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
