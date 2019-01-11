#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string shawn(string a)
{
	vector<bool> dp (94, true);	// -33
	string ans = "";
	
	int length = a.size();
	for (int i = 0; i <= length - 1; ++i)
	{
		char now = a[i];
		
		if (now == ' ')
		{
			ans += now;
		}
		else if (dp[now - 33] == true)
		{
			ans += now;
			dp[now - 33] = false;
		}
	}
	
	return ans;
}

int main()
{
	string a;
	getline(cin, a);
	
	cout << shawn(a) << endl;

	
	
	return 0;
}
