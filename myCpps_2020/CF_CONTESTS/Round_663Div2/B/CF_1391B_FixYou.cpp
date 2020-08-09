/*
-------------------------------------------------------------------
* @Name:           1391B Fix You
* @Author:         Shawn
* @Create Time:    2020/8/9 22:35:11  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1391/problem/B
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
    const int inf = INT_MAX / 4;

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;
            
            vector<string> d(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> d[i];
            }

            auto isg=[&](int y, int x)
            {
                return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
            };
            map<char, pair<int, int>> mp;
            mp['D'] = {1, 0};
            mp['U'] = {-1, 0};
            mp['L'] = {0, -1};
            mp['R'] = {0, 1};

            vector<vector<int>> f(n, vector<int>(m, inf));
            vector<vector<int>> lst = f; lst[n - 1][m - 1] = 0;
            for (int c = 1; c <= n + m; ++c)
            {
                for (int y = 0; y <= n - 1; ++y)
                {
                    for (int x = 0; x <= m - 1; ++x)
                    {
                        if (y == n - 1 && x == m - 1) continue;

                        if (y == 2 && x == 1)
                        {
                            for (int __s = 0; __s == 0; ++__s);
                        }

                        for (auto pls:mp)
                        {
                            int nxtY = y + pls.second.first, nxtX = x + pls.second.second;
                            if (isg(nxtY, nxtX))
                            {
                                if (lst[nxtY][nxtX] != inf)
                                {
                                    f[y][x] = min(f[y][x], (int)(pls.first != d[y][x]));
                                }
                            }
                        }
                    }
                }

                lst = f;
            }

            int ans = 0;
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    if (y == n - 1 && x == m - 1) continue;
                    ans += f[y][x];
                }
            }

            cout << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1391B_FixYou.in", "r", stdin);
    freopen("CF_1391B_FixYou.out", "w", stdout);
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