/** 基础练习题
 * https://www.spoj.com/problems/EZDIJKST/
*/

#include <bits/stdc++.h>
using namespace std;

//INF = 1B, not 2^31-1 to avoid overflow
const int INF = 1e9; 

class vertex
{
  public:
    int distance;
    int v;
    vertex(int d, int id)
    {
        distance = d;
        v = id;
    };

    bool operator<(const vertex & b) const
    {
        return this->distance > b.distance;
    }
};

class dijkstra
{
  private:
    int V;
    int E;
    vector<vector<vertex>> g;      //图的数组
    vector<int> father;            //father[v]=u,顶点v的父亲是u，代表v是通过u过来的u->v;初始值-1
    vector<set<int>> multiFather;  //multiFather[v]=u,顶点v的父亲是u数组，多个父亲，代表顶点v是通过u(u是数组)过来的u->v;初始值空数组。用set取代数组，强制里面元素是唯一的
    vector<vector<int>> multiPath; //多条路径二维数组

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
        vector<int> distance(V, INF);
        distance[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.distance > distance[now.v])
                continue;

            int u = now.v;
            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组distance，放入优先队列
                if (distance[u] + next.distance < distance[next.v])
                {
                    distance[next.v] = distance[u] + next.distance; // relax operation
                    pq.push(next);
                }
            }
        }

        for (int t = 1; t <= V - 1; ++t)
        {
            cout << "SSSP(" << s << "->" << t << ") = " << distance[t] << "\n";
        }
    }

    void RunOnePath(int s)
    {
        vector<int> distance(V, INF);
        distance[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.distance > distance[now.v])
                continue;

            int u = now.v;

            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组distance，放入优先队列
                if (distance[u] + next.distance < distance[next.v])
                {
                    distance[next.v] = distance[u] + next.distance; // 松弛操作
                    father[next.v] = u;
                    pq.push(next);
                }
            }
        }

        for (int t = 1; t <= V - 1; ++t)
        {
            cout << "SSSP(" << s << "->" << t << ") = " << distance[t] << "\n";
        }
    }

    void RunMultiPath(int s)
    {
        vector<int> distance(V, INF);
        distance[s] = 0;
        priority_queue<vertex> pq;
        pq.push(vertex(0, s));

        while (!pq.empty())
        {
            vertex now = pq.top();
            pq.pop();

            //当前取出的路径更长，则忽略（重要）
            if (now.distance > distance[now.v])
                continue;

            int u = now.v;

            for (unsigned int j = 0; j < g[u].size(); ++j)
            {
                vertex next = g[u][j]; //all outgoing edges from u

                //发现更短的路径，更新数组distance，放入优先队列，清除multiFather
                if (distance[u] + next.distance < distance[next.v])
                {
                    distance[next.v] = distance[u] + next.distance; // 松弛操作
                    multiFather[next.v].clear();
                    multiFather[next.v].insert(u);
                    pq.push(next);
                }
                else if (distance[u] + next.distance == distance[next.v])  //发现一样长的路径，更新数组distance，放入优先队列，不清除multiFather，加入
                {
                    distance[next.v] = distance[u] + next.distance; // 松弛操作
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
            cout << "SSSP(" << s << "->" << t << ") = " << distance[t] << "\n";
        }
    }
};

int main()
{
    
    /*
        Graph V=6 E=7 Start=0
        6 7 0

        0 1 1
        1 2 1
        2 3 1
        0 3 3
        3 4 1
        4 5 1
        3 5 1
  */

    freopen("dijkstra.in", "r", stdin);

    int V, E, S;
    cin >> V >> E >> S;
    vector<vector<vertex>> g(V, vector<vertex>());
    for (int i = 0; i <= E - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(vertex(w, v)); // directed graph
    }
    dijkstra dij(V, E, g);
    dij.RunMultiPath(S);    //跑dijkstra算法

    int target = 5;         //目标终点

    vector<vector<int>> multiPath = dij.GetMultiPath(target);
    cout << '\n';
    for (auto path : multiPath)
    {
        cout << "Path(" << S << "->" << target << ") = ";
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
    cout << "-------------\n";

    // dij.RunOnePath(S);
    // vector<int> path = dij.GetOnePath(target);
    // cout << '\n';
    // cout << "Path(" << S << "->" << target << ") = ";
    // for (int t = 0; t <= path.size() - 1; ++t)
    // {
    //     cout << path[t] << " ";
    // }

    return 0;
}