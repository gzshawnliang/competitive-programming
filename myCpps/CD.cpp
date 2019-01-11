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

ifstream fin("CD.in");
ofstream fout("CD.out");

int main()
{
    while (true)
    {
        int total = - 1, size0;
        fin >> total >> size0;

        if (total == -1)
        {
            break;
        }

        vector<int> a(size0);
        for (int i = 0; i <= size0 - 1; ++i)
        {
            fin >> a[i];
        }
        
        vector<vector<int>> dp(size0, vector<int>(total + 1, 0));
        vector<vector<vector<int>>> s(size0, vector<vector<int>>(total + 1));
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (i == 0)
            {
                for (int j = 0; j <= total; ++j)
                {
                    if (j < a[0])
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = a[0];
                        s[i][j].push_back(a[0]);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= total; ++j)
                {
                    if (j < a[i])
                    {
                        dp[i][j] = dp[i - 1][j];
                        s[i][j] = s[i - 1][j];
                    }
                    else
                    {
                        if (dp[i - 1][j] > dp[i - 1][j - a[i]] + a[i])
                        {
                            dp[i][j] = dp[i - 1][j];
                            s[i][j] = s[i - 1][j];
                        }
                        else
                        {
                            dp[i][j] = dp[i - 1][j - a[i]] + a[i];
                            s[i][j] = s[i - 1][j - a[i]];
                            s[i][j].push_back(a[i]);
                        }
                    }
                }
            }
        }

        int size1 = s[size0 - 1][total].size();
        for (int i = 0; i <= size1 - 1; ++i)
        {
            fout << s[size0 - 1][total][i] << " ";
        }
        fout << "sum:" << dp[size0 - 1][total] << '\n';
    }

    return 0;
}