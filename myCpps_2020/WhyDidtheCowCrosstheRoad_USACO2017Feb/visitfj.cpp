#include <bits/stdc++.h>

using namespace std;

ifstream fin("visitfj.in");
ofstream fout("visitfj.out");

const int inf = INT_MAX / 2, mod = 3;

struct item
{
    int y;
    int x;
    int cd;
    int cg;

    bool operator<(const item & temp) const
    {
        return cd > temp.cd;
    }
};
item make_item(int y, int x, int cd, int cg)
{
    item temp{y, x, cd, cg}; return temp;
}

int main()
{
    vector<int> yp = {1, 0, -1, 0},
                xp = {0, 1, 0, -1};
                

    int n, t; fin >> n >> t;

    vector<vector<int>> a(n + 2, vector<int>(n + 2, -1));
                        

    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
        {
            fin >> a[y][x];
        }
    }

    queue<item> q; q.push(make_item(1, 1, 0, 0));
    vector<vector<vector<int>>> dis(n + 2, vector<vector<int>>(n + 2, vector<int>(mod, inf)));
    dis[0][0][0] = 0;

    while (q.empty() == false)
    {
        item now = q.front(); q.pop();

        for (int p = 0; p <= 3; ++p)
        {
            item next;
            next.y = now.y + yp[p];
            next.x = now.x + xp[p];

            if (a[next.y][next.x] == -1) continue;

            next.cg = (now.cg + 1) % mod;

            next.cd = now.cd + t;
            if (next.cg == 0) next.cd += a[next.y][next.x];

            if (next.cd >= dis[next.y][next.x][next.cg]) continue;

            dis[next.y][next.x][next.cg] = next.cd;
            q.push(next);
        }
    }

    int ans = inf;
    for (int t = 0; t <= mod - 1; ++t)
    {
        ans = min(ans, dis[n][n][t]);
    }

    fout << ans << '\n';

    return 0;
}
