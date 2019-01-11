#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream my_cin("score.in");
	ofstream my_cout("score.out");
	
	double a, b, c;
	
	my_cin >> a >> b >> c;
	
	my_cout << a * 0.2 + b * 0.3 + c * 0.5 << endl;
	
	
	return 0;
}
