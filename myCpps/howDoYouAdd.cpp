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

ifstream fin("howDoYouAdd.in");
ofstream fout("howDoYouAdd.out");

int main()
{
    vector<vector<int>> dp(101, vector<int>(101, 0));
    for (int i = 0; i <= 100; ++i)
    {
        dp[0][i] = 1;
        dp[i][1] = 1;
    }
    for (int j = 2; j <= 100; ++j)
    {
        for (int i = 1; i <= 100; ++i)
        {
            for (int k = 0; k <= i; ++k)
            {
                dp[i][j] += dp[k][j - 1] % 1000000;
                dp[i][j] %= 1000000;
            }
        }
    }

    while (true)
    {
        int n = 0, k = 0;
        fin >> n >> k;

        if (n + k == 0)
        {
            break;
        }
        else
        {
            fout << dp[n][k] << '\n';
        }
    }

    return 0;
}