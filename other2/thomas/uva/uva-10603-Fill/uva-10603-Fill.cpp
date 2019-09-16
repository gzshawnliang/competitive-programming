#include <bits/stdc++.h>

using namespace std;



struct Node
{
    int v[3];
    int dist;   //變量dist表示達到當前狀態需要取出的水量
    bool operator<(const Node & rhs) const
    {
        return dist > rhs.dist;
    } 
};



const int maxn = 200 + 5;
int vis[maxn][maxn];    //vis是二維數組，因爲知道前2個水杯的水量，第三個水杯即爲確定的
vector<int> cap(3);
int ans[maxn];

void update_ans(const Node & u)
{
    for (int i = 0; i < 3; i++)
    {
        int d = u.v[i];
        if (ans[d] < 0 || u.dist < ans[d])
            ans[d] = u.dist;
    } //每次更新ans把三個水杯各自水量的最短路徑進行更新
}

void bfs(int dest)
{
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    priority_queue<Node> q;
    Node start;
    start.dist = 0;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = cap[2];
    q.push(start);
    vis[0][0] = 1;
    while (!q.empty())
    {
        Node u = q.top();
        q.pop();
        update_ans(u); //對當前已進入隊列的結點更新狀態
        if (ans[dest] >= 0)
        {
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                { //i是出水的水杯編號 j是入水的水杯
                    if (u.v[i] == 0 || u.v[j] == cap[j])
                        continue;
                    int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
                    Node u2;
                    memcpy(&u2, &u, sizeof(u)); //memcpy可對結構體對象使用
                    u2.dist = u.dist + amount;
                    u2.v[i] -= amount;
                    u2.v[j] += amount;
                    if (!vis[u2.v[0]][u2.v[1]])
                    {   
                        //注意此處v數組的下標是0和1不是i和j
                        vis[u2.v[0]][u2.v[1]] = 1;
                        q.push(u2);
                    }
                }
            }
        }
    }
    while (dest >= 0)
    {
        if (ans[dest] >= 0)
        { //從目標水量d開始，查找距離d最近的d'
            printf("%d %d\n", ans[dest], dest);
            return;
        }
        dest--; //無法找到當前dest的答案則dest--
    }
}

int main()
{
    freopen("uva-10603-Fill.in", "r", stdin);      
    freopen("uva-10603-Fill.out", "w", stdout);     
    int T;
    cin>>T;
    while (T--)
    {
        //輸入3個水杯的容量和目標水量，求到達該目標水量的最小倒水量
        int d;

        cin>>cap[0]>>cap[1]>>cap[2]>>d;
        

        bfs(d);
    }
    return 0;
}