#include <bits/stdc++.h>

using namespace std;


using ll = long long;
const ll N = 65;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 2, vector<ll>(2, 0)));
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    for (ll i = 2; i <= N; ++i)
    {
        dp[i][0][0] = dp[i - 1][1][1] + dp[i - 1][0][0];
        for (ll j = 1; j <= i; ++j)
        {
            dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
        }
    }

    while (true)
    {
        ll n = -1, s = -1; cin >> n >> s;
        if (n + s < 0) break;

        cout << dp[n][s][0] + dp[n][s][1] << '\n';
    }

   	cout.flush();
   	return 0;
}

