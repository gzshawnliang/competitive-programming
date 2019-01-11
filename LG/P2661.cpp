#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P2661.in");
ofstream fout("P2661.out");

int _find(int i, vector<int> & g, vector<int> & d)
{
    if (g[i] != i)
    {
        int last = g[i];
        g[i] = _find(g[i], g, d);
        d[i] += d[last];
    }
    return g[i];
}

int main()
{
    int n; fin >> n;

    vector<int> g(n + 1), d(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }

    int ans = 2147483647;
    for (int i = 1; i <= n; i++)
    {
        int j; fin >> j;

        int fi = _find(i, g, d), fj = _find(j, g, d);

        if (fi != fj)
        {
            g[fi] = fj;
            d[i] = d[j] + 1;
        }
        else
        {
            ans = min(ans, d[i] + d[j] + 1);
        }
    }
    fout << ans << '\n';
    return 0;
}