/*
-------------------------------------------------------------------
* @Name:           1426F Number of Subsequences
* @Author:         Shawn
* @Create Time:    2020/10/5 18:33:25  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/F
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
    ill mod = (ill)1e9 + 7;

    void solve()
    {
        ill n; cin >> n;
        string s; cin >> s;

        ill tolQ = 0;
        for (ill i = 0; i <= n - 1; ++i)
            if (s[i] == '?') ++tolQ;

        vector<ill> pow3(n + 1, 1);
        for (ill i = 1; i <= n; ++i)
        {
            pow3[i] = (pow3[i - 1] * 3) % mod;
        }

        vector<vector<vector<ill>>> f(n + 1, vector<vector<ill>> (4, vector<ill>(4, 0)));

        f[0][0][0] = 1;
        for (ill i = 0; i <= n - 1; ++i)
        {
            for (ill j = 0; j <= 3; ++j)
            {
                for (ill k = 0; k <= 3; ++k)
                {
                    if (f[i][j][k] == 0) continue;

                    f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % mod;
                    if (j < 3 && (s[i] == '?' || s[i] == 'a' + j))
                    {
                        if (s[i] == '?')
                            f[i + 1][j + 1][k + 1] = (f[i + 1][j + 1][k + 1] + f[i][j][k]) % mod;
                        else
                            f[i + 1][j + 1][k] = (f[i + 1][j + 1][k] + f[i][j][k]) % mod;
                    }
                }
            }
        }

        ill ans = 0;
        for (ill i = 0; i <= 3; ++i)
        {
            if (tolQ >= i)
                ans = (ans + (f[n][3][i] * pow3[tolQ - i]) % mod) % mod;
        }

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426F_NumberofSubsequences.in", "r", stdin);
    freopen("CF_1426F_NumberofSubsequences.out", "w", stdout);
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