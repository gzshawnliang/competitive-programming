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

ifstream fin("haybales.in");
ofstream fout("haybales.out");

int main()
{
    int n, q; fin >> n >> q;

    vector<int> farm(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> farm[i];
    }

    sort(farm.begin(), farm.end());

    for (int c = 1; c <= q; ++c)
    {
        int a, b; fin >> a >> b;
        int pos1 = lower_bound(farm.begin(), farm.end(), a) - farm.begin(),
            pos2 = upper_bound(farm.begin(), farm.end(), b) - farm.begin();
        fout << max(pos2 - pos1, 0) << '\n';
    }

    return 0;
}