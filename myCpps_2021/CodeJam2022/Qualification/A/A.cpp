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
            int n, m; cin >> n >> m;

            cout << "Case #" << tcc << ":\n";
            
            cout << "..";
            for (int x = 0; x <= m - 2; ++x)
                cout << "+-";
            cout << "+\n";

            cout << "..";
            for (int x = 0; x <= m - 2; ++x)
                cout << "|.";
            cout << "|\n";

            for (int c = 1; c <= n - 1; ++c)
            {
                for (int x = 0; x <= m - 1; ++x)
                    cout << "+-";
                cout << "+\n";
                for (int x = 0; x <= m - 1; ++x)
                    cout << "|.";
                cout << "|\n";
            }
            for (int x = 0; x <= m - 1; ++x)
                cout << "+-";
            cout << "+\n";
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