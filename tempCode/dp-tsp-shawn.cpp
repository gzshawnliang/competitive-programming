#include <bits/stdc++.h>

using namespace std;

const int n = 4, inf = INT_MAX / 2;

vector<vector<int>> dist
{
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

vector<vector<int>> dp(n, vector<int>(1 << n, inf));

void solve(int u, int visit)
{
    if (visit == ((1 << n) - 1))
    {
        dp[u][visit] = dist[u][0];
        return;
    }

    if (dp[u][visit] < inf)
    {
        return;
    }

    int ans = inf;
    for (int v = 0; v <= n - 1; ++v)
    {
        if ((visit & (1 << v)) == 0)
        {
            int temp = visit | (1 << v);
            solve(v, temp);

            ans = min(ans, dist[u][v] + dp[v][temp]);
        }
    }

    dp[u][visit] = ans;
}

int main()
{
    solve(0, 0);
    cout << dp[0][0] << '\n';

    return 0;
}
