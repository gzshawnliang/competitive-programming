#include <bits/stdc++.h>

using namespace std;


using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        ll n = 0, s = 0; cin >> n >> s;
        if (n + s == 0) break;

        vector<ll> a(n, 0);
        for (ll i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
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
            cout << "0\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

