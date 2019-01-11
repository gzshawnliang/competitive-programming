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

ifstream fin("troublemaker.in");
ofstream fout("troublemaker.out");

struct student
{
    int num;
    int c;
    bool operator<(const student &temp)
    {
        return c > temp.c;
    }
};

struct store
{
    int a;
    int b;
    bool operator==(const store &temp)
    {
        return (temp.a == a && temp.b == b) || (temp.a == b && temp.b == a);
    }
};

int main()
{
    int totalTest;
    fin >> totalTest;

    for (int c = 1; c <= totalTest; ++c)
    {
        int n, m;
        fin >> n >> m;

        if (m == 0)
        {
            fout << "Case #" << c << ": 0\n\n";
            continue;
        }

        vector<store> a(m);
        vector<student> count(n);

        for (int i = 0; i <= m - 1; ++i)
        {
            int u, v;
            fin >> u >> v;

            count[u].num = u;
            ++count[u].c;
            count[v].num = v;
            ++count[v].c;

            a[i].a = u;
            a[i].b = v;
        }

        sort(count.begin(), count.end());

        vector<int> moved;
        int leftTotal = m, rightTotal = 0;
        bool ok = false;
        for (int i = 0; i <= m - 1; ++i)
        {
            leftTotal -= count[i].c;

            int size0 = moved.size();
            for (int j = 0; j <= size0 - 1; ++j)
            {
                store temp{count[i].num, moved[j]};
                if (find(a.begin(), a.end(), temp) != a.end())
                {
                    ++rightTotal;
                }
            }
            moved.push_back(count[i].num);

            if (leftTotal + rightTotal <= m / 2)
            {
                ok = true;
                break;
            }
        }

        if (ok == true)
        {
            int size0 = moved.size();
            sort(moved.begin(), moved.end());

            fout << "Case #" << c << ": " << size0 << '\n';
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (i > 0)
                {
                    fout << ' ';
                }
                fout << moved[i];
            }
            fout << '\n';
        }
        else
        {
            fout << "Case #" << c << ": Impossible.\n";
        }
    }

    return 0;
}