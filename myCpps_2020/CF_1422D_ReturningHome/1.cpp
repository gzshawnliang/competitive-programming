#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
using ull = unsigned long long;
const ill maxN = LONG_LONG_MAX;

class solution
{

    struct myHash
    {
        ull operator()(const pair<ull, ull> &p) const
        {
            return p.first ^ p.second;
            //ull r= ((ull)p.first << 16) | ((ull)p.second && 0xFFFF);
            //return r;
        }
    };

  public:
    void solve()
    {
        ill n, m; cin >> n >> m;
        ill sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;

        unordered_set<pair<ull, ull>, myHash> tmpIn;
        for (int c = 1; c <= m; ++c)
        {
            int x, y; cin >> x >> y;
            tmpIn.insert({x, y});
        }

        m = tmpIn.size();
        int cntI = 0;
        vector<pair<ill, ill>> allTP(m), tx, ty;
        for (auto p:tmpIn)
        {
            allTP[cntI] = p;
            tx.push_back({allTP[cntI].first, cntI});
            ty.push_back({allTP[cntI].second, cntI});
            ++cntI;
        }
        sort(tx.begin(), tx.end()); sort(ty.begin(), ty.end());

        // for(auto i:allTP)
        //     cout << i.first << " " << i.second << "|";

        // cout  << "\n";

        // for(auto i:tx)
        //     cout << i.first << " " << i.second << "|";
        
        // cout  << "\n";
        // for(auto i:ty)
        //     cout << i.first << " " << i.second << "|";

        // cout  << "\n";         

        vector<unordered_set<ill>> g(m);
        for (ill i = 0; i <= m - 2; ++i)
            for (ill j = i + 1; j <= m - 1 && (tx[j].first == tx[i + 1].first); ++j)
                    g[i].insert(j);
        for (ill i = m - 1; i >= 1; --i)
            for (ill j = i - 1; j >= 0 && (tx[j].first == tx[i - 1].first); --j)
                    g[i].insert(j);

        for (ill i = 0; i <= m - 2; ++i)
            for (ill j = i + 1; j <= m - 1 && (ty[j].first == ty[i + 1].first); ++j)
                    g[i].insert(j);
        for (ill i = m - 1; i >= 1; --i)
            for (ill j = i - 1; j >= 0 && (ty[j].first == ty[i - 1].first); --j)
                    g[i].insert(j);

        int id=0;
        for(auto i:g)
        {
            cout << id << ":";
            for(auto j:i)
                cout << j << " ";

            cout << "\n";
            ++id;
        }
        cout << "\n";

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

        for(auto j:d)
                cout << j << " ";
         cout << "\n";

        ill ans = maxN;
        while (!q.empty())
        {
            pair<ill, ill> now = q.top(); q.pop();
            if (now.first > d[now.second]) continue;
            
            pair<ill, ill> np = allTP[now.second];
            ans = min(ans, now.first + abs(np.first - fx) + abs(np.second - fy));

            for (auto i : g[now.second])
            {
                ill tmpD = dis(np, allTP[i]);
                if (tmpD == 0) continue;

                if (now.first + tmpD < d[i])
                {
                    d[i] = now.first + tmpD;
                    q.push({d[i], i});
                }
            }
        }

        ans=min(ans,abs(sx - fx) + abs(sy - fy));

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
    //freopen("CF_1422D_ReturningHome.out", "w", stdout);
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