#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("H(n).in");
ofstream fout("H(n).out");

long long H(long long n)
{
    long long res = 0;
    long long divide = 1, now = 1;
    while (now <= n)
    {
        long long maxDivide = n / (n / now);
        res += (maxDivide - now + 1) * (n / now);
        now = maxDivide + 1;
    }
    return res;
}

int main()
{
    int totalTest;
    fin >> totalTest;
    for (int c = 1; c <= totalTest; ++c)
    {
        long long in;
        fin >> in;
        fout << H(in) << '\n';
    }
}