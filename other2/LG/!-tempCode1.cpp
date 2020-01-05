#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("!-tempCode1.in");
ofstream fout("!-tempCode1.out");

long long getRand(long long l, long long r)
{
    return (rand() % (r - l + 1)) + l;
}

int main()
{
    srand(time(NULL));

    long long n = 10000000;

    fout << n;
    for (long long c = 1; c <= n; ++c)
    {
        fout << ' ' << getRand(0, INT_MAX);
    }
    fout << '\n';

    return 0;
}