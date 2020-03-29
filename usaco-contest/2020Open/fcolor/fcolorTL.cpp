#include <bits/stdc++.h>

using namespace std;

ifstream fin("fcolor.in");
ofstream fout("fcolor.out");

int fnd(vector<int> &f, int x)
{
    if (f[x] == x) return x;
    else           return f[x] = fnd(f, f[x]);
}

bool _merge(vector<int> &f, vector<set<int>> &inn, int x, int y)
{
    x = fnd(f, x), y = fnd(f, y);
    if (x == y) return false;
    
    f[x] = y;
    inn[y].insert(inn[x].begin(), inn[x].end());

    return true;
}

int main()
{
        int n, m; fin >> n >> m;
        vector<set<int>> g(n + 1);
    for (int c = 1; c <= m; ++c)
    {
        int u, v; fin >> u >> v;
        //if (u == v) continue;

        g[u].insert(v);
    }

        vector<int> f(n + 1, 0);
            for (int u = 1; u <= n; ++u) f[u] = u;
        vector<set<int>> inn = g;

    while (true)
    {
            bool flg = false;
            vector<int> visit(n + 1, 0);
            //vector<int> tmpF = f;
            //vector<set<int>> tmpInn = inn;
        for (int u = 1; u <= n; ++u)
        {
            if (visit[fnd(f, u)] == 1) continue;
            visit[fnd(f, u)] = 1;

            set<int> nowInn = inn[fnd(f, u)];
            if (nowInn.size() > 1)
            {
                int first = *nowInn.begin();
                for (auto ite = nowInn.begin(); ite != nowInn.end(); ++ite)
                {
                    //if (fnd(f, *ite) == fnd(f, u)) continue;

                    bool tmp = _merge(f, inn, *ite, first);
                    if (tmp == true) flg = true;
                }
            }
        }

        if (flg == false) break;
    }

        int nowC = 0;
        vector<int> colors(n + 1, -1);
    for (int u = 1; u <= n; ++u)
    {
        if (colors[fnd(f, u)] == -1)
            colors[fnd(f, u)] = ++nowC;

        colors[u] = colors[fnd(f, u)];

        fout << colors[u] << '\n';
    }

    return 0;
}
