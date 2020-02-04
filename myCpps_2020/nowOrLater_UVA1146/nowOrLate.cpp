/*
===========================================================
 * @名称:		1146 Now or later
 * @作者:		Shawn 
 * @创建时间: 2020-02-04 23:04:56 
 * @修改人:   Shawn 
 * @修改时间: 2020-02-04 23:04:56 
 * @备注:	2-sat,Tarjan SCC + 二分
 * @题目来源： https://onlinejudge.org/external/11/1146.pdf
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = 1e7;

void dfs(int u, int &cnt, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk, vector<vector<int>> &g)
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

bool check(int mid, int n, vector<pair<int, int>> &a)
{
    vector<vector<int>> g(n * 2);

    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            if (i == j) continue;

            pair<int, int> p1 = a[i], p2 = a[j];

            if (abs(p1.first - p2.first) >= mid && abs(p1.first - p2.second) < mid)
            {
                g[i * 2].push_back(j * 2);
            }
            else if (abs(p1.first - p2.first) < mid && abs(p1.first - p2.second) >= mid)
            {
                g[i * 2].push_back(j * 2 + 1);
            }
            else if (abs(p1.first - p2.first) < mid && abs(p1.first - p2.second) < mid)
            {
                g[i * 2].push_back(i * 2 + 1);
            }

            if (abs(p1.second - p2.first) >= mid && abs(p1.second - p2.second) < mid)
            {
                g[i * 2 + 1].push_back(j * 2);
            }
            else if (abs(p1.second - p2.first) < mid && abs(p1.second - p2.second) >= mid)
            {
                g[i * 2 + 1].push_back(j * 2 + 1);
            }
            else if (abs(p1.second - p2.first) < mid && abs(p1.second - p2.second) < mid)
            {
                g[i * 2 + 1].push_back(i * 2);
            }
        }
    }

    int cnt = 0;
    vector<int> ids(n * 2, -1), low(n * 2, 0), inStack(n * 2, 0);
    stack<int> stk;

    for (int u = 0; u <= 2 * n - 1; ++u)
    {
        if (ids[u] == -1) dfs(u, cnt, ids, low, inStack, stk, g);
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

    return flg;
}

void solve()
{
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        vector<pair<int, int>> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i].first >> a[i].second;
        }

        int lbd = 0, rbd = inf, ans = -1;
        while (true)
        {
            int mid = (lbd + rbd) / 2;

            if (rbd - lbd <= 1)
            {
                if (check(rbd, n, a) == true) ans = rbd;
                else                          ans = lbd;

                break;
            }
            else
            {
                if (check(mid, n, a) == true)
                {
                    lbd = mid;
                }
                else
                {
                    rbd = mid - 1;
                }
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("nowOrLate.in", "r", stdin);
        freopen("nowOrLate.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}