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
    void dfs(int u, int power, ill res, vector<vector<int>> &a)
    {
        if (u == 0)
        {
            ans = max(ans, res);
        }

        for (int v = 0; v <= n - 1; ++v)
        {
            if (u == v) continue;

            int tmpVal = vals[u];
            vals[u] = 0ll;
            if (a[u][v] == 1)
            {
                a[u][v] = 0;
                a[v][u] = 0;
                dfs(v, power, res + tmpVal, a);
                a[u][v] = 1;
                a[v][u] = 1;
            }
            else if (power > 0)
            {
               dfs(v, power - 1, res + tmpVal, a);
            }
            vals[u] = tmpVal;
        }
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int k; cin >> n >> k;
            vals = vector<ill>(n, 0);
            for (auto &x:vals) cin >> x;
            vector<vector<int>> a(n, vector<int>(n, 0));
            for (int c = 1; c <= n - 1; ++c)
            {
                int u, v; cin >> u >> v;
                --u; --v;
                a[u][v] = 1; a[v][u] = 1; 
            }

            ans = 0;
            dfs(0, k, 0, a);

            cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C2.in", "r", stdin);
    freopen("C2.txt", "w", stdout);
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