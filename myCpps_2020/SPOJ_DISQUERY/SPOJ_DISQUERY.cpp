#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using namespace std;

const int inf = INT_MAX / 2;

vector<pair<int, int>> g[100005];

int _log2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

void dfs(int u, vector<int> &visited, vector<int> &depth, vector<vector<int>> & up, vector<vector<int>> & shortest, vector<vector<int>> & longest)
{
    int size = g[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i].first;

        if (visited[v] == 0)
        {
            visited[v] = 1;

            depth[v] = depth[u] + 1;
            up[v][0] = u;

            shortest[v][0] = g[u][i].second;
            longest[v][0] = g[u][i].second;

            dfs(v, visited, depth, up, shortest, longest);
        }
    }
}

void solve()
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
        int u, v, d; cin >> u >> v >> d;

        isRoot[v] = 0;

        g[u].push_back(make_pair(v, d));
        g[v].push_back(make_pair(u, d));
    }

    int root = 1;
    vector<int> depth  (n + 1, 0),
                visited(n + 1, 0);
    depth[root] = 1; visited[root] = 1;

    vector<vector<int>> up      (n + 1, vector<int>(maxP + 1, 0)),
                        shortest(n + 1, vector<int>(maxP + 1, inf)),
                        longest (n + 1, vector<int>(maxP + 1, 0));

    dfs(root, visited, depth, up, shortest, longest);

    for (int j = 1; j <= maxP; ++j)
    {
        for (int i = 0; i <= n; ++i)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];

            shortest[i][j] = min(shortest[i][j - 1], shortest[up[i][j - 1]][j - 1]);
            longest[i][j] = max(longest[i][j - 1], longest[up[i][j - 1]][j - 1]);
        }
    }

    int q; cin >> q;
    for (int c = 1; c <= q; ++c)
    {
        int qu, qv; cin >> qu >> qv;

        if (depth[qu] < depth[qv]) swap(qu, qv);

        int shortestAns = inf, longestAns = 0;

        for (int b = maxP; b >= 0; --b)
        {
            if (depth[up[qu][b]] >= depth[qv])
            {
                shortestAns = min(shortestAns, shortest[qu][b]);
                longestAns = max(longestAns, longest[qu][b]);

                qu = up[qu][b];
            }
        }

        if (qu != qv)
        {
            for (int b = maxP; b >= 0; --b)
            {
                if (up[qu][b] != up[qv][b])
                {
                    shortestAns = min(shortestAns, shortest[qu][b]);
                    shortestAns = min(shortestAns, shortest[qv][b]);

                    longestAns = max(longestAns, longest[qu][b]);
                    longestAns = max(longestAns, longest[qv][b]);

                    qu = up[qu][b];
                    qv = up[qv][b];
                }
            }

            shortestAns = min(shortestAns, shortest[qu][0]);
            shortestAns = min(shortestAns, shortest[qv][0]);

            longestAns = max(longestAns, longest[qu][0]);
            longestAns = max(longestAns, longest[qv][0]);
        }

        cout << shortestAns << ' ' << longestAns <<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("SPOJ_DISQUERY.in", "r", stdin);
        freopen("SPOJ_DISQUERY.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}