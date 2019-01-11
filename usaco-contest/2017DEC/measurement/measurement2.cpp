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
    string cowNumber;
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

struct p
{
    int g;
    string cowNumber;

    bool operator<(const p &temp) const
    {
        if (g != temp.g)
        {
            return g < temp.g;
        }
        else if (cowNumber != temp.cowNumber)
        {
            return cowNumber > temp.cowNumber;
        }
    }
};

string gen(map<string, int> & m)
{
    vector<p> a;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        p temp{it->second, it->first};
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    
    int size = a.size();
    string ans = a.back().cowNumber + " ";

    for (int i = size - 2; i >= 0; --i)
    {
        if (a[i].g != a[i + 1].g)
        {
            break;
        }

        ans = ans + a[i].cowNumber + " ";
    }

    return ans;
}

int main()
{
    int n, useless; fin >> n >> useless;

    map<string, int> m;
    string now = "";
    vector<measurement> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i].date >> a[i].cowNumber >> a[i].change;
        m[a[i].cowNumber] = 0;
    }

    now = gen(m);

    sort(a.begin(), a.end());
    
    int total = 0, i = 0;
    while (i <= n - 1)
    {
        while (true)
        {
            m[a[i].cowNumber] += a[i].change;

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

        string temp = gen(m);
        if (temp != now)
        {
            ++total;
            now = temp;
        }

        ++i;
    }

    fout << total << '\n';

    return 0;
}