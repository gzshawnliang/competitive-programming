#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowland.in");
ofstream fout("cowland.out");

int main()
{
    int n, q; fin >> n >> q;

    vector<int> e(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        fin >> e[i];
    }

    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    for (int c = 1; c <= q; ++c)
    {
        int _i, u, v; fin >> _i >> u >> v;

        if (_i == 1) 
        {
            e[u] = v;
        }
        else
        {
            vector<int> last(n + 1, -1);
            last[u] = -1;

            queue<int> q;
            q.push(u);

            while (!q.empty())
            {
                int _u = q.front();
                q.pop();

                int _size = g[_u].size();
                for (int i = 0; i <= _size - 1; ++i)
                {
                    int _v = g[_u][i];

                    if (last[_v] != -1 || _v == u) continue;

                    last[_v] = _u;
                    q.push(_v);
                }
            }

            int ans = 0, pos = v;
            while (pos != -1)
            {
                ans ^= e[pos];

                pos = last[pos];
            }

            fout << ans << '\n';
        }
    }

    return 0;
}
