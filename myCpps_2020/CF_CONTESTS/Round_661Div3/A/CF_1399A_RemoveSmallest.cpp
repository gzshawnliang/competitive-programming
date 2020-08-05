/*
-------------------------------------------------------------------
* @Name:           1399A Remove Smallest
* @Author:         Shawn
* @Create Time:    2020/8/5 22:35:21  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/A
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

            sort(a.begin(), a.end());

            bool flg = true;
            for (int i = 1; i <= n - 1; ++i)
            {
                if (a[i] - a[i - 1] > 1)
                {
                    flg = false;
                    break;
                }
            }

            cout << (flg ? "YES\n" : "NO\n");
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1399A_RemoveSmallest.in", "r", stdin);
    freopen("CF_1399A_RemoveSmallest.out", "w", stdout);
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