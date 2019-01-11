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

ifstream fin("letMeCountTheWays.in");
ofstream fout("letMeCountTheWays.out");

int main()
{
    vector<int> c = {1, 5, 10, 25, 50};
    vector<long long> dp(30001, 0);

    dp[0] = 1;

    for (int j = 0; j <= 4; ++j)
    {
        for (int i = 1; i <= 30000; ++i)
        {
            if (i >= c[j])
            {
                dp[i] += dp[i - c[j]];
            }
        }
    }

    int in;
    while (fin >> in)
    {
        if (dp[in] == 1)
        {
            fout << "There is only 1 way to produce " << in << " cents change.\n";
        }
        else
        {
            fout << "There are " << dp[in] << " ways to produce " << in << " cents change.\n";
        }
    }

    return 0;
}