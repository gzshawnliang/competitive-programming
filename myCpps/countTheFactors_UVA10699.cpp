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

ifstream fin("countTheFactors_UVA10699.in");
ofstream fout("countTheFactors_UVA10699.out");

int main()
{
    while (true)
    {
        int n = 0, temp;
        fin >> n;
        if (n == 0) break;

        temp = n;

        int ans = 0;
        for (int i = 2; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                ++ans;

                while (n % i == 0)
                {
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
            ++ans;
        }

        fout << temp << " : " << ans << '\n';
    }

    return 0;
}