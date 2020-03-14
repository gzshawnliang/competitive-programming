/*
===========================================================
* @Name:           451E Devu and Flowers
* @Author:         Shawn
* @create Time:    2020/3/14 21:10:20
* @url:            https://codeforces.com/contest/451/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ill = long long;

const ill mod = 1e9 + 7, maxN = 20;

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

ill C(ill a, ill b)    //计算C(a, b)
{
    if (b > a) return 0;

    ill upper = 1, downw = 1;
    for (ill i = a - b + 1; i <= a; ++i) upper = (upper * i) % mod;
    for (ill i = 1;         i <= b; ++i) downw = (downw * i) % mod;

    return (upper * ine(downw, mod)) % mod;
}

ill lucas(ill a, ill b)
{
    if (b == 0) return  1;
    else        return (C(a % mod, b % mod) * lucas(a / mod, b / mod)) % mod;
}

void solve()
{
    ill n, s; cin >> n >> s;

    vector<ill> a(n);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }

    ill ans = 0;
    for (ill x = 0; x <= (1 << n) - 1; ++x)
    {
        ill totalCrack = n + s - 1;
        bitset<maxN> b(x);
        for (int i = 0; i <= n - 1; ++i)
        {
            if (b[i] == 1)
            {
                totalCrack -= (a[i] + 1);
            }
        }

        if (totalCrack >= n - 1)
        {
            if (b.count() % 2 == 0)
            {
                ans = (ans + lucas(totalCrack, n - 1)) % mod;
            }
            else
            {
                ans = (ans + mod - lucas(totalCrack, n - 1)) % mod;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_451E_DevuandFlowers.in", "r", stdin);
        freopen("CF_451E_DevuandFlowers.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}