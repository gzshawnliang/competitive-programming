#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int total;

string join(string a, string b)
{
	int sizeA = a.size() - 1;
	int sizeB = b.size() - 1;
	
	string temp;
	
	if (sizeA == -1)
	{
		return b;
	} 
	else if (sizeB == -1)
	{
		return a;
	}
	
	for (int i = sizeA; i >= 0; --i)
	{
		bool ok = true;
		int j = i;
		string temp = b;
		
		while (j <= sizeA && temp.size() > 0)
		{
			if (a[j] == temp[0])
			{
				temp.erase(temp.begin());
			}
			else
			{
				ok = false;
				break;
			}
			++j;
		} 
		
		if (ok == true)
		{
			return a + temp;
		}
	}
	
	return a + b;
}

string maxString = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";

void solve(vector<string> a, string now)
{
	if (a.size() == 0)
	{
		if (now.size() < maxString.size())
		{
			maxString = now;
			return;
		}
	}
	
	int length = a.size() - 1, MIN = 1000;
	for (int i = 0; i <= length; ++i)
	{
		vector<string> temp = a;
		
		temp.erase(temp.begin() + i);
		
		/* for (int i = total - a.size() + 1; i >= 0; --i)
		{
			cout << "    ";
		}
		cout << now << " + " << a[i] << " = " << join(now, a[i]) << endl; */
		
		solve(temp, join(now, a[i]));
	}
}

int main()
{	
	ifstream cin("data.in");

	vector<string> a;
	string head;

	cin >> total;
	for (int i = 1; i <= total; ++i)
	{
		string temp;

		cin >> temp;
		
		a.push_back(temp);
	}
	cin >> head;
	
	solve(a, head);
	
	cout << maxString << endl;
	cout << maxString.size() << endl; 
	
	//cout << join ("atouch", "cheat") << endl;
}
