#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// struct edge
// {
//     int from;
//     int to;
//     int weight;

//     bool operator < (const edge & temp) const
//     {
//         return weight < temp.weight;
//     }
// };

void sssp1()
{
    int vertexCount = 0; //顶点的数量
    int edgeCount = 0;   //边的数量
    int startVertex = 0; //起始点

    cin >> vertexCount >> edgeCount >> startVertex;

    if (vertexCount == 0)
    {
        return ;
    }

    const int INFINITY_MAX = INT_MAX;
    vector<vector<int>> w(vertexCount + 1, vector<int>(vertexCount + 1, INFINITY_MAX)); //一张有权重的图
    vector<int> distance(vertexCount + 1, 0);                                           //记录起点到图上各顶点的最短路径权重
    vector<int> parent(vertexCount + 1, -1);                                            //记录各个点在最短路径上的父亲是谁
    vector<bool> visit(vertexCount + 1, false);                                         //记录各个点是不是已经在最短路径树中

    for (int i = 0; i <= edgeCount - 1; ++i)
    {
        int from;
        int to;
        int weight;
        cin >> from >> to >> weight;
        w[from][to] = weight;
    }

    distance[startVertex] = 0;
    parent[startVertex] = startVertex;
    visit[startVertex] = true;

    for (int k = 0; k <= vertexCount - 1; ++k)
    {
        int min = INT_MAX;
        int a = 0;
        int b = 0;
        for (int i = 1; i <= vertexCount; ++i)
        {
            //找一個已在最短路徑樹上的點
            if (visit[i] == true)
            {
                for (int j = 1; j <= vertexCount; ++j)
                {
                    // 找一個不在最短路徑樹上的點
                    if (visit[j] == false)
                    {
                        if (w[i][j] != INFINITY_MAX)        //判断有路可通
                        {
                            if (distance[i] + w[i][j] < min)
                            {
                                a = i;// 記錄這一條邊
                                b = j;
                                min = distance[i] + w[i][j];
                            }
                        }
                    }
                }
            }
        }

        // 起点有连通的最短的路径都已找完
        if (a == 0 || b == 0)
        {
            break;
        }
        
        distance[b] = min;      // 儲存由起點到b點的最短路徑权重
        parent[b] = a;          // 记录b点是由a点延伸過去的，b的父母是a
        visit[b] = true;        // b点已经访问过
    }

    int size0 = parent.size();
    for (int i = 0; i <= size0 - 1; ++i)
    {
        if (parent[i] > 0 && distance[i]>0)
        {
            cout << parent[i] << "->" << i << ":" << distance[i] << "\n";
        }
    }
}

void dijkstra()
{
    int vertexCount = 0; //顶点的数量
    int edgeCount = 0;   //边的数量
    int startVertex = 0; //起始点

    cin >> vertexCount >> edgeCount >> startVertex;

    if (vertexCount == 0)
    {
        return ;
    }

    const int INFINITY_MAX = INT_MAX;
    vector<vector<int>> w(vertexCount + 1, vector<int>(vertexCount + 1, INFINITY_MAX)); //一张有权重的图
    vector<int> distance(vertexCount + 1, INT_MAX);                                           //记录起点到图上各顶点的最短路径权重
    vector<int> parent(vertexCount + 1, -1);                                            //记录各个点在最短路径上的父亲是谁
    vector<bool> visit(vertexCount + 1, false);                                         //记录各个点是不是已经在最短路径树中

    for (int i = 0; i <= edgeCount - 1; ++i)
    {
        int from;
        int to;
        int weight;
        cin >> from >> to >> weight;
        w[from][to] = weight;
    }

    distance[startVertex] = 0;
    parent[startVertex] = startVertex;
    visit[startVertex] = true;

    for (int k = 0; k <= vertexCount - 1; ++k)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        
        for (int i = 1; i <= vertexCount; ++i)
        {
            //找一個已在最短路徑樹上的點
            if (visit[i] == true)
            {
                for (int j = 1; j <= vertexCount; ++j)
                {
                    // 找一個不在最短路徑樹上的點
                    if (visit[j] == false)
                    {
                        if (w[i][j] != INFINITY_MAX)        //判断有路可通
                        {
                            if (distance[i] + w[i][j] < min)
                            {
                                a = i;// 記錄這一條邊
                                b = j;
                                min = distance[i] + w[i][j];
                            }
                        }
                    }
                }
            }
        }

        // 起点有连通的最短的路径都已找完
        if (a == 0 || b == 0)
        {
            break;
        }
        
        distance[b] = min;      // 儲存由起點到b點的最短路徑权重
        parent[b] = a;          // 记录b点是由a点延伸過去的，b的父母是a
        visit[b] = true;        // b点已经访问过
    }

    int size0 = parent.size();
    for (int i = 0; i <= size0 - 1; ++i)
    {
        if (parent[i] > 0 && distance[i]>0)
        {
            cout << parent[i] << "->" << i << ":" << distance[i] << "\n";
        }
    }
}


int main()
{
    freopen("sssp.in", "r", stdin);
    sssp1();
    return 0;
}