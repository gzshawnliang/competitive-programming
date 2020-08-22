/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/22 23:20:23  (UTC+08:00)
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
            int n; cin >> n;

            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            vector<int> up(n, 1), down(n, 1);
            for (int i = n - 2; i >= 0; --i)
            {
                if (a[i] < a[i + 1]) up[i] = max(up[i], up[i + 1] + 1);
                if (a[i] > a[i + 1]) down[i] = max(down[i], down[i + 1] + 1);
            }

            int ans = 0;
            int lstN = -1;
            for (int i = 0; i <= n - 1; ++i)
            {
                int nowN = -1;
                if      (lstN == -1)      nowN = -1;
                else if (a[i - 1] < a[i]) nowN = lstN + 1;
                else if (a[i - 1] > a[i]) nowN = lstN - 1;
                else                      nowN = lstN;

                if (nowN < 1 || nowN > 4)
                {
                    if (up[i] > down[i])
                    {
                        nowN = max(1, 5 - up[i]);
                        ++ans;
                    }
                    else if (up[i] < down[i])
                    {
                        nowN = min(4, down[i]);
                        ++ans;
                    }
                }

                cout << nowN;

                lstN = nowN;
            }
            cout << '\n';

            cout << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("PB.in", "r", stdin);
    freopen("PB.out", "w", stdout);
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