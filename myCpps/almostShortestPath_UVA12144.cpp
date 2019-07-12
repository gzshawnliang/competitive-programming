#include <bits/stdc++.h>

using namespace std;

ifstream fin("almostShortestPath_UVA12144.in");
ofstream fout("almostShortestPath_UVA12144.out");

const int inf = INT_MAX / 2;

struct segment
{
    int u;
    int lastU;
    int p;

    bool operator < (const segment & temp) const
    {
        return p > temp.p;
    }
};
segment _segment(int u, int lastU, int p)
{
    segment temp{u, lastU, p}; return temp;
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

        bool isFirstS = true;
        vector<int> pMin(n, inf); pMin[s] = 0;
        priority_queue<segment> pq; pq.push(_segment(s, -1, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.p >= pMin[now.u] && isFirstS == false) continue;
            isFirstS = false;
            pMin[now.u] = now.p;

            for (int v = 0; v <= n - 1; ++v)
            {
                if (now.u != v && a[now.u][v] < inf)
                {
                    pq.push(_segment(v, now.u, now.p + a[now.u][v]));
                }
            }
        }

        int ans = pMin[e];
        while (ans == pMin[e])
        {
            for (int u = 0; u <= n - 1; ++u)
            {
                for (int v = u + 1; v <= n - 1; ++v)
                {
                    if (a[u][v] < inf)
                    {
                        fout << u << "-->" << v << ": " << a[u][v] << '\n';
                    }
                    if (a[v][u] < inf)
                    {
                        fout << v << "-->" << u << ": " << a[v][u] << '\n';
                    }
                }
            }

            bool isFirstS_t = true;
            vector<int> f(n, -1), pMin_t(n, inf); pMin_t[s] = 0;
            priority_queue<segment> pq_t; pq_t.push(_segment(s, -1, 0));
            while (pq_t.empty() == false)
            {
                segment now = pq_t.top(); pq_t.pop();

                if (now.p >= pMin_t[now.u] && isFirstS_t == false) continue;
                isFirstS_t = false;
                pMin_t[now.u] = now.p;
                f[now.u] = now.lastU;

                for (int v = 0; v <= n - 1; ++v)
                {
                    if (now.u != v && a[now.u][v] < inf)
                    {
                        pq_t.push(_segment(v, now.u, now.p + a[now.u][v]));
                    }
                }
            }

            ans = pMin_t[e];

            int _u = e;
            while (f[_u] >= 0)
            {
                a[f[_u]][_u] = inf;
                _u = f[_u];
            }

            fout << ans << '\n';
        }

        if (ans == inf)
        {
            fout << "-1\n";
        }
        else
        {
            fout << ans << '\n';
        }
    }

    return 0;
}
