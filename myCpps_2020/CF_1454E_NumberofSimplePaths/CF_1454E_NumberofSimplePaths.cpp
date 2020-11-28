/*
-------------------------------------------------------------------
* @Name:           1454E Number of Simple Paths
* @Author:         Shawn
* @Create Time:    2020/11/28 22:09:27  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1454/problem/E
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
            int n; cin >> n;

            vector<set<int>> g(n);
            for (int c = 1; c <= n; ++c)
            {
                int u, v; cin >> u >> v;
                --u; --v;
                g[u].insert(v); g[v].insert(u);
            }

            vector<int> f(n, 1);
            queue<int> leaves;
            for (int i = 0; i <= n - 1; ++i)
                if (g[i].size() == 1)
                    leaves.push(i);

            while (!leaves.empty())
            {
                int v = leaves.front(); leaves.pop();

                int u = *g[v].begin();

                f[u] += f[v]; f[v] = 0;

                g[v].clear();
                g[u].erase(v);
                if (g[u].size() == 1)
                    leaves.push(u);
            }

            ill ans = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                ans += f[i] * 1LL * (f[i] - 1) / 2;
                ans += f[i] * 1LL * (n - f[i]);
            }
            cout << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1454E_NumberofSimplePaths.in", "r", stdin);
    freopen("CF_1454E_NumberofSimplePaths.out", "w", stdout);
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