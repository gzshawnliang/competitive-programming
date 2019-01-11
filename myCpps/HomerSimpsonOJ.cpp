#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int m = -1, n = -1, t = -1;
        cin >> m >> n >> t;

        if (m == -1)
        {
            break;
        }

        vector<int> dp(t + 1, 0);
        for (int i = 0; i <= t; ++i)
        {
            if (i < m && i < n)
            {
                dp[i] = 0;
            }
            else
            {
                if (i >= m && i >= n)
                {
                    dp[i] = max(dp[i - m], dp[i - n]);
                }
                else if (i >= m)
                {
                    dp[i] = dp[i - m];
                }
                else
                {
                    dp[i] = dp[i - n];
                }

                if (dp[i] != 0)
                {
                    ++dp[i];
                }
                else if (i == m || i == n)
                {
                    dp[i] = 1;
                }
            }
        }

        int j = t;
        while (dp[j] == 0 && j >= 0)
        {
            --j;
        }

        if (j == -1)
        {
            cout << '0';

            if (t > 0)
            {
                cout << ' ' << t;
            }

            cout << '\n';
        }
        else
        {
            cout << dp[j];

            if (j != t)
            {
                cout << ' ' << t - j;
            }

            cout << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
