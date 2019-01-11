#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("Formula1_UVA11056.in");
ofstream fout("Formula1_UVA11056.out");

bool compare(string a, string b)
{
    int size = min(a.size(), b.size());

    for (int i = 0; i <= size - 1; ++i)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = a[i] - 'A' + 'a';
        }
        if (b[i] >= 'A' && b[i] <= 'Z')
        {
            b[i] = b[i] - 'A' + 'a';
        }
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
        else if (i == size - 1)
        {
            return a.size() < b.size();
        }
    }
}

struct pilot
{
    string name;
    int m;
    int s;
    int ms;

    bool operator < (const pilot temp) const
    {
        if (m != temp.m)
        {
            return m < temp.m;
        }
        else if (s != temp.s)
        {
            return s < temp.s;
        }
        else if (ms != temp.ms)
        {
            return ms < temp.ms;
        }
        else
        {
            return compare(name, temp.name);
            //return lexicographical_compare(name.begin(), name.end(), temp.name.begin(), temp.name.end());
        }
    }
};

int main()
{
    while (true)
    {
        int n = 0;
        fin >> n;
        if (n == 0) break;
        
        vector<pilot> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            string temp;

            fin >> temp;
            a[i].name = temp;

            fin >> temp;

            fin >> temp;
            a[i].m = stoi(temp);

            fin >> temp;

            fin >> temp;
            a[i].s = stoi(temp);

            fin >> temp;

            fin >> temp;
            a[i].ms = stoi(temp);

            fin >> temp;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i <= n - 1; i += 2)
        {
            fout << "Row " << i / 2 + 1 << '\n';
            if (i == n - 1)
            {
                fout << a[i].name << '\n';
            }
            else
            {
                fout << a[i].name << '\n';
                fout << a[i + 1].name << '\n';
            }
        }

        fout << '\n';
    }

    return 0;
}