#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> a(1);

void selfTime(int n)
{
	int length = a.size();
	
	int lastIn = 0;
	for (int i = 0; i <= length - 1 && i <= 498; ++i)
	{
		int ans = a[i] * n + lastIn;
		a[i] = ans % 10;
		lastIn = (ans - a[i]) / 10;
	}
	if (lastIn != 0 && a.size() <= 499)
	{
		a.push_back(lastIn);
	}
}

void selfTime64()
{
	vector<int> temp = a;

	int length = temp.size();
	int lastIn = 0;
	for (int i = 0; i <= length - 1 && i <= 498; ++i)
	{
		int ans = temp[i] * 6 + lastIn;
		temp[i] = ans % 10;
		lastIn = (ans - temp[i]) / 10;
	}
	if (lastIn != 0 && temp.size() <= 499)
	{
		temp.push_back(lastIn);
	}
	
	temp.insert(temp.begin(), 0);
	
	lastIn = 0;
	int length2 = a.size();
	for (int i = 0; i <= length2 - 1 && i <= 498; ++i)
	{
		int ans = a[i] * 4 + lastIn;
		a[i] = ans % 10;
		lastIn = (ans - a[i]) / 10;
	}
	if (lastIn != 0 && a.size() <= 499)
	{
		a.push_back(lastIn);
	}
	
	lastIn = 0;
	for (int i = 0; i <= length - 1; ++i)
	{
		if (i <= length2 - 1)
		{
			int ans = a[i] + temp[i] + lastIn;
			a[i] = ans % 10;
			lastIn = (ans - a[i]) / 10;
		}
		else if (i == length2)
		{
			a.push_back(temp[i] + lastIn);
		}
		else
		{
			a.push_back(temp[i]);
		}
	}
}

int main()
{
	long long n;
	cin >> n;
	
	a[0] = 1;
	
	while (n >= 3)
	{
		selfTime(8);
		n -= 3;
	}
	while (n >= 2)
	{
		selfTime(4);
		n -= 2;
	}
	while (n >= 1)
	{
		selfTime(2);
		n -= 1;
	}
	
	int o = 1, length = a.size();
	for (int i = length; i <= 499; ++i)
	{
		cout << 0;
		if (o % 50 == 0)
		{
			cout << endl;
		}
		++o;
	}
	for (int i = length - 1; i >= 1; --i)
	{
		cout << a[i];
		if (o % 50 == 0)
		{
			cout << endl;
		}
		++o;
	}
	cout << a[0] - 1 << endl;

	
	
	return 0;
}
