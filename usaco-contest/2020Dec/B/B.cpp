

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
        string s; cin >> s;
        int n = s.size();
        vector<int> a(n + 1, -1);
        vector<vector<int>> pos(5);
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == '?')      a[i] = 0;
            else if (s[i - 1] == 'G') a[i] = 2;
            else if (s[i - 1] == 'T') a[i] = 4;
            else if (s[i - 1] == 'A') a[i] = 1;
            else if (s[i - 1] == 'C') a[i] = 3;

            pos[a[i]].push_back(i);
        }

        vector<vector<int>> f(n + 1, vector<int>(5, 0));
        for (int c = 1; c <= 4; ++c) f[0][c] = 1;
        
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == a[i - 1])
            {
                f[i][a[i]] += f[i - 1][a[i]];
            }
            else
            {
                for (int j = 0; j <= i - 1; ++j)
                {
                    if (a[j + 1] != a[i] || j == i - 1)
                    {
                        f[i][a[j + 1]] += f[j][a[i]];
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (f[i][j] > 0)
                {
                    cout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
                }
            }
        }

        int ans = 0;
        for (int c = 1; c <= 4; ++c) ans += f[n][c];
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