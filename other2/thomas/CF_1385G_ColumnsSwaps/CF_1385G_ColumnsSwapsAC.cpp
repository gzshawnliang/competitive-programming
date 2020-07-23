#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char * name, Arg1 && arg1)
{
    cout << name << ":" << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char * names, Arg1 && arg1, Args &&... args)
{
    const char * comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << ":" << arg1 << " |";
    __f(comma + 1, args...);
}

const int N = 100005;

struct dsu
{
    vector<int> p, sz;
    dsu(int n)
    {
        sz.clear();
        p.clear();
        p.resize(n);
        sz.resize(n, 0);
        for (int i = n / 2; i < n; i++)
            sz[i] = 1;
        iota(p.begin(), p.end(), 0);
    }
    int get(int x)
    {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y)
        {
            if (y > x)
                swap(x, y);
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
        }
    }
};

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int a[2][n];
    vector<P> idx[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[0][i];
        a[0][i]--;
        idx[a[0][i]].pb({0, i});
    }
    for (i = 0; i < n; i++)
    {
        cin >> a[1][i];
        a[1][i]--;
        idx[a[1][i]].pb({1, i});
    }
    for (i = 0; i < n; i++)
    {
        if (idx[i].size() != 2)
        {
            cout << -1 << '\n';
            return;
        }
    }
    dsu G(2 * n);
    for (i = 0; i < n; i++)
    {
        int r1 = idx[i][0].F, r2 = idx[i][1].F, c1 = idx[i][0].S, c2 = idx[i][1].S;
        if (c1 == c2)
            continue;
        if (r1 == r2)
        {
            G.unite(c1, c2 + n);
            G.unite(c2, c1 + n);
        }
        else
        {
            G.unite(c1, c2);
            G.unite(c1 + n, c2 + n);
        }
    }
    vector<int> res, comp[2 * n];
    for (i = 0; i < 2 * n; i++)
    {
        comp[G.get(i)].pb(i);
        // db(i, G.get(i));
    }
    int vis[n * 2] = {};
    for (i = 0; i < n; i++)
    {
        if (a[0][i] == a[1][i])
            continue;
        if (vis[G.get(i)])
            continue;
        if (vis[G.get(i + n)])
            continue;
        vis[G.get(i)] = 1;
        vis[G.get(i + n)] = 1;
        if (G.get(i) == i)
        {
            ans += min(G.sz[i], G.sz[G.get(i + n)]);
            if (G.sz[i] <= G.sz[G.get(i + n)])
            {
                for (auto x : comp[i])
                {
                    if (x >= n)
                        res.pb(x - n);
                }
            }
            else
            {
                for (auto x : comp[G.get(i + n)])
                {
                    if (x >= n)
                        res.pb(x - n);
                }
            }
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    cout << ans << '\n';
    for (auto x : res)
        cout << x + 1 << " ";
    cout << '\n';
    return;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_1385G_ColumnsSwaps.in", "r", stdin);
    //freopen("CF_1385G_ColumnsSwaps.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}