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
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            string s; cin >> s;
            int n = s.size();

            vector<char> nxtChar(n, '!');
            for (int i = n - 2; i >= 0; --i)
            {
                if (s[i] == s[i + 1]) nxtChar[i] = nxtChar[i + 1];
                else                  nxtChar[i] = s[i + 1];
            }

            vector<int> a(n, 1);
            for (int i = 0; i <= n - 2; ++i)
                if (s[i] < nxtChar[i]) a[i] = 2;

            cout << "Case #" << tcc << ": ";
            for (int i = 0; i <= n - 1; ++i)
                for (int c = 1; c <= a[i]; ++c)
                    cout << s[i];
            cout << '\n';
        }
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