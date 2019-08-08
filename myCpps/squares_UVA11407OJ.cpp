#include <bits/stdc++.h>

using namespace std;


const int N = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<int>> dp(101, vector<int>(N + 1, N)); dp[0][0] = 0;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int c = 0; c * i * i <= j; ++c)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - c * i * i] + c);
            }
        }
    }

    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int x; cin >> x;

        cout << dp[100][x] << '\n';
    }

   	cout.flush();
   	return 0;
}

