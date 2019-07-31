#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

ifstream fin("QueriesI3.in");
ofstream fout("QueriesI3B.out");

const ll inf = LLONG_MAX / 2;

int main()
{
    ll n; fin >> n;
    vector<ll> a(n + 1, inf);
    for (ll i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    ll m; fin >> m;
    for (ll c = 1; c <= m; ++c)
    {
        ll t, x, y; fin >> t >> x >> y;

        if (t == 0)
        {
            a[x] = y;
        }
        else
        {
            int ans = -1 * inf;
            for (int i = x; i <= y; ++i)
            {
                for (int j = i; j <= y; ++j)
                {
                    int res = 0;
                    for (int k = i; k <= j; ++k)
                    {
                        res += a[k];
                    }

                    ans = max(ans, res);
                }
            }

            fout << ans << '\n';
        }
    }

    return 0;
}
