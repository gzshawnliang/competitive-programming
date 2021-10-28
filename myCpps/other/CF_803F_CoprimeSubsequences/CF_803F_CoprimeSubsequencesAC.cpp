/*
===========================================================
* @Name:           803F Coprime Subsequences
* @Author:         Shawn
* @create Time:    2020/3/2 20:13:32
* @url:            https://codeforces.com/contest/803/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
        f[i] = (1ll * pow2[m[i]] - 1 +mod ) % mod;
        for (int j = i + i; j <= mx; j += i)
            f[i] = (f[i] - f[j]) % mod;

        ans = (ans + 1ll * f[i] ) % mod;
    }
    ans = (1ll * pow2[n] - 1 - ans*1ll +mod ) % mod;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_803F_CoprimeSubsequences.in", "r", stdin);
        //freopen("CF_803F_CoprimeSubsequences.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}