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

ifstream fin("throughTheDesert_UVA11935.in");
ofstream fout("throughTheDesert_UVA11935.out");

struct event
{
    double d;
    string name;
    double v;
};

void skipFin(int c)
{
    for (int i = 1; i <= c; ++i)
    {
        string s; fin >> s;
    }
}

bool check(double f, double n, vector<event> & e)
{
    int size = e.size();
    double leak = 0.0, nowF = f;
    for (int i = 1; i <= size - 1; ++i)
    {
        if ((e[i].d - e[i - 1].d) * (n / 100.0 + leak) > nowF)
        {
            return false;
        }
        else
        {
            nowF -= (e[i].d - e[i - 1].d) * (n / 100.0 + leak);

            if (e[i].name == "Goal")
            {
                return true;
            }
            else if (e[i].name == "Leak")
            {
                ++leak;
            }
            else if (e[i].name == "Gas")
            {
                nowF = f;
            }
            else if (e[i].name == "Mechanic")
            {
                leak = 0;
            }
            else if (e[i].name == "Fuel")
            {
                n = e[i].v;
            }
        }
    }
}

int main()
{
    fout << fixed << setprecision(3);
    while (true)
    {
        skipFin(3);
        double n; fin >> n;

        if (n == 0)
        {
            break;
        }

        vector<event> e;
        event ubeless1{0, "start"};
        e.push_back(ubeless1);

        while (true)
        {
            event temp; fin >> temp.d >> temp.name;
            if (temp.name == "Gas" || temp.name == "Fuel")
            {
                skipFin(1);
                if (temp.name == "Fuel")
                {
                    fin >> temp.v;
                }
            }

            e.push_back(temp);

            if (temp.name == "Goal")
            {
                break;
            }
        }

        double l = 0.0, r = 10000000.0001;
        while (r - l > 0.0001)
        {
            double f = (l + r) / 2.0;

            if (check(f, n, e) == true)
            {
                r = f;
            }
            else
            {
                l = f;
            }
        }

        fout << l << '\n';
    }

    return 0;
}
