#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        if (t > 1) cout << '\n';

        int n, e, tl, m; cin >> n >> e >> tl >> m;
        vector<vector<int>> d(n + 1, vector<int>(n + 1, INT_MAX / 2));

        for (int c = 1; c <= m; ++c)
        {
            int u, v, dc; cin >> u >> v >> dc;
            d[u][v] = dc;
        }

        for (int i = 1; i <= n; ++i)
        {
            d[i][i] = 0;
        }

        for (int k = 1; k <= n; ++k)
        {
            for (int u = 1; u <= n; ++u)
            {
                for (int v = 1; v <= n; ++v)
                {
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (d[i][e] <= tl)
            {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

