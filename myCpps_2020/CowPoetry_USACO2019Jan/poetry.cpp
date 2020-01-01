#include <bits/stdc++.h>

using namespace std;

ifstream fin("poetry.in");
ofstream fout("poetry.out");

using ll = long long;

const ll mod = 1e9 + 7;

ll quickPow(ll a, ll b)
{
    a %= mod;

    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a; ans %= mod;
        }
        a *= a; a %= mod;

        b /= 2;
    }

    return ans;
}

int main()
{
    ll n, m, k; fin >> n >> m >> k;

    vector<ll> l(n + 1, 0), y(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        fin >> l[i] >> y[i];
    }

    vector<ll> g(k + 1, 0); g[0] = 1;
    vector<vector<ll>> f(k + 1, vector<ll>(n + 1, 0));
    

    for (ll i = 1; i <= k; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            if (i >= l[j])
            {
                f[i][y[j]] = (f[i][y[j]] + g[i - l[j]]) % mod;
                g[i] = (g[i] + g[i - l[j]]) % mod;
            }
        }
    }

    vector<ll> count(26, 0);
    for (ll c = 1; c <= m; ++c)
    {
        char ch; fin >> ch;
        ++count[ch - 'A'];
    }

    ll ans = 1;
    for (ll ch = 0; ch <= 26 - 1; ++ch)
    {
        if (count[ch] > 0)
        {
            ll res = 0;
            for (ll j = 1; j <= n; ++j)
            {
                if (f[k][j] > 0) res = (res + quickPow(f[k][j], count[ch])) % mod;
            }

            ans = (ans * res) % mod;
        }
    }
    
    fout << ans << '\n';

    return 0;
}
