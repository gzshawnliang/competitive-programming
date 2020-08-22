/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/22 23:20:23  (UTC+08:00)
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

            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            vector<vector<int>> f(n, vector<int>(4, n + 1));
            for (int q = 0; q <= 3; ++q) f[0][q] = 0;

            for (int i = 1; i <= n - 1; ++i)
            {
                for (int p = 0; p <= 3; ++p)
                {
                    for (int q = 0; q <= 3; ++q)
                    {
                        if      (a[i - 1] < a[i])
                        {
                            if (p < q) f[i][q] = min(f[i][q], f[i - 1][p]);
                            else       f[i][q] = min(f[i][q], f[i - 1][p] + 1);
                        }
                        else if (a[i - 1] > a[i])
                        {
                            if (p > q) f[i][q] = min(f[i][q], f[i - 1][p]);
                            else       f[i][q] = min(f[i][q], f[i - 1][p] + 1);
                        }
                        else
                        {
                            if (p == q) f[i][q] = min(f[i][q], f[i - 1][p]);
                            else        f[i][q] = min(f[i][q], f[i - 1][p] + 1);
                        }
                    }
                }
            }

            int ans = *min_element(f[n - 1].begin(), f[n - 1].end());
            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

// #ifndef ONLINE_JUDGE
//     freopen("PB.in", "r", stdin);
//     freopen("PB.out", "w", stdout);
//     auto startTime = std::chrono::high_resolution_clock::now();
// #endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifndef ONLINE_JUDGE
//     auto endTime = std::chrono::high_resolution_clock::now();
//     std::cerr << "Execution time: "
//               << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
//               << " ms\n";
// #endif

    return 0;
}