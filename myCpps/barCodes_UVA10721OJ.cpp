#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        long long n = 0, k = 0, m = 0; cin >> n >> k >> m;
        if (n + k + m == 0) break;

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int t = 1; t <= j; ++t)
                {
                    if (t > m) break;
                    dp[i][j] += dp[i - 1][j - t];
                }
            }
        }

        cout << dp[k][n] << '\n';
    }

   	cout.flush();
   	return 0;
}

