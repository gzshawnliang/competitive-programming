/*
-------------------------------------------------------------------
* @Name:           1462E2 Close Tuples (hard version)
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/E2
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

//*****************************************************************
// const int N = 400, mod = 1000007;
// void solve()
// {
//     vector<vector<int>> C(N + 1, vector<int>(N + 1, 0)); C[0][0] = 1;
//     for (int i = 1; i <= N; ++i)
//     {
//         for (int j = 0; j <= i; ++j)
//         {
//             if (j == 0 || j == i)
//             {
//                 C[i][j] = 1;
//             }
//             else
//             {
//                 C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//             }
//         }
//     }

//     int tcc; cin >> tcc;
//     for (int t = 1; t <= tcc; ++t)
//     {
//         int n, m, k; cin >> n >> m >> k;

//         if (k > n * m)
//         {
//             cout << "Case " << t << ": 0\n";
//             continue;
//         }

//         int ans = 0;
//         for (int i = 0; i <= (1 << 4) - 1; ++i)
//         {
//             bitset<4> b(i);
//             int tmpSiz = n * m;
//             if (b[0] == 1) tmpSiz -= n;
//             if (b[1] == 1) tmpSiz -= n;
//             if (b[2] == 1) tmpSiz -= m;
//             if (b[3] == 1) tmpSiz -= m;
//             tmpSiz += (b[0] + b[1]) * (b[2] + b[3]);

//             if (b.count() % 2 == 0) ans = (ans + C[tmpSiz][k]) % mod;
//             else                    ans = (ans + mod - C[tmpSiz][k]) % mod;
//         }

//         cout << "Case " << t << ": " << ans << '\n';
//     }
// }

 //*****************************************************************
// const ill mod = 1e9 + 7, maxN = 20;
 
// ill quickPow(ill a, ill n, ill p)    //快速幂 a^n % p
// {
//     ill ans = 1;
//     while(n)
//     {
//         if(n & 1) ans = ans * a % p;
//         a = a * a % p;
//         n >>= 1;
//     }
//     return ans;
// }
 
// ill ine(ill a, ill b)   //费马小定理求逆元
// {
//     return quickPow(a, b - 2, b);
// }
 
// ill C(ill a, ill b)    //计算C(a, b)
// {
//     if (b > a) return 0;
 
//     ill upper = 1, downw = 1;
//     for (ill i = a - b + 1; i <= a; ++i) upper = (upper * i) % mod;
//     for (ill i = 1;         i <= b; ++i) downw = (downw * i) % mod;
 
//     return (upper * ine(downw, mod)) % mod;
// }
 
// ill lucas(ill a, ill b)
// {
//     if (b == 0) return  1;
//     else        return (C(a % mod, b % mod) * lucas(a / mod, b / mod)) % mod;
// }
 
// void solve()
// {
//     ill n, s; cin >> n >> s;
 
//     vector<ill> a(n);
//     for (ill i = 0; i <= n - 1; ++i)
//     {
//         cin >> a[i];
//     }
 
//     ill ans = 0;
//     for (ill x = 0; x <= (1 << n) - 1; ++x)
//     {
//         ill totalCrack = n + s - 1;
//         bitset<maxN> b(x);
//         for (int i = 0; i <= n - 1; ++i)
//         {
//             if (b[i] == 1)
//             {
//                 totalCrack -= (a[i] + 1);
//             }
//         }
 
//         if (totalCrack >= n - 1)
//         {
//             if (b.count() % 2 == 0)
//             {
//                 ans = (ans + lucas(totalCrack, n - 1)) % mod;
//             }
//             else
//             {
//                 ans = (ans + mod - lucas(totalCrack, n - 1)) % mod;
//             }
//         }
//     }
 
//     cout << ans << '\n';
// }

//*****************************************************************
// const ill mod = 1e9 + 7, maxN = 300005;
 
// ill quickPow(ill a, ill n, ill p)    //快速幂 a^n % p
// {
//     ill ans = 1;
//     while(n)
//     {
//         if(n & 1) ans = ans * a % p;
//         a = a * a % p;
//         n >>= 1;
//     }
//     return ans;
// }
 
// ill ine(ill a, ill b)   //费马小定理求逆元
// {
//     return quickPow(a, b - 2, b);
// }
 
// ill C(ill a, ill b, vector<ill> &fac)    //计算C(a, b)
// {
//     if      (b > a)  return 0;
//     else if (b == 0) return 1;
//     else if (b == 1) return a;
//     else             return fac[a] * ine(fac[b], mod) % mod * ine(fac[a - b], mod) % mod;
// }

class solution
{
  public:
    const ill mod = 1e9 + 7;
    
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
    
    ill ine(ill a, ill b)   //费马小定理求逆元
    {
        return quickPow(a, b - 2, b);
    }
    
    vector<ill> fac;
    ill C(ill a, ill b)    //计算C(a, b)
    {
        if      (b > a)  return 0;
        else if (b == 0) return 1;
        else if (b == 1) return a;
        else             return fac[a] * ine(fac[b], mod) % mod * ine(fac[a - b], mod) % mod;
    }

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, m, k; cin >> n >> m >> k;

            fac = vector<ill>(n + 1, 1);
            for (int i = 2; i <= n; ++i)
            {
                fac[i] = (fac[i - 1] * i) % mod;
            }
            
            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

            if (n < m)
            {
                cout << "0\n";
                continue;
            }

            sort(a.begin(), a.end());

            ill ans = 0;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill pos = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
                --pos;

                if (pos - i + 1 >= m)
                {
                    ans = (ans + C(pos - i, m - 1)) % mod;
                }
            }

            cout << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1462E2_CloseTupleshardversion.in", "r", stdin);
    freopen("CF_1462E2_CloseTupleshardversion.out", "w", stdout);
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