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
            vector<int> a(n, 0);
            for (auto &x:a) cin >> x;

            int i = 0, j = n - 1, maxD = 0, ans = 0;
            while (i <= j)
            {
                while (a[i] < maxD && i <= j) ++i;
                while (a[j] < maxD && i <= j) --j;
                if (i > j) break;

                if (a[i] < a[j])
                {
                    maxD = a[i];
                    ++i;
                    ++ans;
                }
                else
                {
                    maxD = a[j];
                    --j;
                    ++ans;
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
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
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