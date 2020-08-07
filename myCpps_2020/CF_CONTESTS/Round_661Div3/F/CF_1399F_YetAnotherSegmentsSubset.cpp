/*
-------------------------------------------------------------------
* @Name:           1399F Yet Another Segments Subset
* @Author:         Shawn
* @Create Time:    2020/8/6 22:52:45  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/F
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
    vector<vector<int>> f, rg;

    int dfs(int l, int r)
    {
        if (f[l][r] != -1) return f[l][r];
        f[l][r] = 0;
        if (l > r) return -1;

        int flg = 0;
        for (auto nr : rg[l])
        {
            if (nr == r)
            {
                flg = 1;
                break;
            }
        }

        f[l][r] = max(f[l][r], flg + (l + 1 > r ? 0 : dfs(l + 1, r)));
        for (auto nr : rg[l])
        {
            if (nr >= r) continue;
            f[l][r] = max(f[l][r], flg + dfs(l, nr) + (nr + 1 > r ? 0 : dfs(nr + 1, r)));
        }

        return f[l][r];
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            vector<int> l(n, 0), r(n, 0), allV;
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> l[i] >> r[i];
                allV.push_back(l[i]); allV.push_back(r[i]);
            }
            sort(allV.begin(), allV.end());

            for (int i = 0; i <= n - 1; ++i)
            {
                l[i] = (lower_bound(allV.begin(), allV.end(), l[i]) - allV.begin());
                r[i] = (lower_bound(allV.begin(), allV.end(), r[i]) - allV.begin());
            }

            int maxX = allV.size() - 1;
            f = vector<vector<int>>(maxX + 1, vector<int>(maxX + 1, -1));
		    rg = vector<vector<int>>(maxX + 1);
            for (int i = 0; i <= n - 1; ++i)
            {
                rg[l[i]].push_back(r[i]);
            }

            cout << dfs(0, maxX) << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1399F_YetAnotherSegmentsSubset.in", "r", stdin);
    freopen("CF_1399F_YetAnotherSegmentsSubset.out", "w", stdout);
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