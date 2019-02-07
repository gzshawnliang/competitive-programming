#include <bits/stdc++.h>

using namespace std;

ifstream fin("flightPlanner_UVA10337.in");
ofstream fout("flightPlanner_UVA10337.out");

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        long long x = 0; fin >> x;

        x /= 100;
        vector<vector<long long>> a(10, vector<long long>(x + 1, 0));
        for (int y = 9; y >= 0; --y)
        {
            for (int i = 0; i <= x - 1; ++i)
            {
                fin >> a[y][i];
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

        fout << dp[0][x] << "\n\n";
    }

    return 0;
}
