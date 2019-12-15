#include <bits/stdc++.h>

using namespace std;

ifstream fin("dining.in");
ofstream fout("dining.out");

const int inf = INT_MAX / 2;

void dijkstra(int source, map<int, int> & dis, map<pair<int, int>, int> &a, vector<vector<int>> &g)
{
    set<pair<int, int>> q;
    q.insert(make_pair(0, source));

    int flag = 0;
    while (q.empty() == false)
    {
        int u = q.begin()->second;
        q.erase(q.begin());

        // if (u == source && flag == 2) continue;
        // ++flag;

        for (auto v = g[u].begin(); v != g[u].end(); ++v)
        {
            if (dis.count(*v) == 0 || dis[u] + a[make_pair(u, *v)] < dis[*v])
            {
                dis[*v] = dis[u] + a[make_pair(u, *v)];
                q.insert(make_pair(dis[*v], *v));
            }
        }
    }
}

int main()
{
    int n, m, k; fin >> n >> m >> k;

    vector<pair<int, int>> h(k);
    map<pair<int, int>, int> a;
    vector<vector<int>> g(n + 1);

    for (int c = 1; c <= m; ++c)
    {
        int u, v, t; fin >> u >> v >> t;
        --u; --v;

        a[make_pair(u, v)] = t;
        a[make_pair(v, u)] = t;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i <= k - 1; ++i)
    {
        fin >> h[i].first >> h[i].second;
        --h[i].first;
    }

    map<int, int> dis1;
    dijkstra(n - 1, dis1, a, g);

    // for (int i = 0; i <= n - 1 - 1; ++i)
    // {
    //     if (a.count(make_pair(i, n - 1)) > 0)
    //     {
    //         a[make_pair(i, n - 1)] = inf;
    //     }
    // }
    //g[n - 1].clear();

    for (int i = 0; i <= k - 1; ++i)
    {
        g[n].push_back(h[i].first);
        a[make_pair(n, h[i].first)] = dis1[h[i].first] - h[i].second;
    }

    map<int, int> dis2;
    dijkstra(n, dis2, a, g);

    for (int i = 0; i <= n - 1 - 1; ++i)
    {
        fout << (dis1[i] >= dis2[i]) << '\n';
    }

    return 0;
}
