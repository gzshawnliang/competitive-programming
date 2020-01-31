/*
===========================================================
* @Name:           1153D Serval and Rooted Tree
* @Author:         Shawn
* @create Time:    2020/1/31 15:29:12
* @url:            https://codeforces.com/contest/1153/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int rot = 1;

void dfs(int u, vector<int> &f, vector<int> &typ, vector<vector<int>> &g)
{
    int siz = g[u].size();

    if (siz == 0)
    {
        f[u] = 1;
        return;
    }

    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        dfs(v, f, typ, g);
        
        if (typ[u] == 1) f[u] = min(f[u], f[v]);
        else             f[u] += f[v];
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> typ(n + 1, 0);
    for (int u = 1; u <= n; ++u) cin >> typ[u];

    vector<vector<int>> g(n + 1);
    for (int v = 2; v <= n; ++v)
    {
        int u; cin >> u;

        g[u].push_back(v);
    }

    int k = 0;
    for (int u = 1; u <= n; ++u) k += (g[u].size() == 0);

    vector<int> f(n + 1, 0);
    for (int u = 1; u <= n; ++u)
    {
        if (typ[u] == 1) f[u] = k;
    }
    dfs(rot, f, typ, g);

    cout << k - f[rot] + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1153D_ServalandRootedTree.in", "r", stdin);
        freopen("CF_1153D_ServalandRootedTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}