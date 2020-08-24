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

const ill INF=LLONG_MAX;

class solution
{
  public:
    void solve(int caseId)
    {
        int N, M, S, R;
        cin >> N >> M >> S >> R;
        assert(N > 0);
        vector<vector<int>> g(N + 1, vector<int>(N + 1));

        for (int i = 1; i <= M; ++i)
        {
            int u, v;
            cin >> u >> v;
            cout << u << " " << v << "\n";
            g[u][v] = 1;
            g[v][u] = 1;
        }
        
        vector<vector<int>> Si(N + 1);
        vector<vector<ill>> cost(N + 1, vector<ill>(S + 1,INF));
        for (int i = 1; i <= N; ++i)
        {
            int c;
            cin >> c;

            for (int j = 1; j <= c; ++j)
            {
                int tmp;
                cin >> tmp;
                Si[i].push_back(tmp);
                cost[i][tmp]=0;
            }
        }

        vector<vector<int>> recipe(S + 1); //recipe
        for (int i = 1; i <= R; ++i)
        {
            int k;
            cin >> k;

            vector<int> K;
            for (int j = 1; j <= k; ++j)
            {
                int tmp;
                cin >> tmp;
                K.push_back(tmp);
            }
            int result;
            cin >> result;
            recipe[result] = K;
        }


        int ans = 0;
        cout << "Case #" << caseId << ": " << ans << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PD.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    int T;
    cin >> T;
    solution sln1;
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