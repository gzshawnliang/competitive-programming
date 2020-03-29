#include <bits/stdc++.h>

using namespace std;

ifstream fin("fcolor.in");
ofstream fout("fcolor.out");

int fnd(vector<int> & f, int x)
{
    if (f[x] == x)
        return x;
    else
        return f[x] = fnd(f, f[x]);
}

void dfs(int las, int u, int depth, vector<int> &depFirst, vector<int> &visited, vector<vector<int>> &g, vector<int> &f)
{
    visited[u] = 1;

    if (u == 3)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    for (auto v:g[u])
    {
        if (v == las) continue;

        if ((int)depFirst.size() - 1 < depth + 1)
        {
            depFirst.push_back(fnd(f, v));
        }

        f[fnd(f, v)] = fnd(f, depFirst[depth + 1]);

        if (g[v].size() > 0 && visited[v] == 0)
        {
            dfs(u, v, depth + 1, depFirst, visited, g, f);
        }
    }
}

int main()
{
    int n, m;
    fin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= m; ++c)
    {
        int u, v;
        fin >> u >> v;
        //if (u == v) continue;

        g[u].push_back(v);
    }

    vector<int> f(n + 1, 0);
    for (int u = 1; u <= n; ++u)
        f[u] = u;
   
    
        
    for (int u = 1; u <= n; ++u)
    {
        if (g[u].size() > 0)
        {
                vector<int> depFirst;
                vector<int> visited(n + 1, 0);
            dfs(-1, u, -1, depFirst, visited, g, f);
        }
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
