#include <bits/stdc++.h>

using namespace std;

ifstream fin("airportSetup_UVA11377.in");
ofstream fout("airportSetup_UVA11377.out");

const int inf = INT_MAX / 2;

struct segment
{
    int u;
    int b;

    bool operator < (const segment & temp) const
    {
        return b > temp.b;
    }
};
segment _segment(int u, int b)
{
    segment temp{u, b}; return temp;
}

int main()
{
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m, k; fin >> n >> m >> k;

        vector<int> haveAirport(n + 1, 0);
        for (int c = 1; c <= k; ++c)
        {
            int u; fin >> u;
            haveAirport[u] = 1;
        }

        vector<vector<int>> g(n + 1);
        for (int c = 1; c <= m; ++c)
        {
            int u, v; fin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        fout << "Case " << t << ":\n";

        int q; fin >> q;
        for (int c = 1; c <= q; ++c)
        {
            int s, e; fin >> s >> e;

            if (s == e)
            {
                fout << "0\n";
                continue;
            }

            vector<int> ans(n + 1, inf);

            priority_queue<segment> pq;
            if (haveAirport[s] == 1) pq.push(_segment(s, 0));
            else pq.push(_segment(s, 1));
            
            while (pq.empty() == false)
            {
                segment now = pq.top(); pq.pop();

                if (now.b >= ans[now.u]) continue;
                ans[now.u] = now.b;

                if (now.u == e) break;
                
                int size = g[now.u].size();
                for (int i = 0; i <= size - 1; ++i)
                {
                    int v = g[now.u][i];

                    if (haveAirport[v] == 1) pq.push(_segment(v, now.b));
                    else pq.push(_segment(v, now.b + 1));
                }
            }

            if (ans[e] == inf)
            {
                fout << "-1\n";
            }
            else
            {
                fout << ans[e] << '\n';
            }
        }

        fout << '\n';
    }

    return 0;
}
