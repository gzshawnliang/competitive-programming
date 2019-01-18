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
    int x;
    int c;
};

int main()
{
    long long l, n, rf, rb, b = 0, ans = 0; fin >> l >> n >> rf >> rb;

    vector<stop> s(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> s[i].x >> s[i].c;
    }

    int i = 0;
    while (i <= n - 1)
    {
        long long _max = 0, pos = i; 
        for (int j = i; j <= n - 1; ++j)
        {
            long long now = s[j].c * (s[j].x- b) * (rf - rb);
            if (now > _max)
            {
                _max = now;
                pos = j;
            }
        }

        ans += _max;
        i = pos + 1;
        b = s[pos].x;
    }

    fout << ans << '\n';

    return 0;
}
