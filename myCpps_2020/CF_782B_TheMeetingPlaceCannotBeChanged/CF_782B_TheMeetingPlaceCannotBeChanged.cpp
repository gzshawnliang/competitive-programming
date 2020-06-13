/*
===========================================================
* @Name:           782B The Meeting Place Cannot Be Changed
* @Author:         Shawn
* @create Time:    2020/6/6 20:57:41
* @url:            https://codeforces.com/contest/782/problem/B
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

const double eps = 1e-9;

void solve()
{
    cout << fixed << setprecision(12);

    int n = 0; cin >> n;

    vector<double> poss(n);
    for (int i = 0; i <= n - 1; ++i) cin >> poss[i];
    vector<double> speeds(n);
    for (int i = 0; i <= n - 1; ++i) cin >> speeds[i];

    auto f = [&](double x)
    {
        double ans = 0.0;
        for (int i = 0; i <= n - 1; ++i)
            ans = max(ans, abs((poss[i] - x) / speeds[i]));
        return ans;
    };

    double l = 1, r = 1e9;
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

    cout << f(l) + 5e-10 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_782B_TheMeetingPlaceCannotBeChanged.in", "r", stdin);
    freopen("CF_782B_TheMeetingPlaceCannotBeChanged.out", "w", stdout);
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