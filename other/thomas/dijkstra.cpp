
#include <bits/stdc++.h>
using namespace std;

// typedef pair<int, int> ii;
// typedef vector<int> vi;
// typedef vector<ii> vii;

class v
{
    int u;
};

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

int main()
{
    /*
  // Graph in Figure 4.17
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
    cin >> V >> E >>s;
    vector<vector<pair<int, int>>> AL(V, vector<pair<int, int>>());
    vector<vector<int>> g(V, vector<int>(V,-1));
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >>w;
        AL[u].emplace_back(v, w); // directed graph
        g[u][v]=w;  // directed graph
    }

    // (Modified) Dijkstra's routine
    vector<int> dist(V, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    // sort the pairs by increasing distance from s
    while (!pq.empty())
    {
        pair<int, int> front = pq.top();
        pq.pop();                               // greedy: get shortest unvisited vertex
        int d = front.first;
        int u = front.second;
        if (d > dist[u])
            continue; // this is a very important check
            
        for (int j = 0; j < (int)AL[u].size(); j++)
        {
            pair<int, int> v = AL[u][j]; // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second; // relax operation
                pq.push(pair<int, int>(dist[v.first], v.first));
            }
        }
    }

    for (int u = 0; u < V; ++u)
        cout <<"SSSP("<<s<<","<<u <<") = "<< dist[u] << "\n";

    return 0;
}