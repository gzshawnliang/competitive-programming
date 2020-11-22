/*
-------------------------------------------------------------------
* @Name:           149D Coloring Brackets
* @Author:         Shawn
* @Create Time:    2020/11/22 17:26:26  (UTC+08:00)
* @Url:            https://codeforces.com/contest/149/problem/D
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
    ill mod = 1e9 + 7;
    string s;
    vector<int> pir;
    vector<vector<vector<vector<ill>>>> f;

    void dfs(int l, int r)
    {
        if (l == r - 1)
        {
            for (int x = 1; x <= 2; ++x)
            {
                f[l][r][x][0] = 1; f[l][r][0][x] = 1;
            }
        }
        else if (pir[l] == r)
        {
            dfs(l + 1, r - 1);
            for (int i = 0; i <= 2; ++i)
            {
                for (int j = 0; j <= 2; ++j)
                {
                    for (int x = 1; x <= 2; ++x)
                    {
                        if (i != x) f[l][r][x][0] = (f[l][r][x][0] + f[l + 1][r - 1][i][j]) % mod;
                        if (j != x) f[l][r][0][x] = (f[l][r][0][x] + f[l + 1][r - 1][i][j]) % mod;
                    }
                }
            }
        }
        else
        {
            int k = pir[l];
            dfs(l, k); dfs(k + 1, r);
            for (int i = 0; i <= 2; ++i)
            {
                for (int j = 0; j <= 2; ++j)
                {
                    for (int p = 0; p <= 2; ++p)
                    {
                        for (int q = 0; q <= 2; ++q)
                        {
                            if (p > 0 && p == q) continue;

                            f[l][r][i][j] = (f[l][r][i][j] + (f[l][k][i][p] * f[k + 1][r][q][j]) % mod) % mod;
                        }
                    }
                }
            }
        }
    }

    void solve()
    {
        cin >> s;
        int n = s.size();

        pir = vector<int>(n);
        stack<int> st;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                pir[i] = st.top();
                pir[st.top()] = i;
                st.pop();
            }
        }

        f = vector<vector<vector<vector<ill>>>>(n, vector<vector<vector<ill>>>(n, vector<vector<ill>>(3, vector<ill>(3, 0))));

        dfs(0, n - 1);
        ill ans = 0;
        for (int p = 0; p <= 2; ++p)
            for (int q = 0; q <= 2; ++q)
                ans = (ans + f[0][n - 1][p][q]) % mod;
        cout << ans << '\n';
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("CF_149D_ColoringBrackets.in", "r", stdin);
    freopen("CF_149D_ColoringBrackets.out", "w", stdout);
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