#include <bits/stdc++.h>

using namespace std;

int dd[105][105][4];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {

    freopen("getaway_UVA949.in", "r", stdin);
    freopen("getaway_UVA949.out", "w", stdout);

    int n, m, q;
    int i, j, k;
    int sx, sy, ex, ey, tx, ty, tt;
    int x, y, time;
    while(scanf("%d %d", &n, &m) == 2) {
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                for(k = 0; k < 4; k++)
                    dd[i][j][k] = 1;
        set<int> monitor[105][105];
        scanf("%d", &q);
        while(q--) {
            scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
            for(j = 0; j < 4; j++) {
                tx = sx+dx[j], ty = sy+dy[j];
                if(tx == ex && ty == ey)
                    dd[sx][sy][j] = 0;//can'c allow
            }
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d %d %d", &time, &sx, &sy);
            monitor[sx][sy].insert(time);
        }
        queue<int> X, Y, T;
        X.push(0), Y.push(0), T.push(0);
        int dist[105][105] = {};
        memset(dist, 63, sizeof(dist));
        dist[0][0] = 0;
        if(n == 1 && m == 1) {
            puts("0");
            continue;
        }
        while(!X.empty()) {
            x = X.front(), X.pop();
            y = Y.front(), Y.pop();
            time = T.front(), T.pop();
            time++;
            for(i = 0; i < 4; i++) {
                if(dd[x][y][i] == 0)    continue;
                tx = x+dx[i], ty = y+dy[i];
                if(tx < 0 || ty < 0 || tx >= n || ty >= m)
                    continue;
                tt = time;
                while(monitor[tx][ty].find(tt) != monitor[tx][ty].end())
                    tt++;
                if(tt < dist[tx][ty]) {
                    dist[tx][ty] = tt;
                    X.push(tx), Y.push(ty), T.push(tt);
                }
            }
        }
        printf("%d\n", dist[n-1][m-1]);
    }
    return 0;
}