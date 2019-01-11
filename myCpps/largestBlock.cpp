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

ifstream fin("largestBlock.in");
ofstream fout("largestBlock.out");

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int s, n;
        fin >> s >> n;
        vector<vector<int>> a(s + 2, vector<int>(s + 2, 1));
        vector<vector<int>> dp(s + 2, vector<int>(s + 2));

        for (int i = 1; i <= n; ++i)
        {
            int y1, x1, y2, x2;
            fin >> y1 >> x1 >> y2 >> x2;
            for (int y = y1; y <= y2; ++y)
            {
                for (int x = x1; x <= x2; ++x)
                {
                    a[y][x] = -10001;
                }
            }
        }

        for (int y = 1; y <= s; ++y)
        {
            int sum = 0;
            dp[y][0] = 0;
            for (int x = 1; x <= s + 1; ++x)
            {
                sum += a[y][x];
                dp[y][x] = sum;
            }
        }

        int maxSum = -2147483646;
        for (int y0 = 1; y0 <= s; ++y0)
        {
            for (int x0 = 1; x0 <= s; ++x0)
            {
                for (int x1 = x0; x1 <= s; ++x1)
                {
                    int sum = 0;
                    for (int y1 = y0; y1 <= s; ++y1)
                    {
                        sum += dp[y1][x1] - dp[y1][x0 - 1]; 
                        maxSum = max(maxSum , sum);
                    }
                }
            }
        }

        if (maxSum < 0)
        {
            fout << "0\n";
        }
        else
        {
            fout << maxSum << '\n';
        }     
    }

    return 0;
}