/*
-------------------------------------------------------------------
* @Name:           1373D Maximum Sum on Even Positions
* @Author:         Shawn
* @Create Time:    2020/6/25 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1373/problem/D
* @File:           CF_1373D_MaximumSumonEvenPositions.cpp
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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            ill sumOrg = 0;
            vector<ill> a(n, 0);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                if (i % 2 == 0) sumOrg += a[i];
            }

            if (n == 1)
            {
                cout << a[0] << '\n';
                continue;
            }
            else if (n == 2)
            {
                cout << max(a[0], a[1]) << '\n';
                continue;
            }
    
            vector<ill> b1;
            for (ill i = 0; i + 1 <= n - 1; i += 2) b1.push_back(a[i + 1] - a[i]);

            ill resB1 = b1[0], maxXB1 = b1[0], sizB1 = b1.size();
            for (ill i = 1; i <= sizB1 - 1; i++)
            {
                maxXB1 = max(maxXB1 + b1[i], b1[i]);
                resB1 = max(maxXB1, resB1);
            }

            vector<ill> b2;
            for (ill i = 1; i + 1 <= n - 1; i += 2) b2.push_back(a[i] - a[i + 1]);
            
            ill resB2 = b2[0], maxXB2 = b2[0], sizB2 = b2.size();
            for (ill i = 1; i <= sizB2 - 1; i++)
            {
                maxXB2 = max(maxXB2 + b2[i], b2[i]);
                resB2 = max(maxXB2, resB2);
            }

            cout << sumOrg + max(0LL, max(resB1, resB2)) << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1373D_MaximumSumonEvenPositions.in", "r", stdin);
    freopen("CF_1373D_MaximumSumonEvenPositions.out", "w", stdout);
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