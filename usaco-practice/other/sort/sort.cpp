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

ifstream fin("sort.in");
ofstream fout("sort.out");

struct num
{
    int v;
    int p;

    bool operator < (const num & temp) const
    {
        if (v != temp.v)
        {
            return v < temp.v;
        }
        else
        {
            return p < temp.p;
        }
    }
};

int main()
{
    int n; fin >> n;

    vector<num> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i].v;
        a[i].p = i;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        ans = max(ans, a[i].p - i + 1);
    }

    fout << ans << '\n';

    return 0;
}
