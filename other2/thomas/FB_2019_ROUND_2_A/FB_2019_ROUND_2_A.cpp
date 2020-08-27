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
    void solve(int caseId)
    {
        int N, M, K;
        cin >> N >> M >> K;
        int A, B;
        cin >> A >> B;
        vector<int> HAHA;
        for (int i = 1; i <= K; ++i)
        {
            int R, C;
            cin >> R >> C;
            HAHA.push_back((R + C) % 2);
        }

        int r = (A + B) % 2;

        if (K==2 && r == HAHA[0] && r == HAHA[1])
            cout << "Case #" << caseId << ": Y\n";
        else
            cout << "Case #" << caseId << ": N\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("FB_2019_ROUND_2_A.in", "r", stdin);
    freopen("FB_2019_ROUND_2_A.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        sln1.solve(i);

    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}