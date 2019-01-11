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

ifstream fin("citystate.in");
ofstream fout("citystate.out");

struct city
{
    string n;
    string c;

    bool operator<(const city &temp) const
    {
        return c < temp.c;
    }

    bool operator<=(const city &temp) const
    {
        return c <= temp.c;
    }

    bool operator==(const city &temp) const
    {
        return c == temp.c;
    }
};

int main()
{
    int n; fin >> n;

    vector<city> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i].n >> a[i].c;
    }

    sort(a.begin(), a.end());

    int total = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        string nowCode;
        nowCode.push_back(a[i].n[0]);
        nowCode.push_back(a[i].n[1]);

        city now{"hajgsfguyghjeggjn", nowCode};

        int pos = lower_bound(a.begin(), a.end(), now) - a.begin();

        for (int j = pos; j <= n - 1; ++j)
        {
            if (a[j].c != nowCode)
            {
                break;
            }
            else
            {
                if (a[j].c[0] == a[i].n[0] && a[j].c[1] == a[i].n[1])
                {
                    ++total;
                    break;
                }
            }
        }

        //cout << "";
    }

    fout << total / 2 << '\n';

    return 0;
}