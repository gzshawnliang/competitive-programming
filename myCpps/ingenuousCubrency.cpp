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

ifstream fin("ingenuousCubrency.in");
ofstream fout("ingenuousCubrency.out");

int main()
{
    vector<long long> dp(10000, 0);
    dp[0] = 1;

    for (int j = 1; j <= 21; ++j)
    {
        int cube = j * j * j;

        for (int i = 1; i <= 9999; ++i)
        {
            if (cube <= i)
            {
                dp[i] += dp[i - cube];
            }
        }
    }
    
    int in;
    while (fin >> in)
    {
        fout << dp[in] << '\n';
    }

    return 0;
}