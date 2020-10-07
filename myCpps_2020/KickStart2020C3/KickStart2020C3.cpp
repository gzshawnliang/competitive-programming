/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/10/8 0:22:11  (UTC+08:00)
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

// #ifdef ONLINE_JUDGE
// #define NDEBUG //ban assert when submit to online judge
// #endif

// #ifndef ONLINE_JUDGE
// #include <chrono>
// #endif

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
            ill n; cin >> n;

            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
            }

            ill ans = 0, minF = 0;
            vector<ill> f(n, 0);
            unordered_map<ill, ill> mp;
            for (ill i = 0; i <= n - 1; ++i)
            {
                if (i == 0)
                {
                    f[i] = a[i];

                    ill maxX = f[i];
                    for (ill x = 0; x * x <= maxX; ++x)
                    {
                        if (f[i] == x * x) ++ans;
                    }
                    ++mp[f[i]];

                    minF = min(minF, f[i]);
                }
                else
                {
                    f[i] = f[i - 1] + a[i];

                    ill maxX = f[i] - minF;
                    for (ill x = 0; x * x <= maxX; ++x)
                    {
                        if (mp.count(f[i] - x * x)) ans += mp[f[i] - x * x];
                        if (f[i] == x * x) ++ans;
                    }
                    
                    ++mp[f[i]];

                    minF = min(minF, f[i]);
                }

                //cout << i << '\n';
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("KickStart2020C3.in", "r", stdin);
    //freopen("KickStart2020C3.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

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