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

ifstream fin("LCMCardinality_UVA10892.in");
ofstream fout("LCMCardinality_UVA10892.out");

int main()
{
    while (true)
    {
        long long n = 0;
        fin >> n;
        if (n == 0) break;

        long long ans = 1, temp = n;
        for (long long i = 2; i * i <= n; i += 2)
        {
            long long c = 1;
            while (n % i == 0)
            {
                ++c;
                n /= i;
            }
            ans *= c * 2 - 1;

            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            ans *= 3;
        }

        ans = ans / 2 + 1;

        fout << temp << ' ' << ans << '\n';
    }

    return 0;
}