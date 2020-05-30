/*
===========================================================
* @Name:           UVa-1476 Error Curves
* @Author:         Shawn
* @create Time:    2020/5/30 22:18:53
* @url:            
* @Description:    三分搜索
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const double eps = 1e-9, inf = (double)INT_MAX;

struct quadric
{
    int a;
    int b;
    int c;
};

void solve()
{
    cout << fixed << setprecision(4);

    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n; cin >> n;
        vector<quadric> all(n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> all[i].a >> all[i].b >> all[i].c;

        auto F = [&](double x)
        {
            double ans = -inf;
            for (auto q:all)
                ans = max(ans, (double)(q.a * x * x + q.b * x + q.c));
            return ans;
        };

        double l = 0.0, r = 1000.0;
        while (r - l > eps)
        {
            double p1 = l + (r - l) / 3.0;
            double p2 = r - (r - l) / 3.0;

            if (F(p1) > F(p2)) l = p1;
            else               r = p2;

            // double minY = min(F(l), min(F(r), min(F(p1), F(p2))));

            // if (abs(minY - F(l)) < eps || abs(minY - F(p1)) < eps) r = p2;
            // else                                                   l = p1;
        }

        cout << F(l) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("UVa1476_ErrorCurves.in", "r", stdin);
    freopen("UVa1476_ErrorCurves.out", "w", stdout);
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