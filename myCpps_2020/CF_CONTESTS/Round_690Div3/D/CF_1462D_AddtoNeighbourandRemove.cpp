/*
-------------------------------------------------------------------
* @Name:           1462D Add to Neighbour and Remove
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/D
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
    // vector<ill> a;
    // void check(ill len, ill sum)
    // {
    //     ill cnt = 0, i = 0, n = a.size();
        
    //     while (i <= n - 1)
    //     {
            
    //     }
    // }

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            ill sum = 0;
            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                sum += a[i];
            }

            for (ill len = n; len >= 1; --len)
            {
                if (sum % len == 0)
                {
                    ill tmp = 0, cnt = 0, x = sum / len;
                    for (ill i = 0; i <= n - 1; ++i)
                    {
                        tmp += a[i];
                        if (tmp == x)
                        {
                            ++cnt;
                            tmp = 0;
                        }
                    }

                    if (cnt == len)
                    {
                        cout << n - len << '\n';
                        break;
                    }
                }
            }
            
            // ill l = 0, r = n - 1;
            // while (true)
            // {

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
    freopen("CF_1462D_AddtoNeighbourandRemove.in", "r", stdin);
    freopen("CF_1462D_AddtoNeighbourandRemove.out", "w", stdout);
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