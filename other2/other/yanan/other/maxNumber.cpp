#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long long Sstoi(string hi, int begin, int length)
{
	string temp = "";
	
	for (int i = begin; i <= length + begin - 1; ++i)
	{
		temp += hi[i];
	}
	
	long long j = 0;
	
	for (int i = 0; i <= length - 1; ++i)
	{
		j = j * 10 + temp[i] - '0';
	}
	
	return j;
}

void main2()
{
	string a = "68987612422";
	
	cout << Sstoi(a, 0, a.size()) << endl;
}

int main()
{
	ifstream cin("maxNumber.in");
	
	string input;
	int times, IAmSoUseless;
	cin >> IAmSoUseless >> times >> input;
	
	int size = input.size();
	
	vector< vector<long long> > dp(size + 1, vector<long long> (times + 1));
	
	dp[0][0] = 1;
	for (int i = 1; i <= size; ++i)
	{
		dp[i][0] = Sstoi(input, 0, i); 
	}
	
	for (int i = 2; i <= size; ++i)
	{
		for (int time = 1; time <= i - 1 && time <= times; ++time)
		{
			long long maxNumber = 0;
			
			for (int j = 1; j <= i - time; ++j)
			{
				//cout << dp[i - j][time - 1] << " * " << Sstoi(input, i - j, j) << endl;
				//cout << i - j << " , " << time - 1 << "," << j << "," << input << endl;
				//cout << "dp[i - j].size():" << dp[i - j].size() << endl;
				maxNumber = max(maxNumber, dp[i - j][time - 1] * Sstoi(input, i - j, j));
			}
			dp[i][time] = maxNumber;
		}
	}

	ofstream out("maxNumber.out");
	out << dp[size][times] << endl;
	
	return 0;
}
