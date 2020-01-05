#include <bits/stdc++.h>

using namespace std;

const long long INF = -15008;

class node
{
  public:
    long long sum;
    long long ans;
    long long left;
    long long right;

    node(long long p_Sum, long long p_Ans, long long p_Left, long long p_Right)
    {
        sum = p_Sum;
        ans = p_Ans;
        left = p_Left;
        right = p_Right;
    }
    node()
    {
        sum = INF;
        ans = INF;
        left = INF;
        right = INF;
    }
};

node getNode(long long p_Sum, long long p_Ans, long long p_Left, long long p_Right)
{
    node t(p_Sum, p_Ans, p_Left, p_Right);
    return t;
}

class SegTree
{
  private:
    long long sourSize;              //原数组的大小
    const vector<node> * sour; //原数组
    vector<node> segTree;      //线段树的数组

    void fillNode(long long pos)
    {
        node leftChild = segTree[pos * 2];          //下层的左节点
        node rightChild = segTree[pos * 2 + 1];     //下层的右节点
        
        segTree[pos].sum = leftChild.sum + rightChild.sum;

        segTree[pos].left = max(leftChild.left ,leftChild.sum+rightChild.left);
        segTree[pos].right = max(rightChild.right ,leftChild.right+rightChild.sum);
        segTree[pos].ans =max(max(leftChild.ans,rightChild.ans),leftChild.right+rightChild.left);
    }

    node merge(node a, node b){
        node node1;
        node1.sum = a.sum + b.sum;
        node1.left = max(a.left, a.sum + b.left);
        node1.right = max(b.right, b.sum + a.right);
        node1.ans = max(max(a.ans, b.ans), b.left + a.right); 
        return node1;
    }

    void build(long long left, long long right, long long pos)
    {
        if (left == right)
        {
            segTree[pos] = (*sour)[left];
            return;
        }
        long long mid = (left + right) / 2;
        long long nexLevLeft = pos * 2;      //下层的左节点
        long long nexLevRight = pos * 2 + 1; //下层的右节点

        build(left, mid, nexLevLeft);
        build(mid + 1, right, nexLevRight);

        //segTree[pos] = max(segTree[nexLevLeft], segTree[nexLevRight]);
        fillNode(pos);
    }

    node query(long long left, long long right, long long pos, long long nodeLeft, long long nodeRight)
    {
        //两个区间不重叠
        if (nodeRight < left || right < nodeLeft)
        {
            return getNode(INF, INF, INF, INF);
        }

        //查询的区间包含节点的区间
        if (nodeLeft >= left && nodeRight <= right)
        {
            return segTree[pos];
        }

        //查分两个区间计算合并结果
        long long mid = (nodeLeft + nodeRight) / 2;

        //只用右
        if(right <= mid)
        {
            return query(left, right, pos * 2, nodeLeft, mid);
        }

        //只用左
        if(left > mid)
        {
            return query(left, right, pos * 2 + 1, mid + 1, nodeRight);
        }

        node lChild = query(left, right, pos * 2, nodeLeft, mid);
        node rChild = query(left, right, pos * 2 + 1, mid + 1, nodeRight);
        
        //合并左右结果
        return merge(lChild, rChild);
    }

  public:
    SegTree(const vector<node> * p_Sour)
    {
        sour = p_Sour;
        sourSize = sour->size();
        segTree.assign(sourSize * 4, getNode(INF, INF, INF, INF));

        build(0, sourSize - 1, 1);
    }

    node query(long long left, long long right)
    {
        return query(left, right, 1, 0, sourSize - 1);
    }
};

int main()
{
    freopen("GSS1_2.in", "r", stdin);
    freopen("GSS1_2.out", "w", stdout);

    // ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
    long long N;
    cin >> N;
    vector<node> a(N,getNode(INF, INF, INF, INF));
    for (long long i = 0; i <= N - 1; ++i)
    {
        cin>>a[i].sum;
        a[i].left  = a[i].sum;
        a[i].right  = a[i].sum;
        a[i].ans = a[i].sum;
    }
    SegTree segTree(&a);
    long long M;
    cin >> M;
    for (long long i = 0; i <= M - 1; ++i)
    {
        long long x=0;
        long long y=0;
        cin >> x >> y;
        if(x==0 || y==0)
        {
            break;
        }
        cout << segTree.query(x-1,y-1).ans << '\n';
    }
    cout.flush();
    return 0;
}