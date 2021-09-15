#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std; // save here

vector<int> start;
int left1 = 6;

void solve(vector<int> a, int out, vector<int> ans, int lastPos)
{
	if (out > 0)
	{
		int size = a.size();
		for (int i = lastPos; i <= size - 1; ++i)
		{
			vector<int> temp = a, temp2 = ans;
			temp.erase(temp.begin() + i);
			temp2.push_back(a[i]);
			solve(temp, out - 1, temp2, i);
		}
	}
	else if (left1 > 0 && left1 < 6)
	{
		int size = ans.size();
		for (int i = 0; i <= size - 1; ++i)
		{
			char temp = 'a' + ans[i];
			cout << temp;
		}
		cout << endl;
		
		--left1;
	}
	else if (ans == start)
	{
		left1 = 5;
	}
}

int main()
{
	int s, t, w;
	string in;
	//cin >> s >> t >> w >> in;
	s = 1; t = 10; w = 5; in = "abcde";

	vector<int> a(t - s + 1), useless;
	for (int i = 0; i <= t - s; ++i)
	{
		a[i] = i + s - 1;
	}
	
	for (int i = 0; i <= w - 1; ++i)
	{
		int temp = in[i] - 'a';
		start.push_back(temp);
	}
	
	solve(a, w, useless, 0);
	
	
	return 0;
}
