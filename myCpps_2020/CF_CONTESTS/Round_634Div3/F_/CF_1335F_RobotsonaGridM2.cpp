/*
===========================================================
* @Name:           1335F Robots on a Grid
* @Author:         Shawn
* @create Time:    2020/4/23 23:07:07
* @url:            https://codeforces.com/contest/1335/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    vector<pair<int, int>> pls(256);
    pls['U'] = {0, -1};
    pls['D'] = {0, 1};
    pls['L'] = {-1, 0};
    pls['R'] = {1, 0};

    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
        int n, m; cin >> n >> m;

        // auto leg=[&](int x, int y)
        // {
        //     return x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1;
        // };

            vector<string> orgColors(n);
        for (int y = 0; y <= n - 1; ++y) cin >> orgColors[y];

            vector<int> colors(n * m);
        for (int y = 0; y <= n - 1; ++y)
            for (int x = 0; x <= m - 1; ++x)
                colors[y * m + x] = (orgColors[y][x] - '0');

            vector<string> orgForces(n);
        for (int y = 0; y <= n - 1; ++y) cin >> orgForces[y];

            int log2nm = log2(n * m) + 1;
            vector<vector<int>> f(n * m, vector<int>(log2nm + 1, -1));
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                int nxtX = x + pls[orgForces[y][x]].first, nxtY = y + pls[orgForces[y][x]].second;
                //if (leg(nxtX, nxtY))
                f[y * m + x][0] = nxtY * m + nxtX;
            }
        }

        for (int p = 1; p <= log2nm; ++p)
        {
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    f[y * m + x][p] = f[f[y * m + x][p - 1]][p - 1];
                }
            }
        }
        
        vector<int> isBlack(n * m, 0), hasBlock(n * m, 0);
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                hasBlock[f[y * m + x][log2nm]] = 1;
                if (colors[y * m + x] == 0) isBlack[f[y * m + x][log2nm]] = 1;
            }
        }

        int ans1 = 0, ans2 = 0;
        for (int u = 0; u <= n * m - 1; ++u)
        {
            if (hasBlock[u] == 1) ++ans1;
            if (isBlack[u] == 1) ++ ans2;
        }

        cout << ans1 << ' ' << ans2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1335F_RobotsonaGrid.in", "r", stdin);
        freopen("CF_1335F_RobotsonaGrid.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}