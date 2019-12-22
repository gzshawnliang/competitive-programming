#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int> g[100005];

int _log2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

void dfs(int u, vector<int> &visited, vector<int> &depth, vector<vector<int>> & up)
{
    int size = g[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i];

        if (visited[v] == 0)
        {
            visited[v] = 1;

            depth[v] = depth[u] + 1;
            up[v][0] = u;


            dfs(v, visited, depth, up);
        }
    }
}

void solve()
{
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n; cin >> n;

        int maxP = _log2(n);

        vector<int> isRoot(n + 1, 1);
        
        for (int u = 1; u <= n; ++u)
        {
            g[u].clear();
        }
        
        for (int c = 1; c <= n - 1; ++c)
        {
            int u, v; cin >> u >> v;

            isRoot[v] = 0;

            g[u].push_back(v);
        }

        int root = 0;
        for (int u = 1; u <= n; ++u)
        {
            if (isRoot[u] == 1)
            {
                root = u;
                break;
            }
        }
        
        vector<int> depth  (n + 1, 0),
                    visited(n + 1, 0);
        depth[root] = 1; visited[root] = 1;

        vector<vector<int>> up (n + 1, vector<int>(maxP + 1, 0));

        dfs(root, visited, depth, up);

        for (int j = 1; j <= maxP; ++j)
        {
            for (int i = 0; i <= n; ++i)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        int qu, qv; cin >> qu >> qv;

        if (depth[qu] < depth[qv]) swap(qu, qv);

        int ans = 0;

        for (int b = maxP; b >= 0; --b)
        {
            if (depth[up[qu][b]] >= depth[qv])
            {
                qu = up[qu][b];
            }
        }

        if (qu == qv)
        {
            ans = qu;
        }
        else
        {
            for (int b = maxP; b >= 0; --b)
            {
                if (up[qu][b] != up[qv][b])
                {
                    qu = up[qu][b];
                    qv = up[qv][b];
                }
            }

            ans = up[qu][0];
        }

        cout << ans <<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("POJ_1330.in", "r", stdin);
        freopen("POJ_1330.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}
