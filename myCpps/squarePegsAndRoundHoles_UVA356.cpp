#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("squarePegsAndRoundHoles_UVA356.in");
ofstream fout("squarePegsAndRoundHoles_UVA356.out");

bool inside(int y, int x, int n)
{
    return (y - 2 * n) * (y - 2 * n) + (x - 2 * n) * (x - 2 * n) <= (2 * n - 1) * (2 * n - 1);
}

int main()
{
    bool first = true;
    vector<int> yp = {1, 1, -1, -1}, xp = {1, -1, 1, -1};
    vector<vector<int>> ans(151, vector<int>(2, 0));

    for (int n = 1; n <= 150; ++n)
    {
        int d = 2 * n - 1;
        vector<vector<bool>> a(4 * n + 1, vector<bool>(4 * n + 1, false));

        for (int y = 0; y <= 4 * n; y += 2)
        {
            for (int x = 0; x <= 4 * n; x += 2)
            {
                a[y][x] = inside(y, x, n);
            }
        }

        int count1 = 0, count2 = 0;
        for (int y = 1; y <= 4 * n - 1; y += 2)
        {
            for (int x = 1; x <= 4 * n - 1; x += 2)
            {
                int c = 0;
                for (int p = 0; p <= 3; ++p)
                {
                    if (a[y + yp[p]][x + xp[p]] == true)
                    {
                        ++c;
                    }
                }

                
                if (c == 4)
                {
                    ++count2;
                }
                else if (c > 0)
                {
                    ++count1;
                }
            }
        }

        ans[n][0] = count1;
        ans[n][1] = count2;
    }

    while (true)
    {
        int n = 0; fin >> n;

        if (n == 0) break;

        if (first == false)
        {
            fout << '\n';
        }
        else
        {
            first = false;
        }

        fout << "In the case n = " << n << ", " << ans[n][0] << " cells contain segments of the circle.\n";
        fout << "There are " << ans[n][1] << " cells completely contained in the circle.\n";
    }

    return 0;
}