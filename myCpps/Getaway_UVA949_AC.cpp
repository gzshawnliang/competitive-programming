#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX /2;

struct node
{
    int X;
    int Y;
    int T;
    
    node(int x, int y,int t)
    {
        X=x;
        Y=y;
        T=t;
    }    
};


//int dd[105][105][4];
int main()
{
    int n=0, m=0, q;
    int i, j;
    int sx, sy, ex, ey, tx=0, ty=0, tt;
    int x, y, time;

    freopen("getaway_UVA949.in", "r", stdin);
    freopen("getaway_UVA949.out", "w", stdout);

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    
    while (true)
    {
        cin >> n >> m;

        if (!cin.good())
        {
            break;
        }

        //不允许通过的路
        vector<vector<vector<int>>> dd(n+1,vector<vector<int>>(m+1,vector<int>(4,1)));
        vector<vector<set<int>>> monitor(n+1,vector<set<int>>(m+1));
        
        cin >> q;

        while (q--)
        {
            cin >> sx >> sy >> ex >> ey;
            
            for (j = 0; j < 4; j++)
            {
                tx = sx + dx[j], ty = sy + dy[j];
                
                if (tx == ex && ty == ey)
                {
                    dd[sx][sy][j] = 0; //can't allow
                }
            }
        }
        cin >> q;
        while (q--)
        {
            cin >> time  >> sx >> sy;
            monitor[sx][sy].insert(time);
        }

        if (n == 1 && m == 1)
        {
            cout <<"0\n";
            continue;
        }

        queue<node> q;
        q.push(node(0,0,0));

        
        vector<vector<int>> dist(n+1,vector<int>(m+1,INF)); //dist[x][y]代表到达x,y最小时间
        // int dist[105][105] = {};
        // memset(dist, 63, sizeof(dist));

        dist[0][0] = 0;


        while (!q.empty())
        {

            x = q.front().X;
            y = q.front().Y;
            time = q.front().T;
            q.pop();

            ++time;

            for (i = 0; i < 4; ++i)
            {
                if (dd[x][y][i] == 0)
                {
                    continue;
                }

                tx = x + dx[i];
                ty = y + dy[i];

                if (tx < 0 || ty < 0 || tx >= n || ty >= m)
                {
                    continue;
                }
                tt = time;

                //while (monitor[tx][ty].find(tt) != monitor[tx][ty].end())
                while (monitor[tx][ty].count(tt) != 0)
                {
                    ++tt;
                }

                if (tt < dist[tx][ty])
                {
                    dist[tx][ty] = tt;
                    q.push(node(tx,ty,tt));
                }
            }
        }
        cout << dist[n - 1][m - 1] << '\n';
    }
    return 0;
}