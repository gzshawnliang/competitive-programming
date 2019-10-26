#include <bits/stdc++.h>

using namespace std;

ifstream fin("subsequence_UVA1121.in");
ofstream fout("subsequence_UVA1121.out");

using ll = long long;

int main()
{
    while (true)
    {
        ll n = 0, s = 0; fin >> n >> s;
        if (n + s == 0) break;

        vector<ll> a(n, 0);
        for (ll i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        ll l = 0, r = 0, now = a[0], ans = LLONG_MAX;
        while (true)
        {
            if (now < s)
            {
                ++r;
                if (r > n - 1) break;

                now += a[r];
            }
            else
            {
                ans = min(ans, r - l + 1);

                now -= a[l];
                ++l;
            }
        }

        if (ans == LLONG_MAX)
        {
            fout << "0\n";
        }
        else
        {
            fout << ans << '\n';
        }
    }

    return 0;
}
