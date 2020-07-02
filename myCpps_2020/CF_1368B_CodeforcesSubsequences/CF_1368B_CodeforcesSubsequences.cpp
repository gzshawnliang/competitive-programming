/*
-------------------------------------------------------------------
* @Name:           1368B Codeforces Subsequences
* @Author:         Shawn
* @Create Time:    2020/7/2 22:29:51  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1368/problem/B
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

const ill N = 10;

class solution
{
  public:
    void solve()
    {
        ill k; cin >> k;

        vector<ill> a(N, 1);

        auto f=[&]()
        {
            ill ans = 1;
            for (auto x:a) ans *= x;
            return ans >= k;
        };
        
        ill p = 0;
        while (f() == false)
        {
            ++a[p]; p = (p + 1) % N;
        }

        string s = "codeforces";
        for (ill i = 0; i <= N - 1; ++i)
            for (ill c = 1; c <= a[i]; ++c)
                cout << s[i];
        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1368B_CodeforcesSubsequences.in", "r", stdin);
    freopen("CF_1368B_CodeforcesSubsequences.out", "w", stdout);
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

