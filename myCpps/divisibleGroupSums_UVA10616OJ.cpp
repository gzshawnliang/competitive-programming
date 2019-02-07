#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int t = 0;
    while (true)
    {
        ++t;

        int n = 0, q = 0; cin >> n >> q;
        if (n + q == 0) break;

        vector<long long> in(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> in[i];
        }

        cout << "SET " << t << ":\n";

        for (int qi = 1; qi <= q; ++qi)
        {
            int m, d; cin >> d >> m;

            long long _max = 0;
            vector<long long> a = in;

            for (int i = 0; i <= n - 1; ++i)
            {
                a[i] %= d;
                if (a[i] < 0)
                {
                    a[i] += d;
                }

                _max += a[i];
            }

            vector<vector<long long>> dp(n + 2, vector<long long>(_max * 2 + 1, 0));

            dp[0][0] = 1;
            for (int i = 0; i <= n - 1; ++i)
            {
                for (int c = n; c >= 0; --c)
                {
                    for (int s = 0; s <= _max; ++s)
                    {
                        dp[c + 1][s + a[i]] += dp[c][s];
                    }
                }
            }

            long long ans = 0;

            if (m <= n)
            {
                for (int s = 0; s <= _max; s += d)
                {
                    ans += dp[m][s];
                }
            }
            

            cout << "QUERY " << qi << ": " << ans << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

