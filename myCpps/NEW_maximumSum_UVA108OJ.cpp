#include <bits/stdc++.h>

using namespace std;


const int minf = -128;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        vector<vector<int>> a(n + 1, vector<int>(n + 1, minf));
        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= n; ++x)
            {
                cin >> a[y][x];
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

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

