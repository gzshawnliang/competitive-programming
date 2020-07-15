/*
-------------------------------------------------------------------
* @Name:           607B Zuma
* @Author:         Shawn
* @Create Time:    2020/7/15 22:36:01  (UTC+08:00)
* @Url:            https://codeforces.com/contest/607/problem/B
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
    const int inf = INT_MAX / 2;

    void solve()
    {
        int n; cin >> n;

        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i) cin >> a[i];
        
        vector<vector<int>> f(n, vector<int>(n, inf));
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 0; i <= n - 1; ++i)
            {
                int j = i + len - 1;
                if (j >= n) break;

                if (len == 1)
                {
                    f[i][j] = 1;
                }
                else if (len == 2)
                {
                    if (a[i] == a[j]) f[i][j] = 1;
                    else              f[i][j] = 2;
                }
                else
                {
                    if (a[i] == a[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);

                    for (int k = i; k + 1 <= j; ++k)
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }

        cout << f[0][n - 1] << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_607B_Zuma.in", "r", stdin);
    freopen("CF_607B_Zuma.out", "w", stdout);
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