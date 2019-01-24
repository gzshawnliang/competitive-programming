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

ifstream fin("ubiquitousReligions_UVA10583.in");
ofstream fout("ubiquitousReligions_UVA10583.out");

int _find(int u, vector<int> & p)
{
    if (p[u] == u)
    {
        return u;
    }
    else
    {
        int ans = _find(p[u], p);

        p[u] = ans;

        return ans;
    }
}

int main()
{
    int testCase = 0;
    while (true)
    {
        ++testCase;

        int n, m; fin >> n >> m;

        if (n + m == 0) break;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;
        }

        for (int c = 1; c <= m; ++c)
        {
            int u, v; fin >> u >> v;

            p[_find(v, p)] = p[_find(u, p)];
        }

        set<int> s;
        for (int i = 1; i <= n; ++i)
        {
            s.insert(_find(i, p));
        }

        fout << "Case " << testCase << ": " << s.size() << '\n';
    }

    return 0;
}
