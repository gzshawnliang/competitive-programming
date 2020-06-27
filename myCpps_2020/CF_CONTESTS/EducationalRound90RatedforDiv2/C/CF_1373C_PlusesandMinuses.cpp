/*
-------------------------------------------------------------------
* @Name:           1373C Pluses and Minuses
* @Author:         Shawn
* @Create Time:    2020/6/25 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1373/problem/C
* @File:           CF_1373C_PlusesandMinuses.cpp
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
    const ill maxX = 1e6;

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            string s; cin >> s;

            ill sizS = s.size();

            //cout << sizS << '\n';

            ill ans = 0;
            vector<ill> add(sizS + 1, 0);
            vector<ill> finL(sizS + 2, -1);
            for (ill i = 1; i <= sizS; ++i)
            {
                add[i] = add[i - 1] + (s[i - 1] == '+') * 2 - 1;

                if (-add[i] - 1 >= 0)
                {
                    if (finL[-add[i] - 1] == -1)
                    {
                        finL[-add[i] - 1] = i;
                        ans += i;
                    }
                }
            }

            // for (ill x = 0; x <= maxX + 1; ++x)
            // {
            //     if (finL[x] == -1)
            //     {
            //         ans += sizS;
            //         break;
            //     }
            //     else
            //     {
            //         ans += finL[x];
            //     }
            // }

            cout << ans + sizS << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1373C_PlusesandMinuses.in", "r", stdin);
    freopen("CF_1373C_PlusesandMinuses.out", "w", stdout);
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