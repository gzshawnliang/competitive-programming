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

ifstream fin("ferryLoading.in");
ofstream fout("ferryLoading.out");

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        if (c != 1)
        {
            fout << '\n';
        }

        int l, in = -1;
        fin >> l;
        l *= 100;

        vector<int> a = {0}, sum = {0};
        while (true)
        {
            fin >> in;

            if (in == 0)
            {
                break;
            }

            a.push_back(in);
            sum.push_back(sum.back() + in);
        }

        int size0 = a.size() - 1;
        if (size0 == 0)
        {
            fout << "0\n";
            continue;
        }
        
        int maxCount = 0, maxLength = 0;
        vector<vector<bool>> dp(size0 + 1, vector<bool>(l + 1, false));
        vector<vector<int>> store(size0 + 1, vector<int>(l + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= size0; ++i)
        { 
            for (int j = 0; j <= l; ++j)
            {
                if (j >= a[i] && dp[i - 1][j - a[i]] == 1)
                {
                    maxCount = i;
                    maxLength = j;
                    dp[i][j] = true;
                    store[i][j] = j - a[i];
                }
                else if (sum[i] - j <= l && dp[i - 1][j] == 1)
                {
                    maxCount = i;
                    maxLength = j;
                    dp[i][j] = true;
                    store[i][j] = j;
                }
            }
        }

        vector<bool> out(maxCount + 1);
        int temp;
        for (int i = maxCount; i >= 1; --i)
        {
            temp = store[i][maxLength];
            if (temp == maxLength)
            {
                out[i] = false;
            }
            else
            {
                out[i] = true;
            }
            maxLength = temp;
        }

        fout << maxCount << '\n';
        for (int i = 1; i <= maxCount; ++i)
        {
            if (out[i] == false)
            {
                fout << "port" << '\n';
            }
            else
            {
                fout << "starboard" << '\n';
            }
        }
    }

    return 0;
}