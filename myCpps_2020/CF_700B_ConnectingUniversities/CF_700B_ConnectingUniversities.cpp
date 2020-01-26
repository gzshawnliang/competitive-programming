/*
===========================================================
* @Name:           700B Connecting Universities
* @Author:         Shawn
* @create Time:    2020/1/26 0:33:38
* @url:            https://codeforces.com/contest/700/problem/B
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void dfs(ill u, ill v, ill &ans, ill k, vector<ill> &cfu, vector<vector<ill>> &g)
{
    ill siz = g[u].size();
    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill nex = g[u][i];

        if (nex != v)
        {
            dfs(nex, u, ans, k, cfu, g);

            ans += min(cfu[nex], 2 * k - cfu[nex]);

            cfu[u] += cfu[nex];
        }
    }
}

void solve()
{
    ill n, k; cin >> n >> k;

    vector<ill> cfu(n + 1, 0);
    for (ill c = 1; c <= 2 * k; ++c)
    {
        ill u; cin >> u;
        ++cfu[u];
    }
    
    vector<vector<ill>> g(n + 1);
    for (ill c = 1; c <= n - 1; ++c)
    {
        ill u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    ill ans = 0;
    dfs(1, 0, ans, k, cfu, g);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_700B_ConnectingUniversities.in", "r", stdin);
        freopen("CF_700B_ConnectingUniversities.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}