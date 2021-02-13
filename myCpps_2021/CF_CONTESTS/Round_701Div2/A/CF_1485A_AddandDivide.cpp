/*
-------------------------------------------------------------------
* @Name:           1485A Add and Divide
* @Author:         Shawn
* @Create Time:    2021/2/12 22:50:15  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1485/problem/A
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
    int val(int a, int b, int times)
    {
        for (int c = 1; c <= times && a > 0; ++c) a /= b;
        return a;
    }

    bool check(int a, int b, int tolA)
    {
        int l = 0, r = tolA;
        while (l < r)
        {
            if (l + 1 == r)
            {
                if (val(a, b + l, tolA - l) == 0 || val(a, b + r, tolA - r) == 0) return true;
                return false;
            }

            int mid = (l + r) / 2;
            int midmidR = 0;
            if (mid + 1 == r) midmidR = (mid + r) / 2 +1;
            else              midmidR = (mid + r) / 2;
            
            if (midmidR == r)
            {
                if (val(a, b + l, tolA - l) == 0 || val(a, b + r, tolA - r) == 0 || val(a, b + mid, tolA - mid) == 0) return true;
                return false;
            }

            int valMid = val(a, b + mid, tolA - mid),
                valMidmidR = val(a, b + midmidR, tolA - midmidR);
            if (valMid == 0 || valMidmidR == 0) return true;

            if (valMid < valMidmidR)
            {
                r = midmidR;
            }
            else
            {
                l = mid;
            }
        }

        return false;
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int a, b; cin >> a >> b;

            int l = 0, r = a + 1;
            while (l <= r)
            {
                if (r - l <= 1)
                {
                    if (check(a, b, l) == false) l = r;
                    break;
                }
                else
                {
                    int mid = (l + r) / 2;
                    if (check(a, b, mid))
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }

            cout << l << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1485A_AddandDivide.in", "r", stdin);
    freopen("CF_1485A_AddandDivide.out", "w", stdout);
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