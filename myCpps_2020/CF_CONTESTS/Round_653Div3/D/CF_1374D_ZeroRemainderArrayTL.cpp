/*
-------------------------------------------------------------------
* @Name:           1374D Zero Remainder Array
* @Author:         Shawn
* @Create Time:    2020/6/28 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1374/problem/D
* @File:           CF_1374D_ZeroRemainderArray.cpp
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
            int n, k; cin >> n >> k;
            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i]; a[i] %= k;
            }

            sort(a.begin(), a.end());

            while (true)
            {
                if (a.size() > 0)
                {
                    if (a[0] == 0)
                    {
                        a.erase(a.begin());
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            int ans = 0, x = 0;
            while (a.size() > 0)
            {
                int fnd = k - x;
                if (x == 0) fnd = 0;

                auto it = lower_bound(a.begin(), a.end(), fnd);

                if (*it == fnd)
                {
                    a.erase(it);
                }

                x = (x + 1) % k;
                ++ans;
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
    freopen("CF_1374D_ZeroRemainderArray.in", "r", stdin);
    freopen("CF_1374D_ZeroRemainderArray.out", "w", stdout);
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