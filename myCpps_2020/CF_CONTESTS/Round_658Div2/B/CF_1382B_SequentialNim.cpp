/*
-------------------------------------------------------------------
* @Name:           1382B Sequential Nim
* @Author:         Shawn
* @Create Time:    2020/7/21 22:35:35  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1382/problem/B
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

            int ans = -1;
            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp; cin >> tmp;
                if (tmp > 1 && ans == -1) ans = i % 2;
            }

            if (ans == -1)
            {
                if (n % 2 == 1) cout << "First\n";
                else            cout << "Second\n";
            }
            else if (ans == 0)
            {
                cout << "First\n";
            }
            else
            {
                cout << "Second\n";
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
    freopen("CF_1382B_SequentialNim.in", "r", stdin);
    freopen("CF_1382B_SequentialNim.out", "w", stdout);
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