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

ifstream fin("sum0.in");
ofstream fout("sum0.out");

int main()
{
    int count0;
    fin >> count0;
    for (int c = 1; c <= count0; ++c)
    {
        int size;
        fin >> size;
        
        vector<vector<int>> a(4, vector<int>(size));
        for (int i = 0; i <= size - 1; ++i)
        {
            for (int j = 0; j <= 3; ++j)
            {
                fin >> a[j][i];
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

        
        // multiset<int> sums;
        // for (int i0 = 0; i0 <= size - 1; ++i0)
        // {
        //     for (int i1 = 0; i1 <= size - 1; ++i1)
        //     {
        //         sums.insert(a[0][i0] + a[1][i1]);
        //     }
        // }        


        //cout << (double)(clock() - tStart)/CLOCKS_PER_SEC <<"s"<< endl;

        //clock_t tStart1 = clock();
        
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

                //需要二分查找两次，比较慢
                //ans += upper_bound(sums.begin(), sums.end(), find0) - lower_bound(sums.begin(), sums.end(), find0);
            }
        }

        //cout << (double)(clock() - tStart1)/CLOCKS_PER_SEC <<"s"<< endl;

        if (c != 1)
        {
            fout << '\n';
        }
        fout << ans << '\n';
    }

    return 0;
}