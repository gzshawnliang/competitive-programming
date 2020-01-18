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

struct sorItm
{
    int v;
    int idx;

    bool operator < (const sorItm & tmp) const
    {
        if (idx > 0 && tmp.idx > 0)
        {
            return idx < tmp.idx;
        }
        else
        {
            return v < tmp.v;
        }
    }
};
sorItm _sorItm(int v, int idx)
{
    sorItm tmp{v, idx}; return tmp;
}

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

    if (mid == 262)
    {
        for (int __s = 0; __s == 0; ++__s);
    }

    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int u = 1; u <= n; ++u)
    {
        if (ind[u] == 0)
        {
            q.push(u);
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
    
    int DBtmp = res.size();
    if (res.size() < n)
    {
        vector<int> _null = {}; return _null;
    }

    return res;
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

        if (r - l <= 1)
        {
            vector<int> tmp1 = check(r, n, a);

            if (tmp1.size() == 0) ans = check(l, n, a);
            else                  ans = tmp1;

            break;
        }

        if (tmp.size() == 0)
        {
            r = mid - 1;
        }
        else
        {
            ans = tmp;
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
