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


const int INF = 1000000;

void trans(int & _count, string in, map<string, int> & _stoi)
{
    if (_stoi[in] == 0)
    {
        ++_count;
        _stoi[in] = _count;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int C = 0;
    while (true)
    {
        ++C;

        if (C == 5)
        {
            cout << "";
        }

        int n = 0, m = 0, _count = 0;
        cin >> n >> m;
        if (n + m == 0) break;

        map<string, int> _stoi;
        vector<vector<int>> dp(500, vector<int>(500, INF));
        for (int c = 1; c <= m; ++c)
        {
            string t0, t1; cin >> t0 >> t1;
            trans(_count, t0, _stoi);
            trans(_count, t1, _stoi);

            dp[_stoi[t0]][_stoi[t1]] = 1;
            dp[_stoi[t1]][_stoi[t0]] = 1;
        }

        if (n > _count)
        {
            cout << "Network " << C << ": DISCONNECTED\n\n";
            continue;
        }

        n = _count;

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

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                ans = max(ans, dp[i][j]);
            }
        }

        cout << "Network " << C << ": ";
        if (ans >= INF)
        {
            cout << "DISCONNECTED\n";
        }
        else
        {
            cout << ans << '\n';
        }
        cout << '\n';
    }

   	cout.flush();
   	return 0;
}
