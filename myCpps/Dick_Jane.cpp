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
#include <ctime>
#include <map>

using namespace std;

ifstream fin("Dick_Jane.in");
ofstream fout("Dick_Jane.out");

int main()
{
    while (true)
    {
        int s = -1, p, y, j;
        fin >> s;

        if (s == -1)
        {
            break;
        }

        fin >> p >> y >> j;

        int last0, last1, last2;
        for (int s0 = s; s0 <= s + 1; ++s0)
        {
            for (int p0 = p; p0 <= p + 1; ++p0)
            {
                for (int y0 = y; y0 <= y + 1; ++y0)
                {
                    for (int j0 = j; j0 <= j + 1; ++j0)
                    {
                        last0 = (12 + j0 + s0 - 2 * y0) / 3;
                        last1 = last0 + y0;
                        last2 = last0 + p0;
                        
                    }
                }
            }
        }
        fout << last1 << ' ' << last2 << ' ' << last0 << '\n';
    }

    return 0;
}