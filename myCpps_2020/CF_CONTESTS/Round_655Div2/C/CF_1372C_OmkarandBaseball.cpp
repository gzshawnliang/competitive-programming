/*
-------------------------------------------------------------------
* @Name:           1372C Omkar and Baseball
* @Author:         Shawn
* @Create Time:    2020/7/11 23:05:25  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1372/problem/C
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
            vector<int> a(n, 0), ans;
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i]; --a[i];
                if (a[i] != i) ans.push_back(i);
            }

            int siz = ans.size();

            if (siz == 0)
            {
                cout << "0\n";
                continue;
            }
            else
            {
                bool flg = true;
                for (int i = 1; i <= siz - 1; ++i)
                {
                    if (ans[i] - ans[i - 1] > 1)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg == true)
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "2\n";
                }
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
    freopen("CF_1372C_OmkarandBaseball.in", "r", stdin);
    freopen("CF_1372C_OmkarandBaseball.out", "w", stdout);
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