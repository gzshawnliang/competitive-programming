/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/9/5 23:17:40  (UTC+08:00)
* @Url:            
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
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;

            vector<int> f(n + 1, 0);
            for (int i = 1; i <= n; ++i) f[i] = i;

            auto fnd=[&](int x)
            {
                vector<int> pth;
                while (f[x] != x)
                {
                    pth.push_back(x);
                    x = f[x];
                }

                for (auto v:pth)
                    f[v] = x;

                return x;
            };

            for (int c = 1; c <= m; ++c)
            {
                int l, r; cin >> l >> r;
                for (int x = l, y = r; x < y; ++x, --y)
                    f[fnd(x)] = fnd(y);
            }

            map<int, vector<int>> allMM;
            for (int v = 1; v <= n; ++v)
                allMM[fnd(v)].push_back(v);
            vector<vector<int>> allM;
            for (auto vec : allMM)
                allM.push_back(vec.second);
            
            int siz = allM.size();
            vector<int> dp(n * 2 + 1, 0);
            vector<vector<int>> fsp(siz, vector<int>(n * 2 + 1, -1));
            for (int i = 0; i <= siz - 1; ++i)
            {
                int x = allM[i].size();
                vector<int> tmp(n * 2 + 1, 0);

                if (i == 0)
                {
                    tmp[x + n] = 1; tmp[-x + n] = 1;
                    fsp[i][x + n] = 0; fsp[i][x + n] = 0;
                }
                else
                {
                    for (int lst = -n; lst <= n; ++lst)
                    {
                        if (dp[lst + n] == 1)
                        {
                            if (lst + x <= n)
                            {
                                tmp[lst + x + n] = 1;
                                fsp[i][lst + x + n] = lst + n;
                            }
                            if (lst - x >= -n)
                            {
                                tmp[lst - x + n] = 1;
                                fsp[i][lst - x + n] = lst + n;
                            }
                        }
                    }
                    //cout << ' ';
                }
                //cout << x;

                // for (int x = -n; x <= n; ++x)
                //     if (tmp[x + n] == 1) cout << x << ' ';
                // cout << '\n';

                dp = tmp;
            }
            //cout << '\n';

            int ans = n;
            for (int x = -n; x <= n; ++x)
                if (dp[x + n]) ans = min(ans, abs(x));
            ans += n;
            
            vector<int> out(n + 1, -1);
            for (int i = siz - 1; i > 0; --i)
            {
                int tmp = fsp[i][ans];
                for (auto j : allM[i]) out[j] = (ans > tmp);

                ans = tmp;
            }
            for (auto j : allM[0]) out[j] = (ans - n > 0);

            cout << "Case #" << tcc << ": ";
            for (int i = 1; i <= n; ++i) cout << out[i];
            cout << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND2_B.in", "r", stdin);
    freopen("FB_2019_ROUND2_B.out", "w", stdout);
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