#include <bits/stdc++.h>

using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

int main()
{
    int n, k; fin >> n >> k;
    vector<int> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    dp[0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        int nowMax = 0;
        for (int j = 1; j <= k; ++j)
        {
            if (i + j > n) break;

            nowMax = max(nowMax, a[i + j]);
            dp[i + j] = max(dp[i + j], dp[i] + j * nowMax);
        }
    }

    fout << dp[n] << '\n';

    return 0;
}
