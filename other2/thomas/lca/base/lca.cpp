#include <bits/stdc++.h>

using namespace std;

//ifstream fin("lca.in");
//ofstream fout("lca.out");

//Least Common Ancestors (最近公共祖先)


int lg2(int n)
{
    int i = 0;
    while ((1<<i) <= n)             //(1<<i) = 2^i
        ++i;

    return i-1;
}

class LCA
{
    private:
    int n;                          //节点的数量
    int root;                       //根节点
    int maxUpStep;                  //最大跳跃的步数=log2(n)
    vector<int> depth;              //每个节点的深度depth[2]=1,表示节点2的深度是1
    vector<int> visited;            //深度搜索访问过的节点
    vector<vector<int>> father;     //father[i][j]表示i节点往上2^j个祖先

    public:    

    vector<vector<int>> tree;

    LCA(int p_n,int p_root)
    {
        this->n=p_n;
        this->root=p_root;
        maxUpStep = lg2(n);

        tree.assign(n + 1, vector<int>());
        father.assign(n + 1, vector<int>(maxUpStep+1, 0));

        depth.assign(n + 1, 0);
        visited.assign(n + 1, 0);
        depth[root] = 0;        
    }

    void dfsDepth(int curr)
    {
        visited[curr] = 1;
        //遍历curr的子节点
        for(auto next:tree[curr])
        {
            father[next][0] = curr;
            depth[next] = depth[curr] + 1;
            if (visited[next] == 0)
                dfsDepth(next);
        }
    }

    void setFather()
    {
        for (int i = 1; i <= n ; ++i)
        {
            for (int j = 1; j <= maxUpStep ; ++j)
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
        for (int b = maxUpStep;b >= 0;--b)
            if (depth[father[u][b]] >= depth[v])
                u = father[u][b];        
        
        if (u == 0) 
            return root;
        else if(u == v) 
            return u;
        
        //往上跳跃
        for (int b = maxUpStep;b >= 0;--b)
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


int main3()
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
    }
    lca.dfsDepth(root);
    lca.setFather();

    int i=13,j=12;
    cout << i << "," << j << ":" << lca.lca(i, j) << "\n";
    // for (int i = 1; i <= n ; ++i)
    //     for (int j = i + 1; j <= n ; ++j)
    //         cout << i << "," << j << ":" << lca.lca(i, j) << "\n";

    return 0;
}

void check2Pow(int i)
{
    int maxUpStep = lg2(i);
    int sumTotal = 0;
    bitset<8> b(i);
    cout << setw(10) << b.to_string() << " " << i << "=";
    for (int b = maxUpStep; b >= 0; --b)
    {
        int tmp = pow(2, b);
        if (sumTotal + tmp > i)
            continue;
        else if (b < maxUpStep)             
            cout << "+";

        sumTotal += tmp;
        cout << 2 << "^" << b;
    }
    cout << "\n";
    
}

int main()
{
    for (int i = 1; i <= 100 ; ++i)
        check2Pow(i);
    
    return 0;
}