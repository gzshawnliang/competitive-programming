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
    int W = 15;
    vector<int> v = {4, 2, 1, 10, 2};
    vector<int> w = {12, 2, 1, 4, 1};

    int size = v.size();
    vector<vector<int>> dp(size, vector<int>(W + 1, 0));

    for (int i = 0; i <= size - 1; ++i)
    {
        if (i == 0)
        {
            for (int j = 0; j <= W; ++j)
            {
                if (j < w[0])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = v[0];
                }
            }
        }
        else
        {
            for (int j = 0; j <= W; ++j)
            {
                if (j < w[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }
    }

    cout << dp[size - 1][W] << '\n';

    return 0;
}