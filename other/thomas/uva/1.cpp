#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int map[105][105] = {0};
queue<int> q;
int pre[105] = {0};
bool bfs(int s, int t, int n) //尋找從起點到終點的一條路徑
{
    memset(pre, -1, sizeof(pre));
    while (!q.empty())
        q.pop();
    pre[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int ind = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (pre[i] == -1 && map[ind][i] > 0) //尚未走過且流量>0
            {
                pre[i] = ind;
                if (i == t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}
int ek(int s, int t, int n)
{
    int maxflow = 0;
    while (bfs(s, t, n)) //直到不能再從起點走到終點
    {
        int minflow = 1e7; //將初始流量設最大
        int i;
        for (int i = t; i != s; i = pre[i])
        {
            minflow = min(minflow, map[pre[i]][i]); //路徑上最小容量(=這次可流通的最大流量)
        }
        for (int i = t; i != s; i = pre[i])
        {
            map[pre[i]][i] -= minflow; //正向減流
            map[i][pre[i]] += minflow; //反向加流
        }
        maxflow += minflow;
    }

    return maxflow;
}
int main()
{
    freopen("uva-820-InternetBandwidth.in", "r", stdin);
    freopen("uva-820-InternetBandwidth.out", "w", stdout);

    int n;
    int test = 1;
    while (cin >> n && n != 0)
    {
        memset(map, 0, sizeof(map));
        int s, t, c;
        cin >> s >> t >> c;
        for (int i = 0; i < c; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            map[a][b] += w;
            map[b][a] += w;
        }
        cout << "Network " << test << endl
             << "The bandwidth is " << ek(s, t, n) << '.' << endl;
        test++;
        cout << endl;
    }
    return 0;
}