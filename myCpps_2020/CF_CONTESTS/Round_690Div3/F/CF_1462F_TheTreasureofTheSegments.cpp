/*
-------------------------------------------------------------------
* @Name:           1462F The Treasure of The Segments
* @Author:         Shawn
* @Create Time:    2020/12/15 22:35:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1462/problem/F
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

struct cp
{
    ill pos;
    ill type;
    ill index;

    bool operator < (const cp & tmp) const
    {
        if (pos != tmp.pos)
            return pos < tmp.pos;
        else if (type != tmp.type)
            return type > tmp.type;
        else
            return index < tmp.index;
    }
};

class solution
{
  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;

            vector<cp> allP;
            vector<pair<ill, ill>> a(n);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i].first >> a[i].second;

                cp tmpL{a[i].first, 1, i}; allP.push_back(tmpL);
                cp tmpR{a[i].second, -1, i}; allP.push_back(tmpR);
            }

            //sort(a.begin(), a.end());
            sort(allP.begin(), allP.end());

            set<ill> now;
            vector<set<ill>> g(n);
            for (ill i = 0, siz = allP.size(); i <= siz - 1; ++i)
            {
                cp nowP = allP[i];

                for (auto p:now)
                {
                    if (p != allP[i].index)
                    {
                        g[allP[i].index].insert(p);
                        g[p].insert(allP[i].index);
                    }
                }

                if (nowP.type == 1)
                    now.insert(nowP.index);
                else
                    now.erase(nowP.index);
            }

            ill ans = 0;
            for (ill i = 0; i <= n - 1; ++i)
                ans = max(ans, (ill)g[i].size() + 1);
            cout << n - ans << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_1462F_TheTreasureofTheSegments.in", "r", stdin);
    freopen("CF_1462F_TheTreasureofTheSegments.out", "w", stdout);
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