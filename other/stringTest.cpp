#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

//#include <cstdio>

using namespace std;

//£Ñ
//	vector<int> a;
//	int length;
//	
//	cin >> length;
//	for (int i = 1; i <= length; ++i)
//	{
//		int temp;
//		cin >> temp;
//		a.push_back(temp);
//	}
//	
//	sort(a.begin(), a.end());
//	
//	int last = 0;
//	for (int i = 0; i <= length - 1; ++i)
//	{
//		if (a[i] != last)
//		{
//			last = a[i];
//			cout << last << " ";
//		}
//	}

int STOI(string str)
{
	return atoi(str.c_str());
}

long STOL(string str)
{
	return atol(str.c_str());
}

long long STOLL(string str)
{
	return atoll(str.c_str());
}

string ITOS(int i)
{
	stringstream out;
	out << i;
	return out.str();
}

int main()
{
	string a = "<><><><><><><><><><><><><><><><><><>";
	string in, out;
	cin >> in >> out;
	
	string::size_type pos = a.find(in);
	
	if (pos != string::npos)
	{
		a.replace(a.begin() + pos, a.begin() + pos + in.size(), out);
	}
	
	cout << a << endl;
	
//	cout << STOI(a) << endl;
//	cout << STOL(a) << endl;
//	cout << STOLL(a) << endl;
//	cout << a.append(ITOS(i)) << endl;
	
	
	return 0;
}
