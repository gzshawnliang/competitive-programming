/*
-------------------------------------------------------------------
* @Name:           Problem A: Graphs as a Service
* @Author:         Shawn
* @Create Time:    2020/8/8 23:28:23  (UTC+08:00)
* @Url:            https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/A
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

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, q; cin >> n >> q;

            vector<tuple<int, int, int>> allE;
            vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
            for (int c = 1; c <= q; ++c)
            {
                int u, v, w; cin >> u >> v >> w;
                d[u][v] = w; d[v][u] = w;

                allE.push_back({u, v, w});
            }

            for (int k = 1; k <= n; ++k)
            {
                for (int u = 1; u <= n; ++u)
                {
                    for (int v = 1; v <= n; ++v)
                    {
                        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                    }
                }
            }

            bool flg = true;
            for (auto [u, v, w] : allE)
            {
                if (d[u][v] != w)
                {
                    flg = false;
                    break;
                }
            }

            cout << "Case #" << tcc << ": ";
            if (flg == false)
            {
                cout << "Impossible\n";
            }
            else
            {
                cout << q << '\n';
                for (auto [u, v, w] : allE)
                {
                    cout << u << ' ' << v << ' ' << w << '\n';
                }
            }
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND1_GRAPHS_AS_A_SERVICE.in", "r", stdin);
    freopen("FB_2019_ROUND1_GRAPHS_AS_A_SERVICE.out", "w", stdout);
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