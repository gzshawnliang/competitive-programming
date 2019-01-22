#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("mountains.in");
ofstream fout("mountains.out");

struct line
{
    int l;
    int r;

    bool operator<(const line & temp) const
    {
        if (l != temp.l)
        {
            return l < temp.l;
        }
        else
        {
            return r > temp.r;
        }
    }
};

int main()
{
    int n; fin >> n;
    
    vector<line> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        int y, x; fin >> x >> y;

        a[i].l = x - y;
        a[i].r = x + y;
    }

    sort(a.begin(), a.end());

    int rMax = a[0].r, ans = n;

    if (n > 1)
    {
        if (a[1].r > rMax && a[1].l == a[0].l)
        {
            --ans;
        }
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        if (a[i].r <= rMax)
        {
            --ans;
        }
        else
        {
            rMax = a[i].r;
        }
    }

    fout << ans << '\n';

    return 0;
}
