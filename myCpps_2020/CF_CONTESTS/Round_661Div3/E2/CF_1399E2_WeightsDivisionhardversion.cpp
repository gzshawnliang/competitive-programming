/*
-------------------------------------------------------------------
* @Name:           1399E2 Weights Division (hard version)
* @Author:         Shawn
* @Create Time:    2020/8/5 22:35:22  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1399/problem/E2
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
    vector<int> mtime;
    vector<vector<pair<int, int>>> g;

    void dfs(int u, int las)
    {
        bool flg = true;
        for (auto e:g[u])
        {
            int v = e.first, w = e.second;
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
        int u;
        int v;
        int w;
    };

    struct line
    {
        int w;
        int t;

        bool operator<(const line & tmp) const
        {
            int dv1 = (w - w / 2) * t, dv2 = (tmp.w - tmp.w / 2) * tmp.t;
            
            return dv1 < dv2;
        };
    };

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int N, S; cin >> N >> S;
            
            mtime = vector<int>(N + 1, 0);
            g = vector<vector<pair<int, int>>>(N + 1);
            vector<edge> allE1, allE2;
            for (int c = 1; c <= N - 1; ++c)
            {
                int u, v, w, cst; cin >> u >> v >> w >> cst;
                g[u].push_back({v, w});
                g[v].push_back({u, w});

                edge tmp{u, v, w};
                if (cst == 1) allE1.push_back(tmp);
                else        allE2.push_back(tmp);
            }

            dfs(1, 0);

            int tolW = 0;
            priority_queue<line> lnn1, lnn2;
            for (auto e:allE1)
            {
                line tmp{e.w, min(mtime[e.u], mtime[e.v])};
                lnn1.push(tmp);

                tolW += tmp.t * tmp.w;
            }

            for (auto e:allE2)
            {
                line tmp{e.w, min(mtime[e.u], mtime[e.v])};
                lnn2.push(tmp);

                tolW += tmp.t * tmp.w;
            }

            auto cnr=[&](line l)
            {
                return (l.w - l.w / 2) * l.t;
            };

            int ans = 0;
            while (tolW > S)
            {
                if (lnn1.empty())
                {
                    line now = lnn2.top(); lnn2.pop();

                    tolW -= (now.w - now.w / 2) * now.t;
                    ans += 2;

                    now.w /= 2;
                    if (now.w > 0)
                    {
                        lnn2.push(now);
                    }
                }
                else if (lnn2.empty())
                {
                    line now = lnn1.top(); lnn1.pop();

                    tolW -= (now.w - now.w / 2) * now.t;
                    ++ans;

                    now.w /= 2;
                    if (now.w > 0)
                    {
                        lnn1.push(now);
                    }
                }
                else
                {
                    line now1E1 = lnn1.top();

                    if (tolW - cnr(now1E1) <= S)
                    {
                        ++ans;
                        break;
                    }

                    if (lnn1.size() >= 1)
                    {
                        lnn1.pop();
                        
                        line hlfnow1E1 = {now1E1.w / 2, now1E1.t};
                        
                        line now2E1 = hlfnow1E1;
                        if (lnn1.empty() == false)
                            if (now2E1 < lnn1.top()) now2E1 = lnn1.top();
                        lnn1.push(now1E1);

                        line nowE2 = lnn2.top();

                        if (cnr(now1E1) + cnr(now2E1) > cnr(nowE2))
                        {
                            lnn1.pop();
                            lnn1.push(hlfnow1E1);

                            lnn1.pop();
                            line hlfnow2E1 = {now2E1.w / 2, now2E1.t};
                            lnn1.push(hlfnow2E1);

                            tolW -= cnr(now1E1) + cnr(now2E1);
                        }
                        else
                        {
                            lnn2.pop();
                            line hlfnowE2 = {nowE2.w / 2, nowE2.t};
                            lnn2.push(hlfnowE2);

                            tolW -= cnr(nowE2);
                        }

                        ans += 2;
                    }
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
    freopen("CF_1399E2_WeightsDivisionhardversion.in", "r", stdin);
    freopen("CF_1399E2_WeightsDivisionhardversion.out", "w", stdout);
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