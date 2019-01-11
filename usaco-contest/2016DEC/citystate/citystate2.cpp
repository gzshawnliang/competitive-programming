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

int main()
{
    int n; fin >> n;

    map<string, int> m;
    for (int i = 0; i <= n - 1; ++i)
    {
        string a, b; fin >> a >> b;
        string c;
        
        c.push_back(a[0]);
        c.push_back(a[1]);
        if(c!=b)
        {
            ++m[c + b];
        }
        
    }

    int total = 0;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        string now = it->first;

        if (m[now] == 0) continue;

        string temp;
        temp.push_back(now[2]);
        temp.push_back(now[3]);
        temp.push_back(now[0]);
        temp.push_back(now[1]);

        total += m[temp] * m[now];
    }

    fout << total / 2 << '\n';

    return 0;
}