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
  private:
    int n;
    ill ans;
    vector<ill> vals;
    vector<vector<int>> a;

    ill dfs(int u, int las)
    {
        ill res = vals[u];
        for (int v = 0; v <= n - 1; ++v)
            if (a[u][v] == 1 && v != u && v != las)
                res = max(res, vals[u] + dfs(v, u));

        return res;
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            cin >> n;
            vals = vector<ill>(n, 0);
            for (auto &x:vals) cin >> x;
            a = vector<vector<int>>(n, vector<int>(n, 0));
            for (int c = 1; c <= n - 1; ++c)
            {
                int u, v; cin >> u >> v;
                --u; --v;
                a[u][v] = 1; a[v][u] = 1; 
            }

            vector<int> allAns;
            for (int v = 1; v <= n - 1; ++v)
                if (a[0][v] == 1)
                    allAns.push_back(dfs(v, 0));
            sort(allAns.begin(), allAns.end());

            ill ans = vals[0], sizA = allAns.size();
            if (sizA >= 1) ans += allAns[sizA - 1];
            if (sizA >= 2) ans += allAns[sizA - 2];

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C1.in", "r", stdin);
    freopen("C1.txt", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}