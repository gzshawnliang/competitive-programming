#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("escape10.in");
	
	
	int magic, distance, time;
	//magic = 39; distance = 200; time = 4;
	cin >> magic >> distance >> time;
	
	int nowDistance = 0, walkTime = 0;
	for (int i = 1; i <= time; ++i)
	{
		if (magic >= 10)
		{
			nowDistance += 60;
			magic -= 10;
			//cout << "blink" << endl;
		}
		else if (magic + walkTime * 4 >= 10 && walkTime * 17 < 60 && distance - nowDistance > 17)
		{
			//cout << "back " << walkTime << " step and blink" << endl;
			nowDistance -= walkTime * 17;
			nowDistance += 60;
			magic = magic + walkTime * 4 - 10;
			walkTime = 0;
		}
		else
		{
			++walkTime;
			nowDistance += 17;
			//cout << "walk" << endl;
		}
		
		if (nowDistance >= distance)
		{
			cout << "Yes" << endl;
			cout << i << endl;
			
			return 0;
		}
	}
	
	cout << "No" << endl;
	cout << nowDistance << endl;
	
	
	return 0;
}
