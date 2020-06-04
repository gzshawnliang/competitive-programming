/*
===========================================================
* @Name:           782B The Meeting Place Cannot Be Changed
* @Author:         Thomas
* @create Time:    2020/6/4 15:17:13
* @url:            https://codeforces.com/contest/782/problem/B
* @Description:    三分法
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
const double eps = 1e-10;

void solve()
{
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    assert(n > 0);

    vector<int> x(n);
    vector<int> v(n);
    for (int i = 0; i <= n - 1; ++i)
        cin >> x[i];

    for (int i = 0; i <= n - 1; ++i)
        cin >> v[i];

    //所有人到达y坐标时候的时间
    auto f = [&](double y) 
    {
        double t = 0;
        for (int i = 0; i <= n - 1; ++i)
            t = max(t, abs(x[i] * 1.0 - y) / (v[i] * 1.0));

        return t;
    };

    //三分到达y的时间
    double right = 1e9 + 1;
    double left = 0;
    while (right - left > eps)
    {
        double midL = left * 1.0 + (right - left) / 3.0;
        double midR = right * 1.0 - (right - left) / 3.0;

        //如果是求最大值的话这里判>=即可
        //如果是求最小值的话这里判<=即可
        if (f(midL) <= f(midR))
            right = midR;
        else
            left = midL;
    }

    cout << f(left) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_782B_TheMeetingPlaceCannotBeChanged.in", "r", stdin);
    //freopen("CF_782B_TheMeetingPlaceCannotBeChanged.out", "w", stdout);
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