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

ifstream fin("wavioSequence.in");
ofstream fout("wavioSequence.out");

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

        vector<int> a(n), dp1(n, 1), dp2(n, 1), v1 = {0}, v2 = {0};
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        int i = 0, j = n - 1;
        while (i <= n - 1)
        {
            if (a[i] > v1.back())
            {
                v1.push_back(a[i]);
            }
            else
            {
                *lower_bound(v1.begin(), v1.end(), a[i]) = a[i];
            }

            if (a[j] > v2.back())
            {
                v2.push_back(a[j]);
            }
            else
            {
                *lower_bound(v2.begin(), v2.end(), a[j]) = a[j];
            }

            dp1[i] = v1.size();
            dp2[j] = v2.size();

            ++i;
            --j;
        }

        int ans = 0;
        for (int c = 0; c <= n - 1; ++c)
        {
            ans = max(ans, min(dp1[c], dp2[c]) * 2 - 3);
        }

        fout << ans << '\n';
    }

    return 0;
}