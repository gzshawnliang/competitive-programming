/*
-------------------------------------------------------------------
* @Name:           1337E Kaavi and Magic Spell
* @Author:         Shawn
* @Create Time:    2020/12/18 22:43:56  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1337/problem/E
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
  public:
    const ill mod = 998244353;

    void solve()
    {
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size();
        s = " " + s; t = " " + t;

        vector<vector<ill>> f(n + 1, vector<ill>(n + 1, 0LL));
        for (int i = 1; i <= m; ++i)
            if (t[i] == s[1])
                f[i][i] = 2LL;
        for (int i = m + 1; i <= n; ++i)
            f[i][i] = 2LL;
        
        for (int len = 2; len <= n; ++len)
        {
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                if (i > m || t[i] == s[len]) f[i][j] = (f[i][j] + f[i + 1][j]) % mod;
                if (j > m || t[j] == s[len]) f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
            }
        }

        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= n; ++j)
        //         if (f[i][j] > 0)
        //             cout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';

        ill ans = 0;
        for (int i = m; i <= n; ++i)
            ans = (ans + f[1][i]) % mod;
        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1337E_KaaviandMagicSpell.in", "r", stdin);
    freopen("CF_1337E_KaaviandMagicSpell.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}