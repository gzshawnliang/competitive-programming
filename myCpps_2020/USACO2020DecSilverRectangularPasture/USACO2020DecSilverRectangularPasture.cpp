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

        set<int> allN;
        vector<pair<int, int>> a(n);
        // for (auto & [x, y]:a)
        // {
        //     cin >> x >> y;
        //     allN.insert(x); allN.insert(y);
        // }
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].first >> a[i].second;
            allN.insert(a[i].first); allN.insert(a[i].second);
        }

        int maxN = 1;
        map<int, int> mp;
        for (auto x:allN) mp[x] = maxN++;

        vector<vector<int>> f(maxN, vector<int>(maxN, 0));
        // for (auto & [x, y]:a)
        // {
        //     x = mp[x]; y = mp[y];
        //     f[y][x] = 1;
        // }
        for (int i = 0; i <= n - 1; ++i)
        {
            a[i].first = mp[a[i].first]; a[i].second = mp[a[i].second];
            f[a[i].second][a[i].first] = 1;
        }

        for (int y = 1; y <= maxN - 1; ++y)
        {
            for (int x = 1; x <= maxN - 1; ++x)
            {
                f[y][x] += (f[y - 1][x] + f[y][x - 1] - f[y - 1][x - 1]);
            }
        }

        auto getTol=[&](int y1, int x1, int y2, int x2)
        {
            return f[y2][x2] - f[y2][x1 - 1] - f[y1 - 1][x2] + f[y1 - 1][x1 - 1];
        };

        ill ans = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i; j <= n - 1; ++j)
            {
                int minY = min(a[i].second, a[j].second),
                    maxY = max(a[i].second, a[j].second),
                    minX = min(a[i].first, a[j].first),
                    maxX = max(a[i].first, a[j].first);
                ans += (ill)getTol(minY, 1, maxY, minX) * (ill)getTol(minY, maxX, maxY, maxN - 1);
            }
        }

        cout << ans + 1LL << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("USACO2020DecSilverRectangularPasture.in", "r", stdin);
    freopen("USACO2020DecSilverRectangularPasture.out", "w", stdout);
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