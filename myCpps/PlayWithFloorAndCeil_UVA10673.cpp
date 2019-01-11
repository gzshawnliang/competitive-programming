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
#include <stack>

using namespace std;

ifstream fin("PlayWithFloorAndCeil_UVA10673.in");
ofstream fout("PlayWithFloorAndCeil_UVA10673.out");

int gdc_plus(int a, int b, int & p, int & q)
{
    if (b == 0)
    {
        p = 1;
        q = 0;

        return a;
    }
    else
    {
        int res = gdc_plus(b, a % b, p, q);
        
        int temp = p;
        p = q;
        q = temp - a / b * q;

        return res;
    }
}

int main()
{
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int x, k; fin >> x >> k;

        int a = x / k, b = (int)ceil(double(x) / double(k)), p = 0, q = 0;
        int res = gdc_plus(a, b, p, q);

        fout << p * x / res << ' ' << q * x / res << '\n';
    }

    return 0;
}