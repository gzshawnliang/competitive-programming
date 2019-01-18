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

ifstream fin("reststops.in");
ofstream fout("reststops.out");

struct stop
{
    long long x;
    long long c;

    bool operator<(const stop &temp) const
    {
        if (c != temp.c)
        {
            return c > temp.c;
        }
        else
        {
            return x > temp.x;
        }
    }
};

int main()
{
    long long l, n, rf, rb, b = 0, f = 0, t, ans = 0; fin >> l >> n >> rf >> rb;

    vector<stop> s(n);

    for (long long i = 0; i <= n - 1; ++i)
    {
        fin >> s[i].x >> s[i].c;
    }
    t = rf - rb;

    sort(s.begin(), s.end());

    ans += s[0].c * s[0].x * t;

    long long last = 0;
    for (long long i = 1; i <= n - 1; ++i)
    {
        if (s[i].x > s[last].x)
        {
            ans += s[i].c * (s[i].x - s[last].x) * t;
            last = i;
        }
    }

    fout << ans << '\n';

    return 0;
}
