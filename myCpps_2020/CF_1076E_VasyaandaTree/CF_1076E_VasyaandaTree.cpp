/*
===========================================================
* @Name:           1076E Vasya and a Tree
* @Author:         Shawn
* @create Time:    2020/3/26 23:19:20
* @url:            https://codeforces.com/contest/1076/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill inf = INT_MAX / 2, rot = 1;

class fenwickTree
{
    private:

    ill lowbit(ill x)
    {
        return x & (-x);
    }

    public:

    vector<ill> a;
    vector<ill> s;

    fenwickTree(vector<ill> & in)
    {
        ill n = in.size();

        a.assign(n, 0);
        s.assign(n, 0);
    }

    void update(ill k, ill delta)
    {
        ill n = s.size() - 1;

        a[k] += delta;

        for (ill i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    ill query(ill k)
    {
        ill ans = 0;

        for (ill i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    ill sum(ill i, ill j)
    {
        return query(j) - query(i - 1);
    }
};

void dfs1(ill u, ill las, vector<vector<ill>> &g, vector<ill> &depth, vector<ill> &maxDepth)
{
    ill siz = g[u].size();
    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill v = g[u][i];
        if (v == las) continue;

        depth[v] = depth[u] + 1;
        dfs1(v, u, g, depth, maxDepth);

        maxDepth[u] = max(maxDepth[u], maxDepth[v]);
    }

    if (siz == 1 && u != rot)
    {
        maxDepth[u] = depth[u];
    }
}

void dfs2(ill u, ill las, vector<ill> &depth, fenwickTree &tre, vector<vector<ill>> &g, vector<vector<pair<ill, ill>>> &qs, vector<ill> &values)
{
    ill sizG = g[u].size(), sizQ = qs[u].size();

    for (ill j = 0; j <= sizQ - 1; ++j)
    {
        tre.update(depth[u] + 1, qs[u][j].second);
        tre.update(depth[u] + qs[u][j].first + 1, -qs[u][j].second);
    }

    for (ill i = 0; i <= sizG - 1; ++i)
    {
        ill v = g[u][i];
        if (v == las) continue;
        
        dfs2(v, u, depth, tre, g, qs, values);
    }

    for (ill j = 0; j <= sizQ - 1; ++j)
    {
        tre.update(depth[u] + 1, -qs[u][j].second);
        tre.update(depth[u] + qs[u][j].first + 1, qs[u][j].second);
    }

    for (ill j = 0; j <= sizQ - 1; ++j) values[u] += qs[u][j].second;

    values[u] += tre.query(depth[u]);
}

void solve()
{
    ill n; cin >> n;
        vector<vector<ill>> g(n + 1);
    for (ill c = 1; c <= n - 1; ++c)
    {
        ill u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<ill> depth(n + 1, 1), maxDepth(n + 1, 0);
    dfs1(rot, 0, g, depth, maxDepth);

    ill m; cin >> m;
        vector<vector<pair<ill, ill>>> qs(n + 1);
    for (ill c = 1; c <= m; ++c)
    {
        ill u, d, x; cin >> u >> d >> x;
        qs[u].push_back({min(d, maxDepth[u] - depth[u]), x});
    }

    vector<ill> add(n + 5, 0), values(n + 1, 0);
        fenwickTree tre(add);
    dfs2(rot, 0, depth, tre, g, qs, values);

    for (ill u = 1; u <= n; ++u)
    {
        if (u > 1) cout << ' ';
        cout << values[u];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1076E_VasyaandaTree.in", "r", stdin);
        freopen("CF_1076E_VasyaandaTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}