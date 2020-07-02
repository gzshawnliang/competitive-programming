/*
-------------------------------------------------------------------
* @Name:           1368C Even Picture
* @Author:         Shawn
* @Create Time:    2020/7/2 22:54:46  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1368/problem/C
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
        int n; cin >> n;

        cout << n * 3 + 4 << '\n';
        cout << "0 0\n0 1\n";
        for (int x = 1; x <= n; ++x)
        {
            cout << x << ' ' << x + 1 << '\n';
            cout << x << ' ' << x    << '\n';
            cout << x << ' ' << x - 1 << '\n';
        }
        cout << n + 1 << ' ' << n + 1 << '\n'
             << n + 1 << ' ' << n     << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1368C_EvenPicture.in", "r", stdin);
    freopen("CF_1368C_EvenPicture.out", "w", stdout);
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