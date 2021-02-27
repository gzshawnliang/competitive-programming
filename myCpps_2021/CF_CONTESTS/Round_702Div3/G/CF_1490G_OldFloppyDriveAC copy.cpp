/*
-------------------------------------------------------------------
* @Name:           1490G Old Floppy Drive 
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/G
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
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, tolQ; cin >> n >> tolQ;

            vector<ill> a(n, 0), preSum(n, 0);
            vector<pair<ill, ill>> maxValues;
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                if (i == 0) preSum[i] = a[i];
                else        preSum[i] = a[i] + preSum[i - 1];

                if      (i == 0)                    maxValues.push_back({preSum[i], i});
                else if (preSum[i] > preSum[i - 1]) maxValues.push_back({preSum[i], i});
            }

            ill sizMV = maxValues.size();
            for (ill q = 1LL; q <= tolQ; ++q)
            {
                if (q > 1) cout << ' ';
                ill input; cin >> input;

                auto tmpPos = lower_bound(maxValues.begin(), maxValues.end(), make_pair(input, 0LL)) - maxValues.begin();
                if (tmpPos == sizMV)
                {
                    if (preSum[tmpPos] <= 0)
                    {
                        cout << -1;
                    }
                    else
                    {
                        ill cntLoops = (input - maxValues.back().first) / preSum.back();
                        if (input > maxValues.back().first + cntLoops * preSum.back()) ++cntLoops;
                        auto tmpPos2 = lower_bound(maxValues.begin(), maxValues.end(), make_pair(input - cntLoops * preSum.back(), 0LL)) - maxValues.begin();

                        cout << cntLoops * n + maxValues[tmpPos2].second;
                    }
                }
                else
                {
                    cout << maxValues[tmpPos].second;
                }
            }
            cout << '\n';
        }

        for(int _s_=0;_s_==0;++_s_);
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490G_OldFloppyDrive.in", "r", stdin);
    freopen("CF_1490G_OldFloppyDrive.out", "w", stdout);
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