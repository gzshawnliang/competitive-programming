#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF = LLONG_MAX /2 ;

//线段树模板。原数组0开始下标
class SegTree
{
  private:
    int sourSize;             //原数组的大小
    const vector<ill> * sour; //原数组
    vector<ill> segTree;      //线段树的数组
    vector<ill> lazyTree;     //Lazy Propagation 延迟传播更新标记

    void build(int left, int right, int node)
    {
        if (left == right)
        {
            segTree[node] = (*sour)[left];
            return;
        }
        int mid = (left + right) / 2;
        int nexLevLeft = node * 2;      //下层的左节点
        int nexLevRight = node * 2 + 1; //下层的右节点

        build(left, mid, nexLevLeft);
        build(mid + 1, right, nexLevRight);

        segTree[node] = min(segTree[nexLevLeft], segTree[nexLevRight]);
    }

    ill query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        //两个区间不重叠
        if (nodeRight < left || right < nodeLeft)
        {
            return INF;
        }

        if (lazyTree[node] != 0)
        {
            // This node needs to be updated
            segTree[node] = lazyTree[node]; // Update it

            if (left != right)
            {
                lazyTree[node * 2] = lazyTree[node];     //左节点标记延迟
                lazyTree[node * 2 + 1] = lazyTree[node]; //右节点标记延迟
            }

            lazyTree[node] = 0; // Reset it
        }

        //查询的区间包含节点的区间
        if (nodeLeft >= left && nodeRight <= right)
        {
            return segTree[node];
        }

        //查分两个区间计算合并结果
        int mid = (nodeLeft + nodeRight) / 2;
        ill r1 = query(left, right, node * 2, nodeLeft, mid);
        ill r2 = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return min(r1, r2);
    }

    void update(int index, ill newVal, int node, int nodeLeft, int nodeRight)
    {
        //index不在区间内
        if (index > nodeRight || index < nodeLeft)
        {
            return;
        }

        //已经是叶节点
        if (nodeLeft == nodeRight)
        {
            //sour[index] = newVal;
            segTree[node] = newVal;
            return;
        }

        //查分两个区间计算合并结果
        int mid = (nodeLeft + nodeRight) / 2;
        update(index, newVal, node * 2, nodeLeft, mid);
        update(index, newVal, node * 2 + 1, mid + 1, nodeRight);

        segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
    }

    void updateRange(int left, int right, ill newVal, int node, int nodeLeft, int nodeRight)
    {
        //node此节点需要更新
        if (lazyTree[node] != 0)
        {
            segTree[node] = lazyTree[node]; // 更新

            if (left != right)
            {
                lazyTree[node * 2] = lazyTree[node];     //左节点标记延迟
                lazyTree[node * 2 + 1] = lazyTree[node]; //右节点标记延迟
            }

            lazyTree[node] = 0; // Reset it
        }

        //不在区间内
        if (nodeRight < left || right < nodeLeft)
        {
            return;
        }

        //nodeLeft + nodeRight 线段完全在 left+right内
        if (nodeLeft >= left && nodeRight <= right)
        {
            segTree[node] = newVal;

            //不是叶节点，标记延迟
            if (left != right)
            {
                lazyTree[node * 2] = newVal;
                lazyTree[node * 2 + 1] = newVal;
            }
            return;
        }

        //已经是叶节点
        if (nodeLeft == nodeRight)
        {
            //sour[nodeLeft] = newVal;
            segTree[node] = newVal;
            return;
        }

        //查分两个区间计算合并结果
        int mid = (nodeLeft + nodeRight) / 2;
        updateRange(left, right, newVal, node * 2, nodeLeft, mid);
        updateRange(left, right, newVal, node * 2 + 1, mid + 1, nodeRight);
        segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
    }

  public:
    SegTree(const vector<ill> * p_Sour)
    {
        sour = p_Sour;
        sourSize = sour->size();
        segTree.assign(sourSize * 4, INF);
        lazyTree.assign(sourSize * 4, 0);

        build(0, sourSize - 1, 1);
    }

    ill query(int left, int right)
    {
        return query(left, right, 1, 0, sourSize - 1);
    }

    ill query(int index)
    {
        return query(index, index, 1, 0, sourSize - 1);
    }

    void update(int index, ill newVal)
    {
        update(index, newVal, 1, 0, sourSize - 1);
    }

    void updateRange(int left, int right, ill newVal)
    {
        updateRange(left, right, newVal, 1, 0, sourSize - 1);
    }

    void printSource()
    {
        // for(auto i:sour)
        //     cout << i << " ";
        for (int i = 0; i <= sourSize - 1; ++i)
        {
            cout << sour->at(i) << " ";
        }
        cout << "\n";
    }
};


