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

ifstream fin("arcticNetwork_UVA10369.in");
ofstream fout("arcticNetwork_UVA10369.out");

struct point
{
    int y;
    int x;

    bool operator < (const point & temp) const
    {
        return y < temp.y && x < temp.x;
    }
};

struct edge
{
    int u;
    int v;
    double d;

    bool operator < (const edge & temp) const
    {
        return d < temp.d;
    }
};

double distance(point & u, point & v)
{   
    return sqrt((u.y - v.y) * (u.y - v.y) + (u.x - v.x) * (u.x - v.x));
}

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
    int testCase; fin >> testCase;
    fout << fixed << setprecision(2);
    for (int c0 = 1; c0 <= testCase; ++c0)
    {
        int st, rt; fin >> st >> rt;
        vector<point> radios;
        vector<int> p(rt);
        vector<edge> ways, picked;
        for (int rc = 0; rc <= rt - 1; ++rc)
        {
            int y, x; fin >> y >> x;
            point now{y, x};

            for (int i = 0; i <= rc - 1; ++i)
            {
                edge temp{i, rc, distance(now, radios[i])};
                ways.push_back(temp);
            }
            radios.push_back(now);
        }
        sort(ways.begin(), ways.end());
        for (int i = 0; i <= rt - 1; ++i)
        {
            p[i] = i;
        }

        int sizeWays = ways.size();
        for (int i = 0, j = 0; i <= rt - 2 && j <= sizeWays - 1; ++j)
        {
            int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);
            if (res0 == res1)
            {
                continue;
            }

            p[res0] = res1;
            picked.push_back(ways[j]);

            ++i;
        }

        if (st == 0) st = 1;

        int pos = picked.size() - st;
        if (pos < 0)
        {
            fout << "0.00\n";
        }
        else
        {
            fout << picked[pos].d << '\n';
        }
    }

    return 0;
}