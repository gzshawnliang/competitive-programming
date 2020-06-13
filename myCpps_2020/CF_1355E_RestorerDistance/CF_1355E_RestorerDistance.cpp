/*
===========================================================
* @Name:           1355E Restorer Distance
* @Author:         Shawn
* @create Time:    2020/6/6 22:05:46
* @url:            https://codeforces.com/contest/1355/problem/E
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

void solve()
{
    ill n, a, r, m; cin >> n >> a >> r >> m;

    ill totB = 0, maxH = 0;
    vector<ill> heights(n);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> heights[i];
        totB += heights[i];
        maxH = max(maxH, heights[i]);
    }

    sort(heights.begin(), heights.end());

    auto f = [&](double finH)
    {
        if (finH == 4)
        {
            for (ill __s = 0; __s == 0; ++__s);
        }

        ill out = 0, vac = 0;
        for (ill i = 0; i <= n - 1; ++i)
        {
            if (heights[i] > finH) out += (heights[i] - finH);
            else                   vac += (finH - heights[i]);
        }
        
        ill ans = 0;

        ans += min(out, vac) * min(a + r, m);
        if (out > vac)
        {
            ans += abs(out - vac) * r;
        }
        else
        {
            ans += abs(out - vac) * a;
        }

        return ans;
    };

    ill lb = 0, rb = maxH;
    while (true)
    {
        if (rb - lb == 2)
        {
            cout << min(f(lb), min(f(lb + 1), f(rb))) << '\n';
            break;
        }
        else if (rb - lb <= 1)
        {
            cout << min(f(lb), f(rb)) << '\n';
            break;
        }

        ill p1 = lb + (rb - lb) / 3;
        ill p2 = rb - (rb - lb) / 3;

        ill fp1 = f(p1), fp2 = f(p2);

        if (f(p1) > f(p2)) lb = p1;
        else               rb = p2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1355E_RestorerDistance.in", "r", stdin);
    freopen("CF_1355E_RestorerDistance.out", "w", stdout);
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