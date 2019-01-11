#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("matchMaking.in");
ofstream fout("matchMaking.out");

int main()
{     
    int test = 0;
    while (true)
    {
        ++test;
        int b = 0, s = 0, minAge = INT_MAX;
        fin >> b >> s;

        if (b == 0)
        {
            break;
        }

        for (int i = 0; i <= b - 1; ++i)
        {
            int in; fin >> in;
            minAge = min(minAge, in);
        }

        for (int i = 0; i <= s - 1; ++i)
        {
            int useless; fin >> useless;
        }

        if (b <= s)
        {
            fout << "Case " << test << ": 0\n";
            continue;
        }

        fout << "Case " << test << ": " << b - s << ' ' << minAge << '\n';
    }

    return 0;
}