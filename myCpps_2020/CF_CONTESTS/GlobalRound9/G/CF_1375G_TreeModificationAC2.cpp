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

class solution
{
   //private:
    vector<vector<int>> g;
    vector<int> col;

    int dfs(int u, int las)
    {
        int ans = 0;
        for (auto v : g[u])
        {
            if (v != las)
            {
                col[v] = 1 - col[u];
                dfs(v, u);
            }
        }

        return ans;
    }

  public:  
    void solve()
    {
        int n;
        cin >> n;
        g.assign(n + 1, vector<int>());

        for (int c = 1; c <= n - 1; ++c)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        col.assign(n + 1, -1);
        col[1] = 0;
        dfs(1, -1);

        int cnt0 = 0, cnt1 = 0;
        for (int u = 1; u <= n; ++u)
        {
            if (col[u] == 0)
                ++cnt0;
            else
                ++cnt1;
        }

        cout << min(cnt0, cnt1) - 1 << '\n';
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
    sln1.
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}