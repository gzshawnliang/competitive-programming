/*
-------------------------------------------------------------------
* @Name:           1462E1 Close Tuples (easy version)
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/E1
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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;
            
            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

            if (n < 3)
            {
                cout << "0\n";
                continue;
            }

            sort(a.begin(), a.end());

            ill ans = 0;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill pos = upper_bound(a.begin(), a.end(), a[i] + 2) - a.begin();
                --pos;

                ans += (pos - i - 1) * (pos - i) / 2;
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
    freopen("CF_1462E1_CloseTupleseasyversion.in", "r", stdin);
    freopen("CF_1462E1_CloseTupleseasyversion.out", "w", stdout);
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