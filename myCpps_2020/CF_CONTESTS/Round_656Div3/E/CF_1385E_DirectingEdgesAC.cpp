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
    const int inf = INT_MAX / 2;
    vector<int> vis, pth;
    vector<vector<int>> g;

    void dfs(int u)
    {
        vis[u] = 1;
        for (auto v:g[u])
        {
            if (vis[v] == 0) dfs(v);
        }
        pth.push_back(u);
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;

            vector<int> cntI(n + 1, 0);
            vector<pair<int, int>> allE;

            g.assign(n + 1, vector<int>());
            for (int c = 1; c <= m; ++c)
            {
                int tp, u, v; cin >> tp >> u >> v;

                if (tp == 1) g[u].push_back(v);

                allE.push_back({u, v});
            }

            vis.assign(n + 1, 0);
            pth.clear();
            for (int u = 1; u <= n; ++u)
            {
                if (vis[u] == 0) dfs(u);
            }

            vector<int> num(n + 1, 0);
            for (int i = n - 1; i >= 0; --i)
            {
                num[pth[i]] = n - 1 - i; 
            }

            bool flg = true;
            for (int u = 1; u <= n && flg == true; ++u)
            {
                for (auto v:g[u])
                {
                    if (num[u] > num[v])
                    {
                        flg = false;
                        break;
                    }
                }
            }
            
            if (flg == false)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                for (auto p:allE)
                {
                    if (num[p.first] < num[p.second]) cout << p.first << ' ' << p.second << '\n';
                    else                              cout << p.second << ' ' << p.first << '\n';
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