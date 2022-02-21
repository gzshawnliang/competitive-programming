/*
-------------------------------------------------------------------
* @Name:           1632C Strange Test
* @Author:         Shawn
* @Create Time:    2022/2/19 20:11:38  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1632/problem/C
* @Description:    
-------------------------------------------------------------------
        _____
        |_ _|
   n    (O O)    n
   H   _|\_/|_   H
  nHnn/ \___/ \nnHn
 <V VV /     \ VV V>
  \__\/|     |\/__/
*/

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
        while (t--)
        {
            int a,b;
            cin >> a >> b;
            ++b;
            a = a | b;
            cout <<  a << '\n';
        }
        
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1632C_StrangeTest.in", "r", stdin);
    //freopen("CF_1632C_StrangeTest.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}
