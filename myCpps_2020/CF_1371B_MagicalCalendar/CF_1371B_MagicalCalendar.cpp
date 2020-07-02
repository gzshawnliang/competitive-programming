/*
-------------------------------------------------------------------
* @Name:           1371B Magical Calendar
* @Author:         Shawn
* @Create Time:    2020/7/1 22:17:18  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1371/problem/B
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
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, r; cin >> n >> r;
            
            ill fin = min(r, n - 1);

            ill ans = (fin + 1) * fin / 2;
            if (r >= n) ++ans;

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
    freopen("CF_1371B_MagicalCalendar.in", "r", stdin);
    freopen("CF_1371B_MagicalCalendar.out", "w", stdout);
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