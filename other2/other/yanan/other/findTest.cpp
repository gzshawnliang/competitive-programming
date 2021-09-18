#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int temp[] = {1,4,3426,3,322,6,3242,243,45,22,453,12,13,2,4234,1,3423,234,53,4};
	int sizeTemp = sizeof(temp) / sizeof(int);
	vector<int> a(temp, temp + sizeTemp);
	
	vector<int>::iterator result = find(a.begin(), a.end(), 953);
	//int *result = find(temp + 0, temp + sizeTemp, 12);
	
	if (result == a.end())
	{
		cout << "Nope" << endl;
	}
	else
	{
		//cout << dsitance() << endl;
		cout << distance(a.begin(), result) << endl;
	}
	
//	if (result == temp + sizeTemp)
//	{
//		cout << "Nope" << endl;
//	}
//	else
//	{
//		//cout << result - temp << endl;
//		cout << distance(temp, result) << endl;
//	}
//	
	
	return 0;
}
