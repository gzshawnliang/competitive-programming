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
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            vector<vector<ill>> a(n, vector<ill>(n, 0));
            for (ill y = 0; y <= n - 1; ++y)
            {
                for (ill x = 0; x <= n - 1; ++x)
                {
                    cin >> a[y][x];
                }
            }

            ill ans = 0;
            for (ill x = 0; x <= n - 1; ++x)
            {
                ill nowY = 0, nowX = x, tmp = 0;
                while (nowY <= n - 1 && nowX <= n - 1)
                {
                    tmp += a[nowY][nowX];
                    ++nowY; ++nowX;
                }

                ans = max(ans, tmp);
            }

            for (ill y = 0; y <= n - 1; ++y)
            {
                ill nowY = y, nowX = 0, tmp = 0;
                while (nowY <= n - 1 && nowX <= n - 1)
                {
                    tmp += a[nowY][nowX];
                    ++nowY; ++nowX;
                }

                ans = max(ans, tmp);
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PB.in", "r", stdin);
    freopen("PB.out", "w", stdout);
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