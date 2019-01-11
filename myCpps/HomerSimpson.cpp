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

ifstream fin("HomerSimpson.in");
ofstream fout("HomerSimpson.out");

int main()
{
    while (true)
    {
        int m = -1, n = -1, t = -1;
        fin >> m >> n >> t;

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
            fout << '0';

            if (t > 0)
            {
                fout << ' ' << t;
            }

            fout << '\n';
        }
        else
        {
            fout << dp[j];

            if (j != t)
            {
                fout << ' ' << t - j;
            }

            fout << '\n';
        }
    }

    return 0;
}