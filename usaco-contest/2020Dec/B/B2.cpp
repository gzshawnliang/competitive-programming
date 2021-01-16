

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
    const ill mod = 1e9 +7;

    void solve()
    {
        string s; cin >> s;
        int n = s.size();
        
        string con = "AGCT";
        vector<vector<vector<vector<ill>>>> f(n, vector<vector<vector<ill>>>(4, vector<vector<ill>>(4, vector<ill>(4, 0))));
        for (int j = 0; j <= 3; ++j)
            for (int k = 0; k <= 3; ++k)
                if (s[0] == con[k] || s[0] == '?')
                    f[0][j][k][k] = 1LL;
        
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int nowL = 0; nowL <= 3; ++nowL)
            {
                if (s[i] == con[nowL] || s[i] == '?')
                {
                    for (int j = 0; j <= 3; ++j)
                    {
                        for (int k = 0; k <= 3; ++k)
                        {
                            for (int l = 0; l <= 3; ++l)
                            {
                                if (nowL != l)
                                {
                                    f[i][j][k][nowL] = (f[i][j][k][nowL] + f[i - 1][j][k][l]) % mod;
                                }
                                if (j == l)
                                {
                                    f[i][k][nowL][nowL] = (f[i][k][nowL][nowL] + f[i - 1][j][k][l]) % mod;
                                }
                            }
                        }
                    }
                }
            }
        }

        ill ans = 0;
        for (int k = 0; k <= 3; ++k)
            for (int l = 0; l <= 3; ++l)
                ans = (ans + f[n - 1][l][k][l]) % mod;
        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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