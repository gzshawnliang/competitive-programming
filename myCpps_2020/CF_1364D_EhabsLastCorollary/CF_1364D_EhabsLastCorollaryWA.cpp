/*
===========================================================
* @Name:           1364D Ehab's Last Corollary
* @Author:         Shawn
* @create Time:    2020/6/15 20:59:23
* @url:            https://codeforces.com/contest/1364/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

bool dfs(int las, int u, deque<int> &q, vector<int> &inQ, vector<int> &col, vector<int> &vis, int k, vector<vector<int>> &g)
{
    int sizQ = q.size();

    for (auto v:g[u])
    {
        if (las == v) continue;

        if (vis[v] == 0)
        {
            vis[v] = 1;

            if (col[u] != 2)
            {
                if      (col[v] == -1)     col[v] = 1 - col[u];
                else if (col[v] == col[u]) col[v] = 2;
            }

            if (sizQ == k)
            {
                int bck = q.back();
                q.pop_back(); inQ[bck] = 0;
                q.push_front(v); inQ[v] = 1;
                
                if (dfs(u, v, q, inQ, col, vis, k, g)) return true;

                q.pop_front(); inQ[v] = 0;
                q.push_back(bck); inQ[bck] = 1;
            }
            else
            {
                q.push_front(v); inQ[v] = 1;
                if (dfs(u, v, q, inQ, col, vis, k, g)) return true;
            }
        }
        else if (inQ[v] == 1)
        {
            q.push_front(v); inQ[v] = 1;
            return true;
        }
    }

    return false;
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= m; ++c)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    deque<int> q; q.push_front(1);
    vector<int> vis(n + 1, 0);
    vector<int> inQ(n + 1, 0); inQ[1] = 1;
    vector<int> col(n + 1, -1); col[1] = 0;

    if (dfs(-1, 1, q, inQ, col, vis, k, g))
    {
        cout << "2\n";

        int start = q.front(); q.pop_front();
        vector<int> ans = {start};
        while (q.front() != start)
        {
            ans.push_back(q.front());
            q.pop_front();
        }
        
        int siz = ans.size();
        cout << siz << '\n';
        for (int i = 0; i <= siz - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    else
    {
        cout << "1\n";
        
        vector<int> tm0, tm1;
        for (int u = 1; u <= n; ++u)
        {
            if (col[u] == 0) tm0.push_back(u);
            else             tm1.push_back(u);
        }

        int siz0 = tm0.size(), siz1 = tm1.size(), ukd2 = k / 2 + (k % 2);
        if (siz0 > siz1)
        {
            for (int i = 0; i <= ukd2 - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << tm0[i];
            }
            cout << '\n';
        }
        else
        {
            for (int i = 0; i <= ukd2 - 1; ++i)
            {
                if (i > 0) cout << ' ';
                cout << tm1[i];
            }
            cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1364D_EhabsLastCorollary.in", "r", stdin);
    freopen("CF_1364D_EhabsLastCorollary.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}