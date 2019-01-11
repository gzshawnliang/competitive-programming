#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("sendingEmail_UVA10986.in");
ofstream fout("sendingEmail_UVA10986.out");

const int INF = 1000000;

struct edge
{
    int u;
    int v;
    int w;
};

int main()
{
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, s, e; fin >> n >> m >> s >> e;

        vector<int> dis(n, INF);
        vector<vector<edge>> g(n);

        for (int c = 1; c <= m; ++c)
        {
            int u, v, w;
            fin >> u >> v >> w;

            edge temp0{u, v, w}, temp1{v, u, w};
            g[u].push_back(temp0);
            g[v].push_back(temp1);
        }

        queue<int> q;
        vector<bool> inQueue(n, false);

        dis[s] = 0;
        q.push(s); inQueue[s] = true;
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop(); inQueue[u] = false;

            int size = g[u].size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int v = g[u][i].v;
                if (dis[v] > dis[u] + g[u][i].w)
                {
                    dis[v] = dis[u] + g[u][i].w;
                    if (inQueue[v] == false)
                    {
                        q.push(v); inQueue[v] = true;
                    }
                }
            }
        }

        fout << "Case #" << t << ": ";
        if (dis[e] >= INF)
        {
            fout << "unreachable\n";
        }
        else
        {
            fout << dis[e] << '\n';
        }
    }

    return 0;
}