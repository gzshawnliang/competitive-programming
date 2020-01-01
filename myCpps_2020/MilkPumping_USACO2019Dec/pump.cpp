#include <bits/stdc++.h>

using namespace std;

ifstream fin("pump.in");
ofstream fout("pump.out");

const int inf = INT_MAX / 2;

struct edge
{
    int v;
    int c;
    int f;
};
edge _edge(int v, int c, int f)
{
    edge temp{v, c, f}; return temp;
}

struct segment
{
    int u;
    int cc;
    int cf;
};
segment _segment(int u, int cc, int cf)
{
    segment temp{u, cc, cf}; return temp;
}

bool check(double mid, vector<vector<edge>> & g)
{
    int n = g.size() - 1;

    //vector<int> visited(n + 1, 0);

    queue<segment> q; q.push(_segment(1, 0, inf));
    //visited[1] = 1;

    while (q.empty() == false)
    {
        segment now = q.front(); q.pop();

        int size = g[now.u].size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g[now.u][i].v,
                cc = now.cc + g[now.u][i].c,
                cf = min(now.cf, g[now.u][i].f);

            //if (visited[v] == 1) continue;
            if ((double)cf < (double)cc * mid) continue;
            if (v == n) return true;
            
            //visited[v] = 1;
            q.push(_segment(v, cc, cf));
        }
    }

    return false;
}

int main()
{
    int n, m; fin >> n >> m;
    
    vector<vector<edge>> g(n + 1);
    for (int ce = 1; ce <= m; ++ce)
    {
        int u, v, c, f; fin >> u >> v >> c >> f;

        g[u].push_back(_edge(v, c, f));
        g[v].push_back(_edge(u, c, f));
    }

    double l = 0.0, r = inf;
    for (int c = 1; c <= 100; ++c)
    {
        double mid = (l + r) / 2;

        if (check(mid, g) == true)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    fout << (int)(l * 1e6) << '\n';

    return 0;
}
