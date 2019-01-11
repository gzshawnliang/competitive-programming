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
ofstream fout("haybalesB.out");

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
        int a, b, total = 0; fin >> a >> b;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (farm[i] >= a && farm[i] <= b)
            {
                ++total;
            }
        }
        
        fout << total << '\n';
    }

    return 0;
}