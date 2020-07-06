/*
-------------------------------------------------------------------
* @Name:           1375G Tree Modification
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:40  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/G
* @Description:    
-------------------------------------------------------------------
                                     /~\
                         WA again?  |oo )
                                    _\=/_
                    ___        #   /  _  \
   No,TLE again！  / ()\        \\//|/.\|\\
  mabe Next time _|_____|_       \/  \_/  ||
      get AC    | | === | |         |\ /| ||
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

int dfs(int u, int las, vector<vector<int>> &g)
{
    int ans = 0;
    for (auto v:g[u])
    {
        if (g[v].size() > 1 && v != las)
        {
            int nxt = g[v][0];
            if (nxt == u) nxt = g[v][1];

            ans += 1 + dfs(nxt, v, g);
        }
    }

    return ans;
}

class solution
{
  public:
    void solve()
    {
        int n; cin >> n;

        vector<vector<int>> g(n + 1);
        for (int c = 1; c <= n - 1; ++c)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        int centre = 0, maxD = 0;
        for (int u = 1; u <= n; ++u)
        {
            int siz = g[u].size();
            if (siz > maxD)
            {
                maxD = siz; centre = u;
            }
        }

        cout << dfs(centre, -1, g) << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1375G_TreeModification.in", "r", stdin);
    freopen("CF_1375G_TreeModification.out", "w", stdout);
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