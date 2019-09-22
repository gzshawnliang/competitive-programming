#include <bits/stdc++.h>

using namespace std;

ifstream fin("storageKeepers_UVA10163.in");
ofstream fout("storageKeepers_UVA10163.out");

const int inf = INT_MAX / 3;

int main()
{
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n + m == 0) break;

        vector<int> p(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> p[i];
        }

        sort(p.begin(), p.end(), greater<int>());

        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        for (int i = 0; i <= m - 1; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = p[i] / j;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    for (int k = 1; k <= j; ++k)
                    {
                        dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k], p[i] / k));
                    }
                }
            }
        }

        int ansL = dp[m - 1][n];

        if (ansL == 0)
        {
            fout << "0 0\n";
            continue;
        }

        vector<vector<int>> dp2(m, vector<int>(n * 2 + 1, 0));
        for (int i = 0; i <= m - 1; ++i)
        {
            int nowC = p[i] / ansL;
            for (int j = 1; j <= n * 2; ++j)
            {
                if (i == 0)
                {
                    if (j == nowC)
                    {
                        dp2[i][j] = p[i];
                    }
                    else
                    {
                        dp2[i][j] = inf;
                    }
                }
                else
                {
                    if (j < nowC)
                    {
                        dp2[i][j] = dp2[i - 1][j];
                    }
                    else
                    {
                        dp2[i][j] = min(dp2[i - 1][j], dp2[i - 1][j - nowC] + p[i]);
                    }
                }
            }
        }

        int ansY = 0;
        for (int j = n; j <= n * 2; ++j)
        {
            if (dp2[m - 1][j] < inf)
            {
                ansY = dp2[m - 1][j];
                break;
            }
        }

        fout << ansL << ' ' << ansY << '\n';
    }

    return 0;
}
