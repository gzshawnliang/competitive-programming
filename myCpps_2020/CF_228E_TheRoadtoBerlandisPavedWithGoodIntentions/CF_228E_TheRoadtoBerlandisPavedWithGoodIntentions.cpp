/*
===========================================================
* @Name:           228E The Road to Berland is Paved With Good Intentions
* @Author:         Shawn
* @create Time:    2020/2/5 21:03:16
* @url:            https://codeforces.com/contest/228/problem/E
* @Description:    2-sat,Tarjan SCC ，输出方案
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void dfs(int u, int &cnt, int &cntScc, vector<int> &topLog, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk, vector<vector<int>> &g)
{
    stk.push(u); inStack[u] = 1;
    
    ids[u] = cnt; low[u] = cnt; ++cnt;

    for (auto ite = g[u].begin(); ite != g[u].end(); ++ite)
    {   
        int v = *ite;
        if (ids[v] == -1) dfs(v, cnt, cntScc, topLog, ids, low, inStack, stk, g);

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

            topLog[i] = cntScc;
            
            inStack[i] = 0;
            low[i] = ids[u];

            if (i == u) break;
        }

        ++cntScc;
    }
}

void solve()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> g(2 * n);
    for (int c = 1; c <= m; ++c)
    {
        int u, v ,d; cin >> u >> v >> d;
        
        int u0 = u * 2 - 2, u1 = u * 2 - 1, v0 = v * 2 - 2, v1 = v * 2 - 1;
        if (d == 1)
        {
            g[u0].push_back(v0);
            g[u1].push_back(v1);
            g[v0].push_back(u0);
            g[v1].push_back(u1);
        }
        else
        {
            g[u0].push_back(v1);
            g[u1].push_back(v0);
            g[v0].push_back(u1);
            g[v1].push_back(u0);
        }
    }

    int cnt = 0, cntScc;
    vector<int> topLog(n * 2, 0), ids(n * 2, -1), low(n * 2, 0), inStack(n * 2, 0);
    stack<int> stk;

    for (int u = 0; u <= 2 * n - 1; ++u)
    {
        if (ids[u] == -1) dfs(u, cnt, cntScc, topLog, ids, low, inStack, stk, g);
    }

    bool flg = true;
    for (int u = 0; u <= 2 * n - 2; u += 2)
    {
        if (low[u] == low[u + 1])
        {
            flg = false;
            break;
        }
    }

    if (flg == false)
    {
        cout << "Impossible\n";
    }
    else
    {
        int ansSiz = 0;
        vector<int> ans;

        for (int u = 1; u <= n; ++u)
        {
            int u0 = u * 2 - 2, u1 = u * 2 - 1;
            if (topLog[u0] < topLog[u1])
            {
                ans.push_back(u);
                ++ansSiz;
            }
        }
        
        cout << ansSiz << '\n';
        for (int i = 0; i <= ansSiz - 1; ++i)
        {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_228E_TheRoadtoBerlandisPavedWithGoodIntentions.in", "r", stdin);
        freopen("CF_228E_TheRoadtoBerlandisPavedWithGoodIntentions.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}