/*
-------------------------------------------------------------------
* @Name:           1385E Directing Edges
* @Author:         Thomas
* @Create Time:    2020/7/19 10:12:06  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/E
* @Description:    
-------------------------------------------------------------------
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
    vector<vector<int>> g;                  //graph
    vector<pair<int, int>> undirectedEdge;  //无向图的边
    vector<int> inDegree;                   //inDegree[i],节点i的入度
    vector<int> pos;                        //pos[i],每个节点的位置
    int n, m;                               //the number of vertices and the number of edges in the graph, respectively.

    //拓扑排序，有环无法排序返回false。否则返回true，修改pos数组
    bool topoSort()
    {
        queue<int> q;

        //查找入度是0的节点，放入队列
        for (int i = 1; i <= n; ++i)
            if (inDegree[i] == 0)
                q.push(i);

        vector<int> topoOrder; //topoOrder 为拓扑序列
        while (!q.empty())
        {
            int p = q.front();
            q.pop();                // 选一个入度为0的点，出队列
            topoOrder.push_back(p);
            for (int i = 0, len = g[p].size(); i <= len - 1; ++i)
            {
                int y = g[p][i];
                --inDegree[y];
                if (inDegree[y] == 0)
                    q.push(y);
            }
        }

        if ((int)topoOrder.size() == n)
        {
            for (int i = 0, len = topoOrder.size(); i <= len - 1; ++i)
                pos[topoOrder[i]] = i;

            return true;
        }
        else
        {
            //ans中的长度与n不相等，就说明无拓扑序列,有环
            return false;
        }
    }

  public:
    void solve()
    {
        cin >> n >> m;
        g = vector<vector<int>>(n + 1, vector<int>());
        pos = vector<int>(n + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 1)
            {
                g[x].push_back(y);
            }
            else
            {
                undirectedEdge.push_back({x, y});
            }
        }

        //每个节点的入度
        inDegree = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            for (auto u : g[i])
                ++inDegree[u];

        if (topoSort() == false)                    //topo排序失败，有环无法排序
        {
            cout << "NO\n";
            return;
        }

        for (auto p : undirectedEdge)
        {
            int x = p.first;
            int y = p.second;
            
            if (pos[x] < pos[y])       //topo顺序:小->大 创建边，保证无环
                g[x].push_back(y);
            else
                g[y].push_back(x);
        }

        //输出图
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0, len = g[i].size(); j <= len - 1; ++j)
            {
                cout << i << " " << g[i][j] << "\n";
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385E_DirectingEdges.in", "r", stdin);
    //freopen("CF_1385E_DirectingEdges.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solution sln1;
        sln1.solve();
    }
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}
