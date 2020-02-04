/*
===========================================================
* @Name:           10319 - Manhattan
* @Author:         Shawn
* @create Time:    2020/02/03 18:49:00
* @url:            https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1260
* @Description:    2-SAT,Tarjan SCC
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int trans(int x, bool isS, bool isI, int ns)
{
    if (isS == 1) return (x - 1) * 2 + isI;
    else          return (x - 1) * 2 + isI + ns * 2;
}

void dfs(int u, int &cnt, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk, vector<unordered_set<int>> &g)
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
        int ns = 0, na = 0; cin >> ns >> na;
        int n = ns * 2 + na * 2;

        vector<unordered_set<int>> g(n);

        int tfq; cin >> tfq;
        for (int q = 1; q <= tfq; ++q)
        {
            int s1, a1, s2, a2; cin >> s1 >> a1 >> s2 >> a2;
            if (s1 == s2 && a1 == a2) continue;

            bool isSInc = (a1 < a2), isAInc = (s1 < s2);
            
            if (s1 == s2)
            {
                g[trans(s1, 1, !isSInc, ns)].insert(trans(s1, 1, isSInc, ns));
            }
            else if (a1 == a2)
            {
                g[trans(a1, 0, !isAInc, ns)].insert(trans(a1, 0, isAInc, ns));
            }
            else
            {
                g[trans(s1, 1, !isSInc, ns)].insert(trans(a1, 0, isAInc, ns));
                g[trans(a1, 0, !isAInc, ns)].insert(trans(s1, 1, isSInc, ns));

                g[trans(s2, 1, !isSInc, ns)].insert(trans(a2, 0, isAInc, ns));
                g[trans(a2, 0, !isAInc, ns)].insert(trans(s2, 1, isSInc, ns));

                g[trans(s1, 1, !isSInc, ns)].insert(trans(s2, 1, isSInc, ns));
                g[trans(s2, 1, !isSInc, ns)].insert(trans(s1, 1, isSInc, ns));

                g[trans(a1, 0, !isAInc, ns)].insert(trans(a2, 0, isAInc, ns));
                g[trans(a2, 0, !isAInc, ns)].insert(trans(a1, 0, isAInc, ns));
            }
        }

        int cnt = 0;
        vector<int> ids(n * 2, -1), low(n * 2, 0), inStack(n * 2, 0);
        stack<int> stk;
        for (int s = 1; s <= ns; ++s)
        {
            if (ids[trans(s, 1, 0, ns)] == -1) dfs(trans(s, 1, 0, ns), cnt, ids, low, inStack, stk, g);
            if (ids[trans(s, 1, 1, ns)] == -1) dfs(trans(s, 1, 1, ns), cnt, ids, low, inStack, stk, g);
        }
        for (int a = 1; a <= na; ++a)
        {
            if (ids[trans(a, 0, 0, ns)] == -1) dfs(trans(a, 0, 0, ns), cnt, ids, low, inStack, stk, g);
            if (ids[trans(a, 0, 1, ns)] == -1) dfs(trans(a, 0, 1, ns), cnt, ids, low, inStack, stk, g);
        }

        bool flg = true;
        for (int s = 1; s <= ns && flg == true; ++s)
        {
            if (low[trans(s, 1, 0, ns)] == low[trans(s, 1, 1, ns)])
            {
                flg = false;
            }
        }
        for (int a = 1; a <= na && flg == true; ++a)
        {
            if (low[trans(a, 0, 0, ns)] == low[trans(a, 0, 1, ns)])
            {
                flg = false;
            }
        }

        if (flg == true) cout << "Yes\n";
        else             cout << "No\n";
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