/*
-------------------------------------------------------------------
* @Name:           1373F Network Coverage
* @Author:         Shawn
* @Create Time:    2020/6/25 22:35:23  (UTC+08:00)
* @Url:            https://codeforces.com/gym/1373/problem/F
* @File:           CF_1373F_NetworkCoverage.cpp
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
    const ill inf = LLONG_MAX;

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;
            vector<ill> a(n, 0), b(n, 0);
            for (ill i = 0; i <= n - 1; ++i) cin >> a[i];
            for (ill i = 0; i <= n - 1; ++i) cin >> b[i];

            bool flg = true;
            ill need = 0, add = 0, extra = inf;
            for (ill i = n - 1; i >= 0; --i)
            {
                if (b[i] < need)
                {
                    flg = false;
                    break;
                }
                
                ill val = b[i] - a[i];
                ill addon = min(extra, max(0LL, val - need));
                add += addon;
                extra = min(extra - addon, b[i] - need - addon);
                need = max(0LL, need - val);
            }

            if (need > add || flg == false)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
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
    freopen("CF_1373F_NetworkCoverage.in", "r", stdin);
    freopen("CF_1373F_NetworkCoverage.out", "w", stdout);
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