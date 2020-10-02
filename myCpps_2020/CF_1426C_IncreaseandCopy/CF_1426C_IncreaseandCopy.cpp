/*
-------------------------------------------------------------------
* @Name:           1426C Increase and Copy
* @Author:         Shawn
* @Create Time:    2020/10/2 14:45:42  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/C
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

            auto check=[&](int x)
            {
                int maxR = 0;
                for (int c = x; c >= 0; --c)
                {
                    int res = (c + 1) * (x - c + 1);
                    if (res >= n)
                    {
                        return true;
                    }
                    else if (res <= maxR)
                    {
                        return false;
                    }
                    else
                    {
                        maxR = res;
                    }
                }
                return false;
            };

            int l = 0, r = n;
            while (true)
            {
                if (r - l <= 1)
                {
                    if (check(l) == false) l = r;
                    break;
                }
                else
                {
                    int mid = (l + r) / 2;
                    if (check(mid) == true)
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }

            cout << l << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426C_IncreaseandCopy.in", "r", stdin);
    freopen("CF_1426C_IncreaseandCopy.out", "w", stdout);
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