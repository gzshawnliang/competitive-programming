#include <bits/stdc++.h>

using namespace std;

ifstream fin("HORRIBLE_Thomas_AC.in");
ofstream fout("HORRIBLE_Thomas_AC.out");

//typedef long long LL;

using LL = long long;

const LL INF = 0;

class SegTree
{
  private:
    LL sourSize;             //原数组的大小
    const vector<LL> * sour; //原数组
    vector<LL> segTree;      //线段树的数组
    vector<LL> lazyTree;     //Lazy Propagation 延迟传播更新标记

    void build(LL left, LL right, LL node)
    {
        if (left == right)
        {
            segTree[node] = (*sour)[left];
            return;
        }
        LL mid = (left + right) / 2;
        LL nexLevLeft = node * 2;      //下层的左节点
        LL nexLevRight = node * 2 + 1; //下层的右节点

        build(left, mid, nexLevLeft);
        build(mid + 1, right, nexLevRight);

        segTree[node] = segTree[nexLevLeft]+segTree[nexLevRight];
    }

    void updateLazy(LL node, LL nodeLeft, LL nodeRight)
    {
        if (lazyTree[node] != 0)
        {
            // This node needs to be updated
            segTree[node] += lazyTree[node] * (nodeRight - nodeLeft + 1); // Update it

            if (nodeLeft != nodeRight)
            {
                lazyTree[node * 2] += lazyTree[node];     //左节点标记延迟
                lazyTree[node * 2 + 1] += lazyTree[node]; //右节点标记延迟
            }

            lazyTree[node] = 0; // Reset it
        }
    }

    LL query(LL left, LL right, LL node, LL nodeLeft, LL nodeRight)
    {
        //两个区间不重叠
        if (nodeRight < left || right < nodeLeft)
        {
            return INF;
        }

        updateLazy(node,nodeLeft,nodeRight);

        //查询的区间包含节点的区间
        if (nodeLeft >= left && nodeRight <= right)
        {
            return segTree[node];
        }

        //查分两个区间计算合并结果
        LL mid = (nodeLeft + nodeRight) / 2;

        if (left > mid)
        {
            return query(left, right, node * 2 + 1, mid + 1, nodeRight);
        }
        else if (right <= mid)
        {
            return query(left, right, node * 2, nodeLeft, mid);
        }

        LL r1 = query(left, right, node * 2, nodeLeft, mid);
        LL r2 = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return r1 + r2;
    }

    void update(LL index, LL newVal, LL node, LL nodeLeft, LL nodeRight)
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
        LL mid = (nodeLeft + nodeRight) / 2;
        update(index, newVal, node * 2, nodeLeft, mid);
        update(index, newVal, node * 2 + 1, mid + 1, nodeRight);

        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }

    void updateRange(LL left, LL right, LL newVal, LL node, LL nodeLeft, LL nodeRight)
    {
        updateLazy(node,nodeLeft,nodeRight);

        //不在区间内
        if (nodeRight < left || nodeLeft > right)
        {
            return;
        }

        //nodeLeft + nodeRight 线段完全在 left+right内
        if (nodeLeft >= left && nodeRight <= right)
        {
            segTree[node] += newVal * (nodeRight - nodeLeft + 1);

            //不是叶节点，传播延迟标记
            if (nodeLeft != nodeRight)
            {
                lazyTree[node * 2] += newVal;
                lazyTree[node * 2 + 1] += newVal;
            }
            return;
        }

        //查分两个区间计算合并结果
        LL mid = (nodeLeft + nodeRight) / 2;
        updateRange(left, right, newVal, node * 2, nodeLeft, mid);
        updateRange(left, right, newVal, node * 2 + 1, mid + 1, nodeRight);
        segTree[node] = segTree[node * 2]+ segTree[node * 2 + 1];
    }

  public:
    SegTree(const vector<LL> * p_Sour)
    {
        sour = p_Sour;
        sourSize = sour->size();
        segTree.assign(sourSize * 4, INF);
        lazyTree.assign(sourSize * 4, 0);

        build(0, sourSize - 1, 1);
    }

    LL query(LL left, LL right)
    {
        return query(left, right, 1, 0, sourSize - 1);
    }

    void update(LL index, LL newVal)
    {
        update(index, newVal, 1, 0, sourSize - 1);
    }

    void updateRange(LL left, LL right, LL newVal)
    {
        updateRange(left, right, newVal, 1, 0, sourSize - 1);
    }

};

int main()
{
    LL testCase; 
    fin >> testCase;
    for (LL t = 1; t <= testCase; ++t)
    {
        LL n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0)
            break;

        vector<LL> vec1(n, 0);
        SegTree tree(&vec1);

        for (LL c = 1; c <= m; ++c)
        {
            bool command; fin >> command;

            if (command == 0)
            {
                LL l, r, v; 
                fin >> l >> r >> v;
                tree.updateRange(l - 1, r - 1, v);
            }
            else
            {
                LL l, r; 
                fin >> l >> r;

                LL ans = tree.query(l - 1, r - 1);
                fout << ans << '\n';
            }
        }
    }
    return 0;
}
