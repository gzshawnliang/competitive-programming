/*
-------------------------------------------------------------------
* @Name:           1368D AND, OR and square sum
* @Author:         Thomas
* @Create Time:    2020/7/3 18:56:43  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1368/problem/D
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
#include "MyRandom.h"
#endif

#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

class solution
{
  public:
    vector<ull> a;
    void solve()
    {
        int n = 0;
        cin >> n;
        

        a.assign(n,0);

        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
        }
        // bitset<16> x(a[1]);
        // bitset<16> y(a[2]);
        random rdNum;              //note:随机数
        for (int i = 0; i <= 10 - 1; ++i)
        {
            int ai=rdNum.GetRand(1, 20);
            int aj=rdNum.GetRand(1, 20);

            bitset<6> x(ai);
            bitset<6> y(aj);        
            cout << setw(4) << x.to_ullong() << ": " <<  x.to_string() << " " << "\n";
            cout << setw(4) << y.to_ullong() << ": " <<  y.to_string() << " " << "\n";
            cout <<  "---------------------------" << "\n";
            cout << setw(4) << (x & y).to_ullong() << ": " << (x & y).to_string() << " " << " &\n";
            cout <<  setw(4) << (x | y).to_ullong() << ": " << (x | y).to_string() << " " << " |\n";            

            cout << "\n";
        }

        assert(n > 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1368D_ANDORandsquaresum.in", "r", stdin);
    //freopen("CF_1368D_ANDORandsquaresum.out", "w", stdout);
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



