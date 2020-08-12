#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const int INF = INT_MAX;

class solution
{
    vector<vector<int>> g;

  public:
    void solve(int t)
    {
        int N, H;
        cin >> N >> H;
        vector<tuple<int, int, int>> ladder(N + 1);
        for (int i = 1; i <= N; ++i)
        {
            int x, a, b;
            cin >> x >> a >> b;
            ladder[i] = {x, a, b};
        }
        sort(ladder.begin() + 1, ladder.end());

        // for (int i = 1; i <= N; ++i)
        //     get<3>(ladder[i]) = i;

        int s = 0;
        int e = N + 1;

        auto min3 = [](int a, int b, int c) {
            int r = min(a, b);
            r = min(r, c);
            return r;
        };

        //建图
        g = vector<vector<int>>(N + 2, vector<int>(N + 2, -1));
        for (int i = 1; i <= N; ++i)
        {
            auto [x1, a1, b1] = ladder[i];
            if (a1 == 0)
                g[s][i] = INF;

            if (b1 == H)
                g[i][e] = INF;

            /*
                情况1       情况2       情况3       情况4           情况5
                    b2          b2      b1         b1                       b2
                    |           |       |   b2      |                       |
                b1  |       b1  |       |   |       |                       |
                |   |       |   |       |   |       |                       |
                |   |       |   |       a1  |       a1                      a2
                |   |       |   a2          a2                              
                a1  |       a1                              b2      b1
                    a2                                      |       |
                                                            |       |
                                                            |       |
                                                            a2      a1
                */

            int next = i + 1;
            while (next <= N && b1 - a1 > 0)
            {
                auto [x2, a2, b2] = ladder[next];
                if (a1 > b2 || b1 < a2) //情况4,情况5
                {
                    //do nothing
                }
                else
                {
                    g[i][next] = min3(b1 - a2, b1 - a1, b2 - a1);
                    g[next][i] = g[i][next];

                    if (g[i][next] == b1 - a2) //情况2
                    {
                        b1 = a2;
                    }
                    else if (g[i][next] == b1 - a1) //情况1
                    {
                        a1 = 0;
                        b1 = 0;
                    }
                    else if (g[i][next] == b2 - a1) //情况3
                    {
                        a1 = b2;
                    }
                }
                ++next;
            }
        }

        int ans = 0;
        //int ans = maxflow(s,t);
        cout << "Case #" << t << ": " << ans << "\n";
        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FB_2019_ROUND_1_CLaddersandSnakes.in", "r", stdin);
    //freopen("FB_2019_ROUND_1_CLaddersandSnakes.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif
    int t;
    cin >> t;
    solution sln1;
    for (int i = 1; i <= t; ++i)
        sln1.solve(i);

    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}