#include <bits/stdc++.h>
using namespace std;

class vertex
{
    public:
        int dist;
        int v;
        vertex(int d,int id)
        {
            dist=d;
            v=id;
        };

    bool operator<(const vertex & b) const
    {
        return this->dist > b.dist;
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
        g[u].push_back(vertex(w,v)); // directed graph
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

        //当前取出的路径更长，则忽略（重要）
        if (f.dist > dist[f.v])
            continue; 

        int u=f.v;
        for (unsigned int j = 0; j < g[u].size(); ++j)
        {
            vertex next = g[u][j];      //all outgoing edges from u

            //发现更短的路径，更新数组dist，放入优先队列
            if (dist[u] + next.dist < dist[next.v])
            {
                dist[next.v] = dist[u] + next.dist;              // relax operation
                pq.push(next);
            }
        }
    }

    for (int t = 1; t <= V-1; ++t)
    {
        cout << "SSSP(" << s << "," << t << ") = " << dist[t] << "\n";
    }
    return 0;
}