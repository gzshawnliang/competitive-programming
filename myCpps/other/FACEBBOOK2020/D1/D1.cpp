#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF2 = 9223372036854775807ll / 2;

class solution
{
    vector<ill> a;
    vector<ill> d;
    vector<ill> visi;

  public:
    void solve(int t)
    {

        int N, M;
        cin >> N >> M;
        a = vector<ill>(N + 1);
        d = vector<ill>(N + 1, INF2);
        int lastGasCity = 1;
        for (int i = 1; i <= N; ++i)
        {
            cin >> a[i];

            if (a[i] > 0)
            {
                lastGasCity = i;
            }
            else
            {
                if (i - lastGasCity > M)
                {
                    cout << "Case #" << t << ": -1\n";
                    return;
                }
            }
        }
        ill iCount = 0;
        d[1] = 0;
        a[N] = 0;
        for (int u = 1; u <= N; ++u)
        {
            if (u > 1 && a[u] == 0)
                continue;

            int maxJ = min(M, N - u);
            for (int j = 1; j <= maxJ; ++j)
            {
                int v = u + j;

                if (u == 1 && v < N)
                {
                    d[v] = a[v];
                    continue;
                }
                d[v] = min(d[u] + a[v], d[v]);
                ++iCount;
            }
        }

        cout << iCount << " ";
        cout << "Case #" << t << ": " << (d[N] == INF2 ? -1 : d[N]) << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("d6.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif
    int T;
    cin >> T;
    for (int tcc = 1; tcc <= T; ++tcc)
    {
        solution sln1;
        sln1.solve(tcc);
    }

    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}