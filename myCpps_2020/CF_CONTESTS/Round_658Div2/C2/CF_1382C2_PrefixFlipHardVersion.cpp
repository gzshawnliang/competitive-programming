/*
-------------------------------------------------------------------
* @Name:           1382C1 Prefix Flip (Easy Version)
* @Author:         Shawn
* @Create Time:    2020/7/21 22:35:35  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1382/problem/C1
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
    const int maxN = 1e5;

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            string tmpA, tmpB; cin >> tmpA >> tmpB;
 
            vector<int> a(n, 0), b(n, 0);
            for (int i = 0; i <= n - 1; ++i) a[i] = (tmpA[i] == '1');
            for (int i = 0; i <= n - 1; ++i) b[i] = (tmpB[i] == '1');

            vector<int> ans0;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == n - 1)
                {
                    if (a[i] == 1) ans0.push_back(i + 1);
                }
                else
                {
                    if (a[i] != a[i + 1]) ans0.push_back(i + 1);
                }
            }

            vector<int> ans1;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i == n - 1)
                {
                    if (b[i] == 1) ans1.push_back(i + 1);
                }
                else
                {
                    if (b[i] != b[i + 1]) ans1.push_back(i + 1);
                }
            }

            cout << ans0.size() + ans1.size() << '\n';
            for (auto x:ans0) cout << x << ' ';

            int siz = ans1.size();
            for (int i = siz - 1; i >= 0; --i)
            {
                if (i < siz - 1) cout << ' ';
                cout << ans1[i];
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
    freopen("CF_1382C2_PrefixFlipHardVersion.in", "r", stdin);
    freopen("CF_1382C2_PrefixFlipHardVersion.out", "w", stdout);
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