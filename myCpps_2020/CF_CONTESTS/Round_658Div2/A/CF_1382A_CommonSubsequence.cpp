/*
-------------------------------------------------------------------
* @Name:           1382A Common Subsequence
* @Author:         Shawn
* @Create Time:    2020/7/21 22:35:34  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1382/problem/A
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
    const int maxX = 1000;

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;

            vector<int> vis(maxX + 1, 0);
            for (int c = 1; c <= n; ++c)
            {
                int tmp; cin >> tmp;
                vis[tmp] = 1;
            }

            int ans = -1;
            for (int c = 1; c <= m; ++c)
            {
                int tmp; cin >> tmp;
                
                if (vis[tmp] == 1)
                {
                    ans = tmp;
                }
            }

            if (ans == -1)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                cout << "1 " << ans << '\n';
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
    freopen("CF_1382A_CommonSubsequence.in", "r", stdin);
    freopen("CF_1382A_CommonSubsequence.out", "w", stdout);
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