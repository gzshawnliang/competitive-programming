/*
-------------------------------------------------------------------
* @Name:           1391C Cyclic Permutations 
* @Author:         Shawn
* @Create Time:    2020/8/9 22:35:11  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1391/problem/C
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

        vector<int> a(n);
        for (int x = 1; x <= n; ++x) a[x - 1] = x;

        for (int __s = 0; __s == 0; ++__s);

        int cnt = 1;
        do
        {
            vector<pair<int, int>> allE;

            for (int i = 0; i <= n - 1; ++i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (a[j] > a[i])
                    {
                        allE.push_back({min(i, j), max(i, j)});
                        break;
                    }
                }

                for (int j = i + 1; j <= n - 1; ++j)
                {
                    if (a[j] > a[i])
                    {
                        allE.push_back({min(i, j), max(i, j)});
                        break;
                    }
                }
            }

            bool flg = allE.size() > n - 1;

            if (!flg)
            {
                //cout << cnt << ": ";
                for (auto x:a)
                {
                    cout << x << ' ';
                }
                cout << '\n';
            }

            ++cnt;
        }
        while (next_permutation(a.begin(), a.end()));
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1391C_CyclicPermutations.in", "r", stdin);
    freopen("CF_1391C_CyclicPermutations.out", "w", stdout);
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