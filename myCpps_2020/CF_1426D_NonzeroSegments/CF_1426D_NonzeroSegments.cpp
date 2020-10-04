/*
-------------------------------------------------------------------
* @Name:           1426D Non-zero Segments
* @Author:         Shawn
* @Create Time:    2020/10/4 22:40:07  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1426/problem/D
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
        ill n; cin >> n;
        vector<ill> a(n, 0);
        for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

        vector<ill> f(n, 0);
        map<ill, ill> mp;
        vector<pair<ill, ill>> ssz;
        for (ill i = 0; i <= n - 1; ++i)
        {
            if (i == 0)
            {
                f[i] = a[i];
                mp[f[i]] = i;
            }
            else
            {
                f[i] = f[i - 1] + a[i];

                if (mp.count(f[i]))
                {
                    ssz.push_back({mp[f[i]] + 1, i});
                }
                else if (f[i] == 0) ssz.push_back({0, i});

                mp[f[i]] = i;
            }
        }

        ill siz = ssz.size();
        sort(ssz.begin(), ssz.end());

        // for (auto p:ssz)
        //     cout << p.first << ' ' << p.second << '\n';

        ill ans = 0;
        if (siz > 0)
        {
            ans = 1;
            ill maxR = ssz[0].second;
            for (ill i = 1; i <= siz - 1; ++i)
            {
                if (ssz[i].first <= maxR - 1 && ssz[i].second >= maxR) continue;
                else if (ssz[i].first <= maxR - 1 && ssz[i].second <= maxR - 1)
                {
                    maxR = ssz[i].second;
                }
                else
                {
                    maxR = max(maxR, ssz[i].second);
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1426D_NonzeroSegments.in", "r", stdin);
    freopen("CF_1426D_NonzeroSegments.out", "w", stdout);
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