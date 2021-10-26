/*
===========================================================
* @Name:           1139E Maximize Mex
* @Author:         Thomas
* @create Time:    2020/5/6 17:23:06
* @url:            https://codeforces.com/contest/1139/problem/E
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>
using namespace std;

class solution
{
  public:
    vector<int> p, c, k, visit, match, ans, leaveStudent;
    vector<vector<int>> g;

    bool dfs(int u)
    {
        for (auto v : g[u])
        {
            if (visit[v] == 1)
                continue;

            visit[v] = 1;
            if (match[v] == 0 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    void exec()
    {
        int n, m;
        cin >> n >> m;

        p.assign(n + 1, 0);
        c.assign(n + 1, 0);
        leaveStudent.assign(n + 1, 0);

        int maxP = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i];
            maxP = max(p[i], maxP);
        }
        g.assign(n + maxP + 5, vector<int>());
        match.assign(n + maxP + 5, 0);

        for (int i = 1; i <= n; ++i)
            cin >> c[i];

        int d;
        cin >> d;
        k.assign(d + 1, 0);
        ans.assign(d + 1, 0);
        for (int i = 1; i <= d; ++i)
        {
            cin >> k[i];
            leaveStudent[k[i]] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (leaveStudent[i] == 0)
            {
                int u = n + p[i] + 1;
                int v = c[i];

                g[u].push_back(v);
                g[v].push_back(u);
            }
        }

        int mex = 0;
        for (int i = d; i >= 1; --i)
        {
            while (true)
            {
                visit.assign(n + maxP + 5, 0);
                if (dfs(n + mex + 1))
                    ++mex;
                else
                    break;
            }

            ans[i] = mex;
            int u = n + p[k[i]] + 1;
            int v = c[k[i]];

            cerr << "Day" << i << ":"<< u << "--" << v << "\n";

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 1; i <= d; ++i)
            cout << ans[i] << "\n";
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_1139E_MaximizeMex.in", "r", stdin);
    //freopen("CF_1076E_VasyaandaTree.out", "w", stdout);
#endif

    solution solu1;
    solu1.exec();
    return 0;
}