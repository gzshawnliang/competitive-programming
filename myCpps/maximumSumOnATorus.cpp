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

ifstream fin("maximumSumOnATorus.in");
ofstream fout("maximumSumOnATorus.out");

int get(int y0, int x0, int y1, int x1, vector<vector<int>> & dp)
{
    int ans = dp[y1][x1] - dp[y1][x0 - 1] - dp[y0 - 1][x1] + dp[y0 - 1][x0 - 1];
    return ans;
}

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n;
        fin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> HCount(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int y = 1; y <= n; ++y)
        {
            int count = 0;
            for (int x = 1; x <= n; ++x)
            {
                fin >> a[y][x];
                count += a[y][x];
                HCount[y][x] = count;
            }
        }

        if (n == 1)
        {
            fout << a[1][1] << '\n';
            continue;
        }

        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= n; ++x)
            {
                dp[y][x] = dp[y - 1][x] + HCount[y][x];
            }
        }

        int ans = -562501;
        for (int y0 = 1; y0 <= n; ++y0)
        {
            for (int x0 = 1; x0 <= n; ++x0)
            {
                for (int y1 = y0; y1 <= n; ++y1)
                {
                    for (int x1 = x0; x1 <= n; ++x1)
                    {
                        ans = max(ans, get(y0, x0, y1, x1, dp));
                        
                        if (!(x0 == 1 && x1 == n))
                        {
                            ans = max(ans, get(y0, 1, y1, n, dp) - get(y0, x0, y1, x1, dp));
                        }

                        if (!(y0 == 1 && y1 == n))
                        {
                            ans = max(ans, get(1, x0, n, x1, dp) - get(y0, x0, y1, x1, dp));
                        }

                        if (y0 == 2 && y1 == n - 1 && x0 == 2 && x1 == n - 1)
                        {
                            ans = max(ans, get(1, 1, n, n, dp) - get(y0, 1, y1, n, dp) - get(1, x0, n, x1, dp) + get(y0, x0, y1, x1, dp));
                        }
                        else if (!(y0 <= 2 && y1 >= n - 1 && x0 <= 2 && x1 >= n - 1))
                        {
                            ans = max(ans, get(1, 1, n, n, dp) - get(y0, 1, y1, n, dp) - get(1, x0, n, x1, dp) + get(y0, x0, y1, x1, dp));
                        }
                    }
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}