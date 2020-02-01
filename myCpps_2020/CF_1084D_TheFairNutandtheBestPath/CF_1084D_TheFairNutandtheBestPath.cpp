/*
===========================================================
* @Name:           1084D The Fair Nut and the Best Path
* @Author:         Shawn
* @create Time:    2020/2/1 17:56:54
* @url:            https://codeforces.com/contest/1084/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ill = long long;

ill rot = 1;

void dfs(ill u, ill las, ill &ans, vector<ill> &f, vector<ill> &val, vector<vector<pair<ill, ill>>> &g)
{
    f[u] = val[u];

    ill siz = g[u].size(), max1 = 0, max2 = 0;
    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill v = g[u][i].first, d = g[u][i].second;
        if (v == las) continue;

        dfs(v, u, ans, f, val, g);

        if (f[v] >= d)
        {
            f[u] = max(f[u], f[v] - d + val[u]);

            if (f[v] - d > max1)
            {
                max2 = max1;
                max1 = f[v] - d;
            }
            else if (f[v] - d > max2)
            {
                max2 = f[v] - d;
            }
        }
    }

    ans = max(ans, f[u]);
    ans = max(ans, max1 + max2 + val[u]);
}

void solve()
{
    ill n; cin >> n;

    vector<ill> val(n + 1, 0);
    for (ill i = 1; i <= n; ++i) cin >> val[i];

    vector<vector<pair<ill, ill>>> g(n + 1);
    for (ill c = 1; c <= n - 1; ++c)
    {
        ill u, v, d; cin >> u >> v >> d;

        g[u].push_back({v, d}); g[v].push_back({u, d});
    }

    ill ans = 0;
    vector<ill> f(n + 1, 0);
    dfs(rot, 0, ans, f, val, g);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE    //Submit to OJ in standard input/output,debug in local .in/.out file
        freopen("CF_1084D_TheFairNutandtheBestPath.in", "r", stdin);
        freopen("CF_1084D_TheFairNutandtheBestPath.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}