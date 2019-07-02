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


int main()
{

    freopen("getaway_UVA949.in", "r", stdin);
    freopen("getaway_UVA949.out", "w", stdout);

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    
    while (true)
    {
        int nv=0, nh=0;
        cin >> nv >> nh;

        if (!cin.good())
        {
            break;
        }

        //dd[x][y][z]代表xyz允许通过的路
        vector<vector<vector<int>>> dd(nv+1,vector<vector<int>>(nh+1,vector<int>(4,1)));

        //monitor[x][y]代表xy处的监视器时间，用唯一set表示
        vector<vector<set<int>>> monitor(nv+1,vector<set<int>>(nh+1));

        int r;
        cin >> r;

        while (r--)
        {
            int sx, sy, ex, ey;
            cin >> sx >> sy >> ex >> ey;
            
            for (int j = 0; j < 4; j++)
            {
                int tx = sx + dx[j];
                int ty = sy + dy[j];
                
                if (tx == ex && ty == ey)
                {
                    dd[sx][sy][j] = 0; //can't allow
                }
            }
        }
        int m;
        cin >> m;
        while (m--)
        {
            int sx, sy, time;
            cin >> time  >> sx >> sy;
            monitor[sx][sy].insert(time);
        }

        if (nv == 1 && nh == 1)
        {
            cout <<"0\n";
            continue;
        }

        queue<node> q;
        q.push(node(0,0,0));

        
        vector<vector<int>> dist(nv+1,vector<int>(nh+1,INF)); //dist[x][y]代表到达x,y最小时间
        // int dist[105][105] = {};
        // memset(dist, 63, sizeof(dist));

        dist[0][0] = 0;


        while (!q.empty())
        {

            int x = q.front().X;
            int y = q.front().Y;
            int time = q.front().T;
            q.pop();

            ++time;

            for (int i = 0; i < 4; ++i)
            {
                if (dd[x][y][i] == 0)
                {
                    continue;
                }

                int tx = x + dx[i];
                int ty = y + dy[i];

                if (tx < 0 || ty < 0 || tx >= nv || ty >= nh)
                {   //超出边界了
                    continue;
                }
                int tt = time;

                //查找tt是否在set里面。如果在则等待
                //while (monitor[tx][ty].find(tt) != monitor[tx][ty].end())
                while (monitor[tx][ty].count(tt) != 0)
                {
                    ++tt;
                }

                //当前时间小于已记录的最小时间
                if (tt < dist[tx][ty])
                {
                    dist[tx][ty] = tt;
                    q.push(node(tx,ty,tt));
                }
            }
        }
        cout << dist[nv - 1][nh - 1] << '\n';
    }
    return 0;
}