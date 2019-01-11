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

ifstream fin("P2679.in");
ofstream fout("P2679.out");

const long long MOD = 1000000007;

int main()
{
    long long n, m, K;
    string a, b;
    
    fin >> n >> m >> K >> a >> b;

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

                    //dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j-1][k-1];
                }
                else
                {
                    last[j][k] = 0;
                }
            }
        }
    }

    fout << dp[m][K] << '\n';

    return 0;
}