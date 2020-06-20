/*
===========================================================
* @Name:           1359C Mixing Water
* @Author:         Shawn
* @create Time:    2020/6/20 18:21:08
* @url:            https://codeforces.com/contest/1359/problem/C
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

class solution
{
  public:
    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            double h, c, t; cin >> h >> c >> t;

            auto tempe=[&](int hc, int cc)
            {
                return (double)(h * hc + c * cc) / (double)(hc + cc);
            };

            int l = 0, r = h, ans = -1;
            while (true)
            {
                if (r - l <= 1)
                {
                    vector<pair<double, int>> all;

                    for (int hp = -1; hp <= 1; ++hp)
                        for (int cp = -1; cp <= 1; ++cp)
                            if (l + hp >= 0 && l + cp >= 0 && l + hp + l + cp > 0) all.push_back({abs(tempe(l + hp, l + cp) - t), l + hp + l + cp});

                    for (int hp = -1; hp <= 1; ++hp)
                        for (int cp = -1; cp <= 1; ++cp)
                            if (r + hp >= 0 && r + cp >= 0 && l + hp + l + cp > 0) all.push_back({abs(tempe(r + hp, r + cp) - t), r + hp + r + cp});

                    sort(all.begin(), all.end());
                    ans = all[0].second;

                    if (ans % 2 == 0) ans = 2;

                    break;
                }
                else
                {
                    int mid = (l + r) / 2;

                    if (tempe(mid + 1, mid) > t)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
            }

            cout << ans << '\n';

            // for (int c = 1; c <= h; ++c)
            // {
            //     cout << tempe(c / 2 + c % 2, c / 2) << '\n';
            // }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1359C_MixingWater.in", "r", stdin);
    freopen("CF_1359C_MixingWater.out", "w", stdout);
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