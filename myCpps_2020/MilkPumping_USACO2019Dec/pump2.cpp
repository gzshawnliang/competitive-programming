#include <bits/stdc++.h>

using namespace std;

ifstream fin("pump.in");
ofstream fout("pump.out");

const int inf = INT_MAX / 2;

struct edge
{
    int v;
    int c;
    int f;
};
edge _edge(int v, int c, int f)
{
    edge temp{v, c, f}; return temp;
}

struct segment
{
    int u;
    int cc;

    bool operator < (const segment & temp) const
    {
        return cc > temp.cc;
    }
};
segment _segment(int u, int cc)
{
    segment temp{u, cc}; return temp;
}


int main()
{
    int n, m; fin >> n >> m;
    
    vector<vector<edge>> g(n + 1);
    for (int ce = 1; ce <= m; ++ce)
    {
        int u, v, c, f; fin >> u >> v >> c >> f;

        g[u].push_back(_edge(v, c, f));
        g[v].push_back(_edge(u, c, f));
    }

    double ans = 0.0;
    for (int minF = 1; minF <= 1000; ++minF)
    {
        vector<vector<edge>> g2(n + 1);
        for (int u = 1; u <= n; ++u)
        {
            int size = g[u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                if (g[u][i].f >= minF)
                {
                    g2[u].push_back(g[u][i]);
                }
            }
        }

        vector<int> distances(n + 1, inf);
        priority_queue<segment> q; q.push(_segment(1, 0));
        distances[1] = 0;

        while (q.empty() == false)
        {
            segment now = q.top(); q.pop();

            int size = g2[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g2[now.u][i].v,
                    c = g2[now.u][i].c;

                if (distances[v] <= distances[now.u] + c) continue;
                distances[v] = distances[now.u] + c;

                q.push(_segment(v, distances[v]));
            }
        }

        ans = max(ans, (double)minF / (double)distances[n]);
    }

    fout << (int)(ans * 1e6) << '\n';

    return 0;
}
