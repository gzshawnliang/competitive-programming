/*
-------------------------------------------------------------------
* @Name:           1466C Canine poetry
* @Author:         Shawn
* @Create Time:    2020/12/30 22:35:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1466/problem/C
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
            string s; cin >> s;
            int n = s.size();

            vector<int> farR(n, 0);
            for (int i = n - 2; i >= 0; --i)
            {
                if (s[i] == s[i + 1])
                {
                    farR[i] = farR[i + 1] + 1;
                }
            }

            int ans = 0;
            for (int i = 0; i <= n - 1; ++i)
            {
                int ro = 0;
                if (farR[i] > 1)
                {
                    for (int j = i; j <= i + farR[i]; ++j)
                    {
                        if (ro > 0)
                        {
                            s[j] = '#';
                            ++ans;
                        }
                        ro = (ro + 1) % 3;
                    }
                    i += farR[i];
                }   
            }

            for (int i = 0; i <= n - 1; ++i)
            {
                int l = 1;
                while (i - l >= 0 && i + l <= n - 1)
                {
                    if (s[i - l] != s[i + l] || s[i + l] == '#' || s[i - l] == '#') break;
                    ++l;
                }
                --l;
                
                if (l > 0)
                {
                    s[i + 1] = '#';
                    ++ans;
                }
                i += l;
            }

            for (int i = 0; i <= n - 2; ++i)
            {
                if (s[i] != s[i + 1]) continue;

                int l = 1;
                while (i - l >= 0 && i + 1 + l <= n - 1)
                {
                    if (s[i - l] != s[i + 1 + l] || s[i + 1 + l] == '#' || s[i - l] == '#') break;
                    ++l;
                }
                --l;
                
                if (l > 0)
                {
                    s[i + 1] = '#';
                    ++ans;
                }
                i += (l + 1);
            }

            cout << ans << '\n';
            cout << s << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1466C_Caninepoetry.in", "r", stdin);
    freopen("CF_1466C_Caninepoetry.out", "w", stdout);
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
