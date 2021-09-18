#include <iostream>
#include <vector>

using namespace std;

vector<int> a(500);

time_a_by_2()
{
	int lastIn = 0, lastlast = 1;
	for (int i = 0; i <= 499; ++i)
	{
		a[i] = a[i] * 2 + lastIn;
		
		if (a[i] > 9)
		{
			lastIn = (a[i] - a[i] % 10) / 10;
		}
		else
		{
			lastIn = 0;
		}
		
		a[i] %= 10;
	}
}

int main()
{
	a[0] = 1;
	long long p;
	
	cin >> p;
	
	for (long long i = 1; i <= p; ++i)
	{
		time_a_by_2();
	}
	
	int count = 499;
	while (a[count] == 0)
	{
		--count;
	}
	
	cout << count + 1 << endl;
	
	count = 1;
	
	for (int i = 499; i >= 0; --i)
	{
		if (i == 0)
		{
			cout << a[i] - 1;
		}
		else
		{
			cout << a[i];
		}
		if (count % 50 == 0)
		{
			cout << endl;
		}
		++count;
	}
	
	
	return 0;
}
