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
#include <climits>

using namespace std;

ofstream fout;

int getRand(int a, int b)
{
    return (rand() % (b - a + 1)) + a;
}

int main()
{
    srand(time(0));

    for (int t = 1; t <= 100; ++t)
    {
        int total = getRand(10, 500);

        string text = "sumOfDifferentPrimes" + to_string(t) + ".in";
        fout.open(text);

        for (int t = 1; t <= total; ++t)
        {
            // int n = getRand(1, 1120), k = getRand(1, min(14, n / 2));

            // if (k == 0) ++k;

            int n = getRand(1, 1120);
            int kMax=min(14, n / 2);
            
            if (kMax==0)
            {
                kMax = 2;
            }

            int k = getRand(1, kMax);

            fout << n << ' ' << k << '\n';
        }
        fout << "0 0\n";

        fout.close();
    }

    return 0;
}