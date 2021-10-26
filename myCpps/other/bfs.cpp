#include <bits/stdc++.h>
using namespace std;

void bfs(int s,int t,int n,vector<vector<int>> & data)
{
    queue<int> q;
    q.push(s);
    
    
    vector<int> visited(n + 1, 0);  //已经访问过的点，0未访问，1已访问

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            int v = data[u][i];
            if (v==1 && visited[i] ==0)
            {
                q.push(i);
                visited[i] = 1;     //i已经访问过
                cout << i << " ";

                if(i==t)
                {
                    //找到目标点
                    return ;
                }
            }
        }
    }
}

int main()
{
    freopen("bfs.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> data(n + 1, vector<int>(n + 1, 0));
    
    int s = 1;      //起始点
    int t = n;      //目标点

    for (int i = 1; i <= n ; ++i)
    {
        int a;
        int b;
        cin >> a >> b;
        data[a][b] = 1;
        //data[b][a] = 1;
    }

    bfs(s, t, n, data);

    return 0;
}