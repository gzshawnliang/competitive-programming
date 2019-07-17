#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;
const int N = 6005;

struct box
{
    int m;
    int l;
};
box _box(int m, int l)
{
    box temp{m, l}; return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        vector<box> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].m >> a[i].l;
        }
        
        int ans = 1;
        vector<vector<int>> dp(n, vector<int>(N + 1, -1 * inf)); dp[n - 1][a[n - 1].m] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= N; ++j)
            {
                dp[i][a[i].m] = 1;
                if (a[i].l >= j - a[i].m && j >= a[i].m)
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - a[i].m] + 1);
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }

                ans = max(ans, dp[i][j]);
            }
        }


        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

