#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);               \
    std::cout.tie(nullptr)

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
            int n; cin >> n;
            if (n == 0)
            {
                cout << '\n';
                continue;
            }

            int maxH = 0;
            vector<int> skl(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> skl[i];
                maxH = max(maxH, skl[i]);
            }

            int C = 0;
            for (auto h:skl)
                if (h == maxH) ++C;
            
            int A = 1;
            maxH = skl[0];
            for (int i = 1; i <= n - 1; ++i)
            {   
                if (skl[i] >= maxH) ++A;
                maxH = max(maxH, skl[i]);
            }
    
            int B = 1;
            maxH = skl[n - 1];
            for (int i = n - 2; i >= 0; --i)
            {
                if (skl[i] >= maxH) ++B;
                maxH = max(maxH, skl[i]);
            }
                

            cout << n << ' ' << A << ' ' << B << ' ' << C << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PB.out", "r", stdin);
    freopen("PBcheck.out", "w", stdout);
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