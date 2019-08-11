#include <bits/stdc++.h>

using namespace std;

ifstream fin("SCOI2005_2153.in");
ofstream fout("SCOI2005_2153.out");

using ll = long long;

ll pow2(ll n)
{
    return (1 << n);
}

int main()
{
    ll n, k; fin >> n >> k;
    ll maxN = pow2(n) - 1;

    vector<ll> count(maxN + 1, 0), sta;

    for (ll x = 0; x <= maxN; ++x)
    {
        bitset<9> temp(x);
        
        ll res = 0;
        for (ll j = 0; j <= n - 1; ++j)
        {
            if (temp[j] == 1)
            {
                ++res;

                if (j <= n - 2)
                {
                    if (temp[j] == temp[j + 1])
                    {
                        res = -1;
                        break;
                    }
                }
            }
        }

        count[x] = res;
        if (res >= 0)
        {
            sta.push_back(x);
        }
    }

    ll size = sta.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (maxN + 1, vector<ll>(k + 1, 0)));
    for (ll j = 0; j <= size - 1; ++j)
    {
        ll now = sta[j];
        dp[0][now][count[now]] = 1;
    }

    for (ll i = 1; i <= n - 1; ++i)
    {
        for (ll j = 0; j <= size - 1; ++j)
        {
            ll now = sta[j];
            for (ll c = count[now]; c <= k; ++c)
            {
                for (ll l = 0; l <= size - 1; ++l)
                {
                    bool ok = true;
                    ll last = sta[l];
                    bitset<9> a(now), b(last);
                    for (ll p = 0; p <= n - 1 && ok == true; ++p)
                    {
                        for (ll q = 0; q <= n - 1 && ok == true; ++q)
                        {
                            if (a[p] == 1 && b[q] == 1)
                            {
                                if (abs(p - q) <= 1)
                                {
                                    ok = false;
                                }
                            }
                        }
                    }

                    if (ok == true)
                    {
                        if (i == 1 && j == 0 && c == 1)
                        {
                            for (int __s = 0; __s == 0; ++__s);
                        }

                        dp[i][now][c] += dp[i - 1][last][c - count[now]];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j <= size - 1; ++j)
    {
        ll now = sta[j];
        ans += dp[n - 1][now][k];
    }

    fout << ans << '\n';

    return 0;
}
