/*
-------------------------------------------------------------------
* @Name:           1368D AND, OR and square sum
* @Author:         Shawn
* @Create Time:    2020/7/3 22:29:26  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1368/problem/D
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
    const ill maxP = 20;

    void solve()
    {
        ill n; cin >> n;

        vector<ill> cnt1(maxP + 1, 0);
        for (ill c = 1; c <= n; ++c)
        {
            ill x; cin >> x;

            ill i = 0;
            while (x > 0)
            {
                if (x % 2 == 1) ++cnt1[i];
                ++i;

                x /= 2;
            }
        }

        ill ans = 0, farP = maxP;
        while (true)
        {
            bool flg = false;
            ill now = 0, tmpFarP = farP;
            for (ill i = 0; i <= tmpFarP; ++i)
            {
                if (cnt1[i] > 0)
                {
                    --cnt1[i];
                    now += 1 << i;
                    flg = true;
                    farP = i;
                }
            }

            if (flg == false) break;

            ans += now * now;
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1368D_ANDORandsquaresum.in", "r", stdin);
    freopen("CF_1368D_ANDORandsquaresum.out", "w", stdout);
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