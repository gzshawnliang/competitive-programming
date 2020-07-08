/*
-------------------------------------------------------------------
* @Name:           1368E Ski Accidents
* @Author:         Shawn
* @Create Time:    2020/7/8 22:24:08  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1368/problem/E
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
            int n, m; cin >> n >> m;
            
            vector<vector<int>> g(n + 1);
            for (int c = 1; c <= m; ++c)
            {
                int u, v; cin >> u >> v;
                g[v].push_back(u);
            }

            vector<int> vis(n + 1, 0), ans;
            for (int u = 1; u <= n; ++u)
            {
                bool flg = true;
                for (auto v:g[u])
                {
                    if (flg == false) break;
                    if (vis[v] == false)
                    {
                        for (auto k:g[v])
                        {
                            if (flg == false) break;
                            if (vis[k] == false)
                            {
                                vis[u] = true;
                                ans.push_back(u);
                                flg = false;
                                break;
                            }
                        }
                    }
                }
            }

            int siz = ans.size();
            cout << siz << '\n';
            for (int i = 0; i <= siz - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1368E_SkiAccidents.in", "r", stdin);
    freopen("CF_1368E_SkiAccidents.out", "w", stdout);
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