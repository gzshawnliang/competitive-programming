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

ifstream fin("benefit_UVA11889.in");
ofstream fout("benefit_UVA11889.out");

int main()
{
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        long long a, c; fin >> a >> c;

        if (c % a != 0)
        {
            fout << "NO SOLUTION\n";
            continue;
        }

        long long ans = 1;
        for (int i = 2; i * i <= c; i += 2)
        {
            bool flag = false;
            int _count = 0;
            while (a % i == 0)
            {
                a /= i;
                c /= i;
                ++_count;
            }

            while (c % i == 0)
            {
                c /= i;
                ans *= i;
                flag = true;
            }

            for (int c = 1; c <= _count && flag == true; ++c)
            {
                ans *= i;
            }

            if (i == 2)
            {
                i = 1;
            }
        }

        if (c > 1 && a == 1)
        {
            ans *= c;
        }

        fout << ans << '\n';
    }

    return 0;
}