#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<iterator>

using namespace std;

void f()
{
	char c = getchar();
	if (c == '\n') return;
	f();
	cout << c;
}

int main()
{
	f();
	
	return 0;
}
