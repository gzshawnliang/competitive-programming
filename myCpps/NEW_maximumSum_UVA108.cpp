#include <bits/stdc++.h>

using namespace std;

ifstream fin("NEW_maximumSum_UVA108.in");
ofstream fout("NEW_maximumSum_UVA108.out");

const int minf = -128;

int main()
{
    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0) break;

        vector<vector<int>> a(n + 1, vector<int>(n + 1, minf));
        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= n; ++x)
            {
                fin >> a[y][x];
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                dp[x][y] = dp[x][y - 1] + a[y][x];
            }
        }

        int ans = minf;
        for (int y1 = 1; y1 <= n; ++y1)
        {
            for (int y2 = y1; y2 <= n; ++y2)
            {
                int last = 0;
                for (int x = 1; x <= n; ++x)
                {
                    int now = dp[x][y2] - dp[x][y1 - 1];

                    last = max(now, last + now);
                    ans = max(ans, last);
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
