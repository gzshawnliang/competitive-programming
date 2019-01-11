#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;


const long long MOD = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    long long n, m, K;
    string a, b;
    
    cin >> n >> m >> K >> a >> b;

    vector<vector<long long>> dp(m + 1, vector<long long>(K + 1, 0)), last(m + 1, vector<long long>(K + 1, 0));

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 1; j--)
        {
            for(int k = K; k >= 1; k--)
            {
                if(a[i - 1] == b[j - 1])
                {
                    last[j][k] = (last[j - 1][k] + dp[j - 1][k - 1]) % MOD;
                    dp[j][k] = (dp[j][k] + last[j][k]) % MOD;

                }
                else
                {
                    last[j][k] = 0;
                }
            }
        }
    }

    cout << dp[m][K] << '\n';

   	cout.flush();
   	return 0;
}
