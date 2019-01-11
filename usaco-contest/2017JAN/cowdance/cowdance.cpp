#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

int main()
{
    int n, tmin; fin >> n >> tmin;
    vector<int> d(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> d[i];
    }

    vector<int> s;

    int l = 1, r = n;
    while (l <= r)
    {
        bool type = false;
        int k = (l + r) / 2, i = -1, t = 0;

        s.clear();
        for (int j = 0; j <= k - 1; ++j)
        {
            s.push_back(0);
        }
        
        while (i <= k - 1)
        {
            ++i;
            s[i] = d[i];
        }
        --i;

        while (type == false)
        {
            int pass = *min_element(s.begin(), s.end());
            t += pass;

            if (t > tmin)
            {
                break;
            }

            for (int j = 0; j <= k - 1; ++j)
            {
                s[j] -= pass;
                if (s[j] == 0)
                {
                    ++i;

                    if (i > n - 1)
                    {
                        continue;
                    }

                    s[j] = d[i];
                }
            }

            if (i > n - 1)
            {
                t += *max_element(s.begin(), s.end());

                if (t <= tmin)
                {
                    type = true;
                }
                break;
            }
        }

        if (type == true)
        {
            r = k - 1;
        }
        else
        {
            l = k + 1;
        }
    }

    fout << l << '\n';

    return 0;
}