/*
===========================================================
* @Name:           839D Winter is here
* @Author:         Shawn
* @create Time:    2020/2/29 21:18:28
* @url:            https://codeforces.com/contest/839/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>
using namespace std;

const int mod  = 1e9+7;
const int maxA = 1e6+5;

void solve()
{
    vector<int> m(maxA, 0); //m[x] 能整除数字x有多少个
    vector<int> f(maxA, 0);

    int n = 0;
    cin >> n;
    vector<int> pow2(n + 1, 0); //pow2[i],代表2^i
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = 2ll * pow2[i - 1] % mod;
    
    int mx = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        ++m[x]; //数字x有多少个
        mx = max(mx, x);
    }

    //数字x的倍数有多少个,含x
    for (int x = 1; x <= mx; ++x)
        for (int j = x + x; j <= mx; j += x)
            m[x] += m[j];

    int ans = 0;
    for (int i = mx; i >= 2; --i)
    {
        f[i] = 1ll * m[i] * pow2[m[i] - 1] % mod;
        for (int j = i + i; j <= mx; j += i)
            f[i] = (f[i] - f[j]) % mod;

        ans = (ans + 1ll * f[i] * i) % mod;
    }

    cout << (ans*1ll + mod*1ll) % mod << "\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_839D_Winterishere.in", "r", stdin);
        //freopen("CF_839D_Winterishere.out", "w", stdout);
    #endif

    solve();
    return 0;
}