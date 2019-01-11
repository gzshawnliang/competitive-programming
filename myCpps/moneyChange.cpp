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
    while (true)
    {
        int n;
        vector<int> m = {1, 5, 10, 20, 50, 100};

        cin >> n;

        if (n == -1)
        {
            break;
        }

        int size0 = m.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = INT_MAX;
            for (int j = 0; j <= size0 - 1; ++j)
            {
                if (i >= m[j])
                {
                    dp[i] = min(dp[i], dp[i - m[j]] + 1);
                }
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}