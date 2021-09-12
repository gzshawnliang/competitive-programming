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

    void create(int n, int m, int a, int b)
    {
        vector<vector<int>> data(n, vector<int>(m, 1));
        bool isPossible = true;

        if (m + n - 1 <= a && m + n - 1 <= b)
            isPossible = true;
        else
            isPossible = false;

        if (isPossible)
        {
            cout << "Possible";
            // data[n - 1][m - 1] = 1 + a + 1 - m - n;
            // data[n - 1][0] = 1 + b + 1 - m - n;
            data[0][0] = 1 + a + 1 - m - n;
            data[0][m-1] = 1 + b + 1 - m - n;

            for (int i = 0; i <= n - 1; ++i)
            {
                cout << '\n';
                for (int j = 0; j <= m - 1; ++j)
                {
                    cout << data[i][j];
                    if(j<m - 1)
                        cout << " ";
                }
            }
        }
        else
        {
            cout << "Impossible";
        }
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int t = 1; t <= T; ++t)
        {
            int n, m, a, b;
            cin >> n >> m >> a >> b;
            cout << "Case #" << t << ": ";
            create(n, m, a, b);

            cout << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B.in", "r", stdin);
    freopen("B.txt", "w", stdout);
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