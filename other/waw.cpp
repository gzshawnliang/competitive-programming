#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

int STOI(string a)
{
	return atoi(a.c_str());
}

double STOD(string a)
{
	char *p;
	return strtod(a.c_str(), &p);
}

int main()
{
	string a;
	getline (cin, a);
	int len1 = a.length();
	char unknow;
	
	for (int i = 0; i <= len1 - 1; ++i)
	{
		if 	((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			unknow = a[i];
			break;
		}
	}
	
	string temp = "";
	long double now = -1, num = 0.0, valume = 0.0;
	for (int i = 0; i <= len1 - 1; ++i)
	{
		if (a[i] == ' ')
		{
			//nope
		}
		else if (a[i] == '+' || a[i] == '-')
		{
			valume += now * STOD(temp);
			
			temp = a[i];
		}
		else if (a[i] == '=')
		{
			valume += now * STOD(temp);
			
			now = 1;
			temp = "";
		}
		else if (a[i] == unknow)
		{
			if (temp == "")
			{
				num += -1 * now;
			}
			else
			{
				num += -1 * now * STOD(temp);
				
				temp = "";
			}
		}
		else
		{
			temp += a[i];
		}
	}
	
	valume += STOD(temp);
	
	double ans = valume / num;
	
	cout << unknow;
	cout << "=" << setprecision(3) << setiosflags(ios::fixed) << ans << endl;
	
	
	return 0;
}
