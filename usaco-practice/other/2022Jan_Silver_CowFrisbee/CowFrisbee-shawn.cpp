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
        int n; cin >> n;
        vector<ill> a(n);
        for (auto &x:a) cin >> x;

        stack<pair<ill, ill>> stk;
        stk.push({a[0], 0});

        ill ans = 0LL;
        for (int i = 1; i <= n - 1; ++i)
        {
            while (!stk.empty())
            {
                if (stk.top().first < a[i])
                {
                    ans += i - stk.top().second + 1;
                    stk.pop();
                }
                else
                {
                    break;
                }
            }

            if (!stk.empty()) ans += i - stk.top().second + 1;
            stk.push({a[i], i});
        }

        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CowFrisbee.in", "r", stdin);
    freopen("CowFrisbee.out", "w", stdout);
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