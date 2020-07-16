/*
-------------------------------------------------------------------
* @Name:           1345D Monopole Magnets
* @Author:         Shawn
* @Create Time:    2020/7/16 22:56:45  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1345/problem/D
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
  public:
    int n = 0, m = 0;
    vector<vector<int>> a;

    const vector<pair<int, int>> pls = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool g(int y, int x)
    {
        return y >= 0 && y <= n - 1 && x >= 0 && x <= m - 1;
    };

    void dfs(int y, int x)
    {
        a[y][x] = 0;

        for (int p = 0; p <= 3; ++p)
        {
            int nxtY = y + pls[p].first, nxtX = x + pls[p].second;

            if (g(nxtY, nxtX))
                if (a[nxtY][nxtX] == 1) dfs(nxtY, nxtX);
        }
    }

    void solve()
    {
        cin >> n >> m;
        
        a.assign(n, vector<int>(m, 0));
        //vector<vector<int>> a(n, vector<int>(n, 0));
        for (int y = 0; y <= n - 1; ++y)
        {
            string tmp; cin >> tmp;
            for (int x = 0; x <= m - 1; ++x)
            {
                a[y][x] = (tmp[x] == '#');
            }
        }

        bool flg = true;
        int cntER = 0;
        for (int y = 0; y <= n - 1 && flg == true; ++y)
        {
            int las = -1;
            for (int x = 0; x <= m - 1 && flg == true; ++x)
            {
                if (a[y][x] == 1)
                {
                    if (x - las > 1 && las >= 0)
                    {
                        flg = false; break;
                    }
                    las = x;
                }
            }

            if (las == -1) ++cntER;
        }

        int cntEC = 0;
        for (int x = 0; x <= m - 1 && flg == true; ++x)
        {
            int las = -1;
            for (int y = 0; y <= n - 1 && flg == true; ++y)
            {
                if (a[y][x] == 1)
                {
                    if (y - las > 1 && las >= 0)
                    {
                        flg = false; break;
                    }
                    las = y;
                }
            }

            if (las == -1) ++cntEC;
        }

        if ((cntER > 0 && cntEC == 0) || (cntER == 0 && cntEC > 0)) flg = false;

        if (flg == false)
        {
            cout << "-1\n";
            return;
        }
        
        int ans = 0;
        for (int y = 0; y <= n - 1 && flg == true; ++y)
        {
            for (int x = 0; x <= m - 1 && flg == true; ++x)
            {
                if (a[y][x] == 1)
                {
                    ++ans;
                    dfs(y, x);
                }
            }
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1345D_MonopoleMagnets.in", "r", stdin);
    freopen("CF_1345D_MonopoleMagnets.out", "w", stdout);
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