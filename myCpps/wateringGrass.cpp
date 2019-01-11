#include <algorithm>
#include <climits>
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

ifstream fin("wateringGrass.in");
ofstream fout("wateringGrass.out");

struct line
{
    double start;
    double end;
    bool operator<(const line &temp)
    {
        return start < temp.start;
    }
};

int main()
{
    while (true)
    {
        int n = -1, l = -1, w = -1;
        fin >> n >> l >> w;

        double w0 = w;
        w0 /= 2;

        if (n == -1 && l == -1 && w == -1)
        {
            break;
        }

        vector<line> a(n);
        int nullPos = INT_MIN;
        bool ok = false;
        for (int i = 0; i <= n - 1; ++i)
        {
            double x, r;
            fin >> x >> r;

            double length;
            if (r <= w0)
            {
                a[i].start = nullPos;
                a[i].end = nullPos;
            }
            else
            {
                length = sqrt(r * r - w0 * w0);
                a[i].start = x - length;
                a[i].end = x + length;

                if (a[i].start <= 0 && a[i].end >= l)
                {
                    ok = true;
                }
            }
        }

        if (ok == true)
        {
            fout << "1\n";
            continue;
        }

        sort(a.begin(), a.end());

        int i = 0, total = 1;

        while (a[i].start == nullPos)
        {
            ++i;
        }
        int first = -1, maxE = -1;
        for (int j = i; j <= n - 1; ++j)
        {
            if (a[j].start <= 0 && a[j].end > maxE)
            {
                first = j;
                maxE = a[j].end;
            }
        }

        i = first;

        if (first == -1)
        {
            fout << "-1\n";
            continue;
        }

        while (i <= n - 1)
        {
            if (i == n - 1)
            {
                if (a[i].end < l)
                {
                    total = -1;
                }
                break;
            }
            else
            {
                int j = i + 1, maxEnd = -1, choose = -1;
                while (j <= n - 1 && a[j].start <= a[i].end)
                {
                    if (a[j].end > maxEnd)
                    {
                        choose = j;
                        maxEnd = a[j].end;
                    }
                    ++j;
                }

                if (maxEnd == -1)
                {
                    total = -1;
                    break;
                }
                else
                {
                    if (a[i].end >= l)
                    {
                        break;
                    }

                    ++total;
                    i = choose;
                }
            }
        }

        fout << total << '\n';
    }

    return 0;
}