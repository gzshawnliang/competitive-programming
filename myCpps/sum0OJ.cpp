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
#include <ctime>

using namespace std;

int main()
{
    int count0;
    cin >> count0;
    for (int c = 1; c <= count0; ++c)
    {
        int size;
        cin >> size;
        vector<vector<int>> a(4, vector<int>(size));
        for (int i = 0; i <= size - 1; ++i)
        {
            for (int j = 0; j <= 3; ++j)
            {
                cin >> a[j][i];
            }
        }
        vector<int> sums;
        for (int i0 = 0; i0 <= size - 1; ++i0)
        {
            for (int i1 = 0; i1 <= size - 1; ++i1)
            {
                sums.push_back(a[0][i0] + a[1][i1]);
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i0 = 0; i0 <= size - 1; ++i0)
        {
            for (int i1 = 0; i1 <= size - 1; ++i1)
            {
                int find0 = -1 * (a[2][i0] + a[3][i1]);
                vector<int>::iterator it = lower_bound(sums.begin(), sums.end(), find0);
                while (*it == find0 && it != sums.end())
                {
                    ++ans;
                    ++it;
                }
            }
        }
        if (c != 1)
        {
            cout << '\n';
        }
        cout << ans << '\n';
    }

    return 0;
}