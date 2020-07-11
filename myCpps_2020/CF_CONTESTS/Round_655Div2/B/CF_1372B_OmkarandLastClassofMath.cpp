/*
-------------------------------------------------------------------
* @Name:           1372B Omkar and Last Class of Math
* @Author:         Shawn
* @Create Time:    2020/7/11 23:05:24  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1372/problem/B
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

    const int N = sqrt(1e9) + 1;

    // int gcd(int a, int b)
    // {
    //     while(b != 0)
    //     {
    //         int r = b;
    //         b = a % b;
    //         a = r;
    //     }
    //     return a;
    // }
    
    void solve()
    {
        vector<bool> isPrime(N, true);
        isPrime[0] = false; isPrime[1] = false;
        vector<int> primes;
        
        for (int i = 2; i <= N; ++i)
        {
            if (isPrime[i] == true)
            {
                primes.push_back(i);

                for (int j = i * i; j <= N; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            if (n % 2 == 0)
            {
                cout << n / 2 << ' ' << n / 2 << '\n';
            }
            else
            {
                int minX = -1;
                for (auto x:primes)
                {
                    if (n % x == 0)
                    {
                        minX = x;
                        break;
                    }
                }

                if (minX == -1)
                {
                    cout << 1 << ' ' << n - 1 << '\n';
                }
                else
                {
                    int lft = n / minX;

                    cout << lft << ' ' << n - lft << '\n';
                }
            }
        }

        // for (int x = 1; x <= 100; x += 2)
        // {
        //     int minV = x, ansA = -1, ansB = -1;
        //     for (int y = 1; y <= x / 2; ++y)
        //     {
        //         if (y * (x - y) / gcd(y, x - y) < minV)
        //         {
        //             ansA = y; ansB = x - y;
        //             minV = y * (x - y) / gcd(y, x - y);
        //         }
        //     }

        //     if (ansA != 1) cout << ansA << ' ' << ansB << '\n';
        // }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1372B_OmkarandLastClassofMath.in", "r", stdin);
    freopen("CF_1372B_OmkarandLastClassofMath.out", "w", stdout);
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