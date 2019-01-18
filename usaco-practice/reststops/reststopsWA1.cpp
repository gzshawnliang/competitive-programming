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
    int _pos;

    bool operator<(const stop & temp) const
    {
        return c > temp.c;
    }
};

int main()
{
    long long l, n, rf, rb, b = 0, ans = 0; fin >> l >> n >> rf >> rb;

    vector<stop> s1(n), s2;

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> s1[i].x >> s1[i].c;
        s1[i]._pos = i;
    }

    s2 = s1;
    sort(s2.begin(), s2.end());

    int j = 0, _time = 0;
    vector<bool> visit(n, false);
    for (int i = 0; i <= n - 1; ++i)
    {
        while (visit[s2[j]._pos] == true)
        {
            ++j;
        }

        _time += (s1[i].x - b) * (rf - rb);

        if (s2[j]._pos == i)
        {
            if (visit[s2[j]._pos] == false)
            {
                ans += s2[j].c * _time;
                _time = 0;
            }

            ++j;
        }

        b = s1[i].x;
        visit[i] = true;
    }

    fout << ans << '\n';

    return 0;
}
