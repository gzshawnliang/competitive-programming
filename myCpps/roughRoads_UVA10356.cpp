#include <bits/stdc++.h>

using namespace std;

ifstream fin("roughRoads_UVA10356.in");
ofstream fout("roughRoads_UVA10356.out");

const int inf = INT_MAX / 2;

struct segment
{
    bool isEven;
    int u;
    int d;

    bool operator < (const segment & temp) const
    {
        return d > temp.d;
    }
};
segment _segment(bool isEven, int u, int d)
{
    segment temp{isEven, u, d}; return temp;
}

int main()
{
    int t = 0;
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n + m == 0) break;

        
        ++t;

        vector<vector<int>> a(n, vector<int>(n, inf)),
                            g(n);
        for (int c = 1; c <= m; ++c)
        {
            int u, v, d; fin >> u >> v >> d;
            a[u][v] = d; a[v][u] = a[u][v];
            g[u].push_back(v); g[v].push_back(u);
        }

        vector<vector<int>> d(n, vector<int>(2, inf));
        priority_queue<segment> pq; pq.push(_segment(1, 0, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.d >= d[now.u][now.isEven]) continue;
            d[now.u][now.isEven] = now.d;

            int size = g[now.u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[now.u][i];

                pq.push(_segment(1 - now.isEven, v, now.d + a[now.u][v]));
            }
        }

        fout << "Set #" << t << '\n';
        if (d[n - 1][1] == inf)
        {
            fout << "?\n";
        }
        else
        {
            fout << d[n - 1][1] << '\n';
        }
    }

    return 0;
}
