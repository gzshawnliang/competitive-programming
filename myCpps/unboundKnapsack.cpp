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
    int W = 8;
    vector<int> v = {10, 40, 50, 70};
    vector<int> w = {1, 3, 4, 5};

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
                    dp[i][j] = (j / w[0]) * v[0];
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
                    for (int k = 0; k <= j / w[i]; ++k)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i] * k] + v[i] * k);
                    }
                }
            }
        }
    }

    cout << dp[size - 1][W] << '\n';

    return 0;
}