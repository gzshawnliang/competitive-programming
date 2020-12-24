/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/12/24 21:20:25  (UTC+08:00)
* @Url:            
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("fcolor.in");
ofstream fout("fcolor.out");

int fnd(int u, vector<int> &f)
{
    if (f[u] == u)
        return u;
    else
        return f[u] = fnd(f[u], f);
}

void merge(int u, int v, vector<int> &f)
{
    u = fnd(u, f); v = fnd(v, f);
}

int main()
{
    int n, m; fin >> n >> m;
    
    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= m; ++c)
    {
        int u, v; fin >> u >> v;
        g[u].push_back(v);
    }

    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    priority_queue<pair<int, int>> q;
    vector<int> f(n + 1, -1);
    //vector<int> f
    for (int u = 1; u <= n; ++u)
    {
        f[u] = u;
        if (g[u].size() >= 2) q.push({g[u].size(), u});
    }

    while (!q.empty())
    {
        int v = q.top().second; q.pop();

        bool flg = true;
        int u0 = fnd(g[v][0], f);
        vector<int> tmp = g[u0];
        for (int i = 1, siz = g[v].size(); i <= siz - 1; ++i)
        {
            int u = g[v][i];
            
            if (fnd(u, f) != u0)
            {
                for (auto x:g[fnd(u, f)]) tmp.push_back(x);
                g[fnd(u, f)].clear();
                f[fnd(u, f)] = u0;

                flg = false;
            }
        }
        
        if (flg == false)
        {
            g[u0] = tmp;
            if (tmp.size() >= 2) q.push({g[u0].size(), u0});
        }
    }

    vector<int> groupName(n + 1, -1);
    for (int u = 1; u <= n; ++u)
        groupName[u] = fnd(u, f);

    int cnt = 1;
    vector<int> groupCol(n + 1, -1);
    for (int u = 1; u <= n; ++u)
    {
        if (groupCol[fnd(u, f)] == -1)
            groupCol[fnd(u, f)] = cnt++;

        fout << groupCol[fnd(u, f)] << '\n';
    }

    return 0;
}
