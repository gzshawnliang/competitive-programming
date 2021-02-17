/*
-------------------------------------------------------------------
* @Name:           1490D Permutation Transformation
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/dep
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
    vector<int> a;
    vector<int> dep;

    void dfs(int nowPos, int l, int r)
    {
        int n = a.size();

        int maxN, maxPos;

        maxN = 0; maxPos = -1;
        for (int i = nowPos - 1; i >= l; --i)
        {
            if (a[i] > maxN)
            {
                maxN = a[i]; maxPos = i;
            }
        }
        if (maxN > 0)
        {
            dep[maxPos] = dep[nowPos] + 1;
            dfs(maxPos, l, nowPos - 1);
        }

        maxN = 0; maxPos = -1;
        for (int i = nowPos + 1; i <= r; ++i)
        {
            if (a[i] > maxN)
            {
                maxN = a[i]; maxPos = i;
            }
        }

        if (maxN > 0)
        {
            dep[maxPos] = dep[nowPos] + 1;
            dfs(maxPos, nowPos + 1, r);
        }
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;

            int maxN = 0, maxPos = -1;
            a = vector<int>(n);
            dep = vector<int>(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                if (a[i] > maxN)
                {
                    maxN = a[i]; maxPos = i;
                }
            }

            dfs(maxPos, 0, n - 1);

            for (int i = 0; i <= n - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << dep[i];
            }
            cout << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490D_PermutationTransformation.in", "r", stdin);
    freopen("CF_1490D_PermutationTransformation.out", "w", stdout);
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