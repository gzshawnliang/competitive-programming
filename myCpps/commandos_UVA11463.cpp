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

ifstream fin("commandos_UVA11463.in");
ofstream fout("commandos_UVA11463.out");

const int INF = 99999999;

int main()
{
    int T; fin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, m; fin >> n >> m;
        vector<bool> vis0(n, false), vis1(n, false);
        vector<vector<int>> a(n, vector<int>(n, INF));
        for (int c = 1; c <= m; ++c)
        {
            int u, v; fin >> u >> v;
            a[u][v] = 1; a[v][u] = 1;
        }
        int s, d; fin >> s >> d;

        vis0[s] = true; vis1[d] = true;
        vector<int> dis0(n, INF), dis1(n, INF);
        for (int i = 0; i <= n - 1; ++i)
        {
            a[i][i] = 0;
            dis0[i] = a[s][i]; dis1[i] = a[d][i];
        }

        for (int c = 1; c <= n - 1; ++c)
        {
            int _min0 = INF, u0;
            int _min1 = INF, u1;
            for (int i = 0; i <= n - 1; ++i)
            {
                if (vis0[i] == false && dis0[i] < _min0)
                {
                    _min0 = dis0[i]; u0 = i;
                }

                if (vis1[i] == false && dis1[i] < _min1)
                {
                    _min1 = dis1[i]; u1 = i;
                }
            }

            vis0[u0] = true;
            vis1[u1] = true;
            for (int v = 0; v <= n - 1; ++v)
            {
                if (a[u0][v] != INF)
                {
                    dis0[v] = min(dis0[v], dis0[u0] + a[u0][v]);
                }

                if (a[u1][v] != INF)
                {
                    dis1[v] = min(dis1[v], dis1[u1] + a[u1][v]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            ans = max(ans, dis0[i] + dis1[i]);
        }

        fout << "Case " << t << ": " << ans << '\n';
    }

    return 0;
}