#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct item
{
	int w;
	int v;
};

int main()
{
	int itemTotal, maxWeight;
	cin >> itemTotal >> maxWeight;
	
	vector< vector<int> > dp(itemTotal + 1, vector<int>(maxWeight + 1));

	for (int i = 1; i <= itemTotal; ++i)
	{
		int v, w;
		cin >> v >> w;
		for (int j = 0; j <= maxWeight; ++j)
		{
			if (i == 1)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			
			if (j >= v)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
			}
		}
	}
	
	
	cout << dp[itemTotal][maxWeight] << endl;
}
