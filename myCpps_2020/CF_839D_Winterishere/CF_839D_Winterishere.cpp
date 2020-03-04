/*
===========================================================
* @Name:           839D Winter is here
* @Author:         Shawn
* @create Time:    2020/3/4 22:07:28
* @url:            https://codeforces.com/contest/839/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill maxN = 1000000, mod = 1e9 + 7;

void solve()
{
    ill n; cin >> n;

    ill maxNum = 0;
    vector<ill> a(n), m(maxN + 1), cnt(maxN + 1), pow2(n + 1, 1);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        ++m[a[i]]; ++cnt[a[i]];

        maxNum = max(maxNum, a[i]);
    }

    for (ill i = 1; i <= maxNum; ++i)
    {
        for (ill j = i * 2; j <= maxNum; j += i)
        {
            m[i] = (m[i] + m[j]) % mod;
        }
    }

    for (ill i = 1; i <= n; ++i)
    {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    // ill ans = 0;
    // for (ill i = 2; i <= maxNum; ++i)
    // {
    //     if (m[i] == 0) continue;

    //     ill tolTra = (pow2[m[i] - 1] * m[i]) % mod;
    //         tolTra = (tolTra + mod - (m[i] + mod - cnt[i])) % mod;

    //     ans = (ans + (i * tolTra) % mod) % mod;
    // }

    ill ans = 0;
    vector<ill> f(maxNum + 1, 0);
    for (ill i = maxNum; i >= 2; --i)
    {
        f[i] = (pow2[m[i] - 1] * m[i]) % mod;
        for (ill j = i * 2; j <= maxNum; j += i)
        {
            f[i] = (f[i] + mod - f[j]) % mod;
        }

        ans = (ans + (i * f[i]) % mod) % mod;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_839D_Winterishere.in", "r", stdin);
        freopen("CF_839D_Winterishere.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}