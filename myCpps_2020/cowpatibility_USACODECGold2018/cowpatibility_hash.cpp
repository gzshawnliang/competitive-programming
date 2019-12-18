#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

using ll = long long;

const ll m = 5;
const ll base = 1001629, MOD = 1000000000000003951;

int main()
{
    ll n; fin >> n;

    unordered_map<ll, ll> mp;

    ll ans = n * (n - 1) / 2;
    for (ll c = 1; c <= n; ++c)
    {
        vector<ll> a(m);
        for (ll i = 0; i <= m - 1; ++i)
        {
            fin >> a[i];
        }

        sort(a.begin(), a.end());

        ll res = 0;
        for (ll i = 1; i <= 31; ++i)
        {
            bitset<5> b(i);

            ll temp = 0;
            for (ll i = 0; i <= m - 1; ++i)
            {
                if (b[i] == 1) temp = (temp * base % MOD + a[i]) % MOD;
            }

            ++mp[temp];
            if (b.count() % 2 == 1)
            {
                res += (mp[temp] - 1);
            }
            else
            {
                res -= (mp[temp] - 1);
            }
        }

        ans -= res;
    }

    fout << ans << '\n';

    return 0;
}
