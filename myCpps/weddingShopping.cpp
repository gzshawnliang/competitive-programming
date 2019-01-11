#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("weddingShopping.in");
ofstream fout("weddingShopping.out");

int main()
{
    int testCase;
    fin >> testCase;
    for (int cc = 0; cc <= testCase - 1; ++cc)
    {
        int m = - 1, c = - 1;
        fin >> m >> c;
        
        if (m == -1)
        {
            break;
        }

        vector<vector<int>> a(c);
        for (int i = 0; i <= c - 1; ++i)
        {
            int k;
            fin >> k;
            vector<int> temp(k);
            for (int j = 0; j <= k - 1; ++j)
            {
                fin >> temp[j];
            }

            a[i] = temp;
        }

        vector<vector<bool>> dp(c, vector<bool>(m + 1, false));

        for (int i = 0; i <= c - 1; ++i)
        {
            if (i == 0)
            {
                int size0 = a[0].size();
                for (int k = 0; k <= size0 - 1; ++k)
                {
                    if (a[0][k] <= m)
                    {
                        dp[0][a[0][k]] = true;
                    }
                }
            }
            else
            {
                for (int j = 0; j <= m; ++j)
                {
                    if (dp[i - 1][j] == true)
                    {
                        int size0 = a[i].size();
                        for (int k = 0; k <= size0 - 1; ++k)
                        {
                            if (j + a[i][k] <= m)
                            {
                                dp[i][j + a[i][k]] = true;
                            }
                        }
                    }
                }
            }
        }

        int ans = m;
        while (ans >= 0)
        {
            if (dp[c - 1][ans] == true)
            {
                break;
            }

            --ans;
        }

        if (ans == -1) 
        {
            fout << "no solution\n";
        }
        else
        {
            fout << ans << '\n';
        }
    }

    return 0;
}