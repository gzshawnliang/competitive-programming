#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct block
{
	long long distance;
	long long point;
};

int main()
{
	ifstream my_cin("jump6.in");
	ofstream my_cout("jump.out");
	
	long long length, jump, point;
	my_cin >> length >> jump >> point;
	
	vector<block> a(length);
	for (int i = 0; i <= length - 1; ++i)
	{
		my_cin >> a[i].distance >> a[i].point;
	}
	
	for (long long money = 0; true; ++money)
	{
		int far = jump + money, near = jump - money;
		
		vector<long long> dp(length);
		dp[0] = a[0].point;
		
		for (int i = 1; i <= length - 1; ++i)
		{
			long long maxPoint = 0;	
			
			for (int j = 0; j <= length - 1; ++j)
			{
				if (a[j].distance <= a[i].distance - near && a[j].distance >= a[i].distance - far)
				{
					maxPoint = max(maxPoint, dp[j]);
				}
			}
			
			
			dp[i] = maxPoint + a[i].point;
			
			if (dp[i] >= point)
			{
				my_cout << money << endl;
				
				
				return 0;
			}
		}
	}
	
	my_cout << -1 << endl;
	
	return 0;
}
