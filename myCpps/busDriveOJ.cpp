#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
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
    while (true)
    {
        int n = -1, d = -1, r = -1;
        cin >> n >> d >> r;

        if (n == 0)
        {
            break;
        }

        vector<int> morning(n), evening(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> morning[i];
        }

        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> evening[i];
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        int total = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (morning[i] + evening[i] > d)
            {
                total += morning[i] + evening[i] - d;
            }
        }

        cout << total * r << '\n';
    }

   	cout.flush();
	return 0;
}
