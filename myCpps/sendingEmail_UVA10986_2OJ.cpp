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


const int INF = 1000000;

struct edge
{
    int u;
    int v;
    int w;
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m, s, e; cin >> n >> m >> s >> e;

        vector<int> dis(n, INF);
        vector<vector<edge>> g(n);

        for (int c = 1; c <= m; ++c)
        {
            int u, v, w;
            cin >> u >> v >> w;

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

        cout << "Case #" << t << ": ";
        if (dis[e] >= INF)
        {
            cout << "unreachable\n";
        }
        else
        {
            cout << dis[e] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
