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
    while ((1 << i) <= n)           //(1<<i) = 2^i
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

    vector<int> depth;
    int maxUpStep;                  //最大跳跃的步数=log2(n)
    vector<int> father;             //father[i]第i个节点的父节点
    vector<vector<int>> ancestor;   //ancestor[i][j]表示i节点往上2^j个祖先

    vector<int> visitedPreOrder;
    vector<int> visitedPosOrder;
    vector<int> preOrder;           //前序遍历第i个节点的顺序
    vector<int> posOrder;           //前序遍历第i个节点的顺序
    int preNodeOrder;
    int posNodeOrder;

    vector<int> eulerWalk;          //欧拉序列
    vector<int> eulerDepth;         //欧拉序列每个节点的深度
    vector<int> FAI;                //First appearance of ith node in Euler Walk array
    int maxJ;
    vector<vector<int>> ST;          //Sparse Table (ST表)
    vector<int> P2;                  //stores power of 2

    int lg2(int n)
    {
        int i = 0;
        while ((1 << i) <= n) //(1<<i) = 2^i
            ++i;

        return i - 1;
    }

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
        visitedPreOrder.assign(N + 1, 0);
        visitedPosOrder.assign(N + 1, 0);
        father.assign(N + 1, 0);
        tree.assign(N + 1, vector<int>());
        typeofCow.assign(N + 1, set<int>());
        ancestor.assign(N + 1, vector<int>(maxUpStep + 1, 0));

        preNodeOrder = 0;
        posNodeOrder = 0;
        preOrder.assign(N + 1, 0);
        posOrder.assign(N + 1, 0);
        FAI.assign(N + 1, -1);

        maxJ = lg2(N)+1;
        P2.assign(maxJ , 0);
        P2[0] = 1; 
        for (int i=1; i<=maxJ; ++i) 
            P2[i] = P2[i-1]*2; 

        ST.assign(maxM, vector<int>(maxJ+1, -1));      //Sparse Table (ST表)

        //eulerWalk.assign(2*N,0);
    }

    // void setAncestor()
    // {
    //     for (int j = 1; j <= maxUpStep; ++j)
    //         for (int i = 1; i <= N; ++i)
    //             ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    // }

    void dfs_preOrder(int curr)
    {
        if(FAI[curr]==-1)
            FAI[curr] =preNodeOrder;

        eulerWalk.push_back(curr);
        visitedPreOrder[curr] = 1;
        ++preNodeOrder;
        preOrder[curr] = preNodeOrder;
        for (auto child : tree[curr])
        {
            if (visitedPreOrder[child] == 0)
            {
                father[child] = curr;
                ancestor[child][0] = curr;
                depth[child] = depth[curr] + 1;

                dfs_preOrder(child);

                eulerWalk.push_back(curr);
                ++preNodeOrder;
            }
        }
    }

    void makeEulerDepth()
    {
        for (auto i : eulerWalk)
            eulerDepth.push_back(depth[i]);
    }

    void dfs_posOrder(int curr)
    {
        visitedPosOrder[curr] = 1;
        for (auto child : tree[curr])
        {
            if (visitedPosOrder[child] == 0)
            {
                dfs_posOrder(child);
            }
        }
        ++posNodeOrder;
        posOrder[curr] = posNodeOrder;
    }

    void buitST()
    {
        //int len = a.size();

        //vector<vector<int>> M(N, vector<int>(maxJ, -1));      //Sparse Table (ST表)

        for (int i = 0; i <= N-1 ; ++i)
        {
            ST[i][0] = i;
        }

        for (int j = 1; j <= maxJ+1 ; ++j)
        {
            for (int i = 0; i <= N-1 ; ++i)
            {
                int front=j-1;
                int back= i + (1<<(j-1));
                if(back>N*2)
                    continue;

                if (eulerWalk[ST[i][front]] <= eulerWalk[ST[back][front]])
                    ST[i][j] = ST[i][front];
                else                 
                    ST[i][j] = ST[back][front];
            }
        }
        for (int __s = 0; __s == 0; ++__s);
    }

    int queryST(int i,int j) 
    { 
        if(i==j)
            return ST[i][0];

        if(i>j)
            swap(i,j);

        int d = j-i; 
        int k=lg2(d+1);               //长度

        int front=ST[i][k];              //前段
        int i2=j-(1<<k)+1;          //后段j-2^k+1;
        int back=ST[i2][k];
        
        if(front==-1 || back==-1)
            return root;

        if(eulerWalk[front]<=eulerWalk[back])
            return front;
        else 
            return back;

    }

    //todo O(1)算法,未完成
    int getLCA(int u, int v)
    {
        if (u==v) 
            return u; 
        int i=FAI[u];
        int j=FAI[v];
        if (i > j) 
            swap(u, v); 

        return eulerWalk[queryST(i, j)];                        
    }

    void setAncestor()
    {
        for (int j = 1; j <= maxUpStep; ++j)
            for (int i = 1; i <= N; ++i)
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    /*
    O(1)算法求x是不是y的祖先？
    https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.03.md
    https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
    For two given nodes x and y of a tree T, x is an ancestor of y if and only if x occurs 
    before y in the preorder traversal of T and after y in the post-order traversal.
    */
    bool isAncestor(int y, int x)
    {
        if (x == root)
            return true;

        if (y == x)
            return true;

        if (preOrder[x] < preOrder[y] && posOrder[x] > posOrder[y])
            return true;

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
                    if (depth[i] > depth[a] && depth[i] > depth[b])
                        continue;
                    else if (depth[i] < depth[lca])
                        continue;
                    else if (isAncestor(a, i) || isAncestor(b, i))
                    {
                        result = 1;
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
    slv.init(n, m);
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

    slv.dfs_preOrder(slv.root);
    slv.dfs_posOrder(slv.root);
    slv.makeEulerDepth();
    slv.setAncestor();
    slv.buitST();

    //cout << slv.lca(7,3) << "\n";
    //cout << slv.isAncestor(8,3) << "\n";

    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        slv.query.push_back(Q{a, b, c});
    }

    slv.solve();


    return 0;
}
