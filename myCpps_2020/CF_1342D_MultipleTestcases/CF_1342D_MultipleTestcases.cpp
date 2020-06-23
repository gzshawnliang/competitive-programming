/*
-------------------------------------------------------------------
* @Name:           1342D Multiple Testcases
* @Author:         Shawn
* @Create Time:    2020/6/24 0:18:19  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1342/problem/D
* @File:           CF_1342D_MultipleTestcases.cpp
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
    vector<int> a;
    void solve()
    {
        int n, k; cin >> n >> k;
        vector<int> a(n), maxCnt(k + 1, 0);
        for (int i = 0; i <= n - 1; ++i) cin >> a[i];
        for (int i = 1; i <= k; ++i)     cin >> maxCnt[i];

        sort(a.begin(), a.end(), greater<int>());

        int ansLen = 0;
        for (int ak = k, i = 0; ak >= 1; --ak)
        {
            while (a[i] == ak && i <= n - 1) ++i;
            ansLen = max(ansLen, (i + maxCnt[ak] - 1) / maxCnt[ak]);
        }

        vector<vector<int>> ansOut(ansLen);
        for (int i = 0; i <= n - 1; ++i)
            ansOut[i % ansLen].push_back(a[i]);

        cout << ansLen << '\n';
        for (int i = 0; i <= ansLen - 1; ++i)
        {
            int siz = ansOut[i].size();
            cout << siz;
            for (int j = 0; j <= siz - 1; ++j)
                cout << ' ' << ansOut[i][j];
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
    freopen("CF_1342D_MultipleTestcases.in", "r", stdin);
    freopen("CF_1342D_MultipleTestcases.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}