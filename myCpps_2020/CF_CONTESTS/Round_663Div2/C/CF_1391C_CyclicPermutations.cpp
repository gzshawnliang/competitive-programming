/*
-------------------------------------------------------------------
* @Name:           1391C Cyclic Permutations 
* @Author:         Shawn
* @Create Time:    2020/8/9 22:35:11  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1391/problem/C
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
    const ill mod = 1e9 + 7;

  public:
    void solve()
    {
        ill n; cin >> n;

        ill tol1 = 1;
        for (ill x = 1; x <= n; ++x)
        {
            tol1 = (tol1 * x) % mod;
        }

        ill tol2 = 1;
        for (ill c = 1; c <= n - 1; ++c)
        {
            tol2 = (tol2 * 2) % mod;
        }

        cout << (tol1 - tol2 + mod) % mod << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1391C_CyclicPermutations.in", "r", stdin);
    freopen("CF_1391C_CyclicPermutations.out", "w", stdout);
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