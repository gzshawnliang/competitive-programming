/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/8/2 22:41:02  (UTC+08:00)
* @Url:            
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
    ill n, m;
    const double inf = LLONG_MAX / 2, eps = 1e-9;
    vector<double> H, up, down;

    bool check(double x)
    {
        vector<pair<double, double>> p(n + 1);
        p[1].first = H[1] - x;
        p[1].second = H[1] + x;

        if (x == 4.125)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        for (ill i = 2; i <= n; ++i)
        {
            p[i].first = max(H[i] - x, p[i - 1].first - down[i - 1]);
            p[i].second = min(H[i] + x, p[i - 1].second + up[i - 1]);

            if (p[i].first > p[i].second)
            {
                return false;
            }
        }

        return true;
    }

  public:
    void solve()
    {
        cout << fixed << setprecision(6);

        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            cin >> n >> m;
            
            H = vector<double>(n + 1, 0); cin >> H[1] >> H[2];
            ill W, X, Y, Z; cin >> W >> X >> Y >> Z;
            for (ill i = 3; i <= n; ++i)
            {
                H[i] = (W * (ill)H[i - 2] + X * (ill)H[i - 1] + Y) % Z;
            }

            up = vector<double>(n, inf); down = vector<double>(n, inf);
            for (ill c = 1; c <= m; ++c)
            {
                double A, B, U, D; cin >> A >> B >> U >> D;
                if (A > B)
                {
                    swap(A, B); swap(U, D);
                }

                for (ill i = A; i <= B - 1; ++i)
                {
                    up[i] = min(up[i], U); down[i] = min(down[i], D);
                }
            }

            double l = 0, r = Z;
            while (r - l > eps)
            {
                double x = (l + r) / 2;

                if (check(x))
                {
                    r = x;
                }
                else
                {
                    l = x;
                }
            }

            cout << "Case #" << tcc << ": " << l << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("PlatformParkour.in", "r", stdin);
    freopen("PlatformParkour.out", "w", stdout);
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