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

ifstream fin("convention.in");
ofstream fout("convention.out");

bool check(int w, int n, int m, int c, vector<int> & a)
{
    int i = 0;
    while (i <= n - 1)
    {
        int j = i, nowC = 0;
        while (j <= n - 1 && a[j] - a[i] <= w && j - i + 1 <= c)
        {
            ++j;
        }
        i = j;

        --m;
        if (m < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m, c;
    fin >> n >> m >> c;

    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = a.back() - a[0];
    while (l < r)
    {
        int w = (l + r) / 2;
        
        if (check(w, n, m, c, a) == true)
        {
            r = w;
        }
        else
        {
            l = w + 1;
        }
    }

    fout << l << '\n';

    return 0;
}
