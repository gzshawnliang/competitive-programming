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

ifstream fin("heavyCycleEdges_UVA11747.in");
ofstream fout("heavyCycleEdges_UVA11747.out");

struct edge
{
    int u;
    int v;
    int w;

    bool operator < (const edge & temp) const
    {
        return w < temp.w;
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

int main()
{
    while (true)
    {
        int n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0) break;

        vector<int> p(n), out;
        vector<bool> mark(m, false);
        vector<edge> ways;
        for (int c = 1; c <= m; ++c)
        {
            int u, v, w; fin >> u >> v >> w;

            edge temp{u, v, w};
            ways.push_back(temp);
        }

        sort(ways.begin(), ways.end());
        for (int i = 0; i <= n - 1; ++i)
        {
            p[i] = i;
        }

        for (int i = 1, j = 0; i <= n - 1 && j <= m - 1; ++j)
        {
            int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);

            if (res0 == res1)
            {
                continue;
            }

            p[res0] = res1;

            mark[j] = true;

            ++i;
        }

        for (int i = 0; i <= m - 1; ++i)
        {
            if (mark[i] == false)
            {
                out.push_back(ways[i].w);
            }
        }
        sort(out.begin(), out.end());

        int size0 = out.size();
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (i > 0) fout << ' ';
            fout << out[i];
        }
        if (size0 == 0) fout << "forest";

        fout << '\n';
    }

    return 0;
}