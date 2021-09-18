#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

//int maxTimeLeft = 0, minDistanceLeft = 100000000;

//bool solve(int magic, int timeLeft, int distance, int nowCos)
//{
//	if (timeLeft < 0)
//	{
//		return false;
//	}
//	
//	if (distance <= 0)
//	{
//		if (timeLeft > maxTimeLeft)
//		{
//			maxTimeLeft = (timeLeft * 17 - distance) / 17;
//		}
//			
//		return true;
//	}
//	
//	if (nowCos == 3)
//	{
//		if (timeLeft * 17 >= distance)
//		{
//			if (timeLeft > maxTimeLeft)
//			{
//				maxTimeLeft = (timeLeft * 17 - distance) / 17;
//			}
//			
//			return true;
//		}
//		else
//		{	
//			minDistanceLeft = min(minDistanceLeft, distance - (timeLeft + 1) * 17);
//			
//			return false;
//		}
//	}
//	else if (nowCos == 2)
//	{
//		if (magic >= 10)
//		{
//			bool ans;	
//			for (int i = 0; i <= timeLeft && magic % 10; ++i)
//			{
//				ans = solve(magic - 10 * i, timeLeft - i, distance - 60 * i, 3);
//			}
//			
//			return ans;
//		}
//		else
//		{
//			return solve(magic, timeLeft, distance, 3);
//		}
//	}
//	else
//	{
//		return solve(magic + 4, timeLeft - 1, distance, 1) || solve(magic + 4, timeLeft - 1, distance, 2);
//	}
//}

int main3()
{
	ifstream cin("escape2.in");
	//ofstream cout("escape.out");
	
	long long magic, distance, timeLeft, maxDistance, step;
	
	cin >> magic >> distance >> timeLeft;
	
	maxDistance = (magic / 10) * 60;
	
	magic %= 10;
	
	step = timeLeft;
	
	long long temp = magic + timeLeft * 4;
	magic = temp;
	
	while (magic % 10 == temp % 10)
	{
		--step;
		magic -= 4;
	}
	
	temp = (magic / 10);
	
	maxDistance += temp * 60;
	
	while (maxDistance >= distance)
	{
		maxDistance -= 60;
		--step;
	}
	
	maxDistance += 60;
	++step;
	
	//cout << maxDistance << endl;
	
	if (maxDistance >= distance)
	{
		cout << "Yes" << endl;
		
		cout << step << endl;
	}
	
	return 0;
}

int main2()
{
	ifstream cin("escape3.in");
//	ofstream cout("escape.out");
	
	long long magic, distance, timeLeft, nowDistance = 0, walkTime = 0;
	
	cin >> magic >> distance >> timeLeft;
	
	long long startedBlink = magic / 10;
	
	nowDistance += startedBlink * 60;
	
	magic %= 10;
	
//	cout << timeLeft << endl;
	
	for (long long time = startedBlink; time <= timeLeft - 1; ++time)
	{
		cout << "magic : " << magic << " nowDistance : " << nowDistance << " walkTime : "  << walkTime << endl;
		
		if (nowDistance >= distance)
		{
			cout << "Yes" << endl;
			cout << time << endl;
			
			return 0;
		}
		
		if (magic < 10 && (magic + walkTime * 4) >= 10)
		{
			magic -= 10 - walkTime * 4;
			nowDistance -= walkTime * 17;
			nowDistance += 60;
			//++time;
			walkTime = 0;
			cout << " <-back blink->" << endl;
		}
		else
		{
			++walkTime;
			nowDistance += 17;
			cout << " <-walk->" << endl;
		}
	}
	
	if (nowDistance >= distance)
	{	
		cout << "Yes" << endl;
		cout << timeLeft << endl;
		
		return 0;
	}
	
	cout << "No" << endl;
	cout << nowDistance << endl;
	
	return 0;
}

int main()
{
	ifstream cin("escape4.in");
//	ofstream cout("escape.out");
	
	long long magic, distance, timeLeft, nowDistance = 0, totalTime, maxBlink;
	
	cin >> magic >> distance >> timeLeft;
	
	long long startedBlink = magic / 10;
	
	totalTime = timeLeft;
	
	timeLeft -= startedBlink;
	nowDistance += startedBlink * 60;
	magic %= 10;
	
	maxBlink = (timeLeft - timeLeft % 7) / 7;
	
	for (int i = 0; i <= maxBlink; ++i)
	{
		timeLeft -= 7;
		nowDistance += 120;
		if (nowDistance >= distance)
		{	
		    timeLeft += 7;
			nowDistance -= 120;
			
			if (distance - nowDistance <= 60)
			{
				if ((10 - magic) / 4 + 1 > (distance - nowDistance) / 17 + 1)
				{
					timeLeft -= (10 - magic) / 4 + 1;
				}
				else
				{
					timeLeft -= (distance - nowDistance) / 17 + 1;
				}
			}
			else
			{
				timeLeft -= (distance - nowDistance) / 17 - 1;
			}
			cout << "Yes" << endl;
			cout << totalTime - timeLeft << endl;
			return 0;
		}
	}
	

	
	long long maxDistance = nowDistance, mintime = timeLeft;
	
	for (int use = 1; use <= timeLeft; ++use)
	{
		for (int rest = 0; rest < use; ++rest)
		{
			int temp = nowDistance;
			if (magic + rest * 4 >= 10)
			{
				temp += 60;
			}
			temp += (timeLeft - rest) * 17;
			
			if (temp >= distance)
			{
				cout << "Yes" << endl;
		
				cout << totalTime - timeLeft - use << endl;
				
				return 0;
			}
			
			if (maxDistance < temp)
			{
				maxDistance = temp;
			}
		}
	}
	
	if (maxDistance < distance)
	{
		cout << "No" << endl;
		
		cout << maxDistance << endl;
	}
	
	return 0;
}
