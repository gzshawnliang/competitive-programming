/*
-------------------------------------------------------------------
* @Name:           512B Fox And Jumping
* @Author:         Shawn
* @Create Time:    2020/7/14 22:24:57  (UTC+08:00)
* @Url:            https://codeforces.com/contest/512/problem/B
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
    ill gcd(ill a, ill b)
    {
        return b ? gcd(b, a % b) : a;
    }

    void solve()
    {
        ill n; cin >> n;

        vector<ill> l(n, 0), c(n, 0);
        for (ill i = 0; i <= n - 1; ++i) cin >> l[i];
        for (ill i = 0; i <= n - 1; ++i) cin >> c[i];

        map<ill, ill> f;
        for (ill i = 0; i <= n - 1; ++i)
        {
            if (f.count(l[i]) > 0) f[l[i]] = min(f[l[i]], c[i]);
            else                   f[l[i]] = c[i];

            for (auto it = f.begin(); it != f.end(); ++it)
            {
                ill nxt = gcd(it->first, l[i]);

                if (f.count(nxt) > 0) f[nxt] = min(f[nxt], it->second + c[i]);
                else                  f[nxt] = it->second + c[i];
            }
        }

        if (f.count(1) == 0) cout << "-1\n";
        else                 cout << f[1] << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_512B_FoxAndJumping.in", "r", stdin);
    freopen("CF_512B_FoxAndJumping.out", "w", stdout);
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