/*
===========================================================
 * @名称:		
 * @作者:		Thomas 
 * @创建时间: 2019-12-21 10:38:05 
 * @修改人:   Shawn 
 * @修改时间: 2019-12-21 10:38:05 
 * @备注:		
 * @题目来源： 
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int lg2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

class LCA
{
  private:
    int n;                      //节点的数量
    int root;                   //根节点    
    int maxUpStep;              //最大跳跃的步数=log2(n)
    vector<int> depth;          //每个节点的深度depth[2]=1,表示节点2的深度是1
    vector<int> visited;        //深度搜索访问过的节点
    vector<vector<int>> father; //father[i][j]表示i节点往上2^j个祖先

  public:
    vector<vector<int>> tree;


    LCA(int p_n)
    {
        this->n = p_n;
        maxUpStep = lg2(n);

        tree.assign(n + 1, vector<int>());
        father.assign(n + 1, vector<int>(maxUpStep + 1, 0));

        depth.assign(n + 1, 0);
        visited.assign(n + 1, 0);

    }

    void setRoot(int p_root)
    {
        this->root = p_root;
        depth[root] = 0;
    }

    void dfsDepth(int curr)
    {
        visited[curr] = 1;
        //遍历curr的子节点POJ不支持auto关键字
        // for(auto next:tree[curr])
        // {
        //     father[next][0] = curr;
        //     depth[next] = depth[curr] + 1;
        //     if (visited[next] == 0)
        //         dfsDepth(next);
        // }
        int size1 = tree[curr].size();
        for (int i = 0; i <= size1 - 1; ++i)
        {
            int next = tree[curr][i];
            father[next][0] = curr;
            depth[next] = depth[curr] + 1;
            if (visited[next] == 0)
                dfsDepth(next);
        }
    }

    void setFather()
    {
        for (int j = 1; j <= maxUpStep; ++j)
            for (int i = 1; i <= n; ++i)
                father[i][j] = father[father[i][j - 1]][j - 1];
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        //设置同等深度
        for (int b = maxUpStep; b >= 0; --b)
            if (depth[father[u][b]] >= depth[v])
                u = father[u][b];

        if (u == 0)
            return root;
        else if (u == v)
            return u;

        //往上跳跃
        for (int b = maxUpStep; b >= 0; --b)
        {
            if (father[u][b] != father[v][b])
            {
                u = father[u][b];
                v = father[v][b];
            }
        }
        return father[u][0];
    }
};

void solve()
{
    int T;
    cin >> T;
    int caseNumber=1;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> fa(n + 1, 0);
        LCA lca(n);    
        for (int i = 1; i <= n ; ++i)
        {
            int m;
            cin >> m;
            for (int j = 1; j <= m ; ++j)
            {
                int temp;
                cin >>temp;
                lca.tree[i].push_back(temp);
                fa[temp] = i;
            }
        }

        int root = 1;
        while (fa[root] > 0)
            root = fa[root];        

        lca.setRoot(root);
        lca.dfsDepth(root);
        lca.setFather();

        cout << "Case "<< caseNumber <<":" << "\n";
        int m;
        cin >> m;
        while (m--)
        {
            int a, b;
            cin >> a >> b;            
            cout << lca.lca(a, b) << "\n";
        }
        ++caseNumber;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("SPOJ_LCA.in", "r", stdin);
        freopen("SPOJ_LCA.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}