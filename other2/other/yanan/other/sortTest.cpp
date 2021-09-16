#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

struct student
{
	string name;
	int Math;
	int English;
};

bool compareStudent(student a, student b)
{
	return a.Math * 70 + a.English * 30 > b.Math * 70 + b.English * 30;
}

bool campare(int a, int b)
{
	return a % 10 > b % 10;
}

int main()
{
	int temp[] = {1,5,22,3,34,89,345,6,785,22,1,67,9,4,6,243,76,34,4};
	int tempLength = sizeof(temp) / sizeof(int);
	vector<int> a (temp, temp + tempLength);
	vector<student> students;
	
	student no1, no2, no3;
	
	no1.name = "Shawn";
	no1.Math = 150;
	no1.English = 135;
	
	no2.name = "Thomas";
	no2.Math = 40;
	no2.English = 50;
	
	no3.name = "God";
	no3.Math = 10000;
	no3.English = 10000;
	
	students.push_back(no1);
	students.push_back(no2);
	students.push_back(no3);

	sort(students.begin(), students.end(), compareStudent);
	//sort(a.begin(), a.end(), campare);
	//sort(temp, temp + tempLength, campare);
	
//	int length = a.size();
//	for (int i = 0; i <= length - 1; ++i)
//	{
//		cout << a[i] << " ";
//	}

//	for (int i = 0; i <= tempLength - 1; ++i)
//	{
//		cout << temp[i] << " ";
//	}

	int length = students.size();
	for (int i = 0; i <= length - 1; ++i)
	{
		cout << "NO."  << i + 1  << " : " << students[i].name << " Total : " << students[i].Math * 70 + students[i].English * 30 << endl;
	}
	
	
	return 0;
}
