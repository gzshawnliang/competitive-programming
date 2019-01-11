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

ifstream fin("troubleOf13-dots.in");
ofstream fout("troubleOf13-dots.out");

int main()
{
    while (true)
    {
        int m = -1, n = -1;
        fin >> m >> n;

        if (m == -1)
        {
            break;
        }
        else if (m > 1800)
        {
            m += 200;
        }

        vector<vector<int>> dp(n, vector<int>(m + 1));
        for (int i = 0; i <= n - 1; ++i)
        {
            int p, f;
            fin >> p >> f;

            if (i == 0)
            {
                for (int j = 0; j <= m; ++j)
                {
                    if (j < p)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = f;
                    }
                }
            }
            else
            {
                for (int j = 0; j <= m; ++j)
                {
                    if (j < p)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p] + f);
                    }
                }
            }
        }

        if (m * n == 0)
        {
            fout << "0\n";
            continue;
        }

        int least = m;
        while (least >= 1 && dp[n - 1][least] == dp[n - 1][least - 1])
        {
            --least;
        }

        if (m > 2000 && least <= 2000)
        {
            fout << dp[n - 1][m - 200] << '\n';
        }
        else
        {
            fout << dp[n - 1][m] << '\n';
        }
        
    }

    return 0;
}