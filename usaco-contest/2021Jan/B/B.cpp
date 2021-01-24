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
    const ill inf = INT_MAX;

    void solve()
    {
        ill n, k; cin >> n >> k;

        vector<ill> b(n + 1, 0);
        vector<vector<ill>> bCat(k + 1);
        for (ill i = 1; i <= n; ++i)
        {
            cin >> b[i];
            bCat[b[i]].push_back(i);
        } 

        //vector<vector<ill>> a(k + 1, vector<ill>(k + 1, 0));
        vector<vector<ill>> g(k + 1);
        for (ill i = 1; i <= k; ++i)
        {
            string tmp; cin >> tmp;
            for (ill j = 1; j <= k; ++j)
            {
                if (tmp[j - 1] == '1') g[i].push_back(j);
            }
        }

        vector<ill> d(n + 1, inf);
        priority_queue<pair<ill, ill>, vector<pair<ill, ill>>, greater<pair<ill, ill>>> q;
        q.push({0, 1}); d[1] = 0;
        while (!q.empty())
        {
            ill nowU = q.top().second, nowD = q.top().first; q.pop();
            for (auto bre:g[b[nowU]])
            {
                for (auto v:bCat[bre])
                {
                    if (d[v] > nowD + abs(v - nowU))
                    {
                        d[v] = nowD + abs(v - nowU);
                        q.push({nowD + abs(v - nowU), v});
                    }
                }
            }
        }

        cout << d[n] << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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