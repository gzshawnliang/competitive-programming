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

ifstream fin("measurement.in");
ofstream fout("measurement.out");

struct measurement
{
    int date;
    int cowNumber;
    int change;

    bool operator<(const measurement &temp) const
    {
        if (date != temp.date)
        {
            return date < temp.date;
        }
        else if (cowNumber != temp.cowNumber)
        {
            return cowNumber < temp.cowNumber;
        }
    }
};

int main()
{
    int n, t = 1, useless; fin >> n >> useless;

    map<int, int> m;
    vector<measurement> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        int temp;
        fin >> a[i].date >> temp >> a[i].change;

        if (m[temp] == 0)
        {
            m[temp] = t;
            ++t;
        }

        a[i].cowNumber = m[temp];
    }
    
    vector<int> last(t, 0);

    sort(a.begin(), a.end());

    int total = 0, i = 0;
    while (i <= n - 1)
    {
        vector<int> now = last;

        while (true)
        {
            now[a[i].cowNumber] += a[i].change;

            if (i == n - 1)
            {
                break;
            }
            else if (a[i].date != a[i + 1].date)
            {
                break;
            }

            ++i;
        }

        vector<int> L, N;

        int Lmax = 0, Nmax = 0;
        for (int j = 1; j <= t - 1; ++j)
        {
            if (last[j] == Lmax)
            {
                L.push_back(j);
            }
            else if (last[j] > Lmax)
            {
                Lmax = last[j];

                L.clear();
                L.push_back(j);
            }

            if (now[j] == Nmax)
            {
                N.push_back(j);
            }
            else if (now[j] > Nmax)
            {
                Nmax = now[j];

                N.clear();
                N.push_back(j);
            }
        }

        sort(N.begin(), N.end());
        sort(L.begin(), L.end());

        bool ok = true;
        int size = N.size();

        if (size != L.size()) ok = false;
        for (int i = 0; i <= size - 1 && ok == true; ++i)
        {
            if (L[i] != N[i])
            {
                ok = false;
            }
        }

        total += (ok == false);

        last = now;
        ++i;
    }

    fout << total << '\n';

    return 0;
}