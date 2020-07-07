/*
-------------------------------------------------------------------
* @Name:           1375E Inversion SwapSort
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:39  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/E
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
    void solve()
    {
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i) cin >> a[i];

        vector<pair<int, int>> allP;
        for (int i = 0; i <= n - 1; ++i)
            for (int j = 0; j <= i - 1; ++j)
                if (a[j] > a[i]) allP.push_back({j, i});

        sort(allP.begin(), allP.end(), [&](pair<int, int> &x, pair<int, int> &y)
        {
            if (a[x.second] == a[y.second])
            {
                if (x.second == y.second) return x.first < y.first;
                else                      return x.second > y.second;
            }
            else                          return a[x.second] > a[y.second];
        });

        int siz = allP.size();
        cout << siz << '\n';
        for (int i = 0; i <= siz - 1; ++i)
        {
            cout << allP[i].first + 1 << ' ' << allP[i].second + 1 << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1375E_InversionSwapSort.in", "r", stdin);
    freopen("CF_1375E_InversionSwapSort.out", "w", stdout);
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