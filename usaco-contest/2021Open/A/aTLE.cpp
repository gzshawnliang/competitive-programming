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
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        ill ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            unordered_map<int, int> mp;
            ++mp[a[i]];
            for (int j = i + 1; j <= n; ++j)
            {
                ++mp[a[j]];

                if (mp[a[j]] > 1 || mp[a[i]] > 1)
                    continue;
                ++ans;
            }
        }

        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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