/*
-------------------------------------------------------------------
* @Name:           1462A Favorite Sequence
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/A
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
            
            vector<int> a(n + 1, 0);
            for (int i = 1; i <= n; ++i) cin >> a[i];
            
            vector<int> ans(n + 1, 0);
            if (n % 2 == 0)
            {
                for (int i = 1; i <= n / 2; ++i)
                    ans[i * 2 - 1] = a[i];
                for (int i = n, c = 1; i >= n / 2 + 1; --i, ++c)
                    ans[c * 2] = a[i];
            }
            else
            {
                for (int i = 1; i <= n / 2 + 1; ++i)
                    ans[i * 2 - 1] = a[i];
                for (int i = n, c = 1; i >= n / 2 + 2; --i, ++c)
                    ans[c * 2] = a[i];
            }

            for (int i = 1; i <= n; ++i)
            {
                if (i > 1) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1462A_FavoriteSequence.in", "r", stdin);
    freopen("CF_1462A_FavoriteSequence.out", "w", stdout);
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