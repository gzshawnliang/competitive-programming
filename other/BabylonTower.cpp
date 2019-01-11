#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct cube
{
	int a_;
	int b_;
	int c_;
};

int solve(vector<cube> input, int size)
{
	int Isize = input.size(), ans = 0;
	for (int i = 0; i <= Isize - 1; ++i)
	{
		int a = input[i].a_, b = input[i].b_, c = input[i].c_;
		
		if (a * b < size)
		{
			ans = max(ans, solve(input, a * b) + c);
		}
		
		if (a * c < size)
		{
			ans = max(ans, solve(input, a * c) + b);
		}
		
		if (c * b < size)
		{
			ans = max(ans, solve(input, c * b) + a);
		}
	}
	
	return ans;
}

int main()
{
	ifstream cin("BabylonTower.in");
	
	int n, maxSize = 0;
	cin >> n;
	vector<cube> input(n);
	
	for (int i = 0; i <= n - 1; ++i)
	{
		cin >> input[i].a_ >> input[i].b_ >> input[i].c_;
	}
	
	cout << solve(input, 10000) << endl;
	
	
	
	return 0;
}
