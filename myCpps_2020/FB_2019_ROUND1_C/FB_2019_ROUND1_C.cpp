/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/14 23:46:59  (UTC+08:00)
* @Url:            
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
const int inf = INT_MAX / 3;

class EdmondsKarp
{

  private:
    vector<vector<int>> bandwidth;
    int n;

    int bfs(int s, int t, vector<int> & parent)
    {
        //vector<vector<int>> bandwidth = *a;
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, inf});

        while (!q.empty())
        {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next = 1; next <= n; ++next)
            {
                if (parent[next] == -1 && bandwidth[cur][next] > 0 && cur != next)
                {
                    parent[next] = cur;
                    int new_flow = min(flow, bandwidth[cur][next]);
                    if (next == t)
                    {
                        return new_flow;
                    }
                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

  public:
    EdmondsKarp(vector<vector<int>> & sourGraph, int size1)
    {
        this->n = size1;
        this->bandwidth = sourGraph;
    }

    int Maxflow(int s, int t)
    {
        int flow = 0;

        while (true)
        {
            vector<int> parent(n + 1, -1);
            int new_flow = bfs(s, t, parent);
            if (new_flow == 0)
            {
                break;
            }
            //cout << new_flow << " ";
            flow += new_flow;
            int cur = t;
            while (cur != s)
            {
                int prev = parent[cur];
                bandwidth[prev][cur] -= new_flow;
                bandwidth[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};


class solution
{
  public:
    void solve()
    {
        auto andL=[&](pair<int, int> l1, pair<int, int> l2)
        {
            if (l1.first > l2.first) swap(l1, l2);
            
            if (l2.second <= l1.second)
            {
                return l2;
            }
            else if (l2.first <= l1.second)
            {
                return make_pair(l2.first, l1.second);
            }
            else
            {
                return make_pair(l1.first, l1.first);
            }
        };

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, h; cin >> n >> h;

            vector<tuple<int, int, int>> allL(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                int x, y1, y2; cin >> x >> y1 >> y2;
                allL[i] = {x, y1, y2};
            }

            sort(allL.begin(), allL.end());

            vector<vector<int>> a(n + 3, vector<int>(n + 3, 0));
            for (int i = 0; i <= n - 1; ++i)
            {
                vector<pair<int, int>> q;
                q.push_back({get<1>(allL[i]), get<2>(allL[i])});

                if (i + 2 == 4)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }
                
                for (int j = i + 1; j <= n - 1; ++j)
                {
                    vector<pair<int, int>> tmp = q; q.clear();

                    int res = 0;
                    pair<int, int> now = {get<1>(allL[j]), get<2>(allL[j])};
                    for (auto l : tmp)
                    {
                        pair<int, int> same = andL(l, now);

                        if (same.second > same.first)
                        {
                            res += same.second - same.first;

                            pair<int, int> l1 = {l.first, same.first},
                                           l2 = {same.second, l.second};

                            if (l1.second > l1.first) q.push_back(l1);
                            if (l2.second > l2.first) q.push_back(l2);
                        }
                        else
                        {
                            q.push_back(l);
                        }
                    }

                    a[i + 2][j + 2] = res;
                    a[j + 2][i + 2] = res;
                }
            }

            for (int i = 0; i <= n - 1; ++i)
            {
                if (get<1>(allL[i]) == 0)
                {
                    a[1][i + 2] = inf;
                    a[i + 2][1] = inf;
                }
            }

            for (int i = 0; i <= n - 1; ++i)
            {
                if (get<2>(allL[i]) == h)
                {
                    a[n + 2][i + 2] = inf;
                    a[i + 2][n + 2] = inf;
                }
            }

            // for (int u = 1; u <= n + 2; ++u)
            // {
            //     for (int v = u + 1; v <= n + 2; ++v)
            //     {
            //         if (a[u][v] > 0) cout << u << ' ' << v << ' ' << a[u][v] << '\n';
            //     }
            // }

            EdmondsKarp EdmondsKarp1(a, n + 2);
            int ans = EdmondsKarp1.Maxflow(1, n + 2);

            cout << "Case #" << tcc << ": " << ((ans >= inf) ? -1 : ans) << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND1_C.in", "r", stdin);
    freopen("FB_2019_ROUND1_C.out", "w", stdout);
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