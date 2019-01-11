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

ifstream fin("specialSum.in");
ofstream fout("specialSum.out");

int main()
{
    int count0;
    fin >> count0;
    for (int c = 1; c <= count0; ++c)
    {
        if (c != 1)
        {
            fout << '\n';
        }

        int k;
        fin >> k;

        if (k < 0)
        {
            k *= -1;
        }
        
        for (int n = sqrt(2 * k); n <= 44723; ++n)
        {
            if (n * (n + 1) / 2 < k)
            {
                continue;
            }
            int different = (n * (n + 1) / 2 - k);
            if (different % 2 == 0 && different / 2 <= 2 * n - 1)
            {
                fout << n << '\n';
                break;
            }
        }
    }

    return 0;
}