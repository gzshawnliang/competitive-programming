/*
-------------------------------------------------------------------
* @Name:           1132F Clear the String
* @Author:         Shawn
* @Create Time:    2020/7/24 23:03:33  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1132/problem/F
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
    string s;
    vector<vector<int>> f;

    int dfs(int l, int r)
    {
        if (f[l][r] != -1) return f[l][r];
        
        if      (l > r)  return f[l][r] = 0;
        else if (l == r) return f[l][r] = 1;

        int res = 1 + dfs(l + 1, r);
        for (int i = l + 1; i <= r; ++i)
        {
            if (s[l] == s[i])
            {
                res = min(res, dfs(l + 1, i - 1) + dfs(i, r));
            }
        }

        return f[l][r] = res;
    }

    void solve()
    {
        int n; cin >> n;
        cin >> s;

        f.assign(n, vector<int>(n + 1, -1));
        cout << dfs(0, n - 1) << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1132F_CleartheString.in", "r", stdin);
    freopen("CF_1132F_CleartheString.out", "w", stdout);
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