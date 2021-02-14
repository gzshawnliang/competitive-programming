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
        ill n, k, m; cin >> n >> k >> m;
        vector<pair<int, int>> exgs(k);
        for (int i = 0; i <= k - 1; ++i)
        {
            cin >> exgs[i].first >> exgs[i].second;
        }

        if (m < k)
        {
            vector<int> a(n + 1, 0);
            vector<set<int>> path(n + 1);
            for (int i = 1; i <= n; ++i)
            {
                a[i] = i;
                path[i].insert(i);
            } 
            for (int i = 0; i <= m - 1; ++i)
            {
                int u = exgs[i].first, v = exgs[i].second;
                path[a[u]].insert(v);
                path[a[v]].insert(u);

                swap(a[u], a[v]);
            }

            for (int u = 1; u <= n; ++u)
            {
                cout << path[u].size() << '\n';
            }
            return;
        }

        vector<int> a(n + 1, 0);
        vector<vector<pair<int, int>>> path(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            a[i] = i;
            path[i].push_back({0, i});
        } 
        for (int i = 0; i <= k - 1; ++i)
        {
            int u = exgs[i].first, v = exgs[i].second;
            path[a[u]].push_back({i + 1, v});
            path[a[v]].push_back({i + 1, u});

            swap(a[u], a[v]);
        }

        // vector<int> to(n + 1, 0);
        // for (int u = 1; u <= n; ++u)
        //     to[a[u]] = u;

        vector<int> ans(n + 1, 0);
        for (int u = 1; u <= n; ++u)
        {
            if (ans[u] > 0) continue;

            vector<int> ring; ring.push_back(u);
            
            int stt = path[u].back().second;
            while (stt != u)
            {
                ring.push_back(stt);
                stt = path[stt].back().second;
            }

            int res = 0;
            vector<int> posCnt(n + 1, 0);

            for (auto pr:path[u])
            {
                if (posCnt[pr.second] == 0) ++res;
                ++posCnt[pr.second];
            }

            bool flg = true;
            ill sizR = ring.size(), sizL = m / k;
            if (sizL > sizR)
            {
                flg = false;
                sizL = sizR;
            }
            for (int i = 1; i <= sizL - 1; ++i)
            {
                for (auto pr:path[ring[i]])
                {
                    if (posCnt[pr.second] == 0) ++res;
                    ++posCnt[pr.second];
                }
            }

            int head = 0, tail = head + sizL - 1;
            while (head <= sizR - 1)
            {
                tail = (tail + 1) % sizR;

                vector<int> tmp;
                if (flg)
                {
                    for (auto pr:path[ring[tail]])
                    {
                        if (pr.first <= m % k)
                        {
                            if (posCnt[pr.second] == 0) ++res;
                            ++posCnt[pr.second];
                            tmp.push_back(pr.second);
                        }
                    }
                }
                ans[ring[head]] = res;

                ++head;
                for (auto x:tmp)
                {
                    --posCnt[x];
                    if (posCnt[x] == 0) --res;
                }

                for (auto pr:path[ring[head - 1]])
                {
                    --posCnt[pr.second];
                    if (posCnt[pr.second] == 0) --res;
                }

                for (auto x:path[ring[tail]])
                {
                    if (posCnt[x.second] == 0) ++res;
                    ++posCnt[x.second];
                }
            }
        }

        for (int u = 1; u <= n; ++u)
        {
            cout << ans[u] << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("DanceMooves.in", "r", stdin);
    freopen("DanceMooves.out", "w", stdout);
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