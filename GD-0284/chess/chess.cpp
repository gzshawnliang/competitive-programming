#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

int m, minGold = 100000;

int YPlus[8] = {0 , 1, 0,-1, 1, 1,-1,-1};
int XPlus[8] = {1 , 0,-1, 0, 1,-1,-1, 1};

using namespace std;

void fbs(int y, int x, vector< vector<int> > a, int gold)
{
	vector< vector<int> > temp = a;
	temp[x][y] = 8;
	if (y == m && x == m)
	{
		if (minGold > gold)
		{
			minGold = gold;
		}
		
		return ;
	}
	
	if (a[y][x] == 9)
	{
		return;
	}
	
	if (y < 0 || y > m || x < 0 || x > m)
	{
		return;
	}
	
	else
	{
		for (int plus = 0; plus <= 7; ++plus)
		{
			int posY = y + YPlus[plus];
			int posX = x + XPlus[plus];
			
			if (posY < 0 || posY > m || posX < 0 || posX > m)
			{
				continue;
			}
			
			if (a[posY][posX] == 8)
			{
				continue;
			}
			else if (plus <= 3)
			{
				if (a[y][x] == a[posY][posX])
				{
					fbs(posY, posX, temp, gold + 0);
				}
				else
				{
					fbs(posY, posX, temp, gold + 1);
				}
			}
			else
			{
				if (a[y][x] == a[posY][posX])
				{
					fbs(posY, posX, temp, gold + 2);
				}
				else
				{
					fbs(posY, posX, temp, gold + 3);
				}
			}
		}
	}
}

int main()
{
	ifstream my_cin("chess3.in");
	ofstream my_cout("chess.out");
	
	int n;
	my_cin >> m >> n;
	
	vector< vector<int> > a (m + 1, vector<int>(m + 1, 9));
	
	for (int i = 1; i <= n; ++i)
	{
		int y, x;
		my_cin >> y >> x;
		my_cin >> a[y][x];
	}
	
	fbs(1, 1, a, 0);
	
	my_cout << minGold << endl;
	
	
	return 0;
}
