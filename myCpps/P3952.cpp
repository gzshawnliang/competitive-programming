#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

struct line
{
	char first;
	char value;
	int x;
	int y;
};

int main()
{
	ifstream cin("P3952.in");
	ofstream cout("P3952.out");
	
	int testCase; cin >> testCase;
	for (int t = 1; t <= testCase; ++t)
	{
		int l;
		string s;
		cin >> l >> s;
		
		int givenAns = 0;
		
		if (s[2] == '1')
		{
			givenAns = 1;
		}
		else
		{
			for (int i = 4; '0' <= s[i] && s[i] <= '9'; ++i)
			{
				givenAns = givenAns * 10 + (s[i] - '0');
			}
		}
		
		vector <line> code(l);
		for (int i = 0; i <= l - 1; ++i)
		{
			cin >> code[i].first;
			
			if (code[i].first == 'F')
			{
				cin >> code[i].value >> code[i].x >> code[i].y;
				
				if (code[i].x - 'n' == 0) code[i].x = 666;
				if (code[i].y - 'n' == 0) code[i].y = 666;
			}
			else
			{
				code[i].value = '-';
				code[i].x = -1;
				code[i].y = -1;
			}
		}
		
		cout << "----------0\n";
		
		cout << "l:" << l << '\n';
		cout << "givenAns:" << givenAns << '\n';
		
		for (int i = 0; i <= l - 1; ++i)
		{
			cout << code[i].first << ' ' << code[i].value << ' ' << code[i].x << ' ' << code[i].y << '\n';
		}
		
		cout << "\n------------------------------------------\n";
	}
	
	return 0;
}