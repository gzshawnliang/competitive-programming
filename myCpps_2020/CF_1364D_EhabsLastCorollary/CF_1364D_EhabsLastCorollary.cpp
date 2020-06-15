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

bool dfs(int las, int u, stack<int> &stk, vector<int> &col, vector<int> &vis, int k, vector<pair<int, int>> &pth, vector<vector<int>> &g)
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

            stk.push(v);
            if (dfs(u, v, stk, col, vis, k, pth, g)) return true;
            stk.pop();
        }
        else
        {
            int n = g.size() - 1, m = pth.size();
            deque<int> q; q.push_back(v);
            while (stk.top() != v)
            {
                q.push_back(stk.top());

                stk.pop();
            }

            while (true)
            {
                int nd1 = -1, nd2 = -1, sizQ = q.size();

                vector<int> pos(n + 1, -1);
                for (int i = 0; i <= sizQ - 1; ++i)
                {
                    pos[q[i]] = i;
                }

                for (int i = 0; i <= m - 1 && nd1 == -1; ++i)
                {
                    if (pos[pth[i].first] != -1 && pos[pth[i].second] != -1 && (abs(pos[pth[i].first] - pos[pth[i].second]) != 1) && (abs(pos[pth[i].first] - pos[pth[i].second]) != sizQ - 1))
                    {
                        nd1 = pth[i].first; nd2 = pth[i].second;
                        break;
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

                    pos[q.front()] = 0;
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

                    pos[q.back()] = 0;
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

    vector<pair<int, int>> pth(m);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i <= m - 1; ++i)
    {
        cin >> pth[i].first >> pth[i].second;
        g[pth[i].first].push_back(pth[i].second); g[pth[i].second].push_back(pth[i].first);
    }

    stack<int> stk; stk.push(1);
    vector<int> vis(n + 1, 0); vis[1] = 1;
    vector<int> col(n + 1, -1); col[1] = 0;
    if (!dfs(-1, 1, stk, col, vis, k, pth, g))
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