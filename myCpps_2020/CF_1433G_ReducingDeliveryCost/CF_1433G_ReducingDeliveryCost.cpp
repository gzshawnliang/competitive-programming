/*
-------------------------------------------------------------------
* @Name:           1433G Reducing Delivery Cost
* @Author:         Shawn
* @Create Time:    2020/11/7 22:44:20  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1433/problem/G
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
    const int inf = INT_MAX / 3;

    void solve()
    {
        int n, m, tolQ; cin >> n >> m >> tolQ;

        vector<pair<int, int>> allE;
        vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
        vector<vector<pair<int, int>>> g(n + 1);
        for (int c = 1; c <= m; ++c)
        {
            int u, v, w; cin >> u >> v >> w;
            allE.push_back({u, v});
            g[u].push_back({v, w}); g[v].push_back({u, w});
        }

        for (int st = 1; st <= n; ++st)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

            d[st][st] = 0;
            q.push({0, st});
            while (!q.empty())
            {
                int u = q.top().second;
                q.pop();

                for (auto nxt:g[u])
                {
                    int v = nxt.first, dd = nxt.second;
                    if (d[st][v] > d[st][u] + dd)
                    {
                        d[st][v] = d[st][u] + dd;
                        q.push({d[st][v], v});
                    }
                }
            }
        }

        vector<pair<int, int>> allQ(tolQ);
        for (int i = 0; i <= tolQ - 1; ++i)
        {
            cin >> allQ[i].first >> allQ[i].second;
        }

        int ans = inf;
        for (auto e:allE)
        {
            int u = e.first, v = e.second, res = 0;
            for (auto q:allQ)
            {
                int qst = q.first, qfn = q.second;

                int tmp = d[qst][qfn];
                tmp = min(tmp, d[qst][u] + d[v][qfn]);
                tmp = min(tmp, d[qst][v] + d[u][qfn]);

                res += tmp;
            }

            ans = min(ans, res);
        }

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1433G_ReducingDeliveryCost.in", "r", stdin);
    freopen("CF_1433G_ReducingDeliveryCost.out", "w", stdout);
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