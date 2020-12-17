/*
-------------------------------------------------------------------
* @Name:           793D Presents in Bankopolis
* @Author:         Shawn
* @Create Time:    2020/12/17 22:24:13  (UTC+08:00)
* @Url:            https://codeforces.com/contest/793/problem/D
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
        int n, h, m; cin >> n >> h >> m;

        set<int> allNum;
        vector<tuple<int, int, int>> allEdge;
        for (int c = 1; c <= m; ++c)
        {
            int u, v, d; cin >> u >> v >> d;
            allEdge.push_back({u, v, d});
            
            allNum.insert(u); allNum.insert(v); allNum.insert(d);
        }

        int cnt = 0;
        vector<int> toE(n, -1);
        for (auto x:allNum) toE[x] = cnt++;

        for (auto &[u, v, d]:allEdge)
        {
            u = toE[u]; v = toE[v];
        }

        for (int __s = 0; __s == 0; ++__s);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_793D_PresentsinBankopolis.in", "r", stdin);
    freopen("CF_793D_PresentsinBankopolis.out", "w", stdout);
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