#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:
    vector<vector<ill>> _3b3A, _3b3S;

    ill fndMaxSide(ill y, ill x)
    {
        ill max1 = max(x, y), r = 1ll;
        while (r <= max1)
            r *= 3ll;

        return r;
    }
    
    ill getFull(ill dif, ill n)
    {
        if (dif < 0LL) dif = -1LL * dif;

        if (n == 3LL)
        {
            if      (dif == 0LL) return 3LL;
            else if (dif == 1LL) return 0LL;
            else if (dif == 2LL) return 1LL;
        }
        else
        {
            if      (dif < n / 3LL)     return 3LL * getFull(dif, n / 3LL);
            else if (dif < 2LL * n / 3LL) return getFull(2LL * n / 3LL - dif, n / 3LL);
            else                      return getFull(dif - 2LL * n / 3LL, n / 3LL);
        }
    }

    ill getPart(ill y, ill x, ill n)
    {
        if (y < x) swap(y, x);

        if (n == 3LL)
        {
            return _3b3S[y][x];
        }

        if (y < n / 3LL)
        {
            return getPart(y, x, n / 3LL);
        }
        else if (y < 2LL * n / 3LL)
        {
            if (x >= n / 3LL)
            {
                return getPart(y - n / 3LL, x - n / 3LL, n / 3LL) + getFull(y - x, n / 3LL);
            }
            else if (y - n / 3LL >= x)
            {
                return 0LL;
            }
            else
            {
                return getFull(y - x, n / 3LL);
            }
        }
        else
        {
            if (x < n / 3LL)
            {
                return getPart(y - 2LL * n / 3LL, x, n / 3LL);
            }
            else if (x >= 2LL * n / 3LL)
            {
                return getPart(y - 2LL * n / 3LL, x - 2LL * n / 3LL, n / 3LL) + 2LL * getFull(y - x, n / 3LL);
            }
            else
            {
                if (y - 2LL * n / 3LL > x - n / 3LL)
                {
                    return getFull(n / 3LL - (y - x - n / 3LL), n / 3LL);
                }
                else if (y - 2LL * n / 3LL == x - n / 3LL)
                {
                    return 0LL;
                }
                else
                {
                    return 2LL * getFull(y - x, n / 3LL);
                }
            }
        }
    }

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            ill qd, qy, qx; cin >> qd >> qx >> qy;

            if ((qx + qy) % 2LL == 1)
            {
                cout << "0\n";
                continue;
            }
            
            _3b3A = {{1LL, 0LL, 1LL},
                     {0LL, 1LL, 0LL},
                     {1LL, 0LL, 1LL}};
            _3b3S = {{1LL, 0LL, 1LL},
                     {0LL, 2LL, 0LL},
                     {1LL, 0LL, 3LL}};
            
            if (qy < qx) swap(qy, qx);

            ill n = fndMaxSide(qy + qd, qx + qd);
            ill ans = 0LL;
            if (qy == 0LL || qx == 0LL) ans = getPart(qy + qd, qx + qd, n);
            else
            {
                ill tF = getPart(qy + qd, qx + qd, n);
                ill tC = getPart(qy - 1LL, qx - 1LL, n);
                ans = tF - tC;
            }

            cout << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}