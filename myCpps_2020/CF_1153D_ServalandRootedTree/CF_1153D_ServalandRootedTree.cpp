/*
===========================================================
* @Name:           1153D Serval and Rooted Tree
* @Author:         Shawn
* @create Time:    2020/1/31 15:29:12
* @url:            https://codeforces.com/contest/1153/problem/D
* @Description:    
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int rot = 1;

bool check(int u, int val, int k, vector<int> &typ, vector<int> &cnt, vector<vector<int>> &g)
{
    int siz = g[u].size();

    if (siz == 0)
    {
        return 1;
    }
    else if (typ[u] == 1)
    {
        bool flg = false;
        for (int i = 0; i <= siz - 1; ++i)
        {
            int v = g[u][i];

            if (check(v, val, k, typ, cnt, g) == true)
            {
                flg = true;
                break;
            }
        }

        return flg;
    }
    else
    {
        if (val + cnt[u] - 1 <= k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void dfs(int u, vector<int> &cnt, vector<int> &typ, vector<vector<int>> &g)
{
    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        dfs(v, cnt, typ, g);
        cnt[u] += cnt[v];
    }

    if (typ[u] == 1 || siz == 0)
    {
        cnt[u] = 1;
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> typ(n + 1, 0);
    for (int u = 1; u <= n; ++u) cin >> typ[u];

    vector<vector<int>> g(n + 1);
    for (int v = 2; v <= n; ++v)
    {
        int u; cin >> u;

        g[u].push_back(v);
    }

    int k = 0;
    for (int u = 1; u <= n; ++u) k += (g[u].size() == 0);

    vector<int> cnt(n + 1, 0);
    dfs(rot, cnt, typ, g);

    int l = 1, r = k, ans = 1;
    while (true)
    {
        if (r - l <= 1)
        {
            if (check(rot, r, k, typ, cnt, g) == true) ans = r;
            else                                       ans = l;

            break;
        }
        else
        {
            int mid = (l + r) / 2;

            if (mid == 4)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if (check(rot, mid, k, typ, cnt, g) == true)
            {
                ans = mid;
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1153D_ServalandRootedTree.in", "r", stdin);
        freopen("CF_1153D_ServalandRootedTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}