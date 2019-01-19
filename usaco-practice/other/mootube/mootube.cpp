#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("mootube.in");
ofstream fout("mootube.out");

const int inf = 2147483647;

int solve(int u, int k, vector<bool> & dp, vector<vector<int>> & a, vector<vector<int>> & s)
{
    dp[u] = true;

    int size = s[u].size(), ans = 0;
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = s[u][i];

        if (dp[v] == true || a[u][v] < k)
        {
            continue;
        }

        ans += (solve(v, k, dp, a, s) + 1);
    }

    return ans;
}

int main()
{
    int n, q; fin >> n >> q;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, -1)),
                        s(n + 1);

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v, r; fin >> u >> v >> r;

        a[u][v] = r; a[v][u] = r;
        s[u].push_back(v); s[v].push_back(u);
    }

    for (int c = 1; c <= q; ++c)
    {
        int k, u, ans = 0; fin >> k >> u;

        vector<bool> dp(n + 1, false);
        fout << solve(u, k, dp, a, s) << '\n';
    }

    return 0;
}
