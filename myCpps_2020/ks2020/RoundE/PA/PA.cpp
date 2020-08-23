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
  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            vector<int> f(n - 1, 0);
            for (int i = 0; i <= n - 2; ++i) f[i] = a[i + 1] - a[i];

            int len = 1, ans = 1;
            for (int i = 1; i <= n - 2; ++i)
            {
                if (f[i] == f[i - 1]) ++len;
                else                  len = 1;

                ans = max(ans, len);
            }

            cout << "Case #" << tcc << ": " << ans + 1 << '\n'; 
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PA.in", "r", stdin);
    freopen("PA.out", "w", stdout);
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