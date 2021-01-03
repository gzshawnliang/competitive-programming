/*
-------------------------------------------------------------------
* @Name:           1466B Last minute enhancements
* @Author:         Shawn
* @Create Time:    2020/12/30 22:35:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1466/problem/B
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
            vector<int> a(n), f(2 * n + 1, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                if (f[a[i]] == 0)
                {
                    f[a[i]] = 1;
                }
                else
                {
                    ++a[i];
                    f[a[i]] = 1;
                }
            }

            set<int> st;
            for (auto x:a) st.insert(x);

            cout << st.size() << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1466B_Lastminuteenhancements.in", "r", stdin);
    freopen("CF_1466B_Lastminuteenhancements.out", "w", stdout);
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