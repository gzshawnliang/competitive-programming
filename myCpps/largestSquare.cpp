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

ifstream fin("largestSquare.in");
ofstream fout("largestSquare.out");

int main()
{
    int n, m;
    fin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 10000));
    for (int y = 0; y <= n - 1; ++y)
    {
        for (int x = 0; x <= m - 1; ++x)
        {
            fin >> a[y][x];
        }
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        dp[1][0] = 1;
    }

    for (int i = 0; i <= m - 1; ++i)
    {
        dp[0][1] = 1;
    }

    int largestSide = 1;
    for (int y = 1; y <= n - 1; ++y)
    {
        for (int x = 1; x <= m - 1; ++x)
        {
            if (a[y][x] == 0)
            {
                dp[y][x] = 0;
            }
            else
            {
                if (a[y - 1][x] == 1)
                {
                    dp[y][x] = min(dp[y][x], dp[y - 1][x] + 1);
                }
                if (dp[y][x - 1] == 1)
                {
                    dp[y][x] = min(dp[y][x], dp[y][x - 1] + 1);
                }
                if (dp[y - 1][x - 1] == 1)
                {
                    dp[y][x] = min(dp[y][x], dp[y - 1][x - 1] + 1);
                }

                if (dp[y][x] == 10000)
                {
                    dp[y][x] = 1;
                }

                largestSide = max(largestSide, dp[y][x]);
            }
        }
    }

    fout << largestSide << '\n';

    return 0;
}
