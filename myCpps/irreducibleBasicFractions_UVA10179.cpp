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

ifstream fin("irreducibleBasicFractions_UVA10179.in");
ofstream fout("irreducibleBasicFractions_UVA10179.out");

int main()
{
    while (true)
    {
        int n = 0;
        fin >> n;

        if (n == 0)
        {
            break;
        }

        int ans = 1;
        for (int i = 2; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                ans *= i - 1;
                n /= i;

                while (n % i == 0)
                {
                    ans *= i;
                    n /= i;
                }
            }

            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            ans *= n - 1;
        }

        fout << ans << '\n';
    }

    return 0;
}