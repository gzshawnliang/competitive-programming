#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n; cin >> n; if (n == 0) break;

        vector<int> a(n), dp(n, INT_MIN);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
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
            cout << "The maximum winning streak is " << ans << ".\n";
        }
        else
        {
            cout << "Losing streak.\n";
        }
    }

   	cout.flush();
   	return 0;
}

