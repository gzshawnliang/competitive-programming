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
            ill n, m; cin >> n >> m;

            ill oneLap = 0;
            vector<ill> a(n);
            vector<pair<ill, ill>> f;
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                oneLap += a[i];

                if (f.size() == 0)
                {
                    f.push_back({oneLap, i});
                }
                else if (oneLap > f.back().first)
                {
                    f.push_back({oneLap, i});
                }
            }

            ill sizF = f.size();
            for (ill c = 1; c <= m; ++c)
            {
                if (c == 3)
                {
                    for(ill _s_=0;_s_==0;++_s_);
                }

                if (c > 1) cout << ' ';
                ill qx; cin >> qx;

                if (oneLap <= 0)
                {
                    ill pos = lower_bound(f.begin(), f.end(), make_pair(qx, 0LL)) - f.begin();
                    if (pos == sizF)
                    {
                        cout << -1;
                    }
                    else if (f[pos].first < qx)
                    {
                        cout << -1;
                    }
                    else
                    {
                        cout << f[pos].second + 1 - 1;
                    }
                }
                else
                {
                    bool flg = true;
                    ill pos = lower_bound(f.begin(), f.end(), make_pair(qx, 0LL)) - f.begin();
                    if (pos < sizF)
                    {
                        cout << f[pos].second + 1 - 1;
                        flg = false;
                    }

                    if (flg)
                    {
                        if (qx % oneLap == 0)
                        {
                            cout << (qx / oneLap) * (n) - 1;
                        }
                        else
                        {
                            ill pos = lower_bound(f.begin(), f.end(), make_pair(qx % oneLap, 0LL)) - f.begin();
                        
                            cout << (qx / oneLap) * (n) + f[pos].second + 1 - 1;
                        }
                    }
                }
            }
            cout << '\n';
        }
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