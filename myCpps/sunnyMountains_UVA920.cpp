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
#include <climits>

using namespace std;

ifstream fin("sunnyMountains_UVA920.in");
ofstream fout("sunnyMountains_UVA920.out");

struct point
{
    int x;
    int y;

    bool operator<(const point & temp) const
    {
        if (x != temp.x)
        {
            return x > temp.x;
        }
        else
        {
            return y < temp.y;
        }
    }
};

int main()
{
    fout << fixed << setprecision(2);

    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n; fin >> n;
        double total = 0.0;

        vector<point> m(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> m[i].x >> m[i].y;
        }

        sort(m.begin(), m.end());

        point now = m[0];
        for (int i = 1; i <= n - 1; ++i)
        {
            if (m[i].y > now.y)
            {
                double h = (double)m[i].y - (double)now.y,
                       k = ((double)m[i].y - (double)m[i - 1].y) / ((double)m[i].x - (double)m[i - 1].x),
                       l = h / k;

                total += sqrt(l * l + h * h);

                now = m[i];
            }
        }

        fout << total << '\n';
    }

    return 0;
}