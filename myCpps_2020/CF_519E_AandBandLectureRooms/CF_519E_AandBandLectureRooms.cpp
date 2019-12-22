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

int dfs2(int u, int first, int avoid1, int avoid2, vector<int> &visited)
{
    if (u == avoid1 || u == avoid2) return -1;

    int size = g[u].size(), ans = 1;
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i];

        if (visited[v] == 0)
        {
            visited[v] = 1;

            int temp = dfs2(v, first, avoid1, avoid2, visited);

            if (temp == -1)
            {
                if (u != first)
                {
                    return -1;
                }
            }
            else
            {
                ans += temp;
            }
        }
    }

    return ans;
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


    int q; cin >> q;
    for (int cq = 1; cq <= q; ++cq)
    {
        int qu, qv; cin >> qu >> qv;

        if (qu == qv)
        {
            cout << n << '\n';
            continue;
        }

        vector<int> depth  (n + 1, 0),
                    visited(n + 1, 0);
        depth[qu] = 0; visited[qu] = 1;

        vector<vector<int>> up (n + 1, vector<int>(maxP + 1, 0));

        dfs(qu, visited, depth, up);

        for (int j = 1; j <= maxP; ++j)
        {
            for (int i = 0; i <= n; ++i)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        if (depth[qv] % 2 == 1)
        {
            cout << "0\n";
            continue;
        }

        int dis = depth[qv] / 2, ansP = qv;
        for (int b = maxP; b >= 0; --b)
        {
            if (dis - _pow2[b] >= 0)
            {
                ansP = up[ansP][b];
                dis -= _pow2[b];
            }
        }

        vector<int> visited2(n + 1, 0); visited2[ansP] = 1;
        cout << dfs2(ansP, ansP, qu, qv, visited2) << '\n';
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
