/*
===========================================================
* @Name:           154C Double Profiles
* @Author:         Shawn
* @create Time:    2019/12/14 17:03:34
* @url:            https://codeforces.com/contest/154/problem/C
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

ll MOD = 100000000743856857, base1 = 83563, base2 = 77999;

void solve()
{
    int n, m; cin >> n >> m;
    
    vector<ll> allBase1(n + 1, 1),
               allBase2(n + 1, 1),
               friends1(n + 1, 0),
               friends2(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        allBase1[i] = (allBase1[i - 1] * base1) % MOD;
        allBase2[i] = (allBase2[i - 1] * base2) % MOD;
        friends1[i] = (friends1[i] + allBase1[i]) % MOD;
    }

    for (int c = 1; c <= m; ++c)
    {
        int i, j; cin >> i >> j;
        friends1[i] = (friends1[i] + allBase1[j]) % MOD;
        friends1[j] = (friends1[j] + allBase1[i]) % MOD;

        friends2[i] = (friends2[i] + allBase2[j]) % MOD;
        friends2[j] = (friends2[j] + allBase2[i]) % MOD;
    }

    unordered_map<ll, ll> allHash;
    for (int i = 1; i <= n; ++i)
    {
        ++allHash[friends1[i]];
        ++allHash[friends2[i]];
    }

    ll ans = 0;
    for (auto it = allHash.begin(); it != allHash.end(); ++it)
    {
        ans += (it->second * (it->second - 1) / 2);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_154C_DoubleProfiles.in", "r", stdin);
        freopen("CF_154C_DoubleProfiles.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}