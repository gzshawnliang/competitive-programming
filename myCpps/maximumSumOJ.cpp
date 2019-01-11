#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
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
        int n = - 1;
        cin >> n;

        if (n == -1)
        {
            break;
        }

        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int y = 0; y <= n - 1; ++y)
        {
            int sum = 0;
            dp[y][0] = 0;
            for (int x = 0; x <= n - 1; ++x)
            {
                cin >> a[y][x];
                sum += a[y][x];
                dp[y][x + 1] = sum;
            }
        }
        
        int maxSum = INT_MIN;
        for (int y0 = 0; y0 <= n - 1; ++y0)
        {
            for (int x0 = 0; x0 <= n - 1; ++x0)
            {
                for (int x1 = x0 + 1; x1 <= n; ++x1)
                {
                    int sum = 0;
                    for (int y1 = y0; y1 <= n - 1; ++y1)
                    {
                        sum += dp[y1][x1] - dp[y1][x0];
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }

        cout << maxSum << '\n';
    }

    cout.flush();

    return 0;
}
