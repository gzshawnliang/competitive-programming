/*
-------------------------------------------------------------------
* @Name:           1382D Unmerge
* @Author:         Shawn
* @Create Time:    2020/7/21 22:35:35  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1382/problem/D
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
            
            int maxX = 0, len = 0;
            vector<int> a;
            for (int c = 1; c <= 2 * n + 1; ++c)
            {
                if (c == 2 * n + 1)
                {
                    if (len > 0) a.push_back(len);
                    break;
                }

                int tmp; cin >> tmp;
                
                if (tmp > maxX)
                {
                    if (len > 0) a.push_back(len);
                    len = 1;
                    maxX = tmp;
                }
                else
                {
                    ++len;
                }
            }

            vector<int> f(2 * n + 1, 0); f[0] = 1;
            for (auto x:a)
            {
                for (int k = 2 * n; k >= 0; --k)
                {
                    if (f[k] == 0) continue;
                    if (k + x <= 2 * n - 1) f[k + x] = 1;
                }
            }

            cout << (f[n] ? "YES\n" : "NO\n");
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1382D_Unmerge.in", "r", stdin);
    freopen("CF_1382D_Unmerge.out", "w", stdout);
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