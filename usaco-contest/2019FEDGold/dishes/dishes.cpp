#include <bits/stdc++.h>

using namespace std;

ifstream fin("dishes.in");
ofstream fout("dishes.out");

int main()
{
    int n; fin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    int ans = 0;
    vector<int> dp(n, 1);

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 0; j <= i - 1; ++j)
        {
            if (a[i] < a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    fout << ans + 1 << '\n';

    return 0;
}
