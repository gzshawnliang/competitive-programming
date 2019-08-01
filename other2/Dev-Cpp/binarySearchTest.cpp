#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<iterator>

using namespace std;

void out(vector<int> & a)
{
	int size = a.size();
	for (int i = 0; i <= size - 1; ++i)
	{
		if (i > 0) cout << ' ';
		cout << i;
	}
	cout << '\n';
	for (int i = 0; i <= size - 1; ++i)
	{
		if (i > 0) cout << ' ';
		cout << '|';
	}
	cout << '\n';
	for (int i = 0; i <= size - 1; ++i)
	{
		if (i > 0) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
}

int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(9);
	a.push_back(7);
	a.push_back(5);
	a.push_back(3);
	a.push_back(4);
	a.push_back(8);
	a.push_back(1);
	a.push_back(5);
	
	sort(a.begin(), a.end());
	
	out(a);
	
	int n; cin >> n;
	
	//vector<int>::iterator it = lower_bound(a.begin(), a.end(), n);
	//vector<int>::iterator it = upper_bound(a.begin(), a.end(), n);
	
	if (binary_search(a.begin(), a.end(), n) == true)
	{
		cout << "Found!\n";
	}
	else
	{
		cout << "Not found.\n";
	}
	
//	if (it == a.end())
//	{
//		cout << "Not found.\n";
//	}
//	else
//	{
//		cout << n << " is at " << it - a.begin() << ".\n";
//	}
	
	return 0;
}
