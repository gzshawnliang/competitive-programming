/*
-------------------------------------------------------------------
* @Name:           1374B Multiply by 2, divide by 6
* @Author:         Shawn
* @Create Time:    2020/6/28 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/gym/1374/problem/B
* @File:           CF_1374B_Multiplyby2,divideby6.cpp
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

            if (n == 1)
            {
                cout << "0\n";
                continue;
            }
            
            bool flg = true;
            int cnt2 = 0, cnt3 = 0;
            while (n > 1)
            {
                if (n % 2 == 0)
                {
                    n /= 2;
                    ++cnt2;
                }
                else if (n % 3 == 0)
                {
                    n /= 3;
                    ++cnt3;
                }
                else
                {
                    flg = false;
                    break;
                }
            }

            if (flg == false || cnt2 > cnt3)
            {
                cout << "-1\n";
            }
            else
            {
                int ans = (cnt3 - cnt2) + cnt3;;
                cout << ans << '\n';
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
    freopen("CF_1374B_Multiplyby2,divideby6.in", "r", stdin);
    freopen("CF_1374B_Multiplyby2,divideby6.out", "w", stdout);
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