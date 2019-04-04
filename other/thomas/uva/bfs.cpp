#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bfs.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> data(n + 1, vector<int>(n + 1, 0));
    int s = 1;
    int t = n;

    for (int i = 1; i <= n ; ++i)
    {
        int a;
        int b;
        cin >> a >> b;
        data[a][b] = 1;
        //data[b][a] = 1;
    }
    
    queue<int> q;
    q.push(s);
    
    //vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    vector<int> visited(n + 1, 0);

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
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
    
    return 0;
}