/*
-------------------------------------------------------------------
* @Name:           1114D Flood Fill
* @Author:         
* @Create Time:    2020/7/13 22:10:21  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1114/problem/D
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
        vector<int> a;
        for (int c = 1; c <= n; ++c)
        {
            int tmp; cin >> tmp;
            if (c == 1)               a.push_back(tmp);
            else if (tmp != a.back()) a.push_back(tmp);
        }

        int siz = a.size();
        vector<vector<int>> f(siz, vector<int>(siz, 0));
        for (int len = 1; len <= siz; ++len)
        {
            for (int i = 0; i <= siz - 1; ++i)
            {
                int j = i + len - 1;
                if (j > siz - 1) break;

                if (len == 1) f[i][j] = 1;
                else if (len == 2)
                {
                    if (a[i] == a[j]) f[i][j] = 2;
                    else              f[i][j] = 1;
                }
                else
                {
                    if (i == 8 && j == 14)
                    {
                        for (int __s = 0; __s == 0; ++__s);
                    }

                    f[i][j] = max(f[i][j], f[i + 1][j]);
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                    if (a[i] == a[j]) f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);

                    // if (i == 0 && j == 14)
                    // {
                    //     cout << f[i][j] << "\n";
                    // }                      
                }
                if (i == 8 && j == 14)
                {
                    for (int __s = 0; __s == 0; ++__s);
                } 
                //cout << i << "-" << j << ":" << f[i][j] << " ";
            }
            //cout << "\n";
        }

        cout << siz - (f[0][siz - 1] + 1) / 2 << '\n';
        //cout << "\n" ;
        // for (int i = 0; i <= siz - 1; ++i)
        // {
        //     cout << a[i] << "\n";
        // }
        // for (int i = 0; i <= siz - 1; ++i)
        // {
        //     for (int j = 0; j <= siz - 1; ++j)
        //     {
        //         cout << f[i][j] ;
        //     }
        //     cout << "\n" ;
        // }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1114D_FloodFill.in", "r", stdin);
    freopen("CF_1114D_FloodFill.outc", "w", stdout);
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