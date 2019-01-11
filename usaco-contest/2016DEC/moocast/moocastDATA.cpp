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

ofstream fout("moocast.in");

int getRand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int main()
{
    int n = 200;

    fout << n << '\n';
    for (int c = 1; c <= n; ++c)
    {
        fout << getRand(0, 25000) << ' ' << getRand(0, 25000) << ' ' << getRand(0, 1000) << '\n';
    }

    srand(time(0));
}