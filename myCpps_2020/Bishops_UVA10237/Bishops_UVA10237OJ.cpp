#include <bits/stdc++.h>

using namespace std;


using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        ll n = 0, k = 0; cin >> n >> k;
        if (n + k == 0) break;

        vector<vector<ll>> b(n + 1, vector<ll>(n * n + 1, 0)),
                            w(n + 1, vector<ll>(n * n + 1, 0));

        b[1][0] = 1;
        for (ll i = 2; i <= n; ++i)
        {
            ll l = i / 2 * 2;

            b[i][0] = b[i - 1][0];
            for (ll j = 1; j <= l && j <= k; ++j)
            {
                b[i][j] = b[i - 1][j] + b[i - 1][j - 1] * (l - j + 1);
            }
        }

        w[0][0] = 1;
        for (ll i = 1; i <= n; ++i)
        {
            ll l = (i + 1) / 2 * 2 - 1;

            w[i][0] = w[i - 1][0];
            for (ll j = 1; j <= l && j <= k; ++j)
            {
                w[i][j] = w[i - 1][j] + w[i - 1][j - 1] * (l - j + 1);
            }
        }

        ll ans = 0;
        for (int bc = 0; bc <= k; ++bc)
        {
            ans += (b[n][bc] * w[n][k - bc]);
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

