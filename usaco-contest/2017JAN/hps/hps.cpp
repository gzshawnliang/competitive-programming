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

ifstream fin("hps.in");
ofstream fout("hps.out");

int main()
{
    int n; fin >> n;

    int Ht = 0, Pt = 0, St = 0;
    vector<int> Hc(n + 1), Pc(n + 1), Sc(n + 1);
    Hc[0] = 0; Pc[0] = 0; Sc[0] = 0;

    for (int c = 1; c <= n; ++c)
    {
        char ch; fin >> ch;
        if (ch == 'H')
        {
            Hc[c] = Hc[c - 1] + 1;
            Pc[c] = Pc[c - 1];
            Sc[c] = Sc[c - 1];
            ++Ht;
        }
        else if (ch == 'P')
        {
            Hc[c] = Hc[c - 1];
            Pc[c] = Pc[c - 1] + 1;
            Sc[c] = Sc[c - 1];
            ++Pt;
        }
        else
        {
            Hc[c] = Hc[c - 1];
            Pc[c] = Pc[c - 1];
            Sc[c] = Sc[c - 1] + 1;
            ++St;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        int Fwins = max(Hc[i], max(Pc[i], Sc[i])),
            Ewins = max(Ht - Hc[i], max(Pt - Pc[i], St - Sc[i]));
        ans = max(ans, Fwins + Ewins);
    }

    fout << ans << '\n';

    return 0;
}