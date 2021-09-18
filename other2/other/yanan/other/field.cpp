#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void dfs(int y, int x, vector< vector<char> > & a)
{
	if (y >= a.size() || x >= a[0].size() || y < 0 || x < 0) 
	{
		//derp;
		//cout << y << " " << x << "--- out of range" << endl;
	}
	
	else if (a[y][x] == '.')
	{
		//derp;
		//cout << y << " " << x << "--- meet *" << endl;
	}
	
	else 
	{
		//cout << y << " " << x << "--- all good" << endl;
		
		a[y][x] = '.';
		dfs(y + 1, x, a);
		dfs(y - 1, x, a);
		dfs(y, x + 1, a);
		dfs(y, x - 1, a);
	}
}

int main()
{
	ifstream cin("field.in");
	
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
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i <= y - 1; ++i)
	{
		for (int j = 0; j <= x - 1; ++j)
		{
			if (a[i][j] == '*')
			{
				dfs(i, j, a);
				++ans;
				
				for (int i = 0; i <= y - 1; ++i)
				{
					for (int j = 0; j <= x - 1; ++j)
					{
						cout << a[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
