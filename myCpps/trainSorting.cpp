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

ifstream fin("trainSorting.in");
ofstream fout("trainSorting.out");

int main()
{
    int totalCase;
    fin >> totalCase;

    for (int c = 1; c <= totalCase; ++c)
    {
        int n;
        fin >> n;
        vector<int> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        if (n <= 3)
        {
            fout << n << '\n';
            continue;
        }

        vector<int> dp1(n);
        vector<int> dp2(n);
        
        int ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            dp1[i] = 1; dp2[i] = 1;

            for (int j = n - 1; j >= i + 1; --j)
            {
                if (a[i] > a[j])
                {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
                else if (a[i] < a[j])
                {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }

            ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        fout << ans << '\n';
    }

    return 0;
}