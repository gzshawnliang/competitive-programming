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
    void solve()
    {
        vector<ill> pow3(38, 1);
        for (ill p = 1; p <= 38; ++p)
            pow3[p] = pow3[p - 1] * 3;

        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill d, x, y, ans = 0; cin >> d >> x >> y;

            if (d > 100LL)
            {
                cout << "1000000000000000001\n";
                continue;
            }

            for (ill c = 0; c <= d; ++c)
            {
                ill tx = x + c, ty = y + c;

                bool flg = true;
                if ((ty % 2) != (tx % 2))
                {
                    flg = false;
                }

                if (flg)
                {
                    ill k = 0;
                    while (pow3[k] <= tx || pow3[k] <= ty)
                    {
                        ill modX = tx % pow3[k], modY = ty % pow3[k];
                        if ((modX % 2) != (modY % 2))
                        {
                            flg = false;
                            break;
                        }
                        ++k;
                    }
                }

                if (flg) ++ans;
            }
            cout << ans << '\n';
        }

        // vector<ill> pow3(38, 1);
        // for (ill p = 1; p <= 38; ++p)
        //     pow3[p] = pow3[p - 1] * 3;

        // ill y = 0, x; cin >> x;

        // ill p1 = 0;
        // while (x % (2 * pow3[p1]) == 0)
        // {
        //     ++p1;
        // }
        // --p1;

        // for(ill _s_=0;_s_==0;++_s_);
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
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