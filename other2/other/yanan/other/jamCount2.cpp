#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream cin("jamCount.in");
	
	int first, last, length;
	string input;
	cin >> first >> last >> length >> input;
	//first = 2; last = 10; length = 5; input = "bdfij";
	
	int size = input.size();
	vector<int> a(size);
	for (int i = 0; i <= size - 1; ++i)
	{
		a[i] = input[i] - 'a';
	}
	
	int count = 0;
	
	while (count < 5)
	{
		bool out = true;
		
		++a[size - 1];
		for (int i = size - 1; i >= 1; --i)
		{
			if (a[i] > last - 1)
			{
				a[i] = first;
				++a[i - 1];
				out = false;
			}
			else
			{
				break;
			}
		}
		
		if (a[0] > last - 1)
		{
			break;
		}
		
		if (out == true)
		{
			vector<bool> dp(last + 1, false);
			for (int i = 0; i <= size - 1; ++i)
			{
				if (dp[a[i]] == false)
				{
					dp[a[i]] = true;
				}
				else
				{
					out = false;
					break;
				}
				
				if (i != 0)
				{
					if (a[i] < a[i - 1])
					{
						out = false;
						break;
					}
				}
			}
			
			if (out == true)
			{
				for (int i = 0; i <= size - 1; ++i)
				{
					char temp = a[i] + 'a';
					cout << temp;
				}
				cout << endl;
				
				++count;
			}
		}
	}
	
	
	return 0;
}
