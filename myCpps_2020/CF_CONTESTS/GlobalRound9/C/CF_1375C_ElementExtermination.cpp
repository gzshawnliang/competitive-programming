/*
-------------------------------------------------------------------
* @Name:           1375C Element Extermination
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:39  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/C
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
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            vector<int> a(n, 0);
            vector<vector<int>> l;
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];

                if (i == 0)
                {
                    vector<int> tmp = {a[i]};
                    l.push_back(tmp);
                }
                else
                {
                    if (a[i] > l.back().back())
                    {
                        l.back().push_back(a[i]);
                    }
                    else
                    {
                        vector<int> tmp = {a[i]};
                        l.push_back(tmp);
                    }
                }
            }

            // bool ans = true;
            // int siz = l.size(), las = l[0][0];
            // for (int i = 1; i <= siz - 1; ++i)
            // {
            //     bool flg = false;
            //     for (auto x:l[i])
            //     {
            //         if (x > las)
            //         {
            //             flg = true;
            //             break;
            //         }
            //     }

            //     if (flg == false)
            //     {
            //         ans = false;
            //         break;
            //     }
            // }

            // // if (ans == true)
            // // {
            // //     cout << '\n';
            // //     for (auto x:a) cout << x << ' ';
            // //     cout << '\n';
            // // }

            // if (ans == false) cout << "NO\n";
            // else              cout << "YES\n";

            int siz = l.size();
            vector<pair<int, int>> all;
            for (auto arr:l)
            {
                all.push_back({arr[0], arr.back()});
            }

            while (true)
            {
                bool flg = true;
                
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
    freopen("CF_1375C_ElementExtermination.in", "r", stdin);
    freopen("CF_1375C_ElementExtermination.out", "w", stdout);
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