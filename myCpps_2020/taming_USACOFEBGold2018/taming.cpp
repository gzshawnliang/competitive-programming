#include <bits/stdc++.h>

using namespace std;

ifstream fin("taming.in");
ofstream fout("taming.out");

const int inf = INT_MAX / 4;

int main()
{
    int n; fin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, inf)));

    dp[0][0][0] = 0;
    g[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                if (k == 0)
                {
                    dp[i][j][k] = g[i - 1][j - 1] + (a[i] != 0);
                    g[i][j] = min(g[i][j], dp[i][j][k]);
                }
                else
                {
                    dp[i][j][k] = dp[i - 1][j][k - 1] + (a[i] != k);
                    g[i][j] = min(g[i][j], dp[i][j][k]);
                }
            }
        }
    }

    for (int j = 1; j <= n; ++j)
    {
        int out = inf;
        for (int k = 0; k <= n; ++k)
        {
            out = min(out, dp[n][j][k]);
        }

        fout << out << '\n';
    }

    return 0;
}
