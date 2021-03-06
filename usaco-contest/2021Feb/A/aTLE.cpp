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
        
        int maxN = 0;
        unordered_map<int, int> mmp;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ++mmp[a[i]];

            maxN = max(maxN, a[i]);
        }

        sort(a.begin(), a.end(), greater<int>());

        int ans = 0;
        for (int x = 1; x <= maxN; ++x)
        {
            for (int pos = 0; pos <= n - 1; ++pos)
            {
                if (a[pos] < x) continue;

                vector<int> tmp = a;
                tmp[pos] -= x;

                for (auto &y:tmp) y /= x;

                unordered_map<int, int> tMmp;
                for (auto y:tmp) ++tMmp[y];

                bool flg = true;
                for (auto pr:tMmp)
                {
                    if (pr.first > 0 && pr.second % 2 == 1)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg)
                {
                    ++ans;
                    cout << "Index: " << pos << " take" << x << "\n";
                } 
            }
        }

        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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