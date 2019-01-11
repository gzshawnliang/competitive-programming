#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

const int inf = (int)1e9;

int solve(int i, int m, int c, int _max, vector<int> & a)
{
    int n = a.size();

    if (i > n - 1)
    {
        return _max;
    }
    else if (m == 0)
    {
        return inf;
    }
    else
    {
        int res = inf;
        for (int j = max((n - i) / m, 1); j <= c; ++j)
        {
            res = min(res, solve(i + j, m - 1, c, max(_max, a[min(n - 1, i + j - 1)] - a[i]), a));
        }

        return res;
    }
}

int main()
{
    int n, m, c; fin >> n >> m >> c;
    vector<int> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    sort(a.begin(), a.end());

    fout << solve(0, m, c, 0, a) << '\n';

    return 0;
}
