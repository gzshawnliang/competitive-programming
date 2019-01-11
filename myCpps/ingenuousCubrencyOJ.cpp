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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
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
    while (cin >> in)
    {
        cout << dp[in] << '\n';
    }

   	cout.flush();
   	return 0;
}
