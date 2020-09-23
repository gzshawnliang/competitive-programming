#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);               \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
    const ill inf = 10e12;

  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, m, s, r; cin >> n >> m >> s >> r;
            vector<vector<ill>> f(n + 1, vector<ill>(s + 1, inf)), g(n + 1);
            for (ill c = 1; c <= m; ++c)
            {
                ill u, v; cin >> u >> v;
                g[u].push_back(v); g[v].push_back(u);
            }
            
            priority_queue<tuple<ill, ill, ill>, vector<tuple<ill, ill, ill>>, greater<tuple<ill, ill, ill>>> q;
            for (ill u = 1; u <= n; ++u)
            {
                ill tol; cin >> tol;
                for (ill c = 1; c <= tol; ++c)
                {
                    ill st; cin >> st;
                    f[u][st] = 0;

                    q.push({0, u, st});
                }
            }

            vector<pair<vector<ill>, ill>> recs(r);
            for (ill i = 0; i <= r - 1; ++i)
            {
                ill tol; cin >> tol;
                recs[i].first.assign(tol, 0);
                for (ill j = 0; j <= tol - 1; ++j) cin >> recs[i].first[j];

                cin >> recs[i].second;
            }

            while (!q.empty())
            {
                ill nowD = get<0>(q.top()), u = get<1>(q.top()), st = get<2>(q.top()); q.pop();

                if (f[u][st] < nowD) continue;
                    
                for (auto v:g[u])
                {
                    if (f[v][st] > nowD + 1)
                    {
                        f[v][st] = nowD + 1;
                        q.push({f[v][st], v, st});
                    }
                }

                for (auto nr:recs)
                {
                    bool flg = false;
                    ill tmp = 0;
                    for (auto st2:nr.first)
                    {
                        if (f[u][st2] == inf)
                        {
                            tmp = inf;
                            break;
                        }

                        if (st2 == st) flg = true;

                        tmp += f[u][st2];
                    }
                    
                    if (f[u][nr.second] > tmp && flg == true)
                    {
                        f[u][nr.second] = tmp;
                        q.push({f[u][nr.second], u, st});
                    }
                }
            }

            ill ans = inf;
            for (ill u = 1; u <= n; ++u) ans = min(ans, f[u][1]);
            if (ans >= inf) ans = -1;

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PD.in", "r", stdin);
    freopen("PD.out", "w", stdout);
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