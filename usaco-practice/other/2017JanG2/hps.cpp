#include <bits/stdc++.h>

using namespace std;

ifstream fin("hps.in");
ofstream fout("hps.out");

int main()
{
    int n, k; fin >> n >> k;

    vector<char> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, 0)));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0][0] = dp[i - 1][0][0] + (a[i] == 'H');
        dp[i][0][1] = dp[i - 1][0][1] + (a[i] == 'P');
        dp[i][0][2] = dp[i - 1][0][2] + (a[i] == 'S');
    }

    for (int c = 1; c <= k; ++c)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[i][c][0] = max(dp[i - 1][c][0], max(dp[i - 1][c - 1][1], dp[i - 1][c - 1][2])) + (a[i] == 'H');
            dp[i][c][1] = max(dp[i - 1][c][1], max(dp[i - 1][c - 1][0], dp[i - 1][c - 1][2])) + (a[i] == 'P');
            dp[i][c][2] = max(dp[i - 1][c][2], max(dp[i - 1][c - 1][0], dp[i - 1][c - 1][1])) + (a[i] == 'S');
        }
    }

    int ans = 1;
    ans = max(ans, dp[n][k][0]);
    ans = max(ans, dp[n][k][1]);
    ans = max(ans, dp[n][k][2]);

    fout << ans << '\n';

    return 0;
}
