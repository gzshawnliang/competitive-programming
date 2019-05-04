#include <bits/stdc++.h>
using namespace std;

class vertex
{
    public:
        int dist;
        int id;
        vertex(int d,int u)
        {
            dist=d;
            id=u;
        };

    bool operator<(const vertex & b) const
    {
        return this->dist < b.dist;
    }        
};

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
    vector<vector<vertex>> g(V, vector<vertex>());
    for (int i = 0; i <= E-1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(vertex(w,v)); // directed graph
    }

    // (Modified) Dijkstra's routine
    vector<int> dist(V, INF);
    dist[s] = 0;
    priority_queue<vertex> pq;
    pq.push(vertex(0,s));

    while (!pq.empty())
    {
        vertex f = pq.top();
        pq.pop();

        if (f.dist > dist[f.id])
            continue; // this is a very important check        

        int u=f.id;
        for (int j = 0; j < (int)g[u].size(); ++j)
        {
            vertex v = g[u][j]; // all outgoing edges from u
            if (dist[u] + v.dist < dist[v.id])
            {
                dist[v.id] = dist[u] + v.dist;              // relax operation
                pq.push(v);
            }
        }
    }

    for (int t = 1; t <= V-1; ++t)
    {
        cout << "SSSP(" << s << "," << t << ") = " << dist[t] << "\n";
    }
    return 0;
}