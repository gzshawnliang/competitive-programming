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
    const ill inf = INT_MAX / 2;

    ill n;
    vector<ill> a;
    vector<vector<ill>> f;

    void solve()
    {
        cin >> n;
        a = vector<ill>(n + 1, 0);
        f = vector<vector<ill>>(n + 1, vector<ill>(n + 1, inf));
        for (ill i = 1; i <= n; ++i)
        {
            cin >> a[i];
            f[i][i] = 1;
        }

        for (ill l = 2; l <= n; ++l)
        {
            for(ill i = 1 ; i <= n - l + 1 ; i ++ )
            {
                ill j = i + l - 1;
                if (a[i] != a[j])
                {
                    for (ill k = i; k <= j - 1; ++k)
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
                else
                {
                    f[i][j] = min(f[i][j], min(f[i + 1][j - 1] + 1 , min(f[i + 1][j] , f[i][j - 1])));
                }
            }
        }
        
        cout << f[1][n] << '\n';
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