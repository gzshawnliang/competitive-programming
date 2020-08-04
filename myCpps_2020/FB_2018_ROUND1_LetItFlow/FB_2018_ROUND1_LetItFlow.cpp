/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/4 22:34:53  (UTC+08:00)
* @Url:            
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
    const ill M = 3, MOD = 1000000007;
    
  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill N; cin >> N;

            vector<vector<char>> a(M, vector<char>(N + 1));
            for (ill y = 0; y <= M - 1; ++y)
                for (ill x = 1; x <= N; ++x)
                    cin >> a[y][x];

            vector<vector<ill>> f(M, vector<ill>(N + 1)); //0u 1d 2r
            f[0][0] = 1;
            for (ill x = 1; x <= N; ++x)
            {
                if (a[0][x] == '.' && a[1][x] == '.') f[0][x] = f[1][x - 1];

                if (a[1][x] == '.' && a[0][x] == '.') f[1][x] = (f[1][x] + f[0][x - 1]) % MOD;
                if (a[1][x] == '.' && a[2][x] == '.') f[1][x] = (f[1][x] + f[2][x - 1]) % MOD;

                if (a[2][x] == '.' && a[1][x] == '.') f[2][x] = f[1][x - 1];
            }

            // for (ill y = 0; y <= M - 1; ++y)
            // {
            //     for (ill x = 1; x <= N; ++x)
            //         cout << f[y][x];
            //     cout << '\n';
            // }

            cout << "Case #" << tcc << ": " << f[2][N] << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2018_ROUND1_LetItFlow.in", "r", stdin);
    freopen("FB_2018_ROUND1_LetItFlow.out", "w", stdout);
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