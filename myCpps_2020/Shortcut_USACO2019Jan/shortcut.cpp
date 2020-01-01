#include <bits/stdc++.h>

using namespace std;

ifstream fin("shortcut.in");
ofstream fout("shortcut.out");

using ll = long long;

const ll inf = LLONG_MAX / 2;

struct segment
{
    ll u;
    ll cd;

    bool operator < (const segment & temp) const
    {
        return cd > temp.cd;
    }
};
segment _segment(ll u, ll cd)
{
    segment temp{u, cd}; return temp;
}

struct edge
{
    ll v;
    ll d;

    bool operator < (const edge & temp) const
    {
        return v < temp.v;
    }
};
edge _edge(ll v, ll d)
{
    edge temp{v, d}; return temp;
}


void dfs(ll u, vector<ll> &c, vector<ll> &cc, vector<ll> &visited, vector<vector<edge>> &g)
{
    visited[u] = 1;

    ll ans = c[u], size = g[u].size();
    for (ll i = 0; i <= size - 1; ++i)
    {
        ll v = g[u][i].v;

        if (visited[v] == 0)
        {
            dfs(v, c, cc, visited, g);

            ans += cc[v];
        }
    }

    cc[u] = ans;
}

void dijkstra(ll source, vector<ll> &distances, vector<vector<edge>> &g)
{
    priority_queue<segment> q; q.push(_segment(source, 0));
    distances[source] = 0;

    while (q.empty() == false)
    {
        segment now = q.top(); q.pop();

        ll size = g[now.u].size();
        for (ll i = 0; i <= size - 1; ++i)
        {
            ll v = g[now.u][i].v, d = g[now.u][i].d;

            if (distances[v] <= distances[now.u] + d) continue;
            
            distances[v] = distances[now.u] + d;
            q.push(_segment(v, distances[v]));
        }
    }
}

int main()
{
    ll n, m, t; fin >> n >> m >> t;

    vector<ll> c(n + 1, 0), cc(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        fin >> c[i];
    }

    vector<vector<edge>> g(n + 1);
    for (ll ce = 1; ce <= m; ++ce)
    {
        ll u, v, d; fin >> u >> v >> d;

        g[u].push_back(_edge(v, d));
        g[v].push_back(_edge(u, d));
    }

    for (ll u = 1; u <= n; ++u)
    {
        sort(g[u].begin(), g[u].end());
    }

    vector<ll> distances(n + 1, inf);
    dijkstra(1, distances, g);

    vector<vector<edge>> tempG(n + 1);
    for (ll u = 1; u <= n; ++u)
    {
        ll size = g[u].size();
        for (ll i = 0; i <= size - 1; ++i)
        {
            ll v = g[u][i].v, d = g[u][i].d;

            if (distances[u] == distances[v] + d)
            {
                tempG[v].push_back(_edge(u, d));
                break;
            }
        }
    }

    vector<ll> visited(n + 1, 0);
    dfs(1, c, cc, visited, tempG);

    ll ans = 0;
    for (ll u = 1; u <= n; ++u)
    {
        ans = max(ans, (distances[u] - t) * cc[u]);
    }

    fout << ans << '\n';

    return 0;
}
