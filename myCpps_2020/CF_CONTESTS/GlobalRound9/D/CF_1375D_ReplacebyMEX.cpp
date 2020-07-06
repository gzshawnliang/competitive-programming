/*
-------------------------------------------------------------------
* @Name:           1375D Replace by MEX
* @Author:         Shawn
* @Create Time:    2020/7/4 22:45:39  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1375/problem/D
* @Description:    
-------------------------------------------------------------------
                                     /~\
                         WA again?  |oo )
                                    _\=/_
                    ___        #   /  _  \
   No,TLE again！  / ()\        \\//|/.\|\\
  mabe Next time _|_____|_       \/  \_/  ||
      get AC    | | === | |         |\ /| ||
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
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i) cin >> a[i];

            vector<int> op;
            while (is_sorted(a.begin(), a.end()) == false)
            {
                int pos = -1;
                vector<int> vis(n + 1 ,0);
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (a[i] != i && pos == -1) pos = i;
                    if (a[i] <= n) vis[a[i]] = 1;
                }

                int mex = 0;
                while (mex <= n && vis[mex] == 1) ++mex;

                if (mex == n)
                {
                    a[pos] = mex;
                    op.push_back(pos);
                }
                else
                {
                    a[mex] = mex;
                    op.push_back(mex);
                }
            }

            int siz = op.size();
            cout << siz << '\n';
            for (int i = 0; i <= siz - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << op[i] + 1;
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1375D_ReplacebyMEX.in", "r", stdin);
    freopen("CF_1375D_ReplacebyMEX.out", "w", stdout);
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