/*
-------------------------------------------------------------------
* @Name:           1374E1 Reading Books (easy version)
* @Author:         Shawn
* @Create Time:    2020/6/28 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1374/problem/E1
* @File:           CF_1374E1_ReadingBooks(easyversion).cpp
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
        int n, k; cin >> n >> k;
        
        vector<int> a, x, y;
        for (int c = 1; c <= n; ++c)
        {
            int t, xl, yl; cin >> t >> xl >> yl;
            if (xl == 1 && yl == 1)      a.push_back(t);
            else if (xl == 1 && yl == 0) x.push_back(t);
            else if (xl == 0 && yl == 1) y.push_back(t);
        }

        sort(x.begin(), x.end()); sort(y.begin(), y.end());

        int siz = min(x.size(), y.size());
        for (int i = 0; i <= siz - 1; ++i) a.push_back(x[i] + y[i]);

        if ((int)a.size() < k)
        {
            cout << "-1\n";
            return;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for (int i = 0; i <= k - 1; ++i) ans += a[i];
        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1374E1_ReadingBooks(easyversion).in", "r", stdin);
    freopen("CF_1374E1_ReadingBooks(easyversion).out", "w", stdout);
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