#include <bits/stdc++.h>

using namespace std;

ifstream fin("gameShowMath_UVA10400.in");
ofstream fout("gameShowMath_UVA10400.out");

using ll = long long;

const ll maxN = 64000, maxNH = 32000;

int main()
{
    string operators = "+-*/";

    ll tcc; fin >> tcc;
    for (ll t = 1; t <= tcc; ++t)
    {
        ll n; fin >> n;
        vector<ll> a(n, 0);
        for (ll i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        ll target; fin >> target;

        vector<ll> dp0(maxN + 1, 0),
                   dp1(maxN + 1, 0);
        vector<vector<ll>> f(n, vector<ll>(maxN + 1, 4));

        dp0[a[0] + maxNH] = 1;
        for (ll i = 1; i <= n - 1; ++i)
        {
            for (ll j = -32000; j <= 32000; ++j)
            {
                ll last;

                // +
                last = j - a[i];
                if (-32000 <= last && last <= 32000)
                {
                    if (dp0[last + maxNH] == 1)
                    {
                        dp1[j + maxNH] = 1;
                        f[i][j + maxNH] = 0;
                    }
                }

                // -
                last = j + a[i];
                if (-32000 <= last && last <= 32000)
                {
                    if (dp0[last + maxNH] == 1)
                    {
                        dp1[j + maxNH] = 1;
                        f[i][j + maxNH] = 1;
                    }
                }

                // *
                last = j / a[i];
                if (-32000 <= last && last <= 32000 && j % a[i] == 0)
                {
                    if (dp0[last + maxNH] == 1)
                    {
                        dp1[j + maxNH] = 1;
                        f[i][j + maxNH] = 2;
                    }
                }

                // /
                last = j * a[i];
                if (-32000 <= last && last <= 32000)
                {
                    if (dp0[last + maxNH] == 1)
                    {
                        dp1[j + maxNH] = 1;
                        f[i][j + maxNH] = 3;
                    }
                }
            }

            dp0 = dp1;
            for (ll j = -32000; j <= 32000; ++j)
            {
                dp1[j + maxNH] = 0;
            }
        }

        if (dp0[target + maxNH] == 1)
        {
            ll now = target;
            string ansO = "";

            for (int i = n - 1; i >= 1; --i)
            {
                ansO += operators[f[i][now + maxNH]];

                if      (f[i][now + maxNH] == 0) now -= a[i];
                else if (f[i][now + maxNH] == 1) now += a[i];
                else if (f[i][now + maxNH] == 2) now /= a[i];
                else if (f[i][now + maxNH] == 3) now *= a[i];
            }

            for (ll i = 0; i <= n - 1; ++i)
            {
                if (i > 0) fout << ansO[n - 1 - i];
                fout << a[i];
            }
            fout << '=' << target << '\n';
        }
        else
        {
            fout << "NO EXPRESSION\n";
        }
    }

    return 0;
}
