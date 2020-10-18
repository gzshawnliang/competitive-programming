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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill w, n; cin >> w >> n;

            vector<ill> a(w, 0);
            for (ill i = 0; i <= w - 1; ++i)
                cin >> a[i];
            sort(a.begin(), a.end());

            vector<ill> f(w, 0);
            for (ill i = 0; i <= w - 1; ++i)
                f[i] = ((i == 0) ? a[i] : f[i - 1] + a[i]);

            auto getS=[&](ill st, ill fn)
            {
                if (fn < st) return 0LL;

                if (st == 0) return f[fn];
                else         return f[fn] - f[st - 1];
            };

            ill ans = n * w;
            for (ill i = 0; i <= w - 1; ++i)
            {
                ill res = 0;
                
                if (a[i] <= n / 2)
                {
                    res += (a[i] * i - getS(0, i - 1));

                    ill pos = upper_bound(a.begin(), a.end(), a[i] + n / 2) - a.begin() - 1;

                    res += (getS(i, pos) - a[i] * (pos - i + 1));
                    res += (n * (w - 1 - pos) + a[i] * (w - 1 - pos) - getS(pos + 1, w - 1));
                }
                else
                {
                    res += (getS(i + 1, w - 1) - a[i] * (w - i - 1));

                    ill pos = lower_bound(a.begin(), a.end(), a[i] - n / 2) - a.begin();

                    res += (a[i] * (i - pos) - getS(pos, i - 1));
                    res += (n * (pos) + getS(0, pos - 1) - a[i] * (pos));
                }

                ans = min(ans, res);
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PC.in", "r", stdin);
    freopen("PC.out", "w", stdout);
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