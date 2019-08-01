#include <bits/stdc++.h>

using namespace std;


const int N = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(2);
    while (true)
    {
        int n = 0, x = 0; cin >> n >> x;
        if (n + x == 0) break;

        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            double temp; cin >> temp;
            a[i] = (int)(temp * 100 + 0.5);
        }

        if (a[x] > 5000)
        {
            cout << "100.00\n";
            continue;
        }

        int _max = N - a[x];

        vector<int> dp(N + 1, 0); dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i == x) continue;
            for (int j = _max - a[i]; j >= 0; --j)
            {
                if (dp[j] == 1)
                {
                    dp[j + a[i]] = 1;
                }
            }
        }


        int other = 5001 - a[x];
        while (dp[other] == 0)
        {
            ++other;
        }

        double now_d = a[x], other_d = other;
        double ans = 100.0 * now_d / (now_d + other_d);

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

