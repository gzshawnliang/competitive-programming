#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 52;

inline int & setmax(int & l, int r)
{
    return l = max(l, r);
}

int N, K, C[LIM];
vector<int> adj[LIM];

// dp[i][j][k] = max value in i's subtree,
// with j new paths present,
// and with a free path ongoing from i's parent if k=1.
int dp[LIM][LIM][2];

// dp2[i][j][k][c] = max value after first i children of current node,
// with j new paths present,
// and with a free path available for use if k=1,
// and with at least one child connected if c=1.
int dp2[LIM][LIM][2][2];

void rec(int i, int parent)
{
    int nc = 0;
    for (int j : adj[i])
    {
        if (j != parent)
        {
            rec(j, i);
            nc++;
        }
    }
    // Sub-DP.
    for (int j = 0; j <= nc; j++)
    {
        memset(dp2[j], -1, sizeof dp2[j]);
    }
    dp2[0][0][0][0] = 0;
    nc = 0;
    for (int j : adj[i])
    {
        if (j == parent)
        {
            continue;
        }
        for (int a1 = 0; a1 <= K; a1++)
        {
            for (int x : {0, 1})
            {
                for (int y : {0, 1})
                {
                    int d = dp2[nc][a1][x][y];
                    if (d < 0)
                    {
                        continue;
                    }
                    for (int a2 = 0; a2 <= K - a1; a2++)
                    {
                        // Connect to child.
                        int d2 = dp[j][a2][1];
                        if (d2 >= 0)
                        {
                            setmax(dp2[nc + 1][a1 + a2 + (x ? 0 : 1)][1 - x][1], d + d2);
                        }
                        // Don't connect to child.
                        d2 = dp[j][a2][0];
                        if (d2 >= 0)
                        {
                            setmax(dp2[nc + 1][a1 + a2][x][y], d + d2);
                        }
                    }
                }
            }
        }
        nc++;
    }
    // Combine into main DP.
    memset(dp[i], -1, sizeof dp[i]);
    for (int o : {0, 1})
    {
        for (int j = 0; j <= K; j++)
        {
            for (int x : {0, 1})
            {
                for (int y : {0, 1})
                {
                    if (!i && !y)
                    {
                        continue; // Root must connect to at least one child.
                    }
                    int d = dp2[nc][j][x][y];
                    if (d < 0)
                    {
                        continue;
                    }
                    // Include current node's value?
                    if (o || y)
                    {
                        d += C[i];
                    }
                    // Free path ongoing from parent?
                    setmax(dp[i][j - (o && x ? 1 : 0)][o], d);
                }
            }
        }
    }
}

int solve()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        adj[i].clear();
    }
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // DP
    rec(0, -1);
    int ans = C[0];
    for (int i = 0; i <= K; i++)
    {
        setmax(ans, dp[0][i][0]);
    }
    return ans;
}

int main()
{

    freopen("C2.in", "r", stdin);
    //freopen("C2.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}