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
            vector<vector<int>> a(n, vector<int>(n, 0));
            for (int i = 0; i <= n - 1; ++i)
                for (int j = 0; j <= n - 1; ++j)
                    cin >> a[i][j];

            int trace = 0, reR = 0, reC = 0;
            for (int p = 0; p <= n - 1; ++p) trace += a[p][p];

            for (int i = 0; i <= n - 1; ++i)
            {
                bool flg = false;
                map<int, int> mp;
                for (int j = 0; j <= n - 1; ++j)
                {
                    if (mp.count(a[i][j]) > 0){flg = true; break;}
                    ++mp[a[i][j]];
                }

                if (flg) ++reR;
            }

            for (int j = 0; j <= n - 1; ++j)
            {
                bool flg = false;
                map<int, int> mp;
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (mp.count(a[i][j]) > 0){flg = true; break;}
                    ++mp[a[i][j]];
                }

                if (flg) ++reC;
            }

            cout << "Case #" << tcc << ": " << trace << ' ' << reR << ' ' << reC << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("Vestigium.in", "r", stdin);
    freopen("Vestigium.out", "w", stdout);
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