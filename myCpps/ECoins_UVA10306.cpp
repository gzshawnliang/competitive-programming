#include <bits/stdc++.h>

using namespace std;

ifstream fin("ECoins_UVA10306.in");
ofstream fout("ECoins_UVA10306.out");

struct coin
{
    int x;
    int y;
};

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int m, s; fin >> m >> s;

        vector<coin> a(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> a[i].x >> a[i].y;
        }

        vector<vector<int>> dp(s + 1, vector<int>(s + 1, INT_MAX));

        int ans = INT_MAX;
        dp[0][0] = 0;

        for (int i = 0; i <= s; ++i)
        {
            for (int j = 0; j <= s; ++j)
            {
                for (int k = 0; k <= m - 1; ++k)
                {
                    if (i - a[k].x < 0 || j - a[k].y < 0)
                    {
                        continue;
                    }

                    if (dp[i - a[k].x][j - a[k].y] < INT_MAX)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - a[k].x][j - a[k].y] + 1);
                    }

                    if (i * i + j * j == s * s && dp[i][j] < INT_MAX)
                    {
                        ans = min(ans, dp[i][j]);
                    }
                }
            }
        }

        if (ans == INT_MAX)
        {
            fout << "not possible\n";
        }
        else
        {
            fout << ans << '\n';
        }
    }

    return 0;
}
