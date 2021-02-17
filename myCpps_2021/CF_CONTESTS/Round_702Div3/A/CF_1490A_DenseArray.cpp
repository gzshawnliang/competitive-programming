/*
-------------------------------------------------------------------
* @Name:           1490A Dense Array
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/A
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

#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

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
            vector<int> a(n);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            int ans = 0;
            for (int i = 1; i <= n - 1; ++i)
            {
                int minX = min(a[i - 1], a[i]), maxX = max(a[i - 1], a[i]);

                int cnt = 0;
                while (minX * 2 * (1 << cnt) < maxX)
                {
                    ++cnt;
                }

                ans += cnt;
            }
            cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490A_DenseArray.in", "r", stdin);
    freopen("CF_1490A_DenseArray.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}