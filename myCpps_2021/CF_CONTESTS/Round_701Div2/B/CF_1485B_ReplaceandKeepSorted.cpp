/*
-------------------------------------------------------------------
* @Name:           1485B Replace and Keep Sorted
* @Author:         Shawn
* @Create Time:    2021/2/12 22:50:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1485/problem/B
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
        int n, q, k; cin >> n >> q >> k;
        
        vector<int> a(n + 2, 0), f(n + 2, 0), sum(n + 2, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
            {
                f[i] = max(0, a[i + 1] - 1 - 1);
            }
            else if (i == n)
            {
                f[i] = max(0, k - a[i - 1] - 1);
            }
            else
            {
                f[i] = max(0, a[i + 1] - a[i - 1] - 1 - 1);
            }

            sum[i] = sum[i - 1] + f[i];
        }

        for (int c = 1; c <= q; ++c)
        {
            int l, r; cin >> l >> r;

            if (r == l)
            {
                cout << k - 1 << '\n';
            }
            else
            {
                int ans = 0;
                if (r - l >= 2) ans += sum[r - 1] - sum[l];
                ans += (a[l + 1] - 2);
                ans += (k - a[r - 1] - 1);
                
                cout << ans << '\n';
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1485B_ReplaceandKeepSorted.in", "r", stdin);
    freopen("CF_1485B_ReplaceandKeepSorted.out", "w", stdout);
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