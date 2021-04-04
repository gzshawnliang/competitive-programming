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
        int n = 600;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int y = 0; y <= n; ++y)
        {
            for (int x = 0; x <= n; ++x)
            {
                bool flg = true;
                if ((y % 2) != (x % 2))
                {
                    flg = false;
                }

                if (flg)
                {
                    int k = 0;
                    while (pow(3, k) <= x || pow(3, k) <= y)
                    {
                        int modX = x % (int)pow(3, k), modY = y % (int)pow(3, k);
                        if ((modX % 2) != (modY % 2))
                        {
                            flg = false;
                            break;
                        }
                        ++k;
                    }
                }

                a[y][x] = flg;
                //cout << flg;
                // if (flg) cout << 'x';
                // else     cout << ' ';
            }
        }

        vector<int> yp = {1, -1, -1, 1};
        vector<int> xp = {-1, -1, 1, 1};

        auto g = [&](int y, int x) {
            return y >= 0 && y <= n - 1 && x >= 0 && x <= n - 1;
        };

        for (int x = 0; x <= n - 1; x += 2)
        {
            vector<int> tmp;
            int ty = 0, tx = x;

            while (g(ty, tx))
            {
                tmp.push_back(a[ty][tx]);
                ++ty;
                ++tx;
            }
            //cout << '\n';

            int cntSt = 0, i = 0;
            while (tmp[i] == 0)
            {
                ++cntSt;
                ++i;
            }
            int cnt1 = 0;
            while (tmp[i] == 1)
            {
                ++cnt1;
                ++i;
            }
            int cntSpc = 0;
            while (tmp[i] == 0)
            {
                ++cntSpc;
                ++i;
            }

            // if (cnt1 == 3)
            // {
            cout << 0 << ", " << x;
            if (tx < 10)
                cout << "  ";
            else if (tx < 100)
                cout << " ";
            cout << ": ";
            cout << "cntSt: " << cntSt << " cnt1: " << cnt1 << " cntSpc: " << cntSpc + cnt1;
            // if (cnt1 > 0)
            //     cout << " ??: " << (cntSpc) / (cnt1 * 2);

            cout << " (" << x << ": ";
            for (int i = 1; i <= 4; ++i)
            {
                if (x < (int)pow(3, i)) continue;
                int rem = x % (int)pow(3, i);

                if (rem <= pow(3, i - 1))
                {
                    cout << '1';
                }
                else if (rem >= pow(3, i) - pow(3, i - 1))
                {
                    cout << '3';
                }
                else
                {
                    cout << '2';
                }
                cout << ' ';
            }
            
            cout << '\n';
        }
    }
};


signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c.in", "r", stdin);
    freopen("c3.out", "w", stdout);
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

// for (int y = 0; y <= n; ++y)
        // {
        //     for (int x = 0; x <= n; ++x)
        //     {
        //         // bool flg = true, utFlg = true;
        //         // if (g(y + yp[0], x + xp[0]))
        //         // {
        //         //     if (a[y + yp[0]][x + xp[0]] == 1)
        //         //     {
        //         //         flg = false;
        //         //     }
        //         //     else
        //         //     {
        //         //         utFlg = false;
        //         //     }
        //         // }
        //         // if (g(y + yp[0], x + xp[0]))
        //         // {
        //         //     if (a[y + yp[0]][x + xp[0]] == 1)
        //         //     {
        //         //         flg = false;
        //         //     }
        //         //     else
        //         //     {
        //         //         utFlg = false;
        //         //     }
        //         // }
        //         // if (g(y + yp[1], x + xp[1]))
        //         // {
        //         //     if (a[y + yp[1]][x + xp[1]] == 1)
        //         //     {
        //         //         //flg = false;
        //         //     }
        //         //     else
        //         //     {
        //         //         utFlg = false;
        //         //     }
        //         // }
        //         // if (g(y + yp[3], x + xp[3]))
        //         // {
        //         //     if (a[y + yp[3]][x + xp[3]] == 1)
        //         //     {
        //         //         //flg = false;
        //         //     }
        //         //     else
        //         //     {
        //         //         utFlg = false;
        //         //     }
        //         // }

        //         if (a[y][x])     cout << 'x';
        //         else         cout << ' ';

        //     }
        //     cout << '\n';
        // }