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
            int n, m; cin >> n >> m;

            vector<pair<int, int>> d(n + m + 1, {0, 0});
            vector<vector<int>> a(n, vector<int>(m, 0));
            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= m - 1; ++x)
                {
                    cin >> a[y][x];

                    if (y + x == (n - 1 - y) + (m - 1 - x)) continue;

                    int dis = min(y + x, (n - 1 - y) + (m - 1 - x));

                    if (a[y][x] == 1) ++d[dis].second;
                    else              ++d[dis].first;
                }
            }

            int ans = 0;
            for (auto x : d) ans += min(x.first, x.second);

            
            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1366C_PalindromicPaths.in", "r", stdin);
    freopen("CF_1366C_PalindromicPaths.out", "w", stdout);
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