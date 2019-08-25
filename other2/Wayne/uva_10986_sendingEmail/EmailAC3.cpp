#include <bits/stdc++.h>

using namespace std;

struct node
{
    int p;        //p点编号
    int distance; //p->S的最短距离

    node(int d, int idx)
    {
        distance = d;
        p = idx;
    }

    bool operator<(const node & newnode) const
    {
        return distance > newnode.distance;
    }
};

const int INF = INT_MAX / 2;

int main()
{
    freopen("Email.in", "r", stdin);
    freopen("Email.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    int caseNo = 1;
    while (t--)
    {
        int j, n, m, S, T;
        cin >> n >> m >> S >> T;

        //创建图,使用Adjacency Lists
        //http://www2.csie.ntnu.edu.tw/~u91029/Graph.html#4
        vector<vector<node>> g(n);
        while (m--)
        {
            int a, b, d;
            cin >> a >> b >> d;

            g[a].push_back(node(d, b)); //双向图 a->b:d
            g[b].push_back(node(d, a)); //      b->a:d
        }

        // 从 S 点开始跑 Dijkstra
        vector<int> distance(n, INF);
        distance[S] = 0;                //S->S的最短距离是 0

        priority_queue<node> pq;
        pq.push(node(0, S));            //放入起点

        while (!pq.empty())
        {
            node now = pq.top();
            pq.pop(); // greedy: 选择未访问最短的路线，优先队列自动排序

            int u = now.p;
            int u_distance = now.distance;

            //如果u点的距离u->S长于走过的 distance[u]，则忽略,不重复放入队列（重要）
            if (u_distance > distance[u])
                continue;

            for (j = 0; j < (int)g[u].size(); j++) //遍历u点所有的边
            {
                int v = g[u][j].p;                   //u点的第j条边,u->v
                int distance_u_v = g[u][j].distance; //u-v的距离

                if (distance[v] > distance[u] + distance_u_v) //如果 距离(s->v) > 距离(s->u) + 距离(u->v)
                {
                    distance[v] = distance[u] + distance_u_v; //松弛：更新距离(s->v)
                    pq.push(node(distance[v], v));            //放入队列
                }
            }
        }

        cout << "Case #" << caseNo << ": ";
        if (distance[T] != INF)
            cout << distance[T] << '\n';
        else
            cout << "unreachable\n";

        ++caseNo;
    }
    cout.flush();
    return 0;
}