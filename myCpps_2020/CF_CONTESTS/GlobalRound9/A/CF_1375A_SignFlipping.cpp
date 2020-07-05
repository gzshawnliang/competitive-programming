/*
-------------------------------------------------------------------
* @Name:           1375A Sign Flipping
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:38  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/A
* @Description:    
-------------------------------------------------------------------
                                     /~\
                         WA again?  |oo )
                                    _\=/_
                    ___        #   /  _  \
   No,TLE again！  / ()\        \\//|/.\|\\
  mabe Next time _|_____|_       \/  \_/  ||
      get AC    | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/


#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

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

            vector<ill> aOrg(n, 0);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> aOrg[i]; aOrg[i] = abs(aOrg[i]);
            }

            ill need = n / 2;
            vector<pair<ill, ill>> a;
            for (ill i = 0; i <= n - 1; ++i)
            {
                if (i == 0)
                {
                    a.push_back({aOrg[i], 1});
                }
                else if (aOrg[i] != aOrg[i - 1])
                {
                    a.push_back({aOrg[i], 1});
                }
                else
                {
                    ++a.back().second;
                    --need;
                }
            }
            n = a.size();

            ill cntP = 0, cntM = 0;
            vector<ill> sign(n - 1, 0);
            for (ill i = 0; i <= n - 2; ++i)
            {
                sign[i] = (a[i + 1].first - a[i].first) > 0;
                if (sign[i] == 1) ++cntP;
                else              ++cntM;
            }

            if (cntP > cntM)
            {
                ill cntChange = need - cntM;
                for (ill i = 0; i <= n - 2 && cntChange > 0; ++i)
                {
                    if (i == n - 2)
                    {
                        if (sign[i] == 1)
                        {
                            sign[i] = 0;
                            a[i + 1].first *= -1;
                            --cntChange;
                        }
                    }
                    else
                    {
                        if (sign[i] == 1 && sign[i + 1] == 1)
                        {
                            sign[i] = 0;
                            a[i + 1].first *= -1;
                            --cntChange;
                        }
                    }
                }
            }
            else
            {
                ill cntChange = need - cntP;
                for (ill i = n - 2; i >= 0 && cntChange > 0; --i)
                {
                    if (i == 0)
                    {
                        if (sign[i] == 0)
                        {
                            sign[i] = 1;
                            a[i].first *= -1;
                            --cntChange;
                        }
                    }
                    else
                    {
                        if (sign[i] == 0 && sign[i - 1] == 0)
                        {
                            sign[i] = 1;
                            a[i].first *= -1;
                            --cntChange;
                        }
                    }
                }
            }

            for (ill i = 0; i <= n - 1; ++i)
            {
                for (ill c = 1; c <= a[i].second; ++c)
                {
                    cout << a[i].first << ' ';
                }
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1375A_SignFlipping.in", "r", stdin);
    freopen("CF_1375A_SignFlipping.out", "w", stdout);
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