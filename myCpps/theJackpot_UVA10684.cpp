#include <bits/stdc++.h>

using namespace std;

ifstream fin("theJackpot_UVA10684.in");
ofstream fout("theJackpot_UVA10684.out");

int main()
{
    while (true)
    {
        int n; fin >> n; if (n == 0) break;

        vector<int> a(n), dp(n, INT_MIN);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        int ans = a[0];
        dp[0] = a[0];

        for (int i = 1; i <= n - 1; ++i)
        {
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            ans = max(ans, dp[i]);
        }

        if (ans > 0)
        {
            fout << "The maximum winning streak is " << ans << ".\n";
        }
        else
        {
            fout << "Losing streak.\n";
        }
    }

    return 0;
}
