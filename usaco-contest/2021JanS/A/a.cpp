#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
  public:
    vector<int> f;

    int fnd(int u)
    {
        if (f[u] == u) return u;
        else           return f[u] = fnd(f[u]);
    }
    
    void solve()
    {
        int n, tolL; cin >> n >> tolL;
        
        vector<int> a(n + 1, 0);
        f = vector<int>(n + 1, 0);
        vector<set<int>> ans(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            a[i] = i; f[i] = i;
            ans[i].insert(i);
        }

        for (int c = 1; c <= tolL; ++c)
        {
            int u, v; cin >> u >> v;
            swap(a[u], a[v]);
            ans[a[u]].insert(u);
            ans[a[v]].insert(v);
        }

        vector<int> nxt(n + 1, 0);
        for (int u = 1; u <= n; ++u)
        {
            nxt[u] = a[u];
        }

        vector<int> vis(n + 1, 0);
        for (int u = 1; u <= n; ++u)
        {
            if (vis[u] == 0)
            {
                vis[u] = 1;

                int tmp = nxt[u];
                while (tmp != u)
                {
                    f[fnd(tmp)] = fnd(u);
                    tmp = nxt[tmp];

                    vis[tmp] = 1;
                }
            }
        }

        for (int u = 1; u <= n; ++u)
        {
            ans[fnd(u)].insert(ans[u].begin(), ans[u].end());
        }

        for (int u = 1; u <= n; ++u)
        {
            cout << ans[fnd(u)].size() << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("a.in", "r", stdin);
//     freopen("a.out", "w", stdout);
//     auto startTime = std::chrono::high_resolution_clock::now();
// #endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifndef ONLINE_JUDGE
//     auto endTime = std::chrono::high_resolution_clock::now();
//     std::cerr << "Execution time: "
//               << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
//               << " ms\n";
// #endif

    return 0;
}