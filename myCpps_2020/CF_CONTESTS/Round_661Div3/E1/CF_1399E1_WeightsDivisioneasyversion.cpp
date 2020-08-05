/*
-------------------------------------------------------------------
* @Name:           1399E1 Weights Division (easy version)
* @Author:         Shawn
* @Create Time:    2020/8/5 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/E1
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
    vector<ill> mtime;
    vector<vector<pair<ill, ill>>> g;

    void dfs(ill u, ill las)
    {
        bool flg = true;
        for (auto e:g[u])
        {
            ill v = e.first, w = e.second;
            if (v == las) continue;

            dfs(v, u);
            mtime[u] += mtime[v];
            flg = false;
        }

        if (flg)
        {
            mtime[u] = 1;
            return;
        }
    }

    struct edge
    {
        ill u;
        ill v;
        ill w;
        ill t;
    };

    struct line
    {
        ill w;
        ill t;

        bool operator<(const line & tmp) const
        {
            ill dv1 = (w - w / 2) * t, dv2 = (tmp.w - tmp.w / 2) * tmp.t;
            
            return dv1 < dv2;
        };
    };

  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill N, S; cin >> N >> S;
            
            mtime = vector<ill>(N + 1, 0);
            g = vector<vector<pair<ill, ill>>>(N + 1);
            vector<edge> allE;
            for (ill c = 1; c <= N - 1; ++c)
            {
                ill u, v, w; cin >> u >> v >> w;
                g[u].push_back({v, w});
                g[v].push_back({u, w});

                edge tmp{u, v, w, 0};
                allE.push_back(tmp);
            }

            dfs(1, 0);

            ill tolW = 0;
            priority_queue<line> lnn;
            for (ill i = 0; i <= N - 2; ++i)
            {
                allE[i].t = min(mtime[allE[i].u], mtime[allE[i].v]);

                line tmp{allE[i].w, allE[i].t};
                lnn.push(tmp);

                tolW += tmp.t * tmp.w;
            }

            ill ans = 0;
            while (!lnn.empty() && tolW > S)
            {
                line now = lnn.top(); lnn.pop();

                tolW -= (now.w - now.w / 2) * now.t;
                ++ans;

                now.w /= 2;
                if (now.w > 0)
                {
                    lnn.push(now);
                }
            }

            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1399E1_WeightsDivisioneasyversion.in", "r", stdin);
    freopen("CF_1399E1_WeightsDivisioneasyversion.out", "w", stdout);
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