/*
-------------------------------------------------------------------
* @Name:           1342E Placing Rooks
* @Author:         Shawn
* @Create Time:    2020/6/22 23:17:21  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1342/problem/E
* @File:           CF_1342E_PlacingRooks.cpp
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
    const ill mod = 998244353, maxN = 200000;

    ill quickPow(ill a, ill n, ill p)    //快速幂 a^n % p
    {
        ill ans = 1;
        while(n)
        {
            if(n & 1) ans = ans * a % p;
            a = a * a % p;
            n >>= 1;
        }
        return ans;
    }

    void solve()
    {
        ill n, k; cin >> n >> k;

        vector<ill> fac(n + 1, 1);
        for (ill x = 1; x <= n; ++x) fac[x] = (fac[x - 1] * x) % mod;
        vector<ill> ine(n + 1, -1); ine[n] = quickPow(fac[n], mod - 2, mod);
        for (ill x = n - 1; x >= 0; --x) ine[x] = (ine[x + 1] * (x + 1)) % mod;

        auto C=[&](ill a, ill b)
        {
            return ((fac[a] * ine[a - b]) % mod * ine[b]) % mod;
        };

        if (k == 0)
        {
            cout << fac[n] << '\n';
        }
        else if (k >= n)
        {
            cout << "0\n";
        }
        else
        {
            ill ans = 0, add = 1;
            for (ill ak = 0; k + ak <= n - 1; ++ak)
            {
                ans = (ans + (quickPow(n - k - ak, n, mod) * C(n - k, ak) * add + mod) % mod + mod) % mod;
                add *= -1;
            }

            ans = (ans * C(n, n - k) + mod) % mod;
            cout << (ans * 2 + mod) % mod << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1342E_PlacingRooks.in", "r", stdin);
    freopen("CF_1342E_PlacingRooks.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}