/*
-------------------------------------------------------------------
* @Name:           635E Package Delivery
* @Author:         Shawn
* @Create Time:    2020/8/2 0:01:29  (UTC+08:00)
* @Url:            https://codeforces.com/contest/635/problem/E
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
        ill d, m, n; cin >> d >> m >> n;

        vector<pair<ill, ill>> a(n);
        for (ill i = 0; i <= n - 1; ++i) cin >> a[i].first >> a[i].second;
        
        n += 2;
        a.push_back({d, 0});
        a.push_back({0, 1e6 + 1});

        sort(a.begin(), a.end());

        stack<ill> stk;
        vector<ill> f(n, -1); 
        for (ill i = n - 1; i >= 0; --i)
        {
            while (!stk.empty())
            {
                if (a[stk.top()].second <= a[i].second)
                {
                    f[i] = stk.top();
                    break;
                }

                stk.pop();
            }

            stk.push(i);
        }

        ill i = 0, gas = m, ans = 0;
        while (i < n - 1)
        {
            if (f[i] == -1 || a[f[i]].first - a[i].first > m)
            {
                ill dis = a[i + 1].first - a[i].first;
                if (dis > m)
                {
                    ans = -1;
                    break;
                }

                ans += (m - gas) * a[i].second;

                gas = m - dis;
                ++i;
            }
            else
            {
                ill dis = a[f[i]].first - a[i].first;

                if (gas >= dis) gas -= dis;
                else
                {
                    ans += (dis - gas) * a[i].second;
                    gas = 0;
                }
                i = f[i];
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
    freopen("CF_635E_PackageDelivery.in", "r", stdin);
    freopen("CF_635E_PackageDelivery.out", "w", stdout);
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