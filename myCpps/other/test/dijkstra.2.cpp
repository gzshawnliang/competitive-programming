#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)1e6;

struct node
{
    int b;
    int d;

    bool operator<(const node & temp) const
    {
        return d > temp.d;
    }
};

void dijkstra(int n, int start, vector<int> & dis, vector<int> & parent, vector<vector<int>> & dp)
{
    vector<bool> visit(n + 1, false);

    priority_queue<node> q;
    dis[start] = 0;

    node temp0{start, 0};
    q.push(temp0);
    parent[start] = start;

    for (int c = 1; c <= n - 1; ++c)
    {
        if (q.empty() == true)
        {
            break;
        }

        int u = q.top().b;
        while (visit[u] == true && q.empty() == false)
        {
            q.pop();
            u = q.top().b;
        }

        visit[u] = true;

        for (int v = 1; v <= n; ++v)
        {
            if (visit[v] == false && dis[v] > dis[u] + dp[u][v])
            {
                dis[v] = dis[u] + dp[u][v];

                parent[v] = u;

                node temp1{v, dis[v]};
                q.push(temp1);
            }
        }
    }
}

void path(int v, vector<int> & parent, vector<string> & vertexVec)
{
    if (parent[v] == v)
    {
        cout << vertexVec[v - 1] << '\n';
    }
    else
    {
       cout << vertexVec[v - 1] << ' ';

       path(parent[v], parent, vertexVec);
    }
}

int main()
{
    freopen("dijkstra.in", "r", stdin);

    int vertexCount = 0; //顶点的数量
    int edgeCount = 0;   //边的数量

    string startVertexName = ""; //起始点名称
    int startVertex = 0;         //起始点索引

    map<string, int> mp;      //顶点数字对应的名称
    vector<string> vertexVec; //顶点名称

    cin >> vertexCount >> edgeCount >> startVertexName;

    vector<int> dis(vertexCount + 1, INF), parent(vertexCount + 1);
    dis[startVertex] = 0;
    vector<vector<int>> dp(vertexCount + 1, vector<int>(vertexCount + 1, INF)); //一张有权重的图

    //初始化
    for (int i = 0; i <= edgeCount - 1; ++i)
    {
        string from;
        string to;
        int weight;
        cin >> from >> to >> weight;
        if (mp[from] == 0)
        {
            vertexVec.push_back(from);
            mp[from] = vertexVec.size();
        }

        if (mp[to] == 0)
        {
            vertexVec.push_back(to);
            mp[to] = vertexVec.size();
        }
        dp[mp[from]][mp[to]] = weight;
        dp[mp[to]][mp[from]] = weight;
    }

    startVertex = mp[startVertexName];

    dijkstra(vertexCount, startVertex, dis, parent, dp);
    
    for (int i = 1; i <= vertexCount; ++i)
    {
        cout << vertexVec[i - 1] << " -> " << vertexVec[startVertex - 1] << ": ";
        if (dis[i] >= INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dis[i] << " path: ";
            path(i, parent, vertexVec);
        }
    }

    return 0;
}