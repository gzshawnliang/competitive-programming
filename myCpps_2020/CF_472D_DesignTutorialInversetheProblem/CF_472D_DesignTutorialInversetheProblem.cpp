/*
===========================================================
* @Name:           472D Design Tutorial: Inverse the Problem
* @Author:         Shawn
* @create Time:    2020/1/30 22:08:15
* @url:            https://codeforces.com/contest/472/problem/D
* @Description:    MST
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;
using ill = long long;

struct edg
{
    int u;
    int v;
    int d;

    bool operator < (const edg & tmp) const
    {
        return d < tmp.d;
    }
};
edg _edg(int u, int v, int d)
{
    edg tmp{u, v, d}; return tmp;
}

int fnd(int x, vector<int> &f)
{
    if (f[x] == x) return x;
    else           return f[x] = fnd(f[x], f);
}

void dfs(int u, int las, vector<int> &tmpD, vector<vector<int>> &d, vector<vector<int>> &g)
{
    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (v != las)
        {
            tmpD[v] = tmpD[u] + d[u][v];
            dfs(v, u, tmpD, d, g);
        }
    }
}

void solve()
{
    int n; cin >> n;

    bool flg = false;
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<edg> allEdg;
    for (int u = 0; u <= n - 1 && flg == false; ++u)
    {
        for (int v = 0; v <= n - 1 && flg == false; ++v)
        {
            cin >> d[u][v];

            if (d[u][v] == 0 && u != v)
            {
                flg = true;
                break;
            }

            if (d[v][u] >= 0 && d[u][v] != d[v][u])
            {
                flg = true;
                break;
            }

            if (u < v)
            {
                allEdg.push_back(_edg(u, v, d[u][v]));
            }
        }

        if (d[u][u] > 0)
        {
            flg = true;
            break;
        }
    }

    if (flg == true)
    {
        cout << "NO\n";
        return;
    }

    sort(allEdg.begin(), allEdg.end());

    vector<int> f(n, 0);
    for (int u = 0; u <= n - 1; ++u) f[u] = u;
    
    vector<vector<int>> g(n);

    int siz = allEdg.size();
    for (int c = 1, j = 0; c <= n - 1 && j <= siz - 1; ++j)
    {
        int u = fnd(allEdg[j].u, f), v = fnd(allEdg[j].v, f);

        if (u == v) continue;

        f[v] = u;
        g[allEdg[j].u].push_back(allEdg[j].v); g[allEdg[j].v].push_back(allEdg[j].u);

        ++c;
    }

    for (int rot = 0; rot <= n - 1 && flg == false; ++rot)
    {
        vector<int> tmpD(n, -1); tmpD[rot] = 0;
        dfs(rot, -1, tmpD, d, g);

        for (int u = 0; u <= n - 1 && flg == false; ++u)
        {
            if (d[rot][u] != tmpD[u])
            {
                flg = true;
                break;
            }
        }
    }

    if (flg == true)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_472D_DesignTutorialInversetheProblem.in", "r", stdin);
        freopen("CF_472D_DesignTutorialInversetheProblem.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}