#include <bits/stdc++.h>
using namespace std;
int b1, b2, need, ans = INT_MAX, totalK;

struct Node
{
    int x, y, currK;
};

//x为1桶的单位数，y为2桶的单位数
void bfs()
{
    bool vis[101][101][101] = {};
    memset(vis, 0, sizeof(vis)); //状态记录数组
    queue<Node> q;               //防止MLE
    q.push({0, 0, 0});
    vis[0][0][0] = 1;
    
    while (!q.empty())
    {
        Node n = q.front();
        q.pop();
        if (n.currK == totalK || n.x == 0 || n.y == 0) //判断 如两个桶里有任意一个为0，也做一次检查（之后可以一直倒空这个桶）
        {
            ans = min(ans, abs(n.x + n.y - need)); //cout << n.x + n.y << endl;
            if (n.currK == totalK)
                continue; //防止不必要状态扩展
        }
        int x = n.x, y = n.y, currK = n.currK + 1; //扩展

        if (vis[b1][y][currK]==0)
            q.push({b1, y, currK});
        vis[b1][y][currK] = 1;

        if (!vis[x][b2][currK])
            q.push({x, b2, currK});
        vis[x][b2][currK] = 1;

        if (!vis[0][y][currK])
            q.push({0, y, currK});
        vis[0][y][currK] = 1;

        if (!vis[x][0][currK])
            q.push({x, 0, currK});
        vis[x][0][currK] = 1;

        int Y = x + y, X = 0;
        if (Y > b2)
            X = Y - b2, Y = b2;

        if (!vis[X][Y][currK])
            q.push({X, Y, currK});       
        vis[X][Y][currK] = 1;

        X = x + y, Y = 0;
        if (X > b1)
            Y = X - b1, X = b1;

        if (!vis[X][Y][currK])
            q.push({X, Y, currK});

        vis[X][Y][currK] = 1;
    }
    cout << ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("pails.in", "r", stdin);
        freopen("pails.out", "w", stdout);
    #endif

    cin >> b1 >> b2 >> totalK >> need;
    bfs();
    return 0;
}