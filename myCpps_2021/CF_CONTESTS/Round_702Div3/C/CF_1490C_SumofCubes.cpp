/*
-------------------------------------------------------------------
* @Name:           1490C Sum of Cubes
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/C
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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            map<ill, int> mmp;
            for (ill x = 1; x * x * x <= n; ++x)
            {
                mmp[x * x * x] = 1;
            }

            bool flg = false;
            for (ill x = 1; x * x * x <= n; ++x)
            {
                ill rem = n - x * x * x;

                if (mmp[rem] == 1 && rem > 0)
                {
                    flg = true;
                    break;
                }
            }

            cout << (flg ? "YES\n" : "NO\n");
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490C_SumofCubes.in", "r", stdin);
    freopen("CF_1490C_SumofCubes.out", "w", stdout);
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