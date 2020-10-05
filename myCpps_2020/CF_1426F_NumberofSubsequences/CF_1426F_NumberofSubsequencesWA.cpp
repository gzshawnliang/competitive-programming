/*
-------------------------------------------------------------------
* @Name:           1426F Number of Subsequences
* @Author:         Shawn
* @Create Time:    2020/10/5 18:33:25  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/F
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
        int n; cin >> n;
        string s; cin >> s;

        int tolQ = 0;
        for (int i = 0; i <= n - 1; ++i)
            if (s[i] == '?') ++tolQ;

        int cntQ = 0, ans = 0;
        vector<int> cntA(tolQ + 1, 0), cntAB(tolQ + 1, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            if (s[i] == 'c' || s[i] == '?')
            {
                for (int q = 0; q <= cntQ; ++q)
                {
                    ans += cntAB[q] * pow(3, cntQ - q);
                }
            }

            if (s[i] == '?') ++cntQ;

            if      (s[i] == 'b')
            {
                for (int q = cntQ; q >= 0; --q)
                {
                    cntAB[q] += cntA[q];
                }
            }
            else if (s[i] == '?')
            {
                for (int q = cntQ; q >= 1; --q)
                {
                    cntAB[q] += cntA[q - 1];
                }
            }

            if      (s[i] == 'a') ++cntA[0];
            else if (s[i] == '?')
            {
                for (int q = cntQ; q >= 1; --q)
                {
                    cntA[q] = q;
                }
            }
        }

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426F_NumberofSubsequences.in", "r", stdin);
    freopen("CF_1426F_NumberofSubsequences.out", "w", stdout);
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