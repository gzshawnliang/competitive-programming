#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


void mark(int u, int & n, vector<int> & trans)
{
    if (trans[u] == -1)
    {
        ++n;
        trans[u] = n;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int C = 0;
    cout << fixed << setprecision(3);

    while (true)
    {
        ++C;

        vector<int> trans(101, -1);
        vector<vector<int>> dp(101, vector<int>(101, 100));

        int u = 0, v = 0, n = 0;
        cin >> u >> v;
        if (u + v == 0) break;
        mark(u, n, trans);
        mark(v, n, trans);
        dp[trans[u]][trans[v]] = 1;
        
        
        while (u + v != 0)
        {
            cin >> u >> v;
            if (u + v == 0) break;

            mark(u, n, trans); mark(v, n, trans);
            dp[trans[u]][trans[v]] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 0;
        }

        for (int k = 1; k <= n; ++k)
        {
            for (int u = 1; u <= n; ++u)
            {
                for (int v = 1; v <= n; ++v)
                {
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
                }
            }
        }

        int total = 0;
        for (int u = 1; u <= n; ++u)
        {
            for (int v = 1; v <= n; ++v)
            {
                total += dp[u][v];
            }
        }

        double temp = n * (n - 1);
        double ans = total / temp;

        cout << "Case " << C << ": average length between pages = " << ans << " clicks\n";
    }

   	cout.flush();
   	return 0;
}

