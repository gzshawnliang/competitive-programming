/*
-------------------------------------------------------------------
* @Name:           1371E2 Asterism (Hard Version)
* @Author:         Shawn
* @Create Time:    2020/7/10 22:30:12  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1371/problem/E2
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
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
        ill n, p; cin >> n >> p;

        vector<ill> a(n, 0);
        for (ill i = 0; i <= n - 1; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        ill minX = -1;
        for (ill i = 0; i <= n - 1; ++i) minX = max(minX, a[i] - i);

        auto check=[&](ill x)
        {
            ill now = 0;
            for (ill i = 0; i <= n - 1; ++i)
            {
                while (now <= n - 1 && a[now] <= x) ++now;
                if ((now - i) % p == 0) return false;
                ++x;
            }

            return true;
        };

        ill l = minX - 1, r = 1e9;
        while (l + 1 < r)
        {
            ill mid = (l + r) / 2;

            if (check(mid) == true) l = mid;
            else                    r = mid;
        }

        cout << l - minX + 1 << '\n';
        for (ill x = minX; x <= l; ++x)
        {
            if (x > minX) cout << ' ';
            cout << x;
        }
        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1371E2_AsterismHardVersion.in", "r", stdin);
    freopen("CF_1371E2_AsterismHardVersion.out", "w", stdout);
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