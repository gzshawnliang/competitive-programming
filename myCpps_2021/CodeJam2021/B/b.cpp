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

    const int inf = INT_MAX / 2;

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int cst12 = 0, cst21 = 0; cin >> cst12 >> cst21;
            string s; cin >> s; int n = s.size();
            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                if      (s[i] == '?') a[i] = 0;
                else if (s[i] == 'C') a[i] = 1;
                else                  a[i] = 2;
            }
            
            vector<vector<int>> f(n, vector<int>(3, inf));
                if (a[0] == 0)
                {
                    f[0][1] = 0; f[0][2] = 0;
                }
                else if (a[0] == 1) f[0][1] = 0;
                else                f[0][2] = 0;
            for (int i = 1; i <= n - 1; ++i)
            {
                if (a[i] == 0)
                {
                    f[i][1] = min(f[i - 1][2] + cst21, f[i - 1][1]);
                    f[i][2] = min(f[i - 1][1] + cst12, f[i - 1][2]);
                }
                else if (a[i] == 1)
                {
                    f[i][1] = min(f[i - 1][2] + cst21, f[i - 1][1]);
                }
                else
                {
                    f[i][2] = min(f[i - 1][1] + cst12, f[i - 1][2]);
                }
            }

            cout << "Case #" << tcc << ": " << min(f[n - 1][1], f[n - 1][2]) << '\n';
        }
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