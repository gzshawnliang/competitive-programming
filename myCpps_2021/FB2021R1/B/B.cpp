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
            int n, m, A, B; cin >> n >> m >> A >> B;

            cout << "Case #" << tcc << ": ";
            if (A - n - m + 2 < 1 || B - n - m + 2 < 1)
            {
                cout << "Impossible\n";
                continue;
            }

            cout << "Possible\n";
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    if (x > 0) cout << ' ';
                    if (x == 0 && y == 0)
                    {
                        cout << A - n - m + 2;
                    }
                    else if (x == m - 1 && y == 0)
                    {
                        cout << B - n - m + 2;
                    }
                    else
                    {
                        cout << 1;
                    }
                }
                cout << '\n';
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.txt", "w", stdout);
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