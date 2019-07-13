#include <bits/stdc++.h>

using namespace std;

ifstream fin("almostShortestPath_UVA12144.in");
ofstream fout("almostShortestPath_UVA12144.out");

const int inf = INT_MAX / 2;

struct segment
{
    int u;
    int p;

    bool operator < (const segment & temp) const
    {
        return p > temp.p;
    }
};
segment _segment(int u, int p)
{
    segment temp{u, p}; return temp;
}

struct edge
{
    int u;
    int v;
};
edge _edge(int u, int v)
{
    edge temp{u, v}; return temp;
}

void erasePath(int u, vector<vector<int>> & a, vector<set<int>> & f)
{
    for (auto it = f[u].begin(); it != f[u].end(); ++it)
    {
        int v = *it;

        a[v][u] = inf;
        erasePath(v, a, f);
    }
}

int main()
{
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n + m == 0) break;

        vector<vector<int>> a(n, vector<int>(n, inf));

        int s, e; fin >> s >> e;

        for (int c = 1; c <= m; ++c)
        {
            int u, v, p; fin >> u >> v >> p;
            a[u][v] = p;
        }

        vector<int> d(n, inf);
        priority_queue<segment> pq; pq.push(_segment(s, 0));
        vector<set<int>> f(n);
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            for (int v = 0; v <= n - 1; ++v)
            {
                if (a[now.u][v] == inf) continue;

                segment next;
                next.u = v;
                next.p = now.p + a[now.u][v];

                if (next.p < d[next.u])
                {
                    d[next.u] = next.p;
                    f[v].clear();
                    f[v].insert(now.u);

                    pq.push(next);
                }
                else if (next.p == d[next.u])
                {
                    f[v].insert(now.u);
                }
            }
        }

        f[s].clear();
        erasePath(e, a, f);

        vector<int> _d(n, inf);
        priority_queue<segment> _pq; _pq.push(_segment(s, 0));
        while (_pq.empty() == false)
        {
            segment now = _pq.top(); _pq.pop();

            for (int v = 0; v <= n - 1; ++v)
            {
                if (a[now.u][v] == inf) continue;

                segment next;
                next.u = v;
                next.p = now.p + a[now.u][v];

                if (next.p < _d[next.u])
                {
                    _d[next.u] = next.p;
                    _pq.push(next);
                } 
            }
        }

        if (_d[e] == inf)
        {
            fout << "-1\n";
        }
        else
        {
            fout << _d[e] << '\n';
        }
    }

    return 0;
}
