/*
-------------------------------------------------------------------
* @Name:           1385C Make It Good
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:19  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/C
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

            int i = n - 1, mode = 0;
            while (i >= 0)
            {
                if (mode == 0)
                {
                    if (i == 0)          break;
                    if (a[i - 1] < a[i]) mode = 1;
                }
                else
                {
                    if (i == 0)          break;
                    if (a[i - 1] > a[i]) break;
                }

                --i;
            }

            cout << i<< '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385C_MakeItGood.in", "r", stdin);
    freopen("CF_1385C_MakeItGood.out", "w", stdout);
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