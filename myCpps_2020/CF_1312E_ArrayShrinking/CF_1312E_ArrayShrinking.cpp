/*
-------------------------------------------------------------------
* @Name:           1312E Array Shrinking
* @Author:         Shawn
* @Create Time:    2020/12/14 22:52:08  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1312/problem/E
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
        int n; cin >> n;

        vector<int> a(n + 1, 0);
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0)), g(n + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        
        for (int i = 1; i <= n; ++i)
        {
            f[i][i] = 1; g[i][i] = a[i];
            for (int j = i + 1; j <= n; ++j)
            {
                f[i][j] = j - i + 1;
            }
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                for (int k = i; k <= j - 1; ++k)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    if (f[i][k] == 1 && f[k + 1][j] == 1 && g[i][k] == g[k + 1][j])
                    {
                        f[i][j] = 1; g[i][j] = g[i][k] + 1;
                    }
                }
            }
        }

        cout << f[1][n] << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1312E_ArrayShrinking.in", "r", stdin);
    freopen("CF_1312E_ArrayShrinking.out", "w", stdout);
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