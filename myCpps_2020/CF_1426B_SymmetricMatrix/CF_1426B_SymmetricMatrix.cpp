/*
-------------------------------------------------------------------
* @Name:           1426B Symmetric Matrix
* @Author:         Shawn
* @Create Time:    2020/10/2 22:40:59  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/B
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
            bool flg = false;
            int n, m; cin >> n >> m;
            for (int c = 1; c <= n; ++c)
            {
                int t0, t1, t2, t3; cin >> t0 >> t1 >> t2 >> t3;
                if (t1 == t2) flg = true;
            }

            if (m % 2 == 1) flg = false;

            cout << (flg ? "YES\n" : "NO\n");
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426B_SymmetricMatrix.in", "r", stdin);
    freopen("CF_1426B_SymmetricMatrix.out", "w", stdout);
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