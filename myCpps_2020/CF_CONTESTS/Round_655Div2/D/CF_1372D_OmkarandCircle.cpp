/*
-------------------------------------------------------------------
* @Name:           1372D Omkar and Circle
* @Author:         Shawn
* @Create Time:    2020/7/11 23:05:25  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1372/problem/D
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
        ill n; cin >> n;

        ill totS = 0;
        vector<ill> a(n, 0);
        for (ill i = 0; i <= n - 1; ++i)
        {
            cin >> a[i]; totS += a[i];
        }

        if (n == 1)
        {
            cout << a[0] << '\n';
            return;
        }

        ill nowS = 0, ans = 0;
        for (ill i = 0; i <= n - 1; i += 2) nowS += a[i];

        ans = max(ans, nowS);
        for (ill i = 1; i <= n - 1; ++i)
        {
            nowS = totS - nowS + a[i - 1];
            ans = max(ans, nowS);
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1372D_OmkarandCircle.in", "r", stdin);
    freopen("CF_1372D_OmkarandCircle.out", "w", stdout);
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