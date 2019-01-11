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

ifstream fin("ferryLoading-II_UVA10440.in");
ofstream fout("ferryLoading-II_UVA10440.out");

int main()
{
    int testCase;
    fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n, t, m;
        fin >> n >> t >> m;
        vector<int> times(m);
        for (int i = 0; i <= m - 1; ++i)
        {
            fin >> times[i];
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
        fout << minTime << ' ' << minTrips << '\n';
    }

    return 0;
}