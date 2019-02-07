#include <bits/stdc++.h>

using namespace std;

ifstream fin("barCodes_UVA10721.in");
ofstream fout("barCodes_UVA10721.out");

int main()
{
    while (true)
    {
        long long n = 0, k = 0, m = 0; fin >> n >> k >> m;
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

        fout << dp[k][n] << '\n';
    }

    return 0;
}
