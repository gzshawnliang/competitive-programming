/*
-------------------------------------------------------------------
* @Name:           1375B Neighbor Grid
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:39  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/B
* @Description:    
-------------------------------------------------------------------
                                     /~\
                         WA again?  |oo )
                                    _\=/_
                    ___        #   /  _  \
   No,TLE again！  / ()\        \\//|/.\|\\
  mabe Next time _|_____|_       \/  \_/  ||
      get AC    | | === | |         |\ /| ||
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

            auto maxX = [&](int y, int x)
            {
                int ans = 4;

                if (y == 0 || y == n - 1)
                {
                    ans = 3;
                    if (x == 0 || x == m - 1)
                    {
                        ans = 2;
                    }
                }

                if (x == 0 || x == m - 1)
                {
                    ans = 3;
                    if (y == 0 || y == n - 1)
                    {
                        ans = 2;
                    }
                }

                return ans;
            };

            bool flg = true;
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    int inX; cin >> inX;

                    if (inX > maxX(y, x))
                    {
                        flg = false;
                    }
                }
            }

            if (flg == false)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                for (int y = 0; y <= n - 1; ++y)
                {
                    for (int x = 0; x <= m - 1; ++x)
                    {
                        if (x > 0) cout << ' ';
                        cout << maxX(y, x);
                    }
                    cout << '\n';
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1375B_NeighborGrid.in", "r", stdin);
    freopen("CF_1375B_NeighborGrid.out", "w", stdout);
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