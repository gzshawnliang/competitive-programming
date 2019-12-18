#include <bits/stdc++.h>

using namespace std;

//ifstream fin("lca.in");
//ofstream fout("lca.out");

//Least Common Ancestors (最近公共祖先)
class LCA
{
    private:
    int n;                          //节点的数量
    int root;                       //根节点
    vector<int> depth;              //每个节点的深度depth[2]=1,表示节点2的深度是1
    vector<int> visited;            //深度搜索访问过的节点
    vector<vector<int>> father;     //father[i][j]表示i节点往上2^j个祖先

    public:    

    vector<vector<int>> tree;
    

    LCA(int p_n,int p_root)
    {
        this->n=p_n;
        this->root=p_root;
        tree.assign(n + 1, vector<int>());
        father.assign(n + 1, vector<int>(n + 1, 0));

        depth.assign(n + 1, 0);
        visited.assign(n + 1, 0);
        depth[root] = 0;        
    }

    void dfsDepth(int curr)
    {
        visited[curr] = 1;
        if (tree[curr].size() == 0)
            return;

        int size1 = tree[curr].size();
        //遍历curr的子节点
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
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = 1; j <= n - 1; ++j)
            {
                father[i][j] = father[father[i][j-1]][j-1];
                if (father[i][j]==0)
                    break;
            }
        }
    }

    int lca(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);

        //设置同等深度
        for (int b = n-1;b >= 0;--b)
            if (depth[father[u][b]] >= depth[v])
                u = father[u][b];        
        
        if (u == 0) 
            return root;
        else if(u == v) 
            return u;
        
        //往上跳跃
        for (int b = n-1;b >= 0;--b)
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



int main()
{
#ifndef ONLINE_JUDGE
    freopen("lca.in", "r", stdin);
    //freopen("lca.out", "w", stdout);
#endif

    int n;
    int root;
    cin >> n >> root;

    LCA lca(n,root);

    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        lca.tree[a].push_back(b);
//        lca.father[b][0] = a;
    }
    lca.dfsDepth(root);
    lca.setFather();
    cout << lca.lca(13,1) << "\n";
    return 0;
}
