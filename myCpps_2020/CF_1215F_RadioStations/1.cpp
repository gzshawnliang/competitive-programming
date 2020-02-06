#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1600003;
int n, p, M, m, N, cnt, idx, scc, siz;
int head[maxn], dfn[maxn], low[maxn], c[maxn];
vector<int> e[maxn];
int ans[maxn];
stack<int> s;
bool v[maxn];
bool flag;
void add(int u, int v)
{
    e[u].push_back(v);
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++idx;
    s.push(x);
    v[x] = true;
    for (int i = 0; i < e[x].size(); i++)
    {
        int to = e[x][i];
        if (!dfn[to])
        {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if (v[to])
            low[x] = min(low[x], dfn[to]);
    }
    if (dfn[x] == low[x])
    {
        scc++;
        while (1)
        {
            int k = s.top();
            s.pop();
            v[k] = false;
            c[k] = scc;
            if (k == x)
                return;
        }
    }
}
void solve()
{
    for (int i = 1; i <= N + N; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= N; i++)
        if (c[i] == c[i + N])
        {
            flag = true;
            return;
        }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_1215F_RadioStations.in", "r", stdin);
        freopen("CF_1215F_RadioStations.out", "w", stdout);
    #endif      
    scanf("%d%d%d%d", &n, &p, &M, &m);
    N = p + M + 1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x + N, y);
        add(y + N, x);
    }
    for (int i = 1; i <= p; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        add(i, l + p + N);
        add(i, r + p + 1);
        add(l + p, i + N);
        add(r + p + 1 + N, i + N);
    }
    for (int i = 1; i <= M; i++)
    {
        add(i + p, i + p + 1);
        add(i + p + 1 + N, i + p + N);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v + N);
        add(v, u + N);
    }
    add(p + 1, p + 1 + N);
    solve();
    if (flag)
    {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= p; i++)
        if (c[i] < c[i + N])
            ans[++siz] = i;
    for (int i = 1; i <= M; i++)
        if (c[i + p + 1] < c[i + p + 1 + N])
        {
            printf("%d %d\n", siz, i);
            break;
        }
    for (int i = 1; i <= siz; i++)
        printf("%d ", ans[i]);
    return 0;
}