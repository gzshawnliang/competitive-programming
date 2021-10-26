/*
-------------------------------------------------------------------
* @Name:           1399D Binary String To Subsequences
* @Author:         Shawn
* @Create Time:    2020/8/5 22:35:21  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/D
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
 
            string s; cin >> s;
            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) a[i] = (s[i] - '0');
 
            vector<int> nxt0(n, n), nxt1(n, n);
            for (int i = n - 2; i >= 0; --i)
            {
                if (a[i + 1] == 0) nxt0[i] = i + 1;
                else               nxt0[i] = nxt0[i + 1];
 
                if (a[i + 1] == 1) nxt1[i] = i + 1;
                else               nxt1[i] = nxt1[i + 1];
            }
 
            auto inr=[&](int i)
            {
                return i >= 0 && i <= n - 1;
            };
 
            int ans = 0, lstI = 0;
            vector<int> col(n, 0);
            while (true)
            {
                bool flg = false;
                while (true)
                {
                    if (lstI > n - 1)
                    {
                        flg = true;
                        break;
                    }
                    else if (col[lstI] == 0)
                    {
                        break;
                    }
                    else
                    {
                        ++lstI;
                    }
                }
 
                if (flg) break;
                
                int i = lstI;
                while (i <= n - 1)
                {
                    col[i] = ans + 1;
                    if (inr(i - 1))
                    {
                        nxt0[i - 1] = nxt0[i];
                        nxt1[i - 1] = nxt1[i];
                    }
 
                    if (a[i] == 0) i = nxt1[i];
                    else           i = nxt0[i];
                }
 
                ++ans;
            }
 
            cout << ans << '\n';
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << col[i];
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
    freopen("CF_1399D_BinaryStringToSubsequences.in", "r", stdin);
    freopen("CF_1399D_BinaryStringToSubsequences.out", "w", stdout);
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