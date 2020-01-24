/*
===========================================================
* @Name:           337D Book of Evil
* @Author:         Shawn
* @create Time:    2020/1/21 22:48:50
* @url:            https://codeforces.com/contest/337/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = INT_MAX / 2;

void dfsNO1(int u, int las, vector<int> &dp1, vector<int> &dpm, vector<int> &fat, vector<int> &isAff, vector<vector<int>> &g)
{
    fat[u] = las;

    if (isAff[u] == 1) dp1[u] = 0;

    int maxDis = -1 * inf, siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (v != las)
        {
            dfsNO1(v, u, dp1, dpm, fat, isAff, g);

            dp1[u] = max(dp1[u], dp1[v] + 1);

            if (maxDis < dp1[v])
            {
                maxDis = dp1[v];

                dpm[u] = v;
            }
        }
    }
}

void dfsNO2(int u, int las, vector<int> &dp1, vector<int> &dpm, vector<int> &dp2, vector<int> &fat, vector<int> &isAff, vector<vector<int>> &g)
{
    if (isAff[u] == 1)  dp2[u] = 0;

    if (las != -1)
    {
        dp2[u] = max(dp2[u], dp2[las] + 1);

        if (dpm[las] == u)
        {
            int siz = g[las].size();
            for (int i = 0; i <= siz - 1; ++i)
            {
                int vfl = g[las][i];

                if (vfl != u && vfl != fat[las])
                {
                    dp2[u] = max(dp2[u], dp1[vfl] + 2);
                }
            }
        }
        else
        {
            dp2[u] = max(dp2[u], dp1[dpm[las]] + 2);
        }
    }

    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (v != las)
        {
            dfsNO2(v, u, dp1, dpm, dp2, fat, isAff, g);
        }
    }
}

void solve()
{
    int n, m, d; cin >> n >> m >> d;

    vector<int> isAff(n + 1, 0);
    vector<vector<int>> g(n + 1);

    for (int c = 1; c <= m; ++c)
    {
        int u; cin >> u;
        isAff[u] = 1;
    }

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }


    vector<int> dp1(n + 1, -1 * inf), dpm(n + 1, 0), fat(n + 1, -1);
    dfsNO1(1, -1, dp1, dpm, fat, isAff, g);

    vector<int> dp2(n + 1, -1 * inf);
    dfsNO2(1, -1, dp1, dpm, dp2, fat, isAff, g);

    int ans = 0;
    for (int u = 1; u <= n; ++u)
    {
        if (dp1[u] <= d && dp2[u] <= d)
        {
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_337D_BookofEvil.in", "r", stdin);
        freopen("CF_337D_BookofEvil.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}