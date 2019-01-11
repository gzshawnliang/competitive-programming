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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long long length = 1, nowNum = 3;
    vector<long long> prime = {2};
    while (length <= 187)
    {
        bool ok = true;
        for (long long i = 1; i <= length - 1; ++i)
        {
            long long temp = prime[i];
            if (temp > nowNum / 2)
            {
                ok = true;
                break;
            }
            else if (nowNum % temp == 0)
            {
                ok = false;
                break;
            }
        }

        if (ok == true)
        {
            prime.push_back(nowNum);
            ++length;
        }

        nowNum += 2;
    }

    vector<vector<long long>> dp(1121, vector<long long>(15, 0));

    dp[0][0] = 1;
    for (int k = 0; k <= 186; ++k)
    {
        for (int j = 14; j >= 1; --j)
        {
            for (int i = 1120; i >= prime[k]; --i)
            {
                dp[i][j] += dp[i - prime[k]][j - 1];
            }
        }
    }

    while (true)
    {
        int n = 0, k = 0;
        cin >> n >> k;

        if (n + k == 0)
        {
            break;
        }
        else
        {
            cout << dp[n][k] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
