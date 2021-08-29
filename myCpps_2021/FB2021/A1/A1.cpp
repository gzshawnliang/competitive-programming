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
    vector<vector<int>> dp;

    void ini()
    {
        dp = vector<vector<int>>(NA, vector<int>(NA, inf));
        string vs = "", cs = "";

        for (char ch = 'A'; ch <= 'Z'; ++ch)
        {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                vs += ch;
            else
                cs += ch;
        }

        int sizV = vs.size(), sizC = cs.size();
        for (int i = 0; i <= sizV - 1; ++i)
        {
            for (int j = 0; j <= sizC - 1; ++j)
            {
                dp[vs[i] - 'A'][cs[j] - 'A'] = 1;
                dp[cs[j] - 'A'][vs[i] - 'A'] = 1;
            }
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
    }

  public:
    void solve()
    {
        ini();

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string s; cin >> s;

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
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
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