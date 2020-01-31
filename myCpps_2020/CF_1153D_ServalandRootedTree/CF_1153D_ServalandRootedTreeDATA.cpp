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

void dfs(int u, int las, vector<int> &f, vector<vector<int>> &g)
{
    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];
        if (v == las) continue;

        dfs(v, u, f, g);
        f[v] = u;
    }
}

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1153D_ServalandRootedTree.in_p", "r", stdin);
        freopen("CF_1153D_ServalandRootedTree.in", "w", stdout);
    #endif    

    int n; cin >> n; cout << n << '\n';
    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> f(n + 1, 0);
    dfs(rot, 0, f, g);

    for (int u = 1; u <= n; ++u)
    {
        if (u > 1) cout << ' ';
        cout << getRand(1, 2) - 1;
    }
    cout << '\n';

    for (int u = 2; u <= n; ++u)
    {
        if (u > 2) cout << ' ';
        cout << f[u];
    }
    cout << '\n';

    cout.flush();
    return 0;
}