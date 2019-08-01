
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

int main()
{
    /*
  // Graph
  5 7 0
  0 1 2
  0 2 6
  0 3 7
  1 3 3
  1 4 6
  2 4 1
  3 4 5
  */

    freopen("dijkstra.in", "r", stdin);

    int V, E, s;
    cin >> V >> E >> s;
    vector<vector<int>> g(V, vector<int>(V, -1));
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;              // directed graph
    }

    vector<int> dist(V, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (unsigned int t = 0; t <= g[f].size() - 1; ++t)
        {
            if (g[f][t] > 0)
            {
                int w = g[f][t];
                if (dist[f] + w < dist[t])
                {
                    dist[t] = dist[f] + w;
                    q.push(t);
                }
            }
        }
    }

    for (int t = 1; t <= V-1; ++t)
    {
        cout << "SSSP(" << s << "," << t << ") = " << dist[t] << "\n";
    }
    return 0;
}