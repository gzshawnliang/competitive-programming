/*
-------------------------------------------------------------------
* @Name:           1385D a-Good String
* @Author:         Shawn
* @Create Time:    2020/7/17 22:35:19  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1385/problem/D
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
    int n;
    string s;

    int dfs(char ch, int l, int r)
    {
        int mid = (l + r) / 2;

        if (r == l)
        {
            return (s[l] != ch);
        }

        int cgL = 0;
        for (int i = l; i <= mid; ++i)
        {
            cgL += s[i] != ch;
        }

        int cgR = 0;
        for (int i = mid + 1; i <= r; ++i)
        {
            cgR += s[i] != ch;
        }

        int L = cgL + dfs(ch + 1, mid + 1, r),
            R = cgR + dfs(ch + 1, l, mid);

        return min(L, R);
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            cin >> n;
            cin >> s;

            cout << dfs('a', 0, n - 1) << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1385D_aGoodString.in", "r", stdin);
    freopen("CF_1385D_aGoodString.out", "w", stdout);
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