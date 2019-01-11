#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n, t, m;
        cin >> n >> t >> m;
        vector<int> times(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            cin >> times[i];
        }

        vector<int> a;
        for (int i = m - 1; i >= 0; i -= n)
        {
            a.push_back(times[i]);
        }

        int minTrips = a.size();

        int minTime = 0;
        for (int i = minTrips - 1; i >= 0; --i)
        {
            minTime = max(a[i] + t * 2, minTime + t * 2);
        }

        minTime -= t;
        cout << minTime << ' ' << minTrips << '\n';
    }

   	cout.flush();
   	return 0;
}
