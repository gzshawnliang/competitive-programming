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
    const int inf = INT_MAX / 2;

    int n;
    vector<int> a;
    vector<vector<int>> pos;
    vector<vector<int>> f;

    int dfs(int l, int r)
    {
        if (f[l][r] != inf) return f[l][r];

        if (l == r) return 1;
        if (l > r) return 0;
        
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                //f[l][r] = min(f[l][r], 1 + dfs(i + 1, j - 1) + dfs(j + 1, n));
               

                if (a[i] == a[j])
                {
                    int p = i;
                    while (p <= j && a[p] == a[i]) ++p;

                    int q = j;
                    while (p >= i && a[q] == a[j]) --q;

                    if (p == j + 1)
                    {
                        return f[l][r] = 1;
                    }
                    else
                    {
                        f[l][r] = min(f[l][r], dfs(l, i - 1) + 1 + dfs(p, q) + dfs(j + 1, r));
                    }
                }
                else
                {
                    f[l][r] = min(f[l][r], dfs(l, r - 1) + 1);
                    f[l][r] = min(f[l][r], dfs(l + 1, r) + 1);
                }
            }
        }

        return f[l][r];
    }

    void solve()
    {
        cin >> n;
        
        a = vector<int>(n + 1, 0);
        //pos = vector<vector<int>>(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            //pos[a[i]].push_back(i);
        }

        f = vector<vector<int>>(n + 1, vector<int>(n + 1,inf));
        cout << dfs(1, n) << '\n';

        for(int _s_=0;_s_==0;++_s_);
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
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