class solution
{
    vector<int> parent;
    vector<int> cost;
    vector<vector<int>> treeAdj;
    vector<ill> dp;    
    vector<int> mainPath;
    vector<int> isMainPath;

    vector<int> branch;

    int N,M;

    void dfsNode(int curr,int depth)
    {
        if(depth>=M)
            return;
        
        if(depth>0)
        {
            if((int)branch.size()<=depth)
                branch.push_back(curr);
            else if(cost[curr] >0 && cost[curr] < cost[branch[depth]]) 
                branch[depth] = curr;
        }

        for (int i = 0,len=treeAdj[curr].size(); i <= len - 1; ++i)
        {
            if(isMainPath[treeAdj[curr][i]]==0)
                dfsNode(treeAdj[curr][i],depth+1);
        }
    }

  public:

    void solve(int T)
    {
        int A,B;
        cin >> N>>M>>A>>B;
        parent = vector<int>(N+1);
        cost = vector<int>(N+1);
        //cerr << "T-N:" << T << "-" << N << " " << M << "\n";

        for (int i = 1; i <= N; ++i)
            cin >> parent[i]>>cost[i];

        // if(N>=1e6)
        // {
        //     cout << "Case #" << T <<": " << N << "\n";
        //     return;        
        // }

        //Change Root to B
        int root =B;
        int curr =B;
        vector<int> path;
        while (true)
        {
            path.push_back(curr);
            curr = parent[curr];
            if(curr==0)
                break;
        }

        parent[root]=0;
        for (int i = 1,len=path.size(); i <= len - 1; ++i)
            parent[path[i]] =path[i-1];


        //Make Tree Matrix
        treeAdj= vector<vector<int>>(N+1);
        for (int i = 1; i <= N; ++i)
            treeAdj[parent[i]].push_back(i);
        

        // for (int i = 1; i <= N; ++i)
        // {
        //     for (int j = 0,len=treeAdj[i].size(); j <= len-1; ++j)
        //     {
        //         cout << i << " " << treeAdj[i][j] << "\n";
        //     }
        // }
        // cout << "\n";

        //fill mainPath
        curr =A;
        isMainPath=vector<int>(N+1);
        while (true)
        {
            mainPath.push_back(curr);
            curr = parent[curr];
            if(curr==0)
                break;
        }           

        for (int i = 0,len=mainPath.size(); i <= len - 1; ++i)
            isMainPath[mainPath[i]]=1;
        
        int nodeCount =mainPath.size();
        dp = vector<ill>(nodeCount , INF);
        dp[0]=0;
        SegTree seq(& dp);
        seq.update(0,0);

        for (int i = 1; i <= nodeCount - 1; ++i)
        {
            int curr=mainPath[i];
            //branch.clear();
            branch.assign(1,0);
            dfsNode(curr,0);
            
            if(cost[curr]>0)
            {
                ill r=seq.query(max(0,i-M),i-1);
                seq.update(i,r+cost[curr]*1LL);
            }

            for (int d=1;d <=M-1 && i-d>=0 && d <=(int)branch.size()-1;++d)
            {
                int replaceId = branch[d];
                if(cost[replaceId]==0)
                    continue;

                ill r1=seq.query(max(0,i-(M-d)),i-1);
                ill c=seq.query(i-d);
                seq.update(i-d, min(c,r1+cost[replaceId]*1LL));
            }
        }

        ill ans = seq.query(max(0,nodeCount-M-1),nodeCount-1);
        cout << "Case #" << T << ": " << (ans == INF ? -1 : ans) << "\n";
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("running_on_fumes_chapter_2_input.txt", "r", stdin);
    freopen("D2.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        solution sln1;
        sln1.solve(i);
        cout.flush();
    }

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}