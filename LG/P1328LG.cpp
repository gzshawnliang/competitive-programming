#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<vector<bool>> game = 
    {
        {0,0,1,1,0},
        {1,0,0,1,0},
        {0,1,0,0,1},
        {0,0,1,0,1},
        {1,1,0,0,0}
    };

    int n, A, B; cin >> n >> A >> B;
    vector<int> a(A), b(B);

    for (int i = 0; i <= A - 1; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= B - 1; ++i)
    {
        cin >> b[i];
    }

    int totalA = 0, totalB = 0;
    for (int g = 0; g <= n - 1; ++g)
    {
        totalA += game[a[g % A]][b[g % B]];
        totalB += game[b[g % B]][a[g % A]];
    }

    cout << totalA << ' ' << totalB << '\n';

   	cout.flush();
   	return 0;
}
