/*
===========================================================
* @Name:           1076E Vasya and a Tree
* @Author:         Shawn
* @create Time:    2020/3/26 17:15:00
* @url:            https://codeforces.com/contest/1076/problem/E
* @Description:    树状数组+DFS
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class fenwickTree1index
{
  private:
    ll lowbit(ll x)
    {
        return (x & (-x));
    }

  public:
    vector<ll> a;
    vector<ll> s;

    fenwickTree1index()
    {
    }

    fenwickTree1index(vector<ll> & in)
    {
        build(in);
    }

    void build(vector<ll> & in)
    {
        ll n = in.size();

        a.assign(n + 5, 0);
        s.assign(n + 5, 0);

        for (ll i = 1; i <= n; ++i)
        {
            update(i, in[i - 1]);
        }
    }

    void update(ll k, ll delta)
    {
        ++k;
        ll n = s.size();

        a[k] += delta;

        for (ll i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    ll query(ll k)
    {
        ++k;
        ll ans = 0;

        for (ll i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    int sum(ll i, ll j)
    {
        return query(j) - query(i - 1);
    }
};

class solution
{
  private:
    int n, m;
    vector<vector<int>> edge;
    vector<vector<pair<int, ll>>> query;

    vector<int> level;             //level[i]:节点i的层次
    vector<int> vist;              //vist[i]:是否访问过节点i

    vector<ll> ans;                 //每个节点的最终答案
    int maxLevel = 0;               //最大的层数

    //第一次深度，求出level数组和maxLevel
    void dfs(int curr, int pre)
    {
        vist[curr] = 1;
        for (auto u : edge[curr])
            if (vist[u] == 0)
            {
                level[u] = level[curr] + 1;
                maxLevel = max(maxLevel, level[u]);
                dfs(u, curr);
            }
    }

    //第二次深度，计算ans
    void dfs2(int curr, int pre)
    {
        vist[curr] = 1;

        //当前层~当前层+d，增加x，超出减
        for (auto pair : query[curr])
        {
            bit.update(level[curr], pair.second);
            int vlevel = min(level[curr] + pair.first , maxLevel)+1;   //vlevel：当前节点v影响到第几层，不能超过maxLevel
            bit.update(vlevel, 0 - pair.second);
            //bit.update(pair.first + 1, 0 - pair.second);
        }

// #ifndef ONLINE_JUDGE
//         for (int i = 0; i <= maxLevel; ++i)
//             cout << bit.query(i) << " ";
//         cout << "\n";
// #endif        

        ans[curr] = bit.query(level[curr]);

        for (auto u : edge[curr])
            if (vist[u] == 0)
                dfs2(u, curr);

        //回溯回来的时候，当前层~当前层+d，减x，超出增x，恢复原样
        for (auto pair : query[curr])
        {
            bit.update(level[curr], 0 - pair.second);
            int vlevel = min(level[curr] + pair.first , maxLevel)+1;   //vlevel：当前节点v影响到第几层，不能超过maxLevel
            bit.update(vlevel, pair.second);
            //bit.update(pair.first + 1, pair.second);
        }
    }

  public:
    fenwickTree1index bit;
    solution()
    {
    }
    void solve()
    {
        cin >> n;
        level.assign(n + 1, 0);
        vist.assign(n + 1, 0);
        ans.assign(n + 1, 0);
        edge.assign(n + 1, vector<int>());

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        dfs(1, 0);
        cin >> m;
        query.assign(n + 1, vector<pair<int, ll>>());

        for (int i = 0; i <= m - 1; ++i)
        {
            int v, d;
            ll x;
            cin >> v >> d >> x;
            //int vlevel = min(level[v] + d, maxLevel);   //vlevel：当前节点v影响到第几层，不能超过maxLevel
            query[v].push_back({d, x});
        }
        

        vist.assign(n + 1, 0);
        vector<ll> dep(maxLevel + 5, 0);
        bit.build(dep);

        dfs2(1, 0);

// #ifndef ONLINE_JUDGE        
//         cout << "---\n";
// #endif        

        for (int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1076E_VasyaandaTree.in", "r", stdin);
    //freopen("CF_1076E_VasyaandaTree.out", "w", stdout);
#endif

    solution slu1;
    slu1.solve();

    cout.flush();
    return 0;
}