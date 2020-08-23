#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);               \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:

    const ill inf = LLONG_MAX / 2;

    ill check(vector<pair<ill, ill>> &toys)
    {
        ill n = toys.size();

        if (n == 3)
        {
            for (ill __s = 0; __s == 0; ++__s);
        }

        ill i = 0, cnt = 0, ans = 0;
        vector<ill> mem(n, 0);
        while (true)
        {
            if (i == 0)
            {
                ++cnt;

                if (cnt == 3)
                {
                    ans = inf;
                    break;
                }
            }

            if (mem[i] > 0) break;
            
            ans += toys[i].first;
            for (ill j = 0; j <= n - 1; ++j)
            {
                mem[j] = max(0LL, mem[j] - toys[i].first);
            }
            mem[i] = toys[i].second;

            i = (i + 1) % n;
        }

        return ans;
    }

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;
            vector<pair<ill, ill>> toys(n);
            for (ill i = 0; i <= n - 1; ++i) cin >> toys[i].first >> toys[i].second;

            ill del = 0, ans = 0;
            for (ill x = 1; x <= (1 << n) - 1; ++x)
            {
                bitset<12> b(x);

                vector<pair<ill, ill>> tmp;
                for (ill i = 0; i <= n - 1; ++i)
                    if (b[i] == 1) tmp.push_back(toys[i]);

                ill res = check(tmp);
                if (res >= ans)
                {
                    if (res == ans) del = min(del, n - (ill)tmp.size());
                    else            del = n - (ill)tmp.size();
                    ans = res;
                }
            }

            cout << "Case #" << tcc << ": " << del << ' ';
            if (ans == inf) cout << "INDEFINITELY\n";
            else            cout << ans << '\n';
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