/*
-------------------------------------------------------------------
* @Name:           1426E Rock, Paper, Scissors
* @Author:         Shawn
* @Create Time:    2020/10/4 0:05:07  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/E
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
        vector<int> a(3, 0), b(3, 0);
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];

        vector<pair<int, int>> ord;
        ord.push_back({0, 0});
        ord.push_back({0, 2});
        ord.push_back({1, 1});
        ord.push_back({1, 0});
        ord.push_back({2, 2});
        ord.push_back({2, 1});
        sort(ord.begin(), ord.end());

        int ans1 = n;
        do
        {
            vector<int> tmpA = a, tmpB = b;
            for (int i = 0; i <= 6 - 1; ++i)
            {
                int minV = min(tmpA[ord[i].first], tmpB[ord[i].second]);
                tmpA[ord[i].first] -= minV;
                tmpB[ord[i].second] -= minV;
            }

            ans1 = min(ans1, min(tmpA[0], tmpB[1]) + min(tmpA[1], tmpB[2]) + min(tmpA[2], tmpB[0]));
        }
        while (next_permutation(ord.begin(), ord.end()));

        int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

        cout << ans1 << ' ' << ans2 << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426E_RockPaperScissors.in", "r", stdin);
    freopen("CF_1426E_RockPaperScissors.out", "w", stdout);
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