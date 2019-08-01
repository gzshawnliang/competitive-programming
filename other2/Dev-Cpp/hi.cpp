#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

string to_string0 (int a)
{
	string ans = "";
	while (a > 0)
	{
		string temp = "";
		temp.push_back(a % 10 + '0');
		
		ans = temp + ans;
		
		a /= 10;
	}
	
	return ans;
}

string to_string1 (int a)
{
	ostringstream ans;
	
	ans << a;
	
	return ans.str();
}

int _rand(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

int main()
{
	srand(time(0));
	
	int a;
	cin >> a;
	
	for (int c = 1; c <= a; ++c)
	{
		if (c > 1) cout << ' ';
		cout << _rand(0, 100);
	}
		
	return 0;
}

