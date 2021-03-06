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
        
        int maxN = 0;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            maxN = max(maxN, a[i]);
        }

        //sort(a.begin(), a.end(), greater<int>());

        vector<int> cum(maxN + 1, 0);
        for (auto x:a) ++cum[x];
        for (int x = 1; x <= maxN; ++x) cum[x] += cum[x - 1];

        auto getCum=[&](int x)
        {
            if (x > maxN) return cum[maxN];
            else          return cum[x];
        };

        ill ans = 0;
        for (int x = 1; x <= maxN; ++x)
        {
            vector<int> nowCums = {0};
            for (int t = 1; t * x <= maxN; ++t)
                nowCums.push_back(getCum(x * (t + 1) - 1) - getCum(x * t - 1));

            vector<int> odds;
            for (int t = 1, sizC = nowCums.size(); t <= sizC - 1; ++t)
                if (nowCums[t] % 2 == 1) odds.push_back(t);

            bool flg = false;
            if (odds.size() == 1)
                if (odds[0] == 1) flg = true;
            if (odds.size() == 2)
                if (odds[1] - odds[0] == 1) flg = true;
            if (flg) ans += nowCums[odds.back()];
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