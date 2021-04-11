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
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            
            ill allSum = 0LL;
            vector<pair<ill, ill>> prs(n);
            for (auto &[x, y]:prs)
            {
                cin >> x >> y;
                allSum += x * y;
            }

            ill ans = 0LL;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (allSum % prs[i].first > 0) continue;

                ill nowPr = 1LL;
                for (int c = 1; c <= prs[i].second; ++c)
                {
                    nowPr *= prs[i].first;
                    if (nowPr > allSum - prs[i].first * c) break;
                    else if (nowPr == allSum - prs[i].first * c)
                    {
                        ans = max(ans, nowPr);
                        break;
                    }
                }
            }

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