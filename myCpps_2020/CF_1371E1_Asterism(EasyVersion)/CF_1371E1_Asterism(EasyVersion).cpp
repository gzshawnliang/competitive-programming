/*
-------------------------------------------------------------------
* @Name:           1371E1 Asterism (Easy Version)
* @Author:         Shawn
* @Create Time:    2020/7/9 21:39:08  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1371/problem/E1
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
    const ill maxN = 2000;

    void solve()
    {
        ill n, p; cin >> n >> p;
        
        vector<ill> a(n ,0);
        for (ill i = 0; i <= n - 1; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        vector<ill> ans;
        for (ill x = 1; x <= maxN; ++x)
        {
            // ill res = 0;
            // cout << x << '\n';
            // do
            // {
            //     bool flg = true;
            //     for (ill i = 0; i <= n - 1 && flg == true; ++i)
            //     {
            //         if (a[i] > x + i) flg = false;
            //     }

            //     if (flg == true)
            //     {
            //         ++res;
            //         for (ill i = 0; i <= n - 1; ++i)
            //         {
            //             if (i > 0) cout << ' ';
            //             cout << a[i];
            //         }
            //         cout << '\n';
            //     }
            // }
            // while (next_permutation(a.begin(), a.end()));

            // cout << res << "\n\n";

            bool flg = true;
            for (ill i = 0; i <= n - 1 && flg == true; ++i)
            {
                ill cnt = (upper_bound(a.begin(), a.end(), x + i) - a.begin()) - i;
                if (cnt <= 0 || cnt % p == 0) flg = false;
            }

            if (flg == true)
            {
                ans.push_back(x);
            }
        }

        ill siz = ans.size();
        cout << siz << '\n';
        for (ill i = 0; i <= siz - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1371E1_Asterism(EasyVersion).in", "r", stdin);
    freopen("CF_1371E1_Asterism(EasyVersion).out", "w", stdout);
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