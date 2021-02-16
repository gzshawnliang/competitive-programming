/*
-------------------------------------------------------------------
* @Name:           1490B Balanced Remainders
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/B
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
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            vector<int> a(n);

            vector<int> cnt(3);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                a[i] %= 3;

                ++cnt[a[i]];
            }

            int avg = (cnt[0] + cnt[1] + cnt[2]) / 3;

            vector<vector<int>> dis(3, vector<int>(3, 0));
            dis[0][1] = 1;
            dis[0][2] = 2;
            dis[1][0] = 2;
            dis[1][2] = 1;
            dis[2][0] = 1;
            dis[2][1] = 2;

            int cntOv = 0;
            vector<int> exd(3);
            for (int i = 0; i <= 2; ++i)
            {
                exd[i] = cnt[i] - avg;
                if (exd[i] > 0) ++cntOv;
            }

            if (cntOv == 1)
            {
                if (exd[1] > 0)
                {
                    cout << abs(exd[0]) * dis[1][0] + abs(exd[2]) * dis[1][2] << '\n';
                }
                else if (exd[0] > 0)
                {
                    cout << abs(exd[1]) * dis[0][1] + abs(exd[2]) * dis[0][2] << '\n';
                }
                else
                {
                    cout << abs(exd[1]) * dis[2][1] + abs(exd[0]) * dis[2][0] << '\n';
                }
            }
            else
            {
                if (exd[1] < 0)
                {
                    cout << abs(exd[0]) * dis[0][1] + abs(exd[2]) * dis[2][1] << '\n';
                }
                else if (exd[0] < 0)
                {
                    cout << abs(exd[1]) * dis[1][0] + abs(exd[2]) * dis[2][0] << '\n';
                }
                else
                {
                    cout << abs(exd[1]) * dis[1][2] + abs(exd[0]) * dis[0][2] << '\n';
                }
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490B_BalancedRemainders.in", "r", stdin);
    freopen("CF_1490B_BalancedRemainders.out", "w", stdout);
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