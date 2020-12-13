/*
-------------------------------------------------------------------
* @Name:           1453C Triangles
* @Author:         Shawn
* @Create Time:    2020/12/13 21:53:55  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1453/problem/C
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
            int n; cin >> n;

            vector<int> ymn(10, n - 1), ymx(10, 0), xmn(10, n - 1), xmx(10, 0);
            vector<vector<pair<int, int>>> allN(10);
            //vector<vector<int>> a(n, vector<int>(n, 0));
            for (int y = 0; y <= n - 1; ++y)
            {
                string s; cin >> s;
                for (int x = 0; x <= n - 1; ++x)
                {
                    int num = s[x] - '0';
                    allN[num].push_back({y, x});

                    ymn[num] = min(ymn[num], y); ymx[num] = max(ymx[num], y);
                    xmn[num] = min(xmn[num], x); xmx[num] = max(xmx[num], x);
                }
            }

            for (int num = 0; num <= 9; ++num)
            {
                int res = 0, siz = allN[num].size();
                for (int i = 0; i <= siz - 1; ++i)
                {
                    int maxLX = max(allN[num][i].second, n - 1 - allN[num][i].second);
                    res = max(res, maxLX * max(abs(allN[num][i].first - ymn[num]), abs(allN[num][i].first - ymx[num])));

                    int maxLY = max(allN[num][i].first, n - 1 - allN[num][i].first);
                    res = max(res, maxLY * max(abs(allN[num][i].second - xmn[num]), abs(allN[num][i].second - xmx[num])));
                }

                if (num > 0) cout << ' ';
                cout << res;
            }
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
    freopen("CF_1453C_Triangles.in", "r", stdin);
    freopen("CF_1453C_Triangles.out", "w", stdout);
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