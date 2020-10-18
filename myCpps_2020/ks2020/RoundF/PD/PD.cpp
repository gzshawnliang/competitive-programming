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
    ill allV, allC;
    vector<ill> time;

    void dfs(vector<ill> a, ill ans)
    {
        if (a.size() == 1)
        {
            ++allC;
            allV += ans;
            return;
        }

        for (ill i = 0; i <= a.size() - 2; ++i)
        {
            vector<ill> tmp = a;

            ill v = a[i + 1] + a[i];
            tmp[i + 1] += a[i];
            tmp.erase(tmp.begin() + i);

            dfs(tmp, ans + v);
        }
    }

    void solve()
    {
        cout << fixed << setprecision(10);

        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            vector<ill> a(n);
            for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

            allV = 0; allC = 0;
            time = vector<ill>(n, 0);

            dfs(a, 0);
            
            cout << "Case #" << tcc << ": " << (double)allV / (double)allC << '\n';
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