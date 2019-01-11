#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("P1351.in");
ofstream fout("P1351.out");

const int INF = 2147483647;

int main()
{
    int n; fin >> n;

    vector<int> w(n + 1), sum(n + 1, 0);
    vector<vector<int>> g(n + 1);

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        fin >> w[i];
    }

    int ansMax = 0, ansTotal = 0;
    for (int u = 1; u <= n; ++u)
    {
        int max1 = -1 * INF, max2 = -1 * INF, size = g[u].size();
        
        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g[u][i];
            sum[u] = (sum[u] + w[v]) % 10007;

            if (w[v] > max1)
            {
                max2 = max1;
                max1 = w[v];
            }
            else if (w[v] == max1 || w[v] > max2)
            {
                max2 = w[v];
            }
        }

        ansMax = max(ansMax, max1 * max2);

        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g[u][i];
            ansTotal = (ansTotal + w[v] * (sum[u] - w[v]) % 10007) % 10007;
        }
    }
    
    fout << ansMax << ' ' << ansTotal <<'\n';

    return 0;
}