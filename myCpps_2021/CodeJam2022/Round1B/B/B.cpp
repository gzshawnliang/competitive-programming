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
    ill inf = LLONG_MAX / 3;

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, p; cin >> n >> p;

            vector<vector<ill>> a(n, vector<ill>(p, 0));
            for (int i = 0; i <= n - 1; ++i)
            {
                for (int j = 0; j <= p - 1; ++j)
                    cin >> a[i][j];
                sort(a[i].begin(), a[i].end());
            }

            vector<vector<ill>> f(n, vector<ill>(p, inf));
            for (int j = 0; j <= p - 1; ++j)
            {
                f[0][j] = a[0][p - 1] + (a[0][p - 1] - a[0][j]);
            }

            ill ans = inf;
            for (int i = 1; i <= n - 1; ++i)
            {
                for (int j = 0; j <= p - 1; ++j)
                {
                    for (int k = 0; k <= p - 1; ++k)
                    {
                        ill minD = inf;

                        if (a[i - 1][k] >= a[i][0])     minD = min(minD, (a[i - 1][k] - a[i][0]) + (a[i][p - 1] - a[i][0]) + (a[i][p - 1] - a[i][j]));
                        else                            minD = min(minD, (a[i][p - 1] - a[i - 1][k]) + (a[i][p - 1] - a[i][j]));

                        if (a[i - 1][k] <= a[i][p - 1]) minD = min(minD, (a[i][p - 1] - a[i - 1][k]) + (a[i][p - 1] - a[i][0]) + (a[i][j] - a[i][0]));
                        else                            minD = min(minD, (a[i - 1][k] - a[i][0]) + (a[i][j] - a[i][0]));

                        f[i][j] = min(f[i][j], f[i - 1][k] + minD);
                    }

                    if (i == n - 1) ans = min(ans, f[i][j]);
                }
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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