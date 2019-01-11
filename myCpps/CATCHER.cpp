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

ifstream fin("CATCHER.in");
ofstream fout("CATCHER.out");

int main()
{
    int testCase = 0;
    while (true)
    {
        ++testCase;

        vector<int> missile;
        int in;
        while (true)
        {
            fin >> in;

            if (in == -1)
            {
                break;
            }

            missile.push_back(in);
        }

        int size = missile.size();
        
        if (size == 0)
        {
            break;
        }

        vector<int> dp(size);
        for (int i = 0; i <= size - 1; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j <= i - 1; ++j)
            {
                if (missile[j] >= missile[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        auto it = max_element(dp.begin(), dp.end());

        if (testCase > 1)
        {
            fout << '\n';
        }
        fout << "Test #" << testCase << ":\n  maximum possible interceptions: " << *it << '\n';
    }

    return 0;
}