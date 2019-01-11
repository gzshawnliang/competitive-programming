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

ifstream fin("skyline.in");
ofstream fout("skyline.out");

int main()
{
    int totalCase;
    fin >> totalCase;

    for (int c = 1; c <= totalCase; ++c)
    {
        int n;
        fin >> n;

        vector<int> h(n), w(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> h[i];
        }
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> w[i];
        }

        vector<int> dpI(n), dpD(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            dpI[i] = w[i]; dpD[i] = w[i];

            for (int j = 0; j <= i - 1; ++j)
            {
                if (h[i] > h[j])
                {
                    dpI[i] = max(dpI[i], dpI[j] + w[i]);
                }
                else if (h[i] < h[j])
                {
                    dpD[i] = max(dpD[i], dpD[j] + w[i]);
                }
            }
        }

        int ans1 = *max_element(dpI.begin(), dpI.end()), ans2 = *max_element(dpD.begin(), dpD.end());

        fout << "Case " << c << ". ";
        if (ans1 >= ans2)
        {
            fout << "Increasing (" << ans1 << "). Decreasing (" << ans2 << ").\n";
        }
        else
        {
            fout << "Decreasing (" << ans2 << "). Increasing (" << ans1 << ").\n";
        }
    }

    return 0;
}