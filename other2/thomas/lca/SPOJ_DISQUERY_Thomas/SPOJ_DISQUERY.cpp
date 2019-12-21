#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii =pair<ll,ll>;

ll lg2(ll n)
{
    ll i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

class LCA
{
  private:
    ll n;                      //节点的数量
    ll root;                   //根节点    
    ll maxUpStep;              //最大跳跃的步数=log2(n)
    vector<ll> depth;          //每个节点的深度depth[2]=1,表示节点2的深度是1
    vector<ll> visited;        //深度搜索访问过的节点
    
	vector<vector<ll>> ancestors; 	//ancestors[i][j]表示i节点往上2^j个祖先

	vector<vector<ll>> minDist;
	vector<vector<ll>> maxDist;

	vector<ll> parent; 		//parent[i]表示i节的父亲

  public:
    vector<vector<ii>> tree;


    LCA(ll p_n)
    {
        this->n = p_n;
        maxUpStep = lg2(n);

        tree.assign(n + 1, vector<ii>());
        ancestors.assign(n + 1, vector<ll>(maxUpStep + 1, 0));

		minDist.assign(n + 1, vector<ll>(maxUpStep + 1, INT_MAX));
		maxDist.assign(n + 1, vector<ll>(maxUpStep + 1, INT_MIN));

        depth.assign(n + 1, 0);
		parent.assign(n + 1, 0);
        visited.assign(n + 1, 0);

    }

    void setRoot(ll p_root)
    {
        this->root = p_root;
        depth[root] = 0;
    }

    void dfsDepth(ll curr)
    {
        visited[curr] = 1;

        //遍历curr的子节点POJ不支持auto关键字
        // for(auto next:tree[curr])
        // {
        //     ancestors[next][0] = curr;
        //     depth[next] = depth[curr] + 1;
        //     if (visited[next] == 0)
        //         dfsDepth(next);
        // }

        ll size1 = tree[curr].size();
        for (ll i = 0; i <= size1 - 1; ++i)
        {
            ll next = tree[curr][i].first;
            if (visited[next] == 0)
			{
            	ancestors[next][0] = curr;
				minDist[next][0] = tree[curr][i].second;
				maxDist[next][0] = tree[curr][i].second;

            	depth[next] = depth[curr] + 1;
				parent[next]=curr;
                dfsDepth(next);
			}
        }
    }

    void setFather()
    {
        for (ll j = 1; j <= maxUpStep-1; ++j)
            for (ll i = 1; i <= n; ++i)
			{
                ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
				minDist[i][j] = min(minDist[i][j-1],minDist[ancestors[i][j - 1]][j - 1]);
				maxDist[i][j] = max(maxDist[i][j-1],maxDist[ancestors[i][j - 1]][j - 1]);
			}
    }

    ll lca(ll u, ll v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        //设置同等深度
        for (ll b = maxUpStep-1; b >= 0; --b)
            if (depth[ancestors[u][b]] >= depth[v])
                u = ancestors[u][b];

        if (u == 0)
            return root;
        else if (u == v)
            return u;

        //往上跳跃
        for (ll b = maxUpStep-1; b >= 0; --b)
        {
            if (ancestors[u][b] != ancestors[v][b])
            {
                u = ancestors[u][b];
                v = ancestors[v][b];
            }
        }
        return ancestors[u][0];
    }

	ii cal(ll u,ll v)
	{
		ii result=make_pair(INT_MAX,INT_MIN);

		for (ll j = maxUpStep-1; j >=0; --j)
		{
			if (ancestors[u][j] == v)
			{
				result.first=min(result.first,minDist[u][j]);
				result.second=max(result.second,maxDist[u][j]);
			}
			else if (ancestors[u][j]>0 && depth[ancestors[u][j]] >= depth[v])
			{
				result.first=min(result.first,minDist[u][j]);
				result.second=max(result.second,maxDist[u][j]);

				u = ancestors[u][j];
			}
		}
		return result;
	}
};

void solve()
{
	ll N;
	cin >> N;
	LCA lca(N);
	ll root=1;
	for (ll i = 1; i <= N-1 ; ++i)
	{
		ll u,v,w;
		cin >>u>>v>>w;
		lca.tree[u].push_back(make_pair(v,w));
		if(u!=root)
			lca.tree[v].push_back(make_pair(u,w));
	}

	lca.setRoot(root);
	lca.dfsDepth(root);
	lca.setFather();
	
	ll K;
	cin >> K;
	for (ll i = 1; i <= K ; ++i)
	{
		ll a,b;
		cin >>a>>b;
		ll findlca =lca.lca(a,b);
		ii result ;
		if(findlca==a)
		{
			result = lca.cal(b,findlca);
		}
		else if(findlca==b)
		{
			result = lca.cal(a,findlca);
		}
		else
		{
			ii resulta = lca.cal(a,findlca);
			ii resultb = lca.cal(b,findlca);

			ll minResult=min(resulta.first,resultb.first);
			minResult=min(minResult,resulta.second);
			minResult=min(minResult,resultb.second);

			ll maxResult=max(resulta.second,resultb.second);
			maxResult=max(maxResult,resulta.first);
			maxResult=max(maxResult,resultb.first);			

			result =make_pair(minResult,maxResult);
		}
		

		cout << result.first << " " << result.second << "\n";

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("SPOJ_DISQUERY.in", "r", stdin);
		//freopen("SPOJ_DISQUERY.out", "w", stdout);
	#endif    

	solve();


	cout.flush();
	return 0;
}