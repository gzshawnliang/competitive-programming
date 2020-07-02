/*
-------------------------------------------------------------------
* @Name:           1371D Grid-00100
* @Author:         Shawn
* @Create Time:    2020/7/1 22:36:54  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1371/problem/D
* @Description:    
-------------------------------------------------------------------
*/

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
            int n, k; cin >> n >> k;

            if (k % n == 0) cout << "0\n";
            else            cout << "2\n";

            int cnt = k;
            vector<vector<int>> a(n, vector<int>(n, 0));
            for (int i = 0; i <= n - 1 && cnt > 0; ++i)
            {
                int x, y;
                x = i, y = 0;
                while (x <= n - 1 && y <= n - 1 && cnt > 0)
                {
                    a[y][x] = 1; --cnt;
                    ++x; ++y;
                }

                if (i == 0) continue;

                x = 0, y = n - i;
                while (x <= n - 1 && y <= n - 1 && cnt > 0)
                {
                    a[y][x] = 1; --cnt;
                    ++x; ++y;
                }
            }

            for (int y = 0; y <= n - 1; ++y)
            {
                for (int x = 0; x <= n - 1; ++x) cout << a[y][x];
                cout << '\n';
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1371D_Grid_00100.in", "r", stdin);
    freopen("CF_1371D_Grid_00100.out", "w", stdout);
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