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

using ill = long long int;

const ill INF = LLONG_MAX / 2;
const ill MAX_ANS = 1e12;

class solution
{
  public:
    void solve()
    {
        int t, caseId = 0;
        cin >> t;
        while (t--)
        {
            int n, m, s, r;
            cin >> n >> m >> s >> r;

            vector<vector<int>> g(n + 1, vector<int>());
            while (m--)
            {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }

            priority_queue<tuple<ill, int, int>> pq;

            vector<vector<ill>> cost(n + 1, vector<ill>(s + 1, INF));
            for (int i = 1; i <= n; ++i)
            {
                int sCount;
                cin >> sCount;
                while (sCount--)
                {
                    int x;
                    cin >> x;
                    cost[i][x] = 0;
                    pq.push({0LL, i, x});
                }
            }

            vector<pair<vector<int>, int>> recipe(r + 1);
            vector<vector<int>> recipeId(s + 1);
            
            for (int i = 1; i <= r; ++i)
            {
                int sCount;
                cin >> sCount;

                while (sCount--)
                {
                    int x;
                    cin >> x;
                    recipe[i].first.push_back(x);
                    recipeId[x].push_back(i);
                }
                cin >> recipe[i].second;
            }
            
            vector<vector<int>> done(n + 1, vector<int>(s + 1, 0));
            while (!pq.empty())
            {
                #if __cplusplus <= 201403L          //c++14 c++11  only
                    ill dist;
                    int u, c;
                    tie(dist, u, c) = pq.top();
                #else
                    auto [dist,u,c] =pq.top();        //c++17 only
                #endif

                dist = -dist;
                pq.pop();
                if (cost[u][c] < dist)
                    continue;

                done[u][c] = 1;
                for (int id : recipeId[c])
                {
                    bool ok = true;
                    ill tot = 0;
                    for (int x : recipe[id].first)
                    {
                        tot += cost[u][x];
                        if (done[u][x] == 0)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                    {
                        int to = recipe[id].second;
                        if (cost[u][to] > tot)
                        {
                            cost[u][to] = tot;
                            pq.push({-cost[u][to], u, to});
                        }
                    }
                }
                for (int v : g[u])
                {
                    if (cost[v][c] > cost[u][c] + 1)
                    {
                        cost[v][c] = cost[u][c] + 1;
                        pq.push({-cost[v][c], v, c});
                    }
                }
            }

            ill ans = INF;
            for (int i = 1; i <= n; ++i)
                ans = min(ans, cost[i][1]);

            if (ans >= MAX_ANS)
                ans = -1;

            ++caseId;
            cout << "Case #" << caseId << ": " << ans << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    //cerr << __cplusplus << endl;
    freopen("PD.in", "r", stdin);
    //freopen("PD.out", "w", stdout);
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