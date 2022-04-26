#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:
    void solve()
    {
        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i)
        {
            int n=8;
            while(true)
            {
                int tmp = 0;
                // for (int c = 1; c <= n / 2; ++c)
                // {
                //     cout << "01";
                //     ++tmp;
                // }
                // for (int c = 1; c <= 4 - tmp; ++c)
                // {
                //     cout << "00";
                // }
                for (int c = 1; c <= 8; ++c)
                {
                    if(c % 2==0)
                        cout << "1";
                    else 
                        cout << "0";
                }                
                cout << '\n';
                cout.flush();
                
                cin >>n;
                if(n==0)
                    break;
            }            
        }

    }
};

signed main()
{
    FastIO;

// #ifdef LOCAL_DEBUG
//     freopen("1.in", "r", stdin);
//     freopen("1.out", "w", stdout);
//     auto startTime = chrono::high_resolution_clock::now();
// #endif

    solution sln1;
    sln1.solve();
    //cout.flush();

// #ifdef LOCAL_DEBUG
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
//          << " ms\n";
// #endif

    return 0;
}