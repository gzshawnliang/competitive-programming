#include <iostream>
#include <vector>
#include <fstream>
// ‡Ö 
using namespace std;

int main()
{
	ifstream cin("largest_square.in");
	
	int h, w;
	cin >> h >> w;
	
	vector< vector<int> > dp(h , vector<int>(w));
	
	for (int y = 0; y <= h - 1; ++y)
	{
		for (int x = 0; x <= w - 1; ++x)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				dp[y][x] = 0;
			}
			else
			{
				dp[y][x] = 1;
			}
		}
	}
	
	int maxLenth = 0;
	int theX, theY;
	for (int y = 1; y <= h - 1; ++y)
	{
		for (int x = 1; x <= w - 1; ++x)
		{
			int valume = 0;
			if (dp[y][x] != 0)
			{
				valume = min(dp[y][x - 1], min(dp[y - 1][x - 1], dp[y - 1][x])) + 1;
				dp[y][x] = valume;
				if (valume > maxLenth)
				{
					maxLenth = valume;
					theY = y;
					theX = x;
				} 
			}
 		}
	}
	
	cout << maxLenth * maxLenth << endl;
	cout << theY << ", " << theX << endl;
	
	return 0;
}
