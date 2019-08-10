#include <bits/stdc++.h>

using namespace std;

ifstream fin("aWalkThroughTheForest_UVA10917.in");
ofstream fout("aWalkThroughTheForest_UVA10917.out");

using ll = long long;
const ll inf = LLONG_MAX / 2;

struct segment
{
    ll u;
    ll d;

    bool operator < (const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(ll u, ll d)
{
    segment temp{u, d}; return temp;
}

ll count(ll u, vector<ll> & dp, vector<ll> & dis, vector<vector<ll>> & g)
{
    if (u == 2)
    {
        return 1;
    }
    else if (dp[u] != -1)
    {
        return dp[u];
    }
    else
    {
        ll ans = 0;

        ll size = g[u].size();
        for (ll i = 0; i <= size - 1; ++i)
        {
            ll v = g[u][i];

            if (dis[v] < dis[u])
            {
                ans += count(v, dp, dis, g);
            }
        }

        dp[u] = ans;
        return ans;
    }
}

int main()
{
    while (true)
    {
        ll n = 0; fin >> n;
        if (n == 0) break;

        ll m; fin >> m;

        vector<vector<ll>> a(n + 1, vector<ll>(n + 1, inf)),
                           g(n + 1);
        for (ll c = 1; c <= m; ++c)
        {
            ll u, v, d; fin >> u >> v >> d;

            a[u][v] = d; a[v][u] = a[u][v];
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<ll> dis(n + 1, inf);
        priority_queue<segment> pq; pq.push(_segment(2, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.d >= dis[now.u]) continue;
            dis[now.u] = now.d;

            ll size = g[now.u].size();
            for (ll i = 0; i <= size - 1; ++i)
            {
                ll v = g[now.u][i];

                pq.push(_segment(v, now.d + a[now.u][v]));
            }
        }

        vector<ll> dp(n + 1, -1);
        fout << count(1, dp, dis, g) << '\n';
    }

    return 0;
}
