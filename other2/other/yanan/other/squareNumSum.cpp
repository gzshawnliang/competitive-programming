#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long> dp(n + 1);
	dp[1] = 1;
	
	for (long long i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		for (long long j = 1; j * j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		//cout << "Min square numbers to make " << i << " : " << dp[i] << endl;
	}
	
	cout << dp[n] << endl;
	
	
	
	return 0;
}
