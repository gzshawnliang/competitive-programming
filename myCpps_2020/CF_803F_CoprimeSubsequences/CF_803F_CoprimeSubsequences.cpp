/*
===========================================================
* @Name:           803F Coprime Subsequences
* @Author:         Shawn
* @create Time:    2020/3/6 22:16:17
* @url:            https://codeforces.com/contest/803/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill maxN = 1e6, mod = 1e9 + 7;

void solve()
{
    ill n; cin >> n;

    ill maxNum = 0;
    vector<ill> a(n), m(maxN + 1), pow2(n + 1, 1);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        ++m[a[i]];

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

    ill ans = pow2[n] - 1;
    vector<ill> f(maxNum + 1, 0);
    for (ill i = maxNum; i >= 2; --i)
    {
        f[i] = (pow2[m[i]] - 1) % mod;
        for (ill j = i * 2; j <= maxNum; j += i)
        {
            f[i] = (f[i] + mod - f[j]) % mod;
        }

        ans = (ans + mod - f[i]) % mod;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_803F_CoprimeSubsequences.in", "r", stdin);
        freopen("CF_803F_CoprimeSubsequences.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}