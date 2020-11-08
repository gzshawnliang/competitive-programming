/*
-------------------------------------------------------------------
* @Name:           1433F Zero Remainder Sum 
* @Author:         Shawn
* @Create Time:    2020/11/8 16:32:13  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1433/problem/F
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
        ill n, m, k; cin >> n >> m >> k;

        vector<vector<ill>> a(n + 1, vector<ill>(m + 1, 0));
        for (ill y = 1; y <= n; ++y)
        {
            for (ill x = 1; x <= m; ++x)
            {
                cin >> a[y][x];
            }
        }

        ill ans = 0;
        vector<vector<ill>> f(n + 1, vector<ill>(k, -1));
        f[0][0] = 0;
        for (ill y = 1; y <= n; ++y)
        {
            vector<ill> tmp(k, -1);
            vector<vector<vector<ill>>> fr(m + 1, vector<vector<ill>>(k, vector<ill>(m / 2 + 1, -1)));
            fr[0][0][0] = 0;
            for (ill x = 1; x <= m; ++x)
            {
                for (ill r = 0; r < k; ++r)
                {
                    fr[x][r][0] = fr[x - 1][r][0];
                    for (ill c = 1; c <= m / 2; ++c)
                    {
                        fr[x][r][c] = fr[x - 1][r][c];

                        if (y == 1 && x == 1 && r == 1 && c == 1)
                        {
                            for (ill __s = 0; __s == 0; ++__s);
                        }

                        ill las = fr[x - 1][(r - a[y][x] + k * 70) % k][c - 1];
                        if (las >= 0)
                            fr[x][r][c] = max(fr[x][r][c], las + a[y][x]);

                        tmp[r] = max(tmp[r], fr[x][r][c]);
                    }
                }
            }

            for (ill r = 0; r < k; ++r)
                f[y][r] = f[y - 1][r];

            for (ill rn = 0; rn < k; ++rn)
            {
                for (ill rl = 0; rl < k; ++rl)
                {
                    if (tmp[rn] >= 0 && f[y - 1][rl] >= 0)
                    {
                        if (y == 4 && (rn + rl) % k == 0)
                        {
                            for (ill __s = 0; __s == 0; ++__s);
                        }
                        f[y][(rn + rl) % k] = max(f[y][(rn + rl) % k], tmp[rn] + f[y - 1][rl]);
                    }
                }
            }

            ans = max(ans, f[y][0]);
        }

        // for (ill y = 1; y <= n; ++y)
        // {
        //     for (ill r = 0; r < k; ++r)
        //     {
        //         if (f[y][r] >= 0)
        //             cout << "f[" << y << "][" << r << "] = " << f[y][r] << '\n';
        //     }
        // }

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1433F_ZeroRemainderSum.in", "r", stdin);
    freopen("CF_1433F_ZeroRemainderSum.out", "w", stdout);
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