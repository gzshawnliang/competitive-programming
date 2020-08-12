/*
-------------------------------------------------------------------
* @Name:           Problem B: Class Treasurer
* @Author:         Shawn
* @Create Time:    2020/8/8 23:28:23  (UTC+08:00)
* @Url:            https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/B
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
    const ill mod = 1e9 + 7;

  public:
    void solve()
    {
        vector<ill> pow2(1e6 + 1, 1);
        for (ill x = 1; x <= 1e6; ++x)
            pow2[x] = (pow2[x - 1] * 2) % mod;

        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k; cin >> n >> k;
            string s; cin >> s;

            ill cnt = 0, ans = 0;
            for (ill i = n - 1; i >= 0; --i)
            {
                if (s[i] == 'B')
                {
                    ++cnt;
                    if (cnt > k)
                    {
                        ans = (ans + pow2[i + 1]) % mod;
                        cnt = max(0LL, cnt - 2);
                    }
                }
                else
                {
                    cnt = max(0LL, cnt - 1);
                }
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND1_B.in", "r", stdin);
    freopen("FB_2019_ROUND1_B.out", "w", stdout);
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