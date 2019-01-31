#include <bits/stdc++.h>

using namespace std;


void skip()
{
    string s; getline(cin, s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    skip();
    
    for (int t = 1; t <= testCase; ++t)
    {
        if (t > 1) cout << '\n';

        skip();

        string in; getline(cin, in);

        int n = in.size();
        vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0)), dp(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n - 1; ++i)
        {
            a[1][i + 1] = in[i] - '0';
            if (a[1][i + 1] == 0) a[1][i + 1] = INT_MIN;

            dp[1][i + 1] = dp[1][i] + a[1][i + 1];
        }

        for (int y = 2; y <= n; ++y)
        {
            getline(cin, in);
            for (int i = 0; i <= n - 1; ++i)
            {
                a[y][i + 1] = in[i] - '0';;
                if (a[y][i + 1] == 0) a[y][i + 1] = INT_MIN;

                dp[y][i + 1] = dp[y][i] + a[y][i + 1];
            }
        }

        long long ans = 0;
        for (int x1 = 1; x1 <= n; ++x1)
        {
            for (int x2 = x1; x2 <= n; ++x2)
            {
                for (int y1 = 1; y1 <= n; ++y1)
                {
                    long long sum = 0;
                    for (int y2 = y1; y2 <= n; ++y2)
                    {
                        sum += dp[y2][x2] - dp[y2][x1 - 1];
                        ans = max(ans, sum);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

