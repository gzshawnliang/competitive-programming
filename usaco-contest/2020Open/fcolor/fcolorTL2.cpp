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
    while (true)
    {
        bool flg = false;

        int nowC = 0;
        vector<int> colors(n + 1, -1);
        vector<vector<int>> groups(n + 1);
        for (int u = 1; u <= n; ++u)
        {
            if (colors[fnd(f, u)] == -1)
                colors[fnd(f, u)] = ++nowC;

            colors[u] = colors[fnd(f, u)];
            groups[colors[u]].push_back(u);
        }

        for (int col = 1; col <= nowC; ++col)
        {
            int first = -1;
            for (auto u : groups[col])
            {
                for (auto v : g[u])
                {
                    if (first == -1)
                        first = v;

                    // else if (fnd(f, v) != fnd(f, first))
                    // {
                    //     f[fnd(f, v)] = fnd(f, first);
                    //     flg = true;
                    // }
                    else 
                    {
                        int a=fnd(f, v);
                        int b=fnd(f, first);
                        if (a !=b)
                        {
                            f[a] = b;
                            flg = true;
                        }
                    }

                }
            }
        }

        if (flg == false)
        {
            for (int u = 1; u <= n; ++u)
            {
                fout << colors[u] << '\n';
            }
            break;
        }
    }

    return 0;
}
