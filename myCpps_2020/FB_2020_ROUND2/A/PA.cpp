/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/30 0:57:01  (UTC+08:00)
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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k; cin >> n >> k;
            vector<ill> s(n, 0), x(n, 0), y(n, 0);

            for (ill i = 0; i <= k - 1; ++i) cin >> s[i];
            ill as, bs, cs, ds; cin >> as >> bs >> cs >> ds;
            for (ill i = k; i <= n - 1; ++i) s[i] = (as * s[i - 2] + bs * s[i - 1] + cs) % ds;

            for (ill i = 0; i <= k - 1; ++i) cin >> x[i];
            ill ax, bx, cx, dx; cin >> ax >> bx >> cx >> dx;
            for (ill i = k; i <= n - 1; ++i) x[i] = (ax * x[i - 2] + bx * x[i - 1] + cx) % dx;

            for (ill i = 0; i <= k - 1; ++i) cin >> y[i];
            ill ay, by, cy, dy; cin >> ay >> by >> cy >> dy;
            for (ill i = k; i <= n - 1; ++i) y[i] = (ay * y[i - 2] + by * y[i - 1] + cy) % dy;

            ill emptyTol = 0, emptyMin = 0, overTol = 0, overMin = 0;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill u = s[i], l = x[i], r = x[i] + y[i];

                if (u < r)
                {
                    if (u < l) emptyMin += (l - u);
                    emptyTol += (r - u);
                }

                if (u > l)
                {
                    if (u > r) overMin += (u - r);
                    overTol += (u - l);
                }
            }

            cout << "Case #" << tcc << ": ";

            ill ans = 0;
            if (overMin >= emptyMin)
            {
                overMin -= emptyMin;
                overTol -= emptyMin;
                emptyTol -= emptyMin;
                ans += emptyMin;
                emptyMin = 0;
            }
            else
            {
                emptyMin -= overMin;
                overTol -= overMin;
                emptyTol -= overMin;
                ans += overMin;
                overMin = 0;
            }
            if (overTol >= emptyMin)
            {
                overTol -= emptyMin;
                ans += emptyMin;
                emptyTol -= emptyMin;
                emptyMin = 0;
            }
            else
            {
                emptyMin -= overTol;
                emptyTol -= overTol;
                ans += overTol;
                overTol = 0;
            }

            if (emptyMin >= overMin)
            {
                emptyMin -= overMin;
                overTol -= overMin;
                emptyTol -= overMin;
                ans += overMin;
                overMin = 0;
            }
            else
            {
                overMin -= emptyMin;
                overTol -= emptyMin;
                emptyTol -= emptyMin;
                ans += emptyMin;
                emptyMin = 0;
            }
            if (emptyTol >= overMin)
            {
                emptyTol -= overMin;
                overTol -= overMin;
                ans += overMin;
                overMin = 0;
            }
            else
            {
                overMin -= emptyTol;
                overTol -= emptyTol;
                ans += emptyTol;
                emptyTol = 0;
            }

            if (overMin == 0 && emptyMin == 0)
            {
                cout << ans << '\n';
            }
            else
            {
                cout << "-1\n";
            }

            
            // if (las == 0)
            // {
            //     cout << ans << '\n';
            // }
            // else
            // {
            //     cout << "-1\n";
            // }
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("PA.in", "r", stdin);
    freopen("PA.out", "w", stdout);
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