/*
===========================================================
* @Name:           1215F Radio Stations
* @Author:         Shawn
* @create Time:    2020/2/6 20:51:16
* @url:            https://codeforces.com/contest/1215/problem/F
* @Description:    2-sat,Tarjan SCC，输出方案
                    https://www.luogu.com.cn/blog/Sooke/solution-cf1215f
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> g[1600005];

int yes(int x) { return x * 2; }
int don(int x) { return x * 2 + 1; }

void lnk(int u, int v)
{
    g[u].push_back(v);
    g[v ^ 1].push_back(u ^ 1);
}

void dfs(int u, int &cnt, int &cntScc, vector<int> &topLog, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk)
{
    stk.push(u); inStack[u] = 1;
    
    ids[u] = cnt; low[u] = cnt; ++cnt;

    for (auto ite = g[u].begin(); ite != g[u].end(); ++ite)
    {   
        int v = *ite;
        if (ids[v] == -1) dfs(v, cnt, cntScc, topLog, ids, low, inStack, stk);

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
    int totC, n, maxF, totI; cin >> totC >> n >> maxF >> totI;

    for (int c = 1; c <= totC; ++c)
    {
        int u, v; cin >> u >> v;
        --u; --v;

        lnk(don(u), yes(v));
    }

    for (int i = 0; i <= maxF - 1; ++i)
    {
        lnk(yes(n + i), yes(n + i + 1));
    }

    for (int u = 0; u <= n - 1; ++u)
    {
        int l, r; cin >> l >> r;
        lnk(yes(u), don(n + l - 1));
        lnk(yes(u), yes(n + r));
    }

    for (int c = 1; c <= totI; ++c)
    {
        int u, v; cin >> u >> v;
        --u; --v;

        lnk(yes(u), don(v));
    }

    int cnt = 0, cntScc = 0, totP = don(n + maxF);
    vector<int> topLog(totP + 5, 0), ids(totP + 5, -1), low(totP + 5, 0), inStack(totP + 5, 0);
    stack<int> stk;

    for (int u = 0; u <= totP; ++u)
    {
        if (ids[u] == -1) dfs(u, cnt, cntScc, topLog, ids, low, inStack, stk);
    }

    bool flg = true;
    for (int u = 0; u <= n - 1; ++u)
    {
        if (low[yes(u)] == low[don(u)])
        {
            flg = false;
            break;
        }
    }

    if (flg == false)
    {
        cout << "-1\n";
    }
    else
    {
        int k = 0;
        for (int u = 0; u <= n - 1; ++u)
        {
            if (topLog[yes(u)] < topLog[don(u)]) ++k;
        }
        cout << k << ' ';

        for (int i = 1; i <= maxF; ++i)
        {
            if (topLog[yes(n + i)] < topLog[don(n + i)])
            {
                cout << i << '\n';
                break;
            }
        }

        bool first = true;
        for (int u = 0; u <= n - 1; ++u)
        {
            if (topLog[yes(u)] < topLog[don(u)])
            {
                if (first == false) cout << ' ';
                first = false;

                cout << u + 1;
            }
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
        freopen("CF_1215F_RadioStations.in", "r", stdin);
        freopen("CF_1215F_RadioStations.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}