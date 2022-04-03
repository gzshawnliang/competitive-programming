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
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            vector<ill> a(n);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];
            sort(a.begin(), a.end());

            queue<pair<ill, ill>> stk;
            for (int i = 0; i <= n - 1; ++i)
            {
                a[i] -= (i + 1);
                if (a[i] < 0) stk.push({a[i], i});
            }
            stk.push({LONG_LONG_MIN, n});

            ill delta = 0, ans = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                ans = max(ans, stk.front().second - i);

                ++delta;
                while (stk.front().first >= -delta) stk.pop();
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
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