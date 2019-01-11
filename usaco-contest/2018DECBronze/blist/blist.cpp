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

ifstream fin("blist.in");
ofstream fout("blist.out");

struct dot
{
    int code;
    char type;
};

int main()
{
    int n; fin >> n;

    vector<int> b(n);

    dot _null{-1, '-'};
    vector<dot> l(1001, _null);

    for (int i = 0; i <= n - 1; ++i)
    {
        int s, t; fin >> s >> t >> b[i];

        l[s].code = i; l[s].type = 's';
        l[t].code = i; l[t].type = 't';
    }

    int total = 0;
    vector<int> wait(n, 0);

    for (int t = 1; t <= 1000; ++t)
    {
        if (l[t].code >= 0)
        {
            if (l[t].type == 's')
            {
                wait[l[t].code] = b[l[t].code];
                if (total < b[l[t].code])
                {
                    total = 0;
                }
                else
                {
                   total -= b[l[t].code];
                }
            }
            else
            {
                if (wait[l[t].code] > 0)
                {
                    total += wait[l[t].code];
                    wait[l[t].code] = 0;
                }
            }
        }
    }

    fout << total << '\n';

    return 0;
}
