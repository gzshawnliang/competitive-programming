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

bool dfs(int las, int u, stack<int> &stk, vector<int> &vis, int k, vector<vector<int>> &g)
{
    for (auto v:g[u])
    {
        if (las == v) continue;

        if (vis[v] == 0)
        {
            vis[v] = 1;

            stk.push(v);
            if (dfs(u, v, stk, vis, k, g)) return true;
            stk.pop();
        }
        else
        {
            int n = g.size() - 1;
            deque<int> q; q.push_back(v);
            vector<int> inQ(n + 1); inQ[v] = 1;
            while (stk.top() != v)
            {
                q.push_back(stk.top()); inQ[stk.top()] = 1;
                stk.pop();
            }

            while (true)
            {
                int nd1 = -1, nd2 = -1, sizQ = q.size();

                for (int i = 0; i <= sizQ - 1 && nd1 == -1; ++i)
                {
                    for (auto vit:g[q[i]])
                    {
                        if (inQ[vit] == 1 && vit != q[(i - 1 + sizQ) % sizQ] && vit != q[(i + 1 + sizQ) % sizQ])
                        {
                            nd1 = q[i]; nd2 = vit;
                            break;
                        }
                    }
                }

                if (nd1 == -1 && nd2 == -1) break;

                while (true)
                {
                    if      (q.front() == nd1)
                    {
                        nd1 = -1;
                        break;
                    }
                    else if (q.front() == nd2)
                    {
                        nd2 = -1;
                        break;
                    }

                    inQ[q.front()] = 0;
                    q.pop_front();
                }

                while (true)
                {
                    if      (q.back() == nd1)
                    {
                        nd1 = -1;
                        break;
                    }
                    else if (q.back() == nd2)
                    {
                        nd2 = -1;
                        break;
                    }

                    inQ[q.back()] = 0;
                    q.pop_back();
                }
            }

            int sizQ = q.size();
            if (sizQ > k)
            {
                cout << "1\n";

                int ukd2 = k / 2 + (k % 2);
                for (int c = 1; c <= ukd2; ++c)
                {
                    if (c > 1) cout << ' ';
                    cout << q[2 * c - 2];
                }
                cout << '\n';
            }
            else
            {
                cout << "2\n";

                cout << sizQ << '\n';
                for (int i = 0; i <= sizQ - 1; ++i)
                {
                    if (i > 0) cout << ' ';
                    cout << q[i];
                }
                cout << '\n';
            }

            return true;
        }
    }

    return false;
}

void dfs2(int las, int u, vector<int> &col, vector<int> &vis, vector<vector<int>> &g)
{
    for (auto v:g[u])
    {
        if (las == v) continue;

        if (vis[v] == 0)
        {
            vis[v] = 1;

            if (col[u] != 2)
            {
                if      (col[v] == col[u]) col[v] = 2;
                else if (col[v] == -1)     col[v] = 1 - col[u];
            }

            dfs2(u, v, col, vis, g);
        }
    }
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

    stack<int> stk; stk.push(1);
    vector<int> vis(n + 1, 0); vis[1] = 1;
    if (!dfs(-1, 1, stk, vis, k, g))
    {
        vector<int> vis2(n + 1, 0); vis2[1] = 1;
        vector<int> col(n + 1, -1); col[1] = 0;

        dfs2(-1, 1, col, vis2, g);

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