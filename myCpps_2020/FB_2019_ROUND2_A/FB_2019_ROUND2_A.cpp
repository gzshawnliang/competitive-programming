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
            int n, m, k; cin >> n >> m >> k;
            cout << "Case #" << tcc << ": ";

            int pxX = 0, pxY = 0, p1X = 0, p1Y = 0, p2X = 0, p2Y = 0;
            cin >> pxX >> pxY >> p1X >> p1Y;
            if (k == 2) cin >> p2X >> p2Y;

            if (k == 1)
            {
                cout << "N\n";
                continue;
            }
            else
            {
                if ((abs(pxX - p1X) + abs(pxY - p1Y)) % 2 == 0 && (abs(pxX - p2X) + abs(pxY - p2Y)) % 2 == 0)
                {
                    cout << "Y\n";
                }
                else
                {
                    cout << "N\n";
                }
            }
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND2_A.in", "r", stdin);
    freopen("FB_2019_ROUND2_A.out", "w", stdout);
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