/*
===========================================================
* @Name:           Problem 2. Milk Visits 
* @Author:         Shawn
* @create Time:    2020/1/14 16:35:52
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=970&lang=zh
* @Description:    USACO 2019 December Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

const int maxM = 1e5 + 1;

int lg2(int n)
{
    int i = 0;
    while ((1 << i) <= n) //(1<<i) = 2^i
        ++i;

    return i - 1;
}

struct Q
{
    int a, b, c;
};

class solution
{
  private:
    int N, M;
    vector<int> visited;
    vector<int> depth;
    int maxUpStep;                  //最大跳跃的步数=log2(n)
    vector<int> father;             //father[i]第i个节点的父节点
    vector<vector<int>> ancestor;   //ancestor[i][j]表示i节点往上2^j个祖先

  public:
    vector<int> C;
    vector<vector<int>> tree;
    vector<Q> query;
    vector<set<int>> typeofCow;
    int root = 1;
    
    void init(int n, int m)
    {
        maxUpStep = lg2(n);
        N = n;
        M = m;
        C.assign(N + 1, 0);
        depth.assign(N + 1, 0);
        visited.assign(N + 1, 0);
        father.assign(N + 1, 0);
        tree.assign(N + 1, vector<int>());
        typeofCow.assign(N + 1, set<int>());
        ancestor.assign(N + 1, vector<int>(maxUpStep + 1, 0));
    }

    void setAncestor()
    {
        for (int j = 1; j <= maxUpStep; ++j)
            for (int i = 1; i <= N; ++i)
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];        
    }    

    void dfs(int curr)
    {
        visited[curr] = 1;
        for (auto i : tree[curr])
        {
            if (visited[i] == 0)
            {
                father[i] = curr;
                ancestor[i][0] = curr;
                depth[i] = depth[curr] + 1;
                dfs(i);
            }
        }
    }

    int getLCA(int u,int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        //设置同等深度
        for (int b = maxUpStep; b >= 0; --b)
            if (depth[ancestor[u][b]] >= depth[v])
                u = ancestor[u][b];

        if (u == 0)
            return root;
        else if (u == v)
            return u;

        //往上跳跃
        for (int b = maxUpStep; b >= 0; --b)
        {
            if (ancestor[u][b] != ancestor[v][b])
            {
                u = ancestor[u][b];
                v = ancestor[v][b];
            }
        }
        return ancestor[u][0];
    }

    //todo 需要改成O(1)算法
    //https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.03.md
    //https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
    //https://www.geeksforgeeks.org/lca-n-ary-tree-constant-query-o1/
    bool isAncestor(int u,int v)
    {
        if(v==root)
            return true;

        //往上跳跃
        for (int b = maxUpStep; b >= 0; --b)
            if (depth[ancestor[u][b]] >= depth[v])
                u = ancestor[u][b];

        if(u==v)
            return true;
        else
            return false;
    }

    void solve()
    {
        for (int i = 0; i <= M - 1; ++i)
        {
            int a = query[i].a;
            int b = query[i].b;
            int c = query[i].c;
            int lca = getLCA(a, b);
            if (typeofCow[c].empty())
            {
                fout << "0";
            }
            else
            {
                int result = 0;
                for (auto i : typeofCow[c])
                {
                    if (depth[i]> depth[a] && depth[i]> depth[b])
                        continue;
                    else if (depth[i]< depth[lca])
                        continue;
                    else if(isAncestor(a,i) || isAncestor(b,i))
                    {
                        result=1;
                        break;
                    }
                }
                fout << result;
            }
        }
    }
};

//solution slv;

int main()
{
    solution slv;
    int n, m;
    fin >> n >> m;
    slv.init(n,m);
    //solution slv(n, m);

    for (int i = 1; i <= n; ++i)
    {
        fin >> slv.C[i];
        slv.typeofCow[slv.C[i]].insert(i);
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        fin >> a >> b;
        slv.tree[a].push_back(b);
        slv.tree[b].push_back(a);
    }


    slv.dfs(slv.root);
    slv.setAncestor();

    //cout << slv.lca(7,3) << "\n";
    //cout << slv.isAncestor(8,3) << "\n";


    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        slv.query.push_back(Q{a, b, c});
    }

    slv.solve();


    bitset<maxM> ans;
    //cout << ans.to_string().substr(maxM-M,M) << "\n";

    return 0;
}
