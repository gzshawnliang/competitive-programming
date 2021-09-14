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

const int MOD = 1000000007;

class solution
{
    int sum()
    {
        int N;
        string S;
        cin >> N >> S;
        int b = -1, ans = 0;
        for (int a = 0; a <= N-1; ++a)
        {
            if (S[a] == 'F')
                continue;

            if (b >= 0 && S[a] != S[b])
                ans = (ans + (ill)(b + 1) * (N - a)) % MOD;
            
            b = a;
        }
        return ans;
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int t = 1; t <= T; t++)
            cout << "Case #" << t << ": " << sum() << endl;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
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