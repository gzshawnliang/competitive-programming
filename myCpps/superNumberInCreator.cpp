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
#include <ctime>

using namespace std;

ofstream fout("superNumber.in");

int main()
{
    fout << "406\n";
    for (int n = 1; n <= 29; ++n)
    {
        for (int m = n + 1; m <= 29; ++m)
        {
            fout << n << ' ' << m << '\n';
        }
    }

    return 0;
}