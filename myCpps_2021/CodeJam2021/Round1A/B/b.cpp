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
    ill tolS, ans;
    vector<ill> a;

    void dfs(ill nowPr, ill nowSum, int nowPos)
    {
        if (nowPr == tolS - nowSum)
        {
            ans = nowPr;
        }
        else if (nowPr < tolS - nowSum)
        {
            int sizA = a.size();
            for (int i = nowPos; i <= sizA - 1; ++i)
            {
                dfs(nowPr * a[i], nowSum + a[i], i + 1);
            }
        }
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            
            tolS = 0LL;
            ans = 0LL;
            a.clear();
            for (int c = 1; c <= n; ++c)
            {
                ill x, tt; cin >> x >> tt;
                for (int i = 1; i <= tt; ++i) a.push_back(x);
                tolS += (x * tt);
            }

            dfs(1LL, 0LL, 0);
            cout << "Case #" << tcc << ": " << ans << '\n';
        }
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