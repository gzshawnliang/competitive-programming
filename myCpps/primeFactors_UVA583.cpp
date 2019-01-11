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

ifstream fin("primeFactors_UVA583.in");
ofstream fout("primeFactors_UVA583.out");

int main()
{
    while (true)
    {
        bool first = true;
        long long n = 0;
        fin >> n;
        if (n == 0) break;

        fout << n << " = ";
        if (n < 0)
        {
            fout << "-1";
            n *= -1;
            first = false;
        }

        for (long long i = 2; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                if (first == true)
                {
                    first = false;
                }
                else
                {
                    fout << " x ";
                }

                fout << i;

                n /= i;
            }
            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            if (first == true)
            {
                first = false;
            }
            else
            {
                fout << " x ";
            }

            fout << n;
        }

        fout << '\n';
    }

    return 0;
}