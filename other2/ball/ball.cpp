#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream cin("ball9.in");
	ofstream cout("ball.out"); 
	
	int n, m;
	cin >> n >> m;
	
	if (n == 1)
	{
		if (m > n)
		{
			cout << 0 << endl;
			return 0;
		}
		
		cout << 1 << endl;
		return 0;
	}
	
	vector< vector<int> > dp(n + 1, vector<int>(m + 1)); // dp[i][j] Ϊ��j���򵽵�i���˵��������
	
	dp[1][0] = 1;
	
	for (int j = 1; j <= m; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{	
			if (i == 1)
			{
				dp[1][j] = dp[n][j - 1] + dp[2][j - 1];
			}
			else if (i == n)
			{
				dp[n][j] = dp[n - 1][j - 1] + dp[1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];
			}
			
			//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}
	
	cout << dp[1][m] << endl;
	
	
	return 0;
}
