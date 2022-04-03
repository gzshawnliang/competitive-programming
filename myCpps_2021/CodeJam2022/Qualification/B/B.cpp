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
    const int N = 4, M = 3;

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            vector<vector<int>> a(N, vector<int>(M, 0));
            for (int x = 0; x <= M - 1; ++x)
                for (int y = 0; y <= N - 1; ++y)
                    cin >> a[y][x];

            for (int y = 0; y <= N - 1; ++y) sort(a[y].begin(), a[y].end());

            vector<pair<int, int>> b;
            for (int y = 0; y <= N - 1; ++y) b.push_back({a[y][0], y});
            sort(b.begin(), b.end());

            int total = 1e6;
            vector<int> ans(N, 0);
            for (int i = N - 1; i >= 0; --i)
            {
                if (total > b[i].first)
                {
                    total -= b[i].first;
                    ans[b[i].second] = b[i].first;
                }
                else
                {
                    ans[b[i].second] = total;
                    total -= total;
                    break;
                }
            }
            
            cout << "Case #" << tcc << ":";
            if (total > 0) cout << " IMPOSSIBLE";
            else           for (auto x:ans) cout << ' ' << x;
            cout << '\n';

            for(int _s_=0;_s_==0;++_s_);
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
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