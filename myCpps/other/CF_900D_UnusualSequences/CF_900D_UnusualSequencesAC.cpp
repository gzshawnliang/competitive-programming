/*
===========================================================
* @Name:           900D Unusual Sequences
* @Author:         Shawn
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

#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int MAXN = 1e2 + 7;
typedef long long ll;

using namespace std;

ll mypow(ll base, ll p)
{
    if (p == 0)
        return 1;
    ll tmp = mypow(base, p / 2);
    if (p & 1)
        tmp = (tmp * tmp * base) % MOD;
    else
        tmp = (tmp * tmp) % MOD;
    return tmp;
}

void solve()
{
    ll x, y;
    cin >> x >>y;
    vector<ll> a;
    ll dp[MAXN];

    if (y % x == 0)
    {

        for (ll i = 1; i * i <= y; ++i)
        {
            if (i % x == 0 && y % i == 0)
                a.push_back(i);
            if (i * i != y && y % i == 0 && (y / i) % x == 0)
                a.push_back(y / i);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            dp[i] = mypow(2, (y / a[i] - 1));

        for (int i = (int)a.size() - 1; i >= 0; i--)
            for (int j = i + 1; j < a.size(); j++)
                if (a[j] % a[i] == 0)
                {
                    dp[i] -= dp[j];
                    dp[i] = (dp[i] + MOD) % MOD;
                }
        cout << dp[0] << endl;
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