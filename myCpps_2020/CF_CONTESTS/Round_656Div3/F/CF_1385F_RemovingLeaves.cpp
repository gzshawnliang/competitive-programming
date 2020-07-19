/*
-------------------------------------------------------------------
* @Name:           1385F Removing Leaves
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:19  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/F
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
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, k; cin >> n >> k;

            vector<int> d(n + 1, 0), l(n + 1, 0);
            vector<vector<int>> g(n + 1);
            for (int c = 1; c <= n - 1; ++c)
            {
                int u, v; cin >> u >> v;
                ++d[u]; ++d[v];
                g[u].push_back(v); g[v].push_back(u);
            }

            queue<int> q;
            for (int u = 1; u <= n; ++u)
                if (d[u] == 1) q.push(u);

            int ans = 0;
            vector<int> vis(n + 1, 0);
            while (!q.empty())
            {
                int u = q.front(); q.pop();
                vis[u] = 1;
                for (auto v:g[u])
                {
                    if (vis[v] == 0)
                    {
                        --d[v];
                        ++l[v];

                        if (l[v] % k == 0) ++ans;

                        if (d[v] == 1 && l[v] % k == 0)
                        {
                            q.push(v);
                        }

                        break;
                    }
                }
            }

            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385F_RemovingLeaves.in", "r", stdin);
    freopen("CF_1385F_RemovingLeaves.out", "w", stdout);
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