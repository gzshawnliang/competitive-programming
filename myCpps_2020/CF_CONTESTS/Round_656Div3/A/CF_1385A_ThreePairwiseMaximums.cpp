/*
-------------------------------------------------------------------
* @Name:           1385A Three Pairwise Maximums
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:18  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/A
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
            int x, y, z; cin >> x >> y >> z;

            vector<int> tmp = {x, y, z};
            sort(tmp.begin(), tmp.end());
            if (tmp[1] != tmp[2])
            {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            int maxN = max(x, max(y, z));
            if (maxN != x)
            {
                cout << 1 << ' ' << x << ' ' << y << '\n';
            }
            else if (maxN != y)
            {
                cout << y << ' ' << x << ' ' << 1 << '\n';
            }
            else
            {
                cout << x << ' ' << 1 << ' ' << z << '\n';
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385A_ThreePairwiseMaximums.in", "r", stdin);
    freopen("CF_1385A_ThreePairwiseMaximums.out", "w", stdout);
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