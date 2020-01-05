#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

string toStr(long long i)
{
	string ans = "";
	
	while (i > 0)
	{
		ans += i % 10 + '0';
		i /= 10;
	}
	
	int size = ans.size();
	for (int i = 0; i <= size / 2 - 1; ++i)
	{
		char temp = ans[i];
		ans[i] = ans[size - 1 - i];
		ans[size - 1 - i] = temp;
	}
	
	return ans;
}

int main()
{
	ifstream my_cin("librarian10.in");
	ofstream my_cout("librarian.out");
	
	int n, q;
	my_cin >> n >> q;
	
	vector<long long> nums(n);
	vector<string> realNums(n);
	
	for (int i = 0; i <= n - 1; ++i)
	{
		string temp;
		my_cin >> temp;
		
		nums[i] = atol(temp.c_str());
	}
	
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i <= n - 1; ++i)
	{
		realNums[i] = toStr(nums[i]);
	}
	
	for (int i = 0; i <= q - 1; ++i)
	{
		int useless;
		string in;
		my_cin >> useless >> in;
		bool find = false;
		
		for (int j = 0; j <= n - 1; ++j)
		{
			int size = realNums[j].size();
			for (int k = 0; k <= size - 1; ++k)
			{
				string now = "";
				for (int pos = k; pos <= size - 1; ++pos)
				{
					now	+= realNums[j][pos];
				}
				
				if (now == in)
				{
					my_cout << realNums[j] << '\n';
					find = true;
					break;
				}
			}
			
			if (find == true)
			{
				break;
			}
		}
		if (find == false)
		{
			my_cout << -1 << '\n';
		}
	}


	
	return 0;
}
