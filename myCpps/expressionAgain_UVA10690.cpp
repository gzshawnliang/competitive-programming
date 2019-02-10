#include <bits/stdc++.h>

using namespace std;

ifstream fin("expressionAgain_UVA10690.in");
ofstream fout("expressionAgain_UVA10690.out");

int main()
{
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n + m == 0) break;

        if (n > m) swap(n, m);

        int s = n + m;
        vector<int> a(s);

        for (int i = 0; i <= s - 1; ++i)
        {
            fin >> a[i];
        }
        sort(a.begin(), a.end());

        int total = 0;

        vector<vector<bool>> dp(n + 1, vector<bool>(5001, false));
        dp[0][2500 + 0] = 1;

        for (int i = 1; i <= s; ++i)
        {
            total += a[i - 1];
            for (int j = min(i, n); j >= 1; --j)
            {
                for (int k = -2500; k <= 2500; ++k)
                {
                    if (dp[j - 1][2500 + k] > 0)
                    {
                        dp[j][2500 + k + a[i - 1]] = true;
                    }
                }
            }
        }

        int ansMax = INT_MIN, ansMin = INT_MAX;
        for (int k = -2500; k <= 2500; ++k)
        {
            if (dp[n][k + 2500] == true)
            {
                int now = k * (total - k);

                ansMax = max(ansMax, now);
                ansMin = min(ansMin, now);
            }
        }

        fout << ansMax << ' ' << ansMin << '\n';
    }

    return 0;
}
