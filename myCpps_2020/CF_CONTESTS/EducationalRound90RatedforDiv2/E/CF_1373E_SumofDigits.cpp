/*
-------------------------------------------------------------------
* @Name:           1373E Sum of Digits
* @Author:         Shawn
* @Create Time:    2020/6/25 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1373/problem/E
* @File:           CF_1373E_SumofDigits.cpp
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
    
    // ill f(ill x)
    // {
    //     ill ans = 0;
    //     while (x > 0)
    //     {
    //         ans += (x % 10);
    //         x /= 10;
    //     }

    //     return ans;
    // }

    const ill inf = LLONG_MAX;

    void solve()
    {
        // cout << '\n';
        // for (ill x = 2; x <= 1000; ++x)
        // {
        //     cout << f(x) - f(x - 1) << '\n';
        // }

        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k; cin >> n >> k;

            ill ans = inf;
            for (ill c9 = 0; c9 <= 16; ++c9)
            {
                for (ill r = 0; r <= 9; ++r)
                {
                    ill res = 0;
                    for (ill i = 0; i <= k; ++i)
                    {
                        if (i + r < 10) res += i + r + 9 * c9;
                        else            res += i + r - 9;
                    }

                    ill lef = n - res;
                    if (lef % (k + 1) > 0 || lef < 0)
                    {
                        continue;
                    }

                    lef /= k + 1;

                    ill aans = 0;
                    if (lef < 9)
                    {
                        aans = lef;
                    }
                    else
                    {
                        lef -= 8;
                        
                        aans = lef % 9;
                        for (ill c = 1; c <= lef / 9; ++c) aans = aans * 10 + 9;
                        aans = aans * 10 + 8;
                    }

                    for (ill c = 1; c <= c9; ++c) aans = aans * 10 + 9;
                    aans = aans * 10 + r;

                    // if (aans == 0)
                    // {
                    //     for (int __s = 0; __s == 0; ++__s);
                    // }

                    ans = min(ans, aans);
                }
            }

            if (ans == inf) cout << "-1\n";
            else            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1373E_SumofDigits.in", "r", stdin);
    freopen("CF_1373E_SumofDigits.out", "w", stdout);
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