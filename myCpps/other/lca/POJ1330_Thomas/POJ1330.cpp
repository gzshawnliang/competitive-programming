/*
===========================================================
 * @名称:       Nearest Common Ancestors
 * @作者:       Shawn 
 * @创建时间:   2019-12-21 10:16:47 
 * @修改人:     Shawn 
 * @修改时间:   2019-12-21 10:16:47 
 * @备注:       
 * @题目来源：  http://poj.org/problem?id=1330
===========================================================
*/
#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//Least Common Ancestors (最近公共祖先)

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

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("POJ1330.in", "r", stdin);
    freopen("POJ1330.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        int root = 1;
        cin >> n;
        vector<int> fa(n + 1, 0);
        LCA lca(n);

        for (int i = 1; i <= n - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            lca.tree[a].push_back(b);
            fa[b] = a;
        }
        int a, b;
        cin >> a >> b;
        while (fa[root] > 0)
            root = fa[root];
        
        lca.setRoot(root);
        lca.dfsDepth(root);
        lca.setFather();

        cout << lca.lca(a, b) << "\n";
    }

    cout.flush();
    return 0;
}