#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(2);

    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n, m; cin >> n >> m;

        vector<int> timeNeed(n + 1, 0);
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];

                if (a[i][j] >= 5 && timeNeed[i] == 0)
                {
                    timeNeed[i] = timeNeed[i - 1] + j;
                }
            }
        }

        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int k = m; k >= timeNeed[i]; --k)
            {
                for (int j = 0; j <= k; ++j)
                {
                    if (a[i][j] < 5) continue;
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - j] + a[i][j]);

                    if (i == n) ans = max(ans, dp[i][k]);
                }
            }
        }

        if (ans >= 5 * n)
        {
            double average = (double)ans / (double)n;
            average = (int)(average * 100.0 + 0.5) / 100.0;

            cout << "Maximal possible average mark - " << average << ".\n";
        }
        else
        {
            cout << "Peter, you shouldn't have played billiard that much.\n";
        }
    }

   	cout.flush();
   	return 0;
}

