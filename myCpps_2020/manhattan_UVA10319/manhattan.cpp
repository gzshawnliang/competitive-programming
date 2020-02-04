#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1000;

int trans(int i, bool isUoD, bool isUoR, int m)
{
    if (isUoD == true) return i * 2 - isUoR;
    else               return m * 2 + i * 2 - isUoR;
}

void dfs(int u, int &cnt, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk, vector<set<int>> &g)
{
    stk.push(u); inStack[u] = 1;
    
    ids[u] = cnt; low[u] = cnt; ++cnt;

    for (auto ite = g[u].begin(); ite != g[u].end(); ++ite)
    {   
        int v = *ite;
        if (ids[v] == -1) dfs(v, cnt, ids, low, inStack, stk, g);

        if (inStack[v] == true)
        {
            low[u] = min(low[u], low[v]);
        }
    }

    if (ids[u] == low[u])
    {
        while (stk.empty() == false)
        {
            int i = stk.top(); stk.pop();
            
            inStack[i] = 0;
            low[i] = ids[u];

            if (i == u) break;
        }
    }
}

void solve()
{
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n = 0, m = 0; cin >> n >> m;

        if (t == 134)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        vector<set<int>> g(maxN);

        int tfq; cin >> tfq;
        for (int q = 1; q <= tfq; ++q)
        {
            int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
            if (x1 == x2 && y1 == y2) continue;

            bool dirX = (x1 < x2), dirY = (y1 < y2);

            if (x1 == x2)
            {
                g[trans(x1, 1, !dirY, m)].insert(trans(x1, 1, dirY, m));
            }
            else if (y1 == y2)
            {
                g[trans(y1, 0, !dirX, m)].insert(trans(y1, 0, dirX, m));
            }
            else
            {
                g[trans(x1, 1, !dirY, m)].insert(trans(y1, 0, dirX, m));
                g[trans(y1, 0, !dirX, m)].insert(trans(x1, 1, dirY, m));

                g[trans(x2, 1, !dirY, m)].insert(trans(y2, 0, dirX, m));
                g[trans(y2, 0, !dirX, m)].insert(trans(x2, 1, dirY, m));
            }
        }

        int cnt = 0;
        vector<int> ids(maxN, -1), low(maxN, 0), inStack(maxN, 0);
        stack<int> stk;

        for (int i = 1; i <= n; ++i)
        {
            if (ids[trans(i, 0, 0, m)] == -1) dfs(trans(i, 0, 0, m), cnt, ids, low, inStack, stk, g);
            if (ids[trans(i, 0, 1, m)] == -1) dfs(trans(i, 0, 1, m), cnt, ids, low, inStack, stk, g);
        }

        for (int i = 1; i <= m; ++i)
        {
            if (ids[trans(i, 1, 0, m)] == -1) dfs(trans(i, 1, 0, m), cnt, ids, low, inStack, stk, g);
            if (ids[trans(i, 1, 1, m)] == -1) dfs(trans(i, 1, 1, m), cnt, ids, low, inStack, stk, g);
        }

        bool flg = true;
        for (int i = 1; i <= n && flg == true; ++i)
        {
            if (low[trans(i, 0, 0, m)] == low[trans(i, 0, 1, m)]) flg = false;
        }

        for (int i = 1; i <= m && flg == true; ++i)
        {
            if (low[trans(i, 1, 0, m)] == low[trans(i, 1, 1, m)]) flg = false;
        }

        if (flg == true) cout << "Yes\n";
        else             cout << "No\n";


        // cout << '\n';
        // for (int i = 1; i <= n && flg == true; ++i)
        // {
        //     cout << i << ": " << trans(i, 0, 1, m) << ", " << trans(i, 0, 0, m) << '\n';
        // }

        // for (int i = 1; i <= m && flg == true; ++i)
        // {
        //     cout << i << ": " << trans(i, 1, 1, m) << ", " << trans(i, 1, 0, m) << '\n';
        // }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //Submit to OJ in standard input/output,debug in local .in/.out file
        freopen("manhattan.in", "r", stdin);
        freopen("manhattan.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}