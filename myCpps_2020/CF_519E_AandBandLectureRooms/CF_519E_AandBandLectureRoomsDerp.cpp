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

void dfs(int u, vector<int> &visited, vector<int> &depth)
{
    int size = g[u].size();
    for (int i = 0; i <= size - 1; ++i)
    {
        int v = g[u][i];

        if (visited[v] == 0)
        {
            visited[v] = 1;

            depth[v] = depth[u] + 1;

            dfs(v, visited, depth);
        }
    }
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

        vector<int> depth  (n + 1, 0),
                    visited(n + 1, 0);
        depth[qu] = 1; visited[qu] = 1;

        dfs(qu, visited, depth);

        int ans = 0;
        for (int u = 1; u <= n; ++u)
        {
            if (depth[u] == depth[qv] && u != qv)
            {
                ++ans;
            }
        }

        if (abs(depth[qu] - depth[qv]) % 2 == 1)
        {
            cout << "0\n";
        }
        else
        {
            cout << ans + 1 << '\n';
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
