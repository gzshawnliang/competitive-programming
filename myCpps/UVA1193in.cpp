#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("UVA1193in.in");
ofstream fout("radarInstallation.in");

int _rand(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int main()
{
    srand(time(0));

    for (int c = 1; c <= 500; ++c)
    {
        if (c > 1) fout << '\n';

        int n = _rand(1, 1000);

        fout << n << ' ' << _rand(100, 1000) << '\n';

        for (int i = 1; i <= n; ++i)
        {
            fout << _rand(0, 500) - 250 << ' ' << _rand(1, 500) << '\n';
        }
    }

    fout << "\n0 0\n";

    return 0;
}