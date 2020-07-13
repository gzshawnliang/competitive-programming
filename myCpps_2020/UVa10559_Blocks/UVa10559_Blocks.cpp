/*
-------------------------------------------------------------------
* @Name:           UVa-10559 Blocks
* @Author:         Shawn
* @Create Time:    2020/7/12 23:35:50  (UTC+08:00)
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
            vector<int> a(n + 1, 0);
            for (int i = 1; i <= n; ++i) cin >> a[i];

            vector<int> cntC(n + 1, 0);
            for (int i = 0; i <= n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (a[i] == a[j]) ++cntC[i];

            vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
            for (int i = n; i >= 1; --i)
            {
                for (int j = i; j <= n; ++j)
                {
                    for (int k = i; k <= j - 1; ++k)
                    {
                        if (a[j] == a[k])
                        {
                            for (int p = 0; p <= cntC[j]; ++p)
                            {
                                f[i][j][p] = max(f[i][j][p], f[k + 1][j - 1][0] + f[i][k][p + 1]);
                            }
                        }
                    }

                    for (int p = 0; p <= cntC[j]; ++p)
                    {
                        f[i][j][p] = max(f[i][j][p], f[i][j - 1][0] + (p + 1) * (p + 1));
                    }
                }
            }

            cout << "Case " << tcc << ": " << f[1][n][0] << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa10559_Blocks.in", "r", stdin);
    freopen("UVa10559_Blocks.out", "w", stdout);
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