/*
-------------------------------------------------------------------
* @Name:           1462B Last Year's Substring
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/B
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
            string s; cin >> s;
            //int siz = s.size();

            bool flg = false;
            for (int c = 1; c <= 3; ++c)
                if (s.substr(0, c) + s.substr(n - (4 - c), (4 - c)) == "2020")
                    flg = true;
            if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020") flg = true;
            
            cout << (flg ? "YES\n" : "NO\n");
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1462B_LastYearsSubstring.in", "r", stdin);
    freopen("CF_1462B_LastYearsSubstring.out", "w", stdout);
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