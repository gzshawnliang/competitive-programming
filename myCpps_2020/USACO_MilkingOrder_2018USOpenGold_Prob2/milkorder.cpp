/*
===========================================================
* @Name:           Problem 2. Milking Order 
* @Author:         Shawn
* @create Time:    2020/1/12 20:40:01
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=838&lang=zh
* @Description:    USACO 2018 US Open Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("milkorder.in");
ofstream fout("milkorder.out");

vector<int> check(int mid, int n, vector<vector<int>> & a)
{
    vector<int> ind(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i <= mid - 1; ++i)
    {
        int siz = a[i].size();
        for (int j = 0; j <= siz - 2; ++j)
        {
            g[a[i][j]].push_back(a[i][j + 1]);
            ++ind[a[i][j + 1]];
        }
    }

    vector<int> lef, res;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int u = 1; u <= n; ++u)
    {
        if (ind[u] == 0)
        {
            if (g[u].size() == 0)
            {
                lef.push_back(u);
            }
            else
            {
                q.push(u);
            }
        }
    }

    while (q.empty() == false)
    {
        int u = q.top(); q.pop();

        res.push_back(u);
        
        int siz = g[u].size();
        for (int i = 0; i <= siz - 1; ++i)
        {
            int v = g[u][i];

            --ind[v];
            if (ind[v] == 0) q.push(v);
        }
    }

    vector<int> final = {};
    if (res.size() + lef.size() < n) return final;

    sort(lef.begin(), lef.end());

    int midPos = upper_bound(lef.begin(), lef.end(), res[0]) - lef.begin();

    int sizLef = lef.size(), i = 0;
    while (i <= sizLef - 1 && i < midPos)
    {
        final.push_back(lef[i]);
        ++i;
    }

    int sizRes = res.size();
    for (int j = 0; j <= sizRes - 1; ++j)
    {
        final.push_back(res[j]);
    }

    while (i <= sizLef - 1)
    {
        final.push_back(lef[i]);
        ++i;
    }

    return final;
}

int main()
{
    int n, m; fin >> n >> m;

    vector<vector<int>> a(m);
    for (int i = 0; i <= m - 1; ++i)
    {
        int siz; fin >> siz;

        vector<int> tmp(siz);
        for (int j = 0; j <= siz - 1; ++j)
        {
            fin >> tmp[j];
        }

        a[i] = tmp;
    }

    int l = 1, r = m;
    vector<int> ans;
    while (true)
    {
        int mid = (l + r) / 2;

        vector<int> tmp = check(mid, n, a);

        if (tmp.size() == 0)
        {
            r = mid - 1;
        }
        else
        {
            ans = tmp;

            if (l == mid) break;
            l = mid;
        }
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        if (i > 0) fout << ' ';
        fout << ans[i];
    }
    fout << '\n';

    return 0;
}
