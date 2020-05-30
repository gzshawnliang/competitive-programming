/*
===========================================================
* @Name:           UVa-12197 Trick or Treat
* @Author:         Shawn
* @create Time:    2020/5/30 23:00:28
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const double eps = 1e-9;

void solve()
{
    cout << fixed << setprecision(9);
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        vector<pair<double, double>> houses(n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> houses[i].first >> houses[i].second;

        auto f = [&](double x)
        {
            double ans = 0.0;
            for (auto q:houses)
                ans = max(ans, (double)((q.first - x) * (q.first - x) + q.second * q.second));
            return ans;
        };

        double l = -200000.0, r = 200000.0;
        while (r - l > eps)
        {
            double p1 = l + (r - l) / 3.0;
            double p2 = r - (r - l) / 3.0;

            if (f(p1) > f(p2)) l = p1;
            else               r = p2;

            // double minY = min(f(l), min(f(r), min(f(p1), f(p2))));

            // if (abs(minY - f(l)) < eps || abs(minY - f(p1)) < eps) r = p2;
            // else                                                   l = p1;
        }

        cout << l + 5e-10 << ' ' << sqrt(f(l)) + 5e-10 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa12197_TrickorTreat.in", "r", stdin);
    freopen("UVa12197_TrickorTreat.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}