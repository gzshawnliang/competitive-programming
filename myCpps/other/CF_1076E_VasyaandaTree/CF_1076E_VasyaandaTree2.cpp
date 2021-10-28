/*
===========================================================
* @Name:           1076E Vasya and a Tree
* @Author:         Shawn
* @create Time:    2020/3/26 17:15:00
* @url:            https://codeforces.com/contest/1076/problem/E
* @Description:    
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

        a.assign(n+5, 0);
        s.assign(n+5, 0);

        for (ll i = 1; i <= n; ++i)
        {
            update(i, in[i-1]);
        }
    }    

    void update(ll k, ll delta)
    {
        ll n = s.size();

        a[k] += delta;

        for (ll i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    ll query(ll k)
    {
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

    vector<int> level;             //节点i的层次
    vector<vector<int>> levelNode; //层次i包含的节点，
    vector<int> ord;               //dfs时候节点i的顺序
    vector<int> children;          //dfs时候节点i的孩子数量，子树的大小
    vector<int> vist;              //是否访问过节点i
    
    vector<ll> ans;               //每个节点的最终答案
    int ordId = 0;
    
    void dfs(int curr,int pre)
    {
        vist[curr] = 1;

        for(auto c:query[curr])
            bit.update(curr,c.second);

        for (auto u : edge[curr])
        {
            if (vist[u] == 0)
            {
                ++children[curr];
                level[u] = level[curr] + 1;
                levelNode[level[u]].push_back(u);
                ++ordId;
                ord[u] = ordId;
                
                dfs(u,curr);
                children[curr] += children[u];
            }
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
        levelNode.assign(n + 1, vector<int>());
        children.assign(n + 1, 0);
        ord.assign(n + 1, 0);
        vist.assign(n + 1, 0);

        ans.assign(n + 1, 0);
        
        bit.build(ans);

        edge.assign(n + 1, vector<int>());

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        levelNode[0].push_back(1); //第0层节点是1，根节点

        cin >> m;
        query.assign(n+1, vector<pair<int, ll>>());

        for (int i = 0; i <= m - 1; ++i)
        {
            int v, d;
            ll x;
            cin >> v >> d >> x;
            query[v].push_back({d, x});
        }

        dfs(1,0);

        for (int i = 1; i <= n ; ++i)
            cout << bit.s[i] << " ";
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