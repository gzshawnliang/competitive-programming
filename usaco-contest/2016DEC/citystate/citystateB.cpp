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
ofstream fout("citystateB.out");

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
        for (int j = i + 1; j <= n - 1; ++j)
        {
            string stri, strj;
            stri.push_back(a[i].n[0]);
            stri.push_back(a[i].n[1]);
            strj.push_back(a[j].n[0]);
            strj.push_back(a[j].n[1]);

            if (stri == a[j].c && a[i].c == strj)
            {
                ++total;
            }
        }
    }

    fout << total << '\n';

    return 0;
}