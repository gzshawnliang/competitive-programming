/*
===========================================================
* @Name:           839D Winter is here
* @Author:         Thomas
* @create Time:    2020/2/29 21:18:28
* @url:            https://codeforces.com/contest/839/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int maxA = 100;
const int maxN = 200;

// const int maxA=1001000;
// const int maxN=200100;
void solve()
{
    vector<int> a(maxA, 0); //a[x] 能整除数字x有多少个
    vector<int> f(maxA, 0);

    int n = 0, mx = 0;
    cin >> n;
    vector<int> pow2(n + 1, 0); //pow2[i],代表2^i
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = 2ll * pow2[i - 1] % mod;

    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        ++a[x]; //数字x有多少个
        mx = max(mx, x);
    }

    //数字x的倍数有多少个,含x
    for (int x = 1; x <= mx; ++x)
        for (int j = x + x; j <= mx; j += x)
            a[x] += a[j];

    int ans = 0;
    vector<int> ans2(maxA, 0);
    for (int i = mx; i >= 2; --i)
    {
        f[i] = 1ll * a[i] * pow2[a[i] - 1] % mod;
        cout << i << ":" << f[i] << " ";

        for (int j = i + i; j <= mx; j += i)
            f[i] = (f[i] - f[j]) % mod;

        cout << f[i] << "\n";

        ans = (ans + 1ll * f[i] * i) % mod;
        ans2[i]=(1ll * f[i] * i) % mod;
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