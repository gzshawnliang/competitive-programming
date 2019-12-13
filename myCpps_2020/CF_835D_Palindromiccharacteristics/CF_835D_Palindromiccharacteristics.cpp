/*
===========================================================
* @Name:           835D Palindromic characteristics
* @Author:         Shawn
* @create Time:    2019/12/13 22:15:56
* @url:            https://codeforces.com/contest/835/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MOD = 1e9 + 7, base = 131;
 
ll getHash(bool reverse, int i, int j, ll nowBase, vector<ll> & startHash, vector<ll> & endHash)
{
    if (reverse == false) return ((startHash[j] - startHash[i - 1] * nowBase) % MOD + MOD) % MOD;
    else return ((endHash[i] - endHash[j + 1] * nowBase) % MOD + MOD) % MOD;
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
 
    vector<ll> allBase(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        allBase[i] = (allBase[i - 1] * base) % MOD;
    }

    vector<ll> out(n + 2, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int size = 1; size <= n; ++size)
    {
        for (int i = 1; i <= n - size + 1; ++i)
        {
            if (size == 1)
            {
                dp[i][size] = 1;
            }
            else
            {
                ll nowBase = allBase[size / 2];
                if (getHash(0, i, i + size / 2 - 1, nowBase, startHash, endHash) == getHash(1, i + size - 1 - size / 2 + 1, i + size - 1, nowBase, startHash, endHash))
                {
                    dp[i][size] = dp[i][size / 2] + 1;
                }
            }

            // if (dp[i][size] == 1)
            // {
            //     cout << s.substr(i, size) << '\n';
            // }
            
            ++out[dp[i][size]];
        }
    }

    for (int i = n; i >= 1; --i)
    {
        out[i] += out[i + 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i > 1) cout << ' ';
        cout << out[i] ;
    }
    cout << " \n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_835D_Palindromiccharacteristics.in", "r", stdin);
        freopen("CF_835D_Palindromiccharacteristics.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}