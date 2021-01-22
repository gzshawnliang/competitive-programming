#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:
    const int root = 1;

    vector<vector<int>> g;
    vector<int> fat, tolSonOrg;

    void dfs(int u, int las)
    {
        for (int v:g[u])
        {
            if (v == las) continue;
            dfs(v, u);
            fat[v] = u;
            tolSonOrg[u] += tolSonOrg[v];
        }
    }

    void solve()
    {
        int n; cin >> n;

        g = vector<vector<int>>(n + 1);
        for (int c = 1; c <= n - 1; ++c)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        fat = vector<int>(n + 1, 0);
        tolSonOrg = vector<int>(n + 1, 1);
        dfs(root, 0);

        for (int k = 1; k <= n; ++k)
        {
            if (n % k > 0) continue;

            
        }
    }
};

signed main()
{
    FastIO;

//#ifdef LOCAL_DEBUG
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    //auto startTime = chrono::high_resolution_clock::now();
//#endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifdef LOCAL_DEBUG
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
//          << " ms\n";
// #endif

    return 0;
}