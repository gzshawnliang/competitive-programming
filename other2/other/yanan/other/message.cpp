#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool dfs(int y, int x, vector< vector<char> > & a)
{
	if (y >= a.size() || x >= a[0].size() || y < 0 || x < 0) 
	{
		return false;
	}
	
	else if (a[y][x] == '*')
	{
		return true;
	}
	
	else 
	{
		a[y][x] = '*';
		//cout << y << " " << x << "--- all good" << endl;
		
		return
		dfs(y + 1, x, a) &&
		dfs(y - 1, x, a) &&
		dfs(y, x + 1, a) &&
		dfs(y, x - 1, a);
	}
}

int main()
{
	ifstream cin("message3.in");
	
	int x, y;
	cin >> x >> y;
	vector< vector<char> > a(y, vector<char>(x));
	
	for (int i = 0; i <= y - 1; ++i)
	{
		for (int j = 0; j <= x - 1; ++j)
		{
			cin >> a[i][j];
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i <= y - 1; ++i)
	{
		for (int j = 0; j <= x - 1; ++j)
		{
			if (a[i][j] == '.')
			{
				if (dfs(i, j, a) == true)
				{
					++ans;
				}
			}
		}
	}
	
	if (ans == 1)
	{
		cout << "Ankh" << endl;
	}
	else if (ans == 3)
	{
		cout << "Wedjat" << endl;
	}
	else if (ans == 5)
	{
		cout << "Djed" << endl;
	}
	else if (ans == 4)
	{
		cout << "Scarab" << endl;
	}
	else if (ans == 0)
	{
		cout << "Was" << endl;
	}
	else
	{
		cout << "Akeht" << endl;
	}
	
	return 0;
}
