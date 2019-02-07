#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        long long x = 0; cin >> x;

        x /= 100;
        vector<vector<long long>> a(10, vector<long long>(x + 1, 0));
        for (int y = 9; y >= 0; --y)
        {
            for (int i = 0; i <= x - 1; ++i)
            {
                cin >> a[y][i];
            }
        }

        vector<vector<long long>> dp(10, vector<long long>(x + 1, INT_MAX));

        dp[0][0] = 0;
        for (int i = 1; i <= x; ++i)
        {
            for (int y = 0; y <= 9; ++y)
            {
                dp[y][i] = min(dp[y][i], dp[y][i - 1] + 30 - a[y][i - 1]);

                if (y < 9) dp[y][i] = min(dp[y][i], dp[y + 1][i - 1] + 20 - a[y + 1][i - 1]);
                if (y > 0) dp[y][i] = min(dp[y][i], dp[y - 1][i - 1] + 60 - a[y - 1][i - 1]);
            }
        }

        cout << dp[0][x] << "\n\n";
    }

   	cout.flush();
   	return 0;
}

