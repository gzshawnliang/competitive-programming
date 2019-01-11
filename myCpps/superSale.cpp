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

ifstream fin("superSale.in");
ofstream fout("superSale.out");

int main()
{
    int testCases;
    fin >> testCases;

    for (int c = 1; c <= testCases; ++c)
    {
        int n;
        fin >> n;
        vector<int> P(n);
        vector<int> W(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> P[i] >> W[i];
        }

        int g, total = 0;
        fin >> g;
        for (int l = 1; l <= g; ++l)
        {
            int totalW;
            fin >> totalW;
            vector<vector<int>> dp(n, vector<int>(totalW + 1));
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == 0)
                {
                    for (int j = 0; j <= totalW; ++j)
                    {
                        if (j < W[0])
                        {
                            dp[0][j] = 0;
                        }
                        else
                        {
                            dp[0][j] = P[0];
                        }
                    }
                }
                else
                {
                    for (int j = 0; j <= totalW; ++j)
                    {
                        if (j < W[i])
                        {
                            dp[i][j] = dp[i - 1][j];
                        }
                        else
                        {
                            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + P[i]);
                        }
                    }
                }
            }

            total += dp[n - 1][totalW];
        }

        fout << total << '\n';
    } 

    return 0;
}