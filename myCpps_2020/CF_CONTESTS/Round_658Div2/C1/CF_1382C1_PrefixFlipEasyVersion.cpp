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
 
            auto op=[&](int siz)
            {
                int i = 0, j = siz - 1;
 
                while (i <= j)
                {
                    if (i == j) a[i] = 1 - a[i];
                    else
                    {
                        a[i] = 1 - a[i]; a[j] = 1 - a[j];
                        swap(a[i], a[j]);
                    }
 
                    ++i; --j;
                }
            };
 
            vector<int> ans;
            for (int i = n - 1; i >= 0; --i)
            {
                if (a[i] == b[i]) continue;
 
                if (i == 1)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }
 
                if (i == 0)
                {
                    ans.push_back(1);
                    continue;
                }
 
                if (a[i] == a[0])
                {
                    ans.push_back(i + 1);
 
                    op(i + 1);
                }
                else
                {
 
                    ans.push_back(1);
                    ans.push_back(i + 1);
 
                    op(1);
                    op(i + 1);
                }
            }
 
            cout << ans.size();
            for (auto x:ans) cout << ' ' << x;
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
    freopen("CF_1382C1_PrefixFlipEasyVersion.in", "r", stdin);
    freopen("CF_1382C1_PrefixFlipEasyVersion.out", "w", stdout);
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