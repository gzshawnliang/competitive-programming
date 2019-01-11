/*
===========================================================
 * @名称:	算法导论——切割钢条	
 * @作者:		Shawn 
 * @创建时间: 2018-04-23 20:32:08 
 * @修改人:   Shawn 
 * @修改时间: 2018-04-23 20:32:08 
 * @备注:		
 * @题目来源： 《算法导论》第15章
===========================================================
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solve1()
{
    while (true)
    {
        int n;
        cin >> n;

        vector<int> dp(n + 1);
        vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
        int sizeP = p.size() - 1;
        dp[0] = 0; dp[1] = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (i <= sizeP)
            {
                dp[i] = p[i];
            }
            else
            {
                dp[i] = 0;
            }

            int j = 0, k = i;
            while (j <= k)
            {
                dp[i] = max(dp[i], dp[i - j] + dp[j]);
                ++j; --k;
            }
        }

        cout << dp[n] << '\n';
    }
}

vector<int> dp2(10000, -1);
vector<int> p2 = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int sizeP2 = p2.size() - 1;
int solve2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (dp2[n] != -1)
    {
        return dp2[n];
    }
    else
    {
        int j = 1, k = n - 1;

        int ans;
        if (n <= sizeP2)
        {
            ans = p2[n];
        }
        else
        {
            ans = 0;
        }

        while (j <= k)
        {
            ans = max(ans, solve2(n - j) + solve2(j));
            ++j; --k;
        }

        dp2[n] = ans;
        return ans;
    }
}

int main()
{
    // while (true)
    // {
    //     int n;
    //     cin >> n;
    //     cout << solve2(n) << '\n';
    // }

    solve1();

    return 0;
}