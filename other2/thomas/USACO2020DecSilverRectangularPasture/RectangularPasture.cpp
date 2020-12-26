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
using Point = pair<int, int>;

class solution
{

    vector<vector<int>> pSum;

    int rsum(int x1, int y1, int x2, int y2)
    {
        return pSum[x2 + 1][y2 + 1] - pSum[x2 + 1][y1] - pSum[x1][y2 + 1] + pSum[x1][y1];
    }

  public:
    void solve()
    {
        int N;
        cin >> N;
        pSum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

        vector<Point> P(N);
        for (int i = 0; i <= N - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            P[i] = make_pair(x, y);
        }
        sort(P.begin(), P.end());
        for (int i = 0; i <= N - 1; ++i)
            P[i].first = i + 1;

        sort(P.begin(), P.end(), [](const Point & p, const Point & q) 
        {
            return p.second < q.second;
        });

        for (int i = 0; i <= N - 1; ++i)
            P[i].second = i + 1;

        for (int i = 0; i <= N - 1; ++i)
            pSum[P[i].first][P[i].second] = 1;

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];

        long long answer = 0;
        for (int i = 0; i <= N - 1; ++i)
        {
            for (int j = i; j <= N - 1; ++j)
            {
                int x1 = min(P[i].first, P[j].first) - 1;
                int x2 = max(P[i].first, P[j].first) - 1;
                answer += rsum(0, i, x1, j) * rsum(x2, i, N - 1, j);
                cerr << i << "," << j << ":" << x1 << "|" << x2 << ":" << rsum(0, i, x1, j) << "x" << rsum(x2, i, N - 1, j) << " ";

            }
            cerr << "\n";
        }
        cout << answer + 1 << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("RectangularPasture.in", "r", stdin);
    //freopen("RectangularPasture.out", "w", stdout);
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