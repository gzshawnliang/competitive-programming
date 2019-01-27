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

ifstream fin("theSkylineProblem_UVA105.in");
ofstream fout("theSkylineProblem_UVA105.out");

int main()
{
    int L = 20002, R = 0;
    vector<int> a(20002, 0);

    while (true)
    {
        int l = 0, h = 0, r = 0; fin >> l >> h >> r;

        l *= 2; r *= 2;

        if (l == r)
        {
            break;
        }

        for (int i = l; i <= r; ++i)
        {
            a[i] = max(a[i], h);
        }

        L = min(L, l);
        R = max(R, r);
    }

    ++R;

    bool first = false;
    int i = L;

    while (i <= R)
    {
        if (first == true) fout << ' ';
        first = true;

        if (a[i] < a[i - 1])
        {
            fout << (i - 1) / 2;
        }
        else
        {
            fout << i / 2;
        }

        fout << ' ' << a[i];

        int now = a[i];
        while (i <= R && a[i] == now)
        {
            ++i;
        }
    }

    fout << '\n';

    return 0;
}
