#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int N = 505;
const ill INF = LLONG_MAX;
const ill MAX_ANS = 1e12;

int main()
{
#ifdef LOCAL_DEBUG
    freopen("PD.in", "r", stdin);
    //freopen("d.out", "w", stdout);
#endif

    int t, caseId = 0;
    cin >> t;
    while (t--)
    {
        int n, m, s, r;
        cin >> n >> m >> s >> r;

        vector<vector<int>> g(n + 1, vector<int>());
        vector<vector<ill>> cost(n + 1, vector<ill>(s + 1, INF));
        
        //vector<vector<int>> recipeID(N);
        vector<vector<int>> recipeID(s+1);

        vector<bitset<N>> done(n + 1);
        vector<vector<int>> recipe(r + 1);
        vector<int> result(r + 1);

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        priority_queue<tuple<ill, int, int>> pq;

        for (int i = 1; i <= n; ++i)
        {
            int sz;
            cin >> sz;
            while (sz--)
            {
                int x;
                cin >> x;
                cost[i][x] = 0;
                pq.push({0LL, i, x});
            }
        }

        for (int i = 1; i <= r; ++i)
        {
            int sz;
            cin >> sz;

            for (int k = 0; k <= sz - 1; ++k)
            {
                int x;
                cin >> x;
                recipe[i].push_back(x);
                recipeID[x].push_back(i);
            }

            // recipe[i] = vector<int>(sz);
            // for (int & x : recipe[i])
            // {
            //     cin >> x;
            //     recipeID[x].push_back(i);
            // }
            cin >> result[i];
        }

        while (!pq.empty())
        {
            ill dist;
            int u, c;
            tie(dist, u, c) = pq.top();
            dist = -dist;
            pq.pop();
            if (cost[u][c] < dist)
                continue;
            done[u][c] = 1;
            for (int id : recipeID[c])
            {
                bool ok = 1;
                ill tot = 0;
                for (int x : recipe[id])
                {
                    tot += cost[u][x];
                    if (!done[u][x])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    int to = result[id];
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

        if (ans > MAX_ANS)
            ans = -1;

        cout << "Case #" << ++caseId << ": " << ans << "\n";
    }
    return 0;
}
