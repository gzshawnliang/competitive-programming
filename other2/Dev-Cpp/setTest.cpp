#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	int n; cin >> n;
	
	set<int> s;
	
	for (int i = 0; i <= n - 1; ++i)
	{
		int temp; cin >> temp;
		s.insert(temp);
	}
	
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		if (it != s.begin()) cout << ' ';
		cout << *it;
	}
	cout << '\n';
	
	set<int>::iterator temp = s.begin();
	advance(temp, 3);
	
	cout << *temp << '\n';
	
	return 0;
}
