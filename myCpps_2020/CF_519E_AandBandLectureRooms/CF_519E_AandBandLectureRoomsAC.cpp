/*
===========================================================
* @Name:           519E A and B and Lecture Rooms
* @Author:         Shawn
* @create Time:    2019/12/22 15:18:45
* @url:            https://codeforces.com/contest/519/problem/E
* @Description:    
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];

int _log2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

void dfs(int u, vector<int> &visited, vector<int> &depth, vector<int> &childTotal, vector<vector<int>> &up)
{
    childTotal[u] = 1;

    int size = g[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i];

        if (visited[v] == 0)
        {
            visited[v] = 1;

            depth[v] = depth[u] + 1;
            up[v][0] = u;

            dfs(v, visited, depth, childTotal, up);

            childTotal[u] += childTotal[v];
        }
    }
}

int upAnc(int x, int k, vector<int> & _pow2, vector<vector<int>> &up)
{
    int maxP = _log2(up.size() - 1);

    for (int b = maxP; b >= 0; --b)
    {
        if (k - _pow2[b] >= 0)
        {
            x = up[x][b];
            k -= _pow2[b];
        }
    }

    return x;
}

void solve()
{
    int n; cin >> n;

    int maxP = _log2(n);
    vector<int> _pow2(maxP + 1, 1);
    for (int i = 1; i <= maxP; ++i)
    {
        _pow2[i] = _pow2[i - 1] * 2;
    }

    for (int u = 1; u <= n; ++u)
    {
        g[u].clear();
    }
    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = 1;
    vector<int> depth  (n + 1, 0),
                visited(n + 1, 0),
                childTotal(n + 1, 0);
    depth[root] = 0; visited[root] = 1;

    vector<vector<int>> up(n + 1, vector<int>(maxP + 1, 0));

    dfs(root, visited, depth, childTotal, up);

    for (int j = 1; j <= maxP; ++j)
    {
        for (int i = 0; i <= n; ++i)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    int q; cin >> q;
    for (int cq = 1; cq <= q; ++cq)
    {
        int qu, qv; cin >> qu >> qv;

        if (depth[qu] < depth[qv]) swap(qu, qv);
        int orgQu = qu, orgQv = qv;

        if (qu == qv)
        {
            cout << n << '\n';
            continue;
        }
        
        for (int b = maxP; b >= 0; --b)
        {
            if (depth[up[qu][b]] >= depth[qv])
            {
                qu = up[qu][b];
            }
        }

        int pos = 0;
        if (qu == qv)
        {
            pos = qu;
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
            pos = up[qu][0];
        }
        

        int dis = depth[orgQu] - depth[pos] + depth[orgQv] - depth[pos];

        if (dis % 2 == 1)
        {
            cout << "0\n";
            continue;
        }
        
        if (depth[orgQu] == depth[orgQv])
        {
            cout << n - childTotal[upAnc(orgQu, dis / 2 - 1, _pow2, up)] - childTotal[upAnc(orgQv, dis / 2 - 1, _pow2, up)] << '\n';
        }
        else
        {
            cout << childTotal[upAnc(orgQu, dis / 2, _pow2, up)] - childTotal[upAnc(orgQu, dis / 2 - 1, _pow2, up)] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_519E_AandBandLectureRooms.in", "r", stdin);
        freopen("CF_519E_AandBandLectureRooms.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}
