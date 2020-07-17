/*
-------------------------------------------------------------------
* @Name:           1385E Directing Edges
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:19  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/E
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
  public:
    vector<int> vis, visT;
    vector<vector<int>> g, gD, gU;
    vector<vector<int>> ans;

    void dfs(int u, int las)
    {
        vis[u] = 1;
        visT[u] = 1;
        for (auto v:g[u])
        {
            if (u == 2 && v == 1)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (v == las) continue;
            if (visT[v] == 1) continue;
            ans[u].push_back(v);
            if (vis[v] == 1) continue;

            dfs(v, u);
        }
        visT[u] = 0;
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;

            vector<int> cntE(n + 1, 0);

            g.assign(n + 1, vector<int>());
            gD.assign(n + 1, vector<int>());
            gU.assign(n + 1, vector<int>());
            ans.assign(n + 1, vector<int>());
            for (int c = 1; c <= m; ++c)
            {
                int tp, u, v; cin >> tp >> u >> v;

                if (tp == 1)
                {
                    g[u].push_back(v);
                    gD[u].push_back(v);
                    ++cntE[v];
                }
                else
                {
                    g[u].push_back(v);
                    g[v].push_back(u);
                    gU[u].push_back(v);
                    gU[v].push_back(u);
                }
            }

            vis.assign(n + 1, 0);
            visT.assign(n + 1, 0);
            for (int u = 1; u <= n; ++u)
            {
                if (cntE[u] > 0 || vis[u] == 1) continue;

                dfs(u, -1);
            }

            set<pair<int, int>> fin;
            for (int u = 1; u <= n; ++u)
            {
                for (auto v:gD[u])
                {
                    fin.insert({u, v});
                }
            }

            for (int u = 1; u <= n; ++u)
            {
                for (auto v:ans[u])
                {
                    fin.insert({u, v});
                }
            }

            if (fin.size() < m)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                for (auto x:fin)
                {
                    cout << x.first << ' ' << x.second << '\n';
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385E_DirectingEdges.in", "r", stdin);
    freopen("CF_1385E_DirectingEdges.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}