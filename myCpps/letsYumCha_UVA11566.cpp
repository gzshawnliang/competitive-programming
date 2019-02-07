#include <bits/stdc++.h>

using namespace std;

ifstream fin("letsYumCha_UVA11566.in");
ofstream fout("letsYumCha_UVA11566.out");

int main()
{
    fout << fixed << setprecision(2);

    while (true)
    {
        int n = 0, x = 0, t = 0, k = 0; fin >> n >> x >> t >> k;
        if (n + x + t + k == 0) break;

        ++n;

        int maxC = 2 * n, maxP = x * n * 10 / 11 - t * n, ans = 0;

        vector<vector<int>> dp(maxC + 1, vector<int>(maxP + 1, -1));
        dp[0][0] = 0;

        for (int i = 0; i <= k - 1; ++i)
        {
            int p; fin >> p;

            int v = 0;
            for (int c = 1; c <= n; ++c)
            {
                int temp; fin >> temp;
                v += temp;
            }

            for (int c = 1; c <= 2; ++c)
            {
                for (int i = maxC; i >= 1; --i)
                {
                    for (int j = maxP; j >= p; --j)
                    {
                        if (dp[i - 1][j - p] >= 0)
                        {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j - p] + v);
                        }

                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }

        fout << (double)ans / (double)n << '\n';
    }

    return 0;
}
