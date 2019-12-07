/*
===========================================================
* @Name:           245H Queries for Number of Palindromes
* @Author:         Shawn
* @create Time:    2019/12/7 16:29:35
* @url:            https://codeforces.com/contest/245/problem/H
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

using ll =long long;

ll MOD = 1e9 + 7, base = 137;

ll isPalindromes(int i, int j, ll nowBase, vector<ll> & startHash, vector<ll> & endHash)
{
    if (i == 3 && j == 5)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    ll hash = ((startHash[j] - startHash[i - 1] * nowBase) % MOD + MOD) % MOD,
       hashr = ((endHash[i] - endHash[j + 1] * nowBase) % MOD + MOD) % MOD;

    return hash == hashr;
}

void solve()
{
    string s; cin >> s;
    int n = s.size();

    s = ' ' + s;

    vector<ll> startHash(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        startHash[i] = ((startHash[i - 1] * base + MOD) % MOD + s[i] + MOD) % MOD;
    }
    vector<ll> endHash(n + 2, 0);
    for (int i = n; i >= 1; --i)
    {
        endHash[i] = ((endHash[i + 1] * base + MOD) % MOD + s[i] + MOD) % MOD;
    }

    ll nowBase = 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int l = 1; l <= n; ++l)
    {
        nowBase = (nowBase * base) % MOD;

        for (int i = 1; i <= n - l + 1; ++i)
        {
            int j = i + l - 1;

            if (l == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                if (isPalindromes(i, j, nowBase, startHash, endHash) == true)
                {
                    ++dp[i][j];
                }
            }
        }
    }

    int q; cin >> q;
    for (int c = 1; c <= q; ++c)
    {
        int l, r; cin >> l >> r;

        cout << dp[l][r] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_245H_QueriesforNumberofPalindromes.in", "r", stdin);
        freopen("CF_245H_QueriesforNumberofPalindromes.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}