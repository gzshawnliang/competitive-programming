#include <bits/stdc++.h>
using namespace std;

class vertex
{
  public:
    int dist;
    int v;
    vertex(int d, int id)
    {
        dist = d;
        v = id;
    };

    bool operator<(const vertex & b) const
    {
        return this->dist > b.dist;
    }
};

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

class dijkstra
{
  private:
    int V;
    int E;
    vector<vector<vertex>> g;
    vector<int> father; //father[v]=u,表示顶点v是通过u过来的u->v;初始值-1

    vector<set<int>> multiFather; //multiFather[v]=u,表示顶点v是通过u(u是数组)过来的u->v;初始值-1
    vector<vector<int>> multiPath;

    void dfsPath(int curr, int source, vector<int> & path)
    {
        if (curr == source)
        {
            multiPath.push_back(path);
            return;
        }
        set<int> tmpFather = multiFather[curr];
        for (auto i : tmpFather)
        {
            path.push_back(i);
            dfsPath(i, source, path);
            path.pop_back();
        }
    }

  public:
    dijkstra(int V, int E, vector<vector<vertex>> & g)
    {
        this->V = V;
        this->E = E;
        this->g = g;

        father.resize(V);
        fill(father.begin(), father.end(), -1);

        multiFather.resize(V);
    };

    vector<int> GetOnePath(int n) //到顶点n的最短路（单条）
    {
        vector<int> path;
        path.push_back(n);

        int i = father[n];
        while (i != -1)
        {
            path.push_back(i);
            i = father[i];
        }

        reverse(path.begin(), path.end());
        return path;
    }    

    vector<vector<int>> GetMultiPath(int n) //到顶点n的最短路（多条）
    {
        multiPath.clear();
        vector<int> path;
        path.push_back(n);
        dfsPath(n, 0, path);
        vector<vector<int>> multiPath2;
        for (auto i : multiPath)
        {
            reverse(i.begin(), i.end());
            multiPath2.push_back(i);
        }
        return multiPath2;
    }

    void RunNoPath(int s)
    {
        // (Modified) Dijkstra's routine
        vector<int> dist(V, INF);
        dist[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.dist > dist[now.v])
                continue;

            int u = now.v;
            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组dist，放入优先队列
                if (dist[u] + next.dist < dist[next.v])
                {
                    dist[next.v] = dist[u] + next.dist; // relax operation
                    pq.push(next);
                }
            }
        }

        for (int t = 1; t <= V - 1; ++t)
        {
            cout << "SSSP(" << s << "->" << t << ") = " << dist[t] << "\n";
        }
    }

    void RunOnePath(int s)
    {
        vector<int> dist(V, INF);
        dist[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.dist > dist[now.v])
                continue;

            int u = now.v;

            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组dist，放入优先队列
                if (dist[u] + next.dist < dist[next.v])
                {
                    dist[next.v] = dist[u] + next.dist; // 松弛操作
                    father[next.v] = u;
                    pq.push(next);
                }
            }
        }

        for (int t = 1; t <= V - 1; ++t)
        {
            cout << "SSSP(" << s << "->" << t << ") = " << dist[t] << "\n";
        }

    }

    void RunMultiPath(int s)
    {
        vector<int> dist(V, INF);
        dist[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.dist > dist[now.v])
                continue;

            int u = now.v;

            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组dist，放入优先队列
                if (dist[u] + next.dist < dist[next.v])
                {
                    dist[next.v] = dist[u] + next.dist; // 松弛操作
                    multiFather[next.v].clear();
                    multiFather[next.v].insert(u);
                    pq.push(next);
                }
                else if (dist[u] + next.dist == dist[next.v])
                {
                    dist[next.v] = dist[u] + next.dist; // 松弛操作
                    if (multiFather[next.v].count(u) == 0)
                    {
                        multiFather[next.v].insert(u);
                    }
                    pq.push(next);
                }
            }
        }

        for (int t = 1; t <= V - 1; ++t)
        {
            cout << "SSSP(" << s << "->" << t << ") = " << dist[t] << "\n";
        }
    }
};

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
    for (int i = 0; i <= E - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(vertex(w, v)); // directed graph
    }
    dijkstra dij(V, E, g);

    int target = 5; //终点

    dij.RunMultiPath(s);
    vector<vector<int>> multiPath = dij.GetMultiPath(target);
    cout << '\n';
    for (auto path : multiPath)
    {
        cout << "Path(" << s << "->" << target << ") = ";
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
    cout << "-------------\n";

    // dij.RunOnePath(s);
    // vector<int> path = dij.GetOnePath(target);
    // cout << '\n';
    // cout << "Path(" << s << "->" << target << ") = ";
    // for (int t = 0; t <= path.size() - 1; ++t)
    // {
    //     cout << path[t] << " ";
    // }    

    return 0;
}