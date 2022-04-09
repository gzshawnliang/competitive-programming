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
        int x = 0;
        vector<int> a;
        while (cin >> x) a.push_back(x);
        sort(a.begin(), a.end());

        for (int i = 0; i <= a.size() - 2; ++i)
        {
            bool flg = false;
            while (a[i] == a[i + 1])
            {
                flg = true;
                ++i;
            }
            
            if (flg) cout << a[i] << '\n';
        }
    }
};

signed main()
{
    FastIO;

// #ifdef LOCAL_DEBUG
//     freopen("RE.in", "r", stdin);
//     freopen("RE.out", "w", stdout);
//     auto startTime = chrono::high_resolution_clock::now();
// #endif

    solution sln1;
    sln1.solve();
    cout.flush();

// #ifdef LOCAL_DEBUG
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
//          << " ms\n";
// #endif

    return 0;
}