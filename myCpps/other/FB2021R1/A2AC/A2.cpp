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
        int a = -1, ans = 0;
        for (int b = 0; b <= N - 1; ++b)
        {
            if (S[b] == 'F')
                continue;

            if (a >= 0 && S[b] != S[a])
                ans = (ans + (ill)(a + 1) * (N - b)) % MOD;

            a = b;
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