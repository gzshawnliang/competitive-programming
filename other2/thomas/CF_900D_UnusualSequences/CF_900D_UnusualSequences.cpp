/*
===========================================================
* @Name:           900D Unusual Sequences
* @Author:         Thomas
* @create Time:    2020/3/6 16:44:56
* @url:            https://codeforces.com/contest/900/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (y % x == 0)
    {
        int k = y / x;
        vector<int> pow2; //pow2[i],代表2^i
        pow2.push_back(0);
        pow2[0] = 1;
        for (int i = 1; i <= k; ++i)
        {
            pow2.push_back(0);
            pow2[i] = 2ll * pow2[i - 1] % mod;
        }
        
        //int ans = 1ll * pow2[k - 1] % mod;
        vector<int> m(k+1,1);
    
        //数字x的倍数有多少个,含x
        for (int x = 1; x <= k; ++x)
            for (int j = x + x; j <= k; j += x)
                m[x] += m[j];

        int ans = 0;
        vector<int> f(k+1,0);
        // for (int i = k; i >= 2; --i)
        // {
        //     f[i] = (1ll * pow2[m[i]] - 1 + mod) % mod;
        //     for (int j = i + i; j <= k; j += i)
        //         f[i] = (f[i] - f[j]) % mod;

        //     ans = (ans + 1ll * f[i]) % mod;
        // }
        // ans = (1ll * pow2[k - 1] - ans * 1ll + mod) % mod;

        for (int i = k; i >= 1; --i)
        {
            f[i] = (1ll * pow2[m[i]] - 1 +mod ) % mod;
            for (int j = i + i; j <= k; j += i)
                f[i] = (1ll * f[i] - 1ll * f[j]+ 1ll * mod) % mod;
        }

        cout << f[1] << "\n";
        //cout << ans << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_900D_UnusualSequences.in", "r", stdin);
    //freopen("CF_900D_UnusualSequences.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}