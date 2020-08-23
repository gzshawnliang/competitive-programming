/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/22 23:07:30  (UTC+08:00)
* @Url:            
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
    std::cin.tie(nullptr);               \
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

            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            cout << "Case #" << tcc << ": ";
            if (n == 1)
            {
                cout << "1\n";
                continue;
            }
            
            int ans = 0, maxV = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == 0)
                {
                    if (a[i] > a[i + 1]) ++ans;
                }
                else if (i == n - 1)
                {
                    if (a[i] > maxV) ++ans;
                }
                else
                {
                    if (a[i] > a[i + 1] && a[i] > maxV) ++ans;
                }

                maxV = max(a[i], maxV);
            }

            cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PA.in", "r", stdin);
    freopen("PA.out", "w", stdout);
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