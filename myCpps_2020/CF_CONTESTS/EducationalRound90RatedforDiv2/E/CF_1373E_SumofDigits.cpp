/*
-------------------------------------------------------------------
* @Name:           1373E Sum of Digits
* @Author:         Shawn
* @Create Time:    2020/6/25 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/gym/1373/problem/E
* @File:           CF_1373E_SumofDigits.cpp
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

int f(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += (x % 10);
        x /= 10;
    }

    return ans;
}

class solution
{
  public:
    void solve()
    {
        // cout << '\n';
        // for (int x = 2; x <= 1000; ++x)
        // {
        //     cout << f(x) - f(x - 1) << '\n';
        // }

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, k; cin >> n >> k;

            if ((n - k) % k == 0)
            {
                
            }
            
            for (int c = 1; c <= 17; ++c)
            {
                if ()
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
    freopen("CF_1373E_SumofDigits.in", "r", stdin);
    freopen("CF_1373E_SumofDigits.out", "w", stdout);
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