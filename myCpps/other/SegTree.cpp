/***********************************************************
 * @Name:               SegTree
 * @Created by:         Thomas
 * @Create DateTime:    2019-01-09 20:14:07
 * @Modify by:          Thomas
 * @Modify DateTime:    2019-01-09 20:14:07
 * @Description:        
***********************************************************/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("SegTree.in");
ofstream fout("SegTree.out");

const int INF = INT_MAX;


//线段树模板。原数组0开始下标
class SegTree
{
  private:
    int sourSize;             //原数组的大小
    const vector<int> * sour; //原数组
    vector<int> segTree;      //线段树的数组
    vector<int> lazyTree;     //Lazy Propagation 延迟传播更新标记

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

    int query(int left, int right, int node, int nodeLeft, int nodeRight)
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
        int r1 = query(left, right, node * 2, nodeLeft, mid);
        int r2 = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return min(r1, r2);
    }

    void update(int index, int newVal, int node, int nodeLeft, int nodeRight)
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

    void updateRange(int left, int right, int newVal, int node, int nodeLeft, int nodeRight)
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
    SegTree(const vector<int> * p_Sour)
    {
        sour = p_Sour;
        sourSize = sour->size();
        segTree.assign(sourSize * 4, INF);
        lazyTree.assign(sourSize * 4, 0);

        build(0, sourSize - 1, 1);
    }

    int query(int left, int right)
    {
        return query(left, right, 1, 0, sourSize - 1);
    }

    void update(int index, int newVal)
    {
        update(index, newVal, 1, 0, sourSize - 1);
    }

    void updateRange(int left, int right, int newVal)
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

vector<int> readData()
{
    vector<int> vec1;
    while (true)
    {
        int n;
        fin >> n;
        if (!fin.good())
        {
            break;
        }
        vec1.push_back(n);
    }
    return vec1;
}

int main()
{
    vector<int> vec1 = readData();
    SegTree sTree(&vec1);

    sTree.update(3, 5);
    cout << "1~3:" << sTree.query(1, 3) << "\n";
    cout << "2~5:" << sTree.query(2, 5) << "\n";
    cout << "3~4:" << sTree.query(3, 4) << "\n";
    cout << "2~8:" << sTree.query(2, 8) << "\n";
    cout << "5~6:" << sTree.query(5, 6) << "\n";
    cout << "0~3:" << sTree.query(0, 3) << "\n";

    cout << "update:6->4";
    sTree.update(6, 4);
    cout << "sur:";
    sTree.printSource();

    cout << "5~9:" << sTree.query(5, 9) << "\n";

    cout << "updateRange:3-9:80";
    sTree.updateRange(3, 9, 80);

    cout << "\nupdateRange:3-9:78";
    sTree.updateRange(3, 9, 78);

    cout << "\n5~9:" << sTree.query(5, 9) << "\n";
    cout << "2~9:" << sTree.query(2, 9) << "\n";
    cout << "3~5:" << sTree.query(3, 5) << "\n";
    cout << "4~7:" << sTree.query(4, 7) << "\n";
    cout << "1~3:" << sTree.query(1, 3) << "\n";
    // cout << "sur:" ;
    // sTree.printSource();

    return 0;
}
