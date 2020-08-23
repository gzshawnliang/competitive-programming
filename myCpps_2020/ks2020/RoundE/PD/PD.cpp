#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);               \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
    const int inf = INT_MAX / 10;

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m, s, r; cin >> n >> m >> s >> r;
            vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));

            for (int c = 1; c <= m; ++c)
            {
                int u, v; cin >> u >> v;
                d[u][v] = 1; d[v][u] = 1;
            }

            for (int k = 1; k <= n; ++k)
            {
                for (int u = 1; u <= n; ++u)
                {
                    for (int v = 1; v <= n; ++v)
                    {
                        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                    }
                }
            }

            vector<vector<int>> stoneL(s + 1);
            for (int u = 1; u <= n; ++u)
            {
                int tol; cin >> tol;
                for (int c = 1; c <= tol; ++c)
                {
                    int st; cin >> st;
                    stoneL[st].push_back(u);
                }
            }

            vector<vector<vector<int>>> stoneR(s + 1);
            for (int c = 1; c <= r; ++c)
            {
                int tol; cin >> tol;
                vector<int> tmp;
                for (int c = 1; c <= tol; ++c)
                {
                    int st; cin >> st;
                    tmp.push_back(st);
                }

                int resSt; cin >> resSt;

                stoneR[resSt].push_back(tmp);
            }

            for (int __s = 0; __s == 0; ++__s);
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PD.in", "r", stdin);
    freopen("PD.out", "w", stdout);
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