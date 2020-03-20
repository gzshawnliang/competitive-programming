#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = INT_MAX / 2, rot = 1;

void dfs(int u, int k, vector<vector<int>> &g, vector<int> &f, vector<int> &bac, vector<int> &dis)
{
    for (auto v:g[u])
    {
        dfs(v, k, g, f, bac, dis);

        dis[u] = min(dis[u], dis[v] + 1);

        bac[u] += bac[v];
        f[u] = max(f[u], f[v] - bac[v]);
    }

    if (dis[u] == inf)
    {
        dis[u] = 0; f[u] = 1; bac[u] = 1;
    }
    else
    {
        f[u] += bac[u];

        if (dis[u] >= k) bac[u] = 0;
    }
}

void solve()
{
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n + 1);
    for (int u = 2; u <= n; ++u)
    {
        int las; cin >> las;
        g[las].push_back(u);
    }

    vector<int> f(n + 1, 0), bac(n + 1, 0), dis(n + 1, inf);
    dfs(rot, k, g, f, bac, dis);

    cout << f[rot] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1065F_UpandDowntheTree.in", "r", stdin);
        freopen("CF_1065F_UpandDowntheTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}