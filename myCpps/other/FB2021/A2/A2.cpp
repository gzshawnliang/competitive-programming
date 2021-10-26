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
    const int NA = 26, inf = 10000;

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string s; cin >> s;
            int n; cin >> n;

            vector<vector<int>> dp(NA, vector<int>(NA, inf));
            for (int c = 1; c <= n; ++c)
            {
                string tmp; cin >> tmp;
                dp[tmp[0] - 'A'][tmp[1] - 'A'] = 1;
            }

            for (int ch = 0; ch <= NA - 1; ++ch) dp[ch][ch] = 0;

            for (int k = 0; k <= NA - 1; ++k)
            {
                for (int i = 0; i <= NA - 1; ++i)
                {
                    for (int j = 0; j <= NA - 1; ++j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }

            int ans = inf;
            for (int ch = 0; ch <= NA - 1; ++ch)
            {
                int tmp = 0;
                for (int i = 0, siz = s.size(); i <= siz - 1; ++i)
                    tmp += dp[s[i] - 'A'][ch];
                ans = min(ans, tmp);
            }

            cout << "Case #" << tcc << ": " << (ans == inf ? -1 : ans) << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
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