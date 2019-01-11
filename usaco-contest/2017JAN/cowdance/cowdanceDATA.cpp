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

ofstream fout("cowdance.in");

int getRand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int main()
{
    int n = 10000, tmin = getRand(1000000, 1000);
    fout << n << ' ' << tmin << '\n';
    for (int c = 1; c <= n; ++c)
    {
        fout << getRand(10, 100000) << '\n';
    }

    return 0;
}