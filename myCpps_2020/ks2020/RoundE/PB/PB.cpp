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
        //cout << tct << '\n';

        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, a, b, c; cin >> n >> a >> b >> c;

            bool swaped = false;
            if (a > b)
            {
                swap(a, b);
                swaped = true;
            } 

            vector<int> skl;
            for (int h = 1; h <= a - c; ++h) skl.push_back(h);

            bool flg = false;
            skl.push_back(n);
            for (int h = 1; h <= n - a - b + c; ++h) skl.push_back(1);
            for (int h = 1; h <= c - 1; ++h)
            {   
                skl.push_back(n);
                flg = true;
            }
            
            
            int cnt = b - c;
            for (int h = n - 1; h >= 1 && cnt > 0; --h, --cnt)
            {
                skl.push_back(h);
                flg = true;
            }
            if (n - a - b + c == 0) flg = true;

            if (skl.size() != n) flg = false;

            cout << "Case #" << tcc << ':';
            if (flg)
            {
                //cout << n;
                if (swaped)
                {
                    for (int i = n - 1; i >= 0; --i) cout << ' ' << skl[i];
                }
                else
                {
                    for (auto x : skl) cout << ' ' << x;
                }
                cout << '\n';
            }
            else
            {
                cout << " IMPOSSIBLE\n";
                //cout << "0\n";
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PB.in", "r", stdin);
    freopen("PB.out", "w", stdout);
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