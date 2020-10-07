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
        ill n, m; cin >> n >> m;
        ill sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;

        vector<pair<ill, ill>> allTP(m);
        for (ill i = 0; i <= m - 1; ++i)
            cin >> allTP[i].first >> allTP[i].second;

        auto dis=[&](pair<ill, ill> myP, pair<ill, ill> tpP)
        {
            return (ill)min(abs(myP.first - tpP.first), abs(myP.second - tpP.second));
        };

        vector<ill> d(m, 0);
        priority_queue<pair<ill, ill>, vector<pair<ill, ill>>, greater<pair<ill, ill>>> q;
        for (ill i = 0; i <= m - 1; ++i)
        {
            d[i] = dis({sx, sy}, allTP[i]);
            q.push({d[i], i});
        }

        ill ans = abs(sx - fx) + abs(sy - fy);
        while (!q.empty())
        {
            pair<ill, ill> now = q.top(); q.pop();
            if (now.first > d[now.second]) continue;
            
            pair<ill, ill> np = allTP[now.second];
            ans = min(ans, now.first + abs(np.first - fx) + abs(np.second - fy));

            for (ill i = 0; i <= m - 1; ++i)
            {
                if (i == now.second) continue;

                ill tmpD = now.first + dis(np, allTP[i]);
                if (tmpD < d[i])
                {
                    d[i] = tmpD;
                    q.push({d[i], i});
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
    freopen("CF_1422D_ReturningHome.in", "r", stdin);
    freopen("CF_1422D_ReturningHome.out", "w", stdout);
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