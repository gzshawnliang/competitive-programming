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
#include <climits>

using namespace std;

ifstream fin("cuttingSticks.in");
ofstream fout("cuttingSticks.out");

int main()
{
    while (true)
    {
        int l = 0, n = 0;
        fin >> l;

        if (l == 0)
        {
            break;
        }

        fin >> n;

        if (n == 0)
        {
            fout << "The minimum cutting is 0.\n";
            continue;
        }

        vector<int> a(n + 2);
        for (int i = 1; i <= n; ++i)
        {
            fin >> a[i];
        }

        a[0] = 0; a[n + 1] = l;
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX));

        for (int i = 0; i <= n; ++i)
        {
            dp[i][i + 1] = 0;
        }

        for (int d = 0; d <= n + 1; ++d)
        {
            for (int i = 0; i <= n + 1 - d; ++i)
            {
                for (int k = i + 1; k < d + i; ++k)
                {
                    dp[i][d + i] = min(dp[i][d + i], dp[i][k] + dp[k][d + i] + a[d + i] - a[i]);
                }
            }
        }

        fout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }

    return 0;
}