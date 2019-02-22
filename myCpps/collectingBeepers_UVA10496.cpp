#include <bits/stdc++.h>

using namespace std;

ifstream fin("collectingBeepers_UVA10496.in");
ofstream fout("collectingBeepers_UVA10496.out");

const int inf = INT_MAX / 3;

struct point
{
    int x;
    int y;
};

point _point(int x, int y)
{
    point temp{x, y}; return temp;
}

int _abs(int x)
{
    if (x > 0) return x;
    return -x;
}

void solve(int u, int visit, vector<vector<int>> & a, vector<vector<int>> & dp)
{
    int n = a.size();

    if (visit == ((1 << n) - 1))
    {
        dp[u][visit] = a[u][0];
        return;
    }
    else if (dp[u][visit] < inf)
    {
        return;
    }

    int ans = inf;
    for (int v = 0; v <= n - 1; ++v)
    {
        if ((visit & (1 << v)) == 0)
        {
            int temp = visit | (1 << v);
            solve(v, temp, a, dp);

            ans = min(ans, a[u][v] + dp[v][temp]);
        }
    }

    dp[u][visit] = ans;
}

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int xM, yM, xK, yK; fin >> xM >> yM >> xK >> yK;

        int n; fin >> n; ++n;
        vector<vector<int>> a(n, vector<int>(n, inf));

        vector<point> p(n); p[0] = _point(xK, yK);
        for (int u = 1; u <= n - 1; ++u)
        {
            fin >> p[u].x >> p[u].y;

            for (int v = 0; v <= u - 1; ++v)
            {
                a[u][v] = _abs(p[u].x - p[v].x) + _abs(p[u].y - p[v].y);
                a[v][u] = a[u][v];
            }
        }

        vector<vector<int>> dp(n, vector<int>(1 << n, inf));
        solve(0, 0, a, dp);

        fout << "The shortest path has length " << dp[0][1] << '\n';
    }

    return 0;
}
