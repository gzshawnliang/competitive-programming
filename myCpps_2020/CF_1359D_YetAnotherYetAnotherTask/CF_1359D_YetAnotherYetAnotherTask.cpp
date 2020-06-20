/*
===========================================================
* @Name:           1359D Yet Another Yet Another Task
* @Author:         Shawn
* @create Time:    2020/6/20 17:59:32
* @url:            https://codeforces.com/contest/1359/problem/D
* @Description:    
===========================================================
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

const ill inf = INT_MAX / 2;

class solution
{
  public:
    void solve()
    {
        ill n; cin >> n;

        vector<ill> a(n, 0);
        for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

        ill ans = 0;
        for (ill maxX = 0; maxX <= 30; ++maxX)
        {
            ill sum = 0, minSum = 0;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill now = 0;
                if (a[i] > maxX) now = -inf;
                else             now = a[i];

                sum += now;
                minSum = min(minSum, sum);

                ans = max(ans, sum - minSum - maxX);
            }
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1359D_YetAnotherYetAnotherTask.in", "r", stdin);
    freopen("CF_1359D_YetAnotherYetAnotherTask.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}