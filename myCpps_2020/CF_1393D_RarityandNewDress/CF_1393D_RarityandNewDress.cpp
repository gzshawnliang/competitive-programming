/*
-------------------------------------------------------------------
* @Name:           1393D Rarity and New Dress
* @Author:         Shawn
* @Create Time:    2020/8/8 22:27:34  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1393/problem/D
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
        ill n, m; cin >> n >> m;

        vector<string> a(n);
        vector<vector<ill>> fu(n, vector<ill>(m, 0)),
                            fd(n, vector<ill>(m, 0)),
                            fl(n, vector<ill>(m, 0)),
                            fr(n, vector<ill>(m, 0));

        for (ill y = 0; y <= n - 1; ++y)
            cin >> a[y];

        for (ill x = 0; x <= m - 1; ++x)
        {
            for (ill y = 1; y <= n - 1; ++y)
            {
                if (a[y - 1][x] == a[y][x]) fu[y][x] = fu[y - 1][x] + 1;
                if (fu[y][x] == 1)
                {
                    for (ill __s = 0; __s == 0; ++__s);
                }
            }

            for (ill y = n - 2; y >= 0; --y)
            {
                if (a[y + 1][x] == a[y][x]) fd[y][x] = fd[y + 1][x] + 1;
            }
        }

        for (ill y = 0; y <= n - 1; ++y)
        {
            for (ill x = 1; x <= m - 1; ++x)
            {
                if (a[y][x - 1] == a[y][x]) fl[y][x] = min(fl[y][x - 1] + 1, min(fu[y][x], fd[y][x]));
            }

            for (ill x = m - 2; x >= 0; --x)
            {
                if (a[y][x + 1] == a[y][x]) fr[y][x] = min(fr[y][x + 1] + 1, min(fu[y][x], fd[y][x]));
            }
        }

        ill ans = n * m;
        for (ill y = 0; y <= n - 1; ++y)
            for (ill x = 0; x <= m - 1; ++x)
                ans += min(fl[y][x], fr[y][x]);

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1393D_RarityandNewDress.in", "r", stdin);
    freopen("CF_1393D_RarityandNewDress.out", "w", stdout);
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