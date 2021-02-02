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
        string sstr; cin >> sstr;
        int siz = sstr.size();

        int tolCh = 0;
        vector<int> myCtoi(256, -1);
        vector<int> s(siz);
        for (int i = 0; i <= siz - 1; ++i)
        {
            if (myCtoi[sstr[i]] == -1)
                myCtoi[sstr[i]] = tolCh++;
            s[i] = myCtoi[sstr[i]];
        }

        vector<vector<int>> occ(tolCh, vector<int>(tolCh, 0));
        for (int i = 0; i <= siz - 2; ++i)
        {
            ++occ[s[i]][s[i + 1]];
        }

        vector<int> f((1 << tolCh));
        f[0] = 1;
        for (int x = 1; x <= (1 << tolCh) - 1; ++x)
        {
            f[x] = siz;
            bitset<20> b(x);
            for (int i = 0; i <= tolCh - 1; ++i)
            {
                if (b[i] == 1)
                {
                    b[i] = 0;
                    int res = f[b.to_ulong()];
                    for (int j = 0; j <= tolCh - 1; ++j)
                        if (b[j] == 1 || i == j)
                            res += occ[i][j];
                    b[i] = 1;

                    f[x] = min(f[x], res);
                }
            }
        }

        // for (int x = 0; x <= (1 << tolCh) - 1; ++x)
        // {
        //     if (f[x] > 0)
        //     {
        //         bitset<20> b(x);
        //         cout << "f[" << b.to_string() << "] = " << f[x] << '\n';
        //     }
        // }

        cout << f[(1 << tolCh) - 1] << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
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