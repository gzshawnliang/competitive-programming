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

ofstream fout("haybales.in");

int getRand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int main()
{
    int n = 100000, q = 100, m = 1000000000;

    fout << n << ' ' << q << '\n';
    for (int c = 1; c <= n; ++c)
    {
        if (c > 1) fout << ' ';
        fout << getRand(0, m);
    }

    for (int c = 1; c <= q; ++c)
    {
        int a = getRand(0, m), b = getRand(0, m);
        if (a > b) swap(a, b);
        fout << a << ' ' << b << '\n';
    }

    srand(time(0));
}