/*
-------------------------------------------------------------------
* @Name:           1485C Floor and Mod
* @Author:         Shawn
* @Create Time:    2021/2/12 22:50:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1485/problem/C
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

#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

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
            int x, y; cin >> x >> y;
            int stt = sqrt(x);

            int ans = (1 + stt - 1) * (stt - 1) / 2;

            int nowI = stt + 1;
            for (int val = stt - 1; val >= 1; --val)
            {
                int nxtI = min(x / val, y + 1);
                ans += max(0, (nxtI - nowI) * val);

                //cout << (nxtI - nowI) << "*" << val << '\n';

                nowI = nxtI;
            }

            cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1485C_FloorandMod.in", "r", stdin);
    freopen("CF_1485C_FloorandMod.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}
