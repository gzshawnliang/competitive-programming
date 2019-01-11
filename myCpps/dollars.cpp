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

ifstream fin("dollars.in");
ofstream fout("dollars.out");

int main()
{
    vector<long long> dp(6001, 0);
    vector<int> dollars = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};

    dp[0] = 1;
    for (int c = 10; c >= 0; --c)
    {
        for (int i = dollars[c]; i <= 6000; ++i)
        {
            dp[i] += dp[i - dollars[c]];
        }
    }

    while (true)
    {
        double in = 0.00;
        fin >> in;

        if (in == 0.00)
        {
            break;
        }

        double temp0 = in + 0.005;
        temp0 *= 100;
        int temp1 = temp0;

        fout << fixed << setprecision(2) << setw(6) << in << setw(17) << dp[temp1 / 5] << '\n';
    }

    return 0;
}