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
            ill n, m; cin >> n >> m;

            vector<map<ill, ill>> mmp(n + 1);
            vector<vector<ill>> a(n + 1, vector<ill>(m, 0));
            for (int y = 0; y <= n; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    cin >> a[y][x];
                    ++mmp[y][a[y][x]];
                }
            }

            map<ill, ill> mapMaxOc, mapMinOc, mapTotOc;
            for (int y = 0; y <= n; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    ++mapTotOc[a[y][x]];
                    mapMaxOc[a[y][x]] = 0;
                    mapMinOc[a[y][x]] = (n + 1) * m;
                }
            }
                

            for (int y = 0; y <= n; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    mapMaxOc[a[y][x]] = max(mapMaxOc[a[y][x]], mmp[y][a[y][x]]);
                    mapMinOc[a[y][x]] = min(mapMinOc[a[y][x]], mmp[y][a[y][x]]);
                }
            }

            vector<map<ill, ill>> tmmp = mmp;

            ill save = 0LL, cntOther = 0LL;
            vector<ill> waste = a[0];
            for (int y = 1; y <= n; ++y)
            {
                for (int i = 0; i <= waste.size() - 1 && !waste.empty(); ++i)
                {
                    if (mmp[y][waste[i]] == 0)
                    {
                        waste.erase(waste.begin() + i); --i;
                    }
                }

                for (int x = 0; x <= m - 1; ++x)
                {
                    if (tmmp[y - 1][a[y][x]] > 0)
                    {
                        --tmmp[y - 1][a[y][x]];
                        ++save;
                    }
                    else
                    {
                        ++cntOther;
                    }
                }
            }

            set<ill> ws;
            for (auto &x : waste) ws.insert(x);

            for (auto &x : ws)
            {
                ill bar = mapMinOc[x], out = mapTotOc[x] - bar * (n + 1);

                if (out < bar)
                {
                    save = max(0LL, save - max(1LL, bar - 1));
                }
            }

            cout << "Case #" << tcc << ": " << (n - 1) * m - save << '\n';
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