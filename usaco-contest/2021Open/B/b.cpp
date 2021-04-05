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
    vector<int> f;

    int fnd(int x)
    {
        if (f[x] == x) return x;
        else return f[x] = fnd(f[x]);
    }

    void solve()
    {
        int n; cin >> n;

        f = vector<int>(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) f[i] = i;

        vector<tuple<int, int, int, int, int>> allR(n);
        for (auto &[c, a1, a2, a3, a4]:allR)
        {
            cin >> c >> a1 >> a2 >> a3 >> a4;

            f[fnd(a1)] = fnd(a2);
            f[fnd(a3)] = fnd(a4);
        }

        unordered_set<int> tmpSt;
        for (int i = 1; i <= 2 * n; ++i)
            tmpSt.insert(fnd(i));

        int tolG = tmpSt.size(), ans = 0;
        sort(allR.begin(), allR.end());
        for (int i = 0; i <= n - 1; ++i)
        {
            if (fnd(get<2>(allR[i])) == fnd(get<3>(allR[i]))) continue;
            f[fnd(get<2>(allR[i]))] = fnd(get<3>(allR[i]));

            ans += get<0>(allR[i]);
            --tolG;

            if (tolG == 1) break;
        }
        cout << ans << '\n';

        // for (int i = 1; i <= 2 * n; ++i)
        //     cout << i << ": " << fnd(i) << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
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