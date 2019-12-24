#include <bits/stdc++.h>

using namespace std;

ifstream fin("talent.in");
ofstream fout("talent.out");

const int inf = INT_MAX / 1000;
const pair<int, int> _null = make_pair(-1, -1);

int main()
{
    int n, w; fin >> n >> w;

    int maxW = 0;
    vector<pair<int, int>> a(n + 1, _null);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i].first >> a[i].second;
        maxW += a[i].first;
    }

    vector<vector<int>> dp(n + 1, vector<int>(maxW + 1, -1 * inf));

    dp[0][0] = 0;

    pair<int, int> ans = _null;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= maxW; ++j)
        {
            if (i == 4 && j == 27)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (j < a[i].first)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int temp1 = (dp[i - 1][j - a[i].first] + a[i].second) * j,
                    temp2 = dp[i - 1][j] * (j - a[i].first);

                if ((dp[i - 1][j - a[i].first] + a[i].second) * j > dp[i - 1][j] * (j - a[i].first))
                {
                    dp[i][j] = dp[i - 1][j - a[i].first] + a[i].second;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }

            if (dp[i][j] > 0 && j >= w)
            {
                if (ans == _null)
                {
                    ans = make_pair(j, dp[i][j]);
                }
                else if (dp[i][j] * ans.first > ans.second * j)
                {
                    ans = make_pair(j, dp[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i].first; j <= maxW; ++j)
        {
            if (dp[i][j] > 0)
            {
                fout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
            }
        }
    }

    fout << ans.first << ' ' << ans.second << '\n';

    fout << ans.second * 1000 / ans.first << '\n';

    return 0;
}
