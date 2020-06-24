/*
-------------------------------------------------------------------
* @Name:           1366B Shuffle
* @Author:         Shawn
* @Create Time:    2020/6/24 22:18:27  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1366/problem/B
* @File:           CF_1366B_Shuffle.cpp
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
            int n, x, m; cin >> n >> x >> m;

            vector<pair<int, int>> a(1);
            a[0] = {x, x};
            
            for (int c = 1; c <= m; ++c)
            {
                int nowL, nowR; cin >> nowL >> nowR;
                
                bool flg = false;
                for (auto ar : a)
                {
                    if ((nowR < ar.first || ar.second < nowL) == false)
                    {
                        flg = true;
                        break;

                        // if (nowL <= ar.l && ar.r <= nowR)
                        // {
                        //     ans += ((nowR - nowL + 1) - (ar.r - ar.l + 1));
                        // }
                        // else if (ar.l <= nowL && nowR <= ar.r)
                        // {
                        //     //nope
                        // }
                        // else if (ar.l <= nowR)
                        // {
                        //     ans += (nowR - ar.l + 1);
                        // }
                        // else if (nowL <= ar.r)
                        // {
                        //     ans += (ar.r - nowL + 1);
                        // }
                    }
                }

                if (flg == true) a.push_back({nowL, nowR});
            }

            sort(a.begin(), a.end());
            // for (auto ar : a)
            // {
            //     cout << '[' << ar.first << ", " << ar.second << "]\n";
            // }

            int siz = a.size(), ans = (a[0].second - a[0].first + 1), maxR = a[0].second;
            for (int i = 1; i <= siz - 1; ++i)
            {
                if (a[i].second > maxR)
                {
                    ans += (a[i].second - maxR);
                    maxR = a[i].second;
                }
            }

            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1366B_Shuffle.in", "r", stdin);
    freopen("CF_1366B_Shuffle.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}


