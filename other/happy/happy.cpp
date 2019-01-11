#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("happy10.in");
	
	long long n, total;
	cin >> total >> n;
	 
	vector< vector<long long> > dp(n + 1, vector<long long>(total + 1, 0));
	
	for (long long i = 1; i <= n; ++i)
	{
	 	long long price, valume;
	 	cin >> price >> valume;
	 	
	 	for (long long j = 0; j <= total; ++j)
		{
		 	if (j < price)
			{
			 	dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + price * valume);
			}
			
			//cout << "d[" << i << "]["  << j << "] = " << dp[i][j] << endl;
		}
	}
	
	cout << dp[n][total] << endl;
	
	
	
	return 0;
}
