/*
-------------------------------------------------------------------
* @Name:           1385G Columns Swaps
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:20  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/G
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
    vector<int> col, pth;
    vector<vector<pair<int, int>>> g;

    bool dfs(int u, int las)
    {
        pth.push_back(u);
        for (auto v:g[u])
        {
            if (v.first == las) continue;

            int nxtCol = -1;
            if (v.second == 1) nxtCol = col[u];
            else               nxtCol = 1 - col[u];

            if (col[v.first] != -1)
            {
                return col[v.first] == nxtCol;
            }
            
            col[v.first] = nxtCol;
            if (dfs(v.first, u) == false) return false;
        }
        return true;
    }

  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            // vector<int> a(n, 0), b(n, 0);
            // for (int i = 0; i <= n - 1; ++i) cin >> a[i];
            // for (int i = 0; i <= n - 1; ++i) cin >> b[i];

            if (tcc == 17)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            vector<int> cntX(n + 1, 0);
            vector<vector<pair<int, int>>> pos(n + 1);
            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp; cin >> tmp;
                ++cntX[tmp];
                pos[tmp].push_back({i, 0});
            }

            for (int i = 0; i <= n - 1; ++i)
            {
                int tmp; cin >> tmp;
                ++cntX[tmp];
                pos[tmp].push_back({i, 1});
            }

            bool flg = true;
            for (int x = 1; x <= n; ++x)
            {
                if (cntX[x] != 2)
                {
                    flg = false;
                }
            }

            if (flg == false)
            {
                cout << "-1\n";
                continue;
            }

            col.assign(n, -1);
            g.assign(n, vector<pair<int, int>>());
            for (int x = 1; x <= n; ++x)
            {
                g[pos[x][0].first].push_back({pos[x][1].first, pos[x][0].second != pos[x][1].second});
                g[pos[x][1].first].push_back({pos[x][0].first, pos[x][0].second != pos[x][1].second});
            }

            vector<int> ans;
            for (int u = 0; u <= n - 1; ++u)
            {
                if (col[u] == -1)
                {
                    col[u] = 0;
                    pth.clear();
                    if (dfs(u, -1) == false)
                    {
                        flg = false;
                        break;
                    }

                    vector<int> tmp;
                    for (auto v:pth)
                        if (col[v] == 1)
                            tmp.push_back(v + 1);
                    
                    if (tmp.size() > pth.size() - tmp.size())
                    {
                        tmp.clear();
                        for (auto v:pth)
                            if (col[v] == 0)
                                tmp.push_back(v + 1);
                    }

                    for (auto v:tmp) ans.push_back(v);
                }
            }

            if (flg == true)
            {
                int siz = ans.size();
                cout << siz << '\n';
                for (int i = 0; i <= siz - 1; ++i)
                {
                    if (i > 0) cout << ' ';
                    cout << ans[i];
                }
                cout << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385G_ColumnsSwaps.in", "r", stdin);
    freopen("CF_1385G_ColumnsSwaps.out", "w", stdout);
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