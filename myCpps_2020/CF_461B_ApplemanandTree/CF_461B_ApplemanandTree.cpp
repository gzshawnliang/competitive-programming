/*
===========================================================
* @Name:           461B Appleman and Tree
* @Author:         Shawn
* @create Time:    2020/1/24 14:19:43
* @url:            https://codeforces.com/contest/461/problem/B
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill mod = 1e9 + 7;

void dfs(ill u, ill las, vector<ill> &color, vector<vector<ill>> &f, vector<vector<ill>> &g)
{
    f[u][0] = 1;
    f[u][1] = 0;

    ill siz = g[u].size();
    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill v = g[u][i];

        if (v != las)
        {
            dfs(v, u, color, f, g);

            f[u][1] = (f[u][1] * f[v][0]) % mod;
            f[u][1] = (f[u][1] + f[u][0] * f[v][1]) % mod;
            f[u][0] = (f[u][0] * f[v][0]) % mod;
        }
    }

    if (color[u] == 1)
    {
        f[u][1] = f[u][0];
    }
    else
    {
        f[u][0] = (f[u][0] + f[u][1]) % mod;
    }
}

void solve()
{
    ill n; cin >> n;

    vector<vector<ill>> g(n);
    for (ill u = 1; u <= n - 1; ++u)
    {
        ill v; cin >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ill> color(n, 0);
    for (ill u = 0; u <= n - 1; ++u)
    {
        cin >> color[u];
    }

    vector<vector<ill>> f(n, vector<ill>(2, 0));
    dfs(0, -1, color, f, g);

    cout << f[0][1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_461B_ApplemanandTree.in", "r", stdin);
        freopen("CF_461B_ApplemanandTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}