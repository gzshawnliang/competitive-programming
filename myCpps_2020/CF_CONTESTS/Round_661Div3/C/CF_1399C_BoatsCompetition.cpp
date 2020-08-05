/*
-------------------------------------------------------------------
* @Name:           1399C Boats Competition
* @Author:         Shawn
* @Create Time:    2020/8/5 22:35:21  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/C
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
            vector<int> a(n, 0), cntXOrg(n + 1, 0);
            for (int i = 0; i <= n - 1; ++i)
            {   
                cin >> a[i];
                ++cntXOrg[a[i]];
            }

            int ans = 0;
            for (int s = 1; s <= n * 2; ++s)
            {
                vector<int> cntX = cntXOrg;

                if (s == 9)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                int res = 0;
                for (auto x:a)
                {
                    if (x >= 1 && x <= n && s - x >= 1 && s - x <= n)
                    {
                        --cntX[x]; --cntX[s - x];
                        ++res;

                        if (cntX[x] < 0 || cntX[s - x] < 0)
                        {
                            ++cntX[x]; ++cntX[s - x];
                            --res;
                        }
                    }
                }

                if (res == 8)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                ans = max(ans, res);
            }

            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1399C_BoatsCompetition.in", "r", stdin);
    freopen("CF_1399C_BoatsCompetition.out", "w", stdout);
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