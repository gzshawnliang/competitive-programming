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

void trans(int & n, char chr, vector<int> & ctoi, vector<char> & itoc)
{
    if (ctoi[chr - 'A'] == -1)
    {
        ++n;
        ctoi[chr - 'A'] = n;
        itoc[n] = chr;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, m = 0, q = 0, _count = -1;
        cin >> n >> m;
        if (n + m == 0) break;
        
        vector<int> ctoi(26, -1);
        vector<char> itoc(26);
        vector<vector<int>> dp(n, vector<int>(n, INF));
        vector<vector<bool>> a(n, vector<bool>(n, false));
        vector<vector<vector<int>>> path(n, vector<vector<int>>(n, vector<int>()));
        for (int c = 1; c <= m; ++c)
        {
            char chr0, chr1;
            int w;
            cin >> chr0 >> chr1 >> w;
            trans(_count, chr0, ctoi, itoc);
            trans(_count, chr1, ctoi, itoc);
            dp[ctoi[chr0 - 'A']][ctoi[chr1 - 'A']] = w;
            dp[ctoi[chr1 - 'A']][ctoi[chr0 - 'A']] = w;
            a[ctoi[chr0 - 'A']][ctoi[chr1 - 'A']] = true;
            a[ctoi[chr1 - 'A']][ctoi[chr0 - 'A']] = true;
        }
        for (int i = 0; i <= n - 1; ++i)
        {
            dp[i][i] = 0;
            for (int j = 0; j <= n - 1; ++j)
            {
                path[i][j].push_back(i);
                path[i][j].push_back(j);
            }
        }

        for (int k = 0; k <= n - 1; ++k)
        {
            for (int u = 0; u <= n - 1; ++u)
            {
                for (int v = 0; v <= n - 1; ++v)
                {
                    int size0 = path[u][v].size(), size1 = path[u][k].size(), size2 = path[k][v].size();
                    if (dp[u][v] > dp[u][k] + dp[k][v])
                    {
                        dp[u][v] = dp[u][k] + dp[k][v];

                        path[u][v].clear();
                        for (int i = 0; i <= size1 - 1; ++i)
                        {
                            path[u][v].push_back(path[u][k][i]);
                        }
                        for (int i = 1; i <= size2 - 1; ++i)
                        {
                            path[u][v].push_back(path[k][v][i]);
                        }
                    }
                    else if (dp[u][v] == dp[u][k] + dp[k][v] && size0 > size1 + size2 - 1)
                    {
                        path[u][v].clear();
                        for (int i = 0; i <= size1 - 1; ++i)
                        {
                            path[u][v].push_back(path[u][k][i]);
                        }
                        for (int i = 1; i <= size2 - 1; ++i)
                        {
                            path[u][v].push_back(path[k][v][i]);
                        }
                    }
                }
            }
        }

        cin >> q;
        for (int c0 = 1; c0 <= q; ++c0)
        {
            char chr0, chr1; cin >> chr0 >> chr1;
            trans(_count, chr0, ctoi, itoc);
            trans(_count, chr1, ctoi, itoc);
            vector<int> ans = path[ctoi[chr0 - 'A']][ctoi[chr1 - 'A']];
            int size0 = ans.size();
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << itoc[ans[i]];
            }
            cout << '\n';
        }
    }

   	cout.flush();
   	return 0;
}
