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

using namespace std;


struct edge
{
    int u;
    int v;
    int d;

    bool operator < (const edge & temp) const
    {
        return d < temp.d;
    }

    bool operator == (const edge & temp) const
    {
        return u == temp.u && v == temp.v && d == temp.d;
    }
};

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

int solve(int schT, edge & del, vector<edge> & ways)
{
    vector<int> p(schT + 1);
    for (int i = 1; i <= schT; ++i)
    {
        p[i] = i;
    }

    int ans = 0, conT = ways.size();
    for (int i = 1, j = 0; i <= schT - 1 && j <= conT - 1; ++j)
    {
        if (del == ways[j])
        {
            continue;
        }

        int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);

        if (res0 == res1)
        {
            continue;
        }

        p[res0] = res1;

        ans += ways[j].d;

        ++i;
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int caseT; cin >> caseT;
    for (int caseC = 1; caseC <= caseT; ++caseC)
    {
        int schT, conT; cin >> schT >> conT;
        vector<int> p(schT + 1);
        vector<bool> mark(conT, false);
        vector<edge> ways, pickeds;
        for (int conC = 1; conC <= conT; ++conC)
        {
            int u, v, d; cin >> u >> v >> d;

            edge temp{u, v, d};
            ways.push_back(temp);
        }
        sort(ways.begin(), ways.end());
        for (int i = 1; i <= schT; ++i)
        {
            p[i] = i;
        }

        int total0 = 0, total1 = 2147483647;
        vector<vector<int>> g(schT + 1);
        for (int i = 1, j = 0; i <= schT - 1 && j <= conT - 1; ++j)
        {
            int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);

            if (res0 == res1)
            {
                continue;
            }

            p[res0] = res1;

            g[ways[j].u].push_back(ways[j].v);
            g[ways[j].v].push_back(ways[j].u);
            mark[j] = true;
            total0 += ways[j].d;
            pickeds.push_back(ways[j]);

            ++i;
        }
        
        int size0 = pickeds.size();
        for (int i = 0; i <= size0 - 1; ++i)
        {
            int res = solve(schT, pickeds[i], ways);
            if (res <= total1 && res >= total0)
            {
                total1 = res;
            }
        }

        cout << total0 << ' ' << total1 << '\n';
    }

   	cout.flush();
   	return 0;
}
