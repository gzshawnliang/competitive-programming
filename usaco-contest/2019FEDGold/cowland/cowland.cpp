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

    map<string, int> m;

    for (int c = 1; c <= q; ++c)
    {
        int _i, u, v; fin >> _i >> u >> v;

        if (_i == 1) 
        {
            e[u] = v;
        }
        else
        {
            string index = to_string(u) + "," + to_string(v);
            if (m[index] > 0)
            {
                fout << m[index] << '\n';
                continue;
            }

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

            vector<int> path;
            while (pos != -1)
            {
                path.push_back(pos);

                pos = last[pos];
            }

            reverse(path.begin(), path.end());

            int size = path.size();
            vector<int> dp(size, 0); dp[0] = e[path[0]];
            
            for (int i = 1; i <= size - 1; ++i)
            {
                dp[i] = (e[path[i]] ^ dp[i - 1]);
            }

            for (int i = 0; i <= size - 1; ++i)
            {
                for (int j = i + 1; j <= size - 1; ++j)
                {
                    if (i == 0)
                    {
                        m[to_string(path[i]) + "," + to_string(path[j])] = dp[j];
                    }
                    else
                    {
                        m[to_string(path[i]) + "," + to_string(path[j])] = (dp[j] ^ dp[i - 1]);
                    }
                }
            }

            fout << dp[size - 1] << '\n';
        }
    }

    return 0;
}
