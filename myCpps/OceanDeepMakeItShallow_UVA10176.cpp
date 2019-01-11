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

using namespace std;

ifstream fin("OceanDeepMakeItShallow_UVA10176.in");
ofstream fout("OceanDeepMakeItShallow_UVA10176.out");

const int m = 131071;

int main()
{
    while (true)
    {
        char temp = '-';
        fin >> temp;
        if (temp == '-') break;

        string in = "";
        in.push_back(temp);
        while (temp != '#')
        {
            fin >> temp;
            in.push_back(temp);
        }
        
        long long size0 = in.size() - 1, ans = 0, base = 1;
        for (int i = size0 - 1; i >= 0; --i)
        {
            ans += (in[i] - '0') * base;
            ans %= m;

            base *= 2;
            base %= m;
        }

        if (ans % m == 0)
        {
            fout << "YES\n";
        }
        else
        {
            fout << "NO\n";
        }
    }

    return 0;
